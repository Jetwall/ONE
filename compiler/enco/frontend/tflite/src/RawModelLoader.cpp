/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "RawModelLoader.h"

#include "cwrap/Fildes.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

namespace
{

class MemoryMappedRawModel final : public RawModel
{
public:
  /**
   * @require fd and data SHOULD be valid
   */
  explicit MemoryMappedRawModel(int fd, void *data, size_t size) : _fd{fd}, _data{data}, _size{size}
  {
    // DO NOTHING
  }

public:
  ~MemoryMappedRawModel()
  {
    munmap(_data, _size);
    close(_fd);
  }

public:
  MemoryMappedRawModel(const MemoryMappedRawModel &) = delete;
  MemoryMappedRawModel(MemoryMappedRawModel &&) = delete;

public:
  const tflite::Model *model(void) const override { return tflite::GetModel(_data); }

private:
  int _fd = -1;
  void *_data = nullptr;
  size_t _size = 0;
};

} // namespace

std::unique_ptr<RawModel> load_from(const std::string &path)
{
  cwrap::Fildes fildes{open(path.c_str(), O_RDONLY)};

  if (fildes.get() == -1)
  {
    // Return nullptr on open failure
    return nullptr;
  }

  struct stat st;
  if (fstat(fildes.get(), &st) == -1)
  {
    // Return nullptr on fstat failure
    return nullptr;
  }

  auto size = st.st_size;
  auto data = mmap(nullptr, size, PROT_READ, MAP_SHARED, fildes.get(), 0);

  if (data == MAP_FAILED)
  {
    // Return nullptr on mmap failure
    return nullptr;
  }

  return std::unique_ptr<RawModel>{new MemoryMappedRawModel(fildes.release(), data, size)};
}
