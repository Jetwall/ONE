/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "CircleOptimizerUtils.h"

namespace luci
{

static std::string to_lower_case(std::string s)
{
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
  return s;
}

loco::DataType str_to_dtype(const std::string &str)
{
  if (to_lower_case(str).compare("uint8") == 0)
    return loco::DataType::U8;
  if (to_lower_case(str).compare("uint16") == 0)
    return loco::DataType::U16;
  if (to_lower_case(str).compare("uint32") == 0)
    return loco::DataType::U32;
  if (to_lower_case(str).compare("uint64") == 0)
    return loco::DataType::U64;

  if (to_lower_case(str).compare("int8") == 0)
    return loco::DataType::S8;
  if (to_lower_case(str).compare("int16") == 0)
    return loco::DataType::S16;
  if (to_lower_case(str).compare("int32") == 0)
    return loco::DataType::S32;
  if (to_lower_case(str).compare("int64") == 0)
    return loco::DataType::S64;

  if (to_lower_case(str).compare("float16") == 0)
    return loco::DataType::FLOAT16;
  if (to_lower_case(str).compare("float32") == 0)
    return loco::DataType::FLOAT32;
  if (to_lower_case(str).compare("float64") == 0)
    return loco::DataType::FLOAT64;

  if (to_lower_case(str).compare("bool") == 0)
    return loco::DataType::BOOL;

  return loco::DataType::Unknown;
}

} // namespace luci