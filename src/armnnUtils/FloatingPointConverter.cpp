//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <armnnUtils/FloatingPointConverter.hpp>

#include "BFloat16.hpp"
#include "Half.hpp"

#include <armnn/utility/Assert.hpp>

namespace armnnUtils
{

void FloatingPointConverter::ConvertFloat32To16(const float* srcFloat32Buffer,
                                                size_t numElements,
                                                void* dstFloat16Buffer)
{
    ARMNN_ASSERT(srcFloat32Buffer != nullptr);
    ARMNN_ASSERT(dstFloat16Buffer != nullptr);

    armnn::Half* pHalf = static_cast<armnn::Half*>(dstFloat16Buffer);

    for (size_t i = 0; i < numElements; i++)
    {
        pHalf[i] = armnn::Half(srcFloat32Buffer[i]);
        if (isinf(pHalf[i]))
        {
            // If the value of converted Fp16 is infinity, round to the closest finite Fp16 value.
            pHalf[i] = copysign(std::numeric_limits<armnn::Half>::max(), pHalf[i]);
        }
    }
}

void FloatingPointConverter::ConvertFloat16To32(const void* srcFloat16Buffer,
                                                size_t numElements,
                                                float* dstFloat32Buffer)
{
    ARMNN_ASSERT(srcFloat16Buffer != nullptr);
    ARMNN_ASSERT(dstFloat32Buffer != nullptr);

    const armnn::Half* pHalf = static_cast<const armnn::Half*>(srcFloat16Buffer);

    for (size_t i = 0; i < numElements; i++)
    {
        dstFloat32Buffer[i] = pHalf[i];
    }
}

} //namespace armnnUtils
