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

#ifndef __LUCI_IR_CIRCELARGMIN_H__
#define __LUCI_IR_CIRCELARGMIN_H__

#include "luci/IR/CircleNodeDecl.h"
#include "luci/IR/CircleOpcode.h"

#include "luci/IR/LuciNodeMixins.h"

namespace luci
{

/**
 * @brief ARG_Min in Circle
 */
class CircleArgMin final : public FixedArityNode<2, CircleNodeImpl<CircleOpcode::ARG_MIN>>
{
public:
  loco::Node *input(void) const { return at(0)->node(); }
  void input(loco::Node *node) { at(0)->node(node); }

  loco::Node *dimension(void) const { return at(1)->node(); }
  void dimension(loco::Node *node) { at(1)->node(node); }

public:
  loco::DataType output_type(void) const { return _output_type; }
  void output_type(loco::DataType ot) { _output_type = ot; }

private:
  loco::DataType _output_type{loco::DataType::S64};
};

} // namespace luci

#endif // __LUCI_IR_CIRCELARGMIN_H__
