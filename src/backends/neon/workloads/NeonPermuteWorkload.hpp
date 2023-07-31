//
// Copyright © 2017-2018,2021-2023 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "NeonBaseWorkload.hpp"
#include <armnn/backends/WorkloadData.hpp>
#include <neon/workloads/NeonWorkloadUtils.hpp>

#include <armnn/TypesUtils.hpp>
#include <arm_compute/runtime/NEON/functions/NEPermute.h>

#include <string>

namespace armnn
{
arm_compute::Status NeonPermuteWorkloadValidate(const TensorInfo& input, const TensorInfo& output,
                                                const PermuteDescriptor& descriptor);

class NeonPermuteWorkload : public NeonBaseWorkload<PermuteQueueDescriptor>
{
public:
    NeonPermuteWorkload(const PermuteQueueDescriptor& descriptor, const WorkloadInfo& info);
    void Execute() const override;

private:
    using BaseWorkload<PermuteQueueDescriptor>::m_Data;
    mutable arm_compute::NEPermute m_PermuteFunction;
};

} // namespace armnn
