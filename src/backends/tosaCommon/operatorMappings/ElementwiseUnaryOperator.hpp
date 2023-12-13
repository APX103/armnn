//
// Copyright © 2023 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "TosaOperatorUtils.hpp"

using namespace armnn;
using namespace tosa;

TosaSerializationBasicBlock* ConvertElementwiseUnaryOperator(const Layer* layer,
                                                             const std::vector<const TensorInfo*>& inputs,
                                                             const std::vector<const TensorInfo*>& outputs,
                                                             const ElementwiseUnaryDescriptor* unaryDescriptor);
