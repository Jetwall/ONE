/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __MOCO_ONNX_FRONTEND_H__
#define __MOCO_ONNX_FRONTEND_H__

#include <loco.h>

#include <memory>

namespace moco
{
namespace onnx
{

class Frontend
{
public:
  enum class FileType
  {
    Text,
    Binary,
  };

public:
  Frontend();

public:
  std::unique_ptr<loco::Graph> load(const char *, FileType) const;
};

} // namespace onnx
} // namespace moco

#endif // __MOCO_ONNX_FRONTEND_H__
