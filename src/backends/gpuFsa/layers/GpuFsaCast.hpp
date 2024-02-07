//
// Copyright © 2024 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include <armnn/Descriptors.hpp>

#include <gpuFsa/GpuFsaBackend.hpp>

namespace armnn
{

arm_compute::Status GpuFsaCastValidate(const TensorInfo& input,
                                       const TensorInfo& output);

void GpuFsaCastCreateOp(GpuFsaPreCompiledBlob* blob,
                        const TensorInfo& input,
                        const TensorInfo& output);

} // namespace armnn