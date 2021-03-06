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

#ifndef __NEST_DOMAIN_CONTEXT_H__
#define __NEST_DOMAIN_CONTEXT_H__

#include "nest/DomainInfo.h"
#include "nest/Domain.h"

#include <vector>

namespace nest
{

class DomainContext
{
public:
  uint32_t count(void) const;

public:
  Domain make(std::initializer_list<uint32_t> dims);

public:
  const DomainInfo &info(const Domain &) const;

private:
  std::vector<DomainInfo> _info;
};

} // namespace nest

#endif // __NEST_DOMAIN_CONTEXT_H__
