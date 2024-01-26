//
// Copyright © 2022-2024 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "backendsCommon/test/EndToEndTestImpl.hpp"

#include "backendsCommon/test/Convolution2dEndToEndTestImpl.hpp"
#include "backendsCommon/test/DepthwiseConvolution2dEndToEndTests.hpp"

#include <doctest/doctest.h>

TEST_SUITE("GpuFsaEndToEnd")
{

std::vector<BackendId> gpuFsaDefaultBackends = {"GpuFsa"};

// Conv2d
TEST_CASE("GpuFsaConv2dEndtoEndTestFloat32")
{
    Convolution2dEndToEnd<armnn::DataType::Float32>(gpuFsaDefaultBackends, armnn::DataLayout::NHWC);
}

TEST_CASE("GpuFsaConv2dWithoutBiasEndtoEndTestFloat32")
{
    Convolution2dEndToEnd<armnn::DataType::Float32>(gpuFsaDefaultBackends, armnn::DataLayout::NHWC, false);
}

TEST_CASE("GpuFsaDepthwiseConvolution2dEndtoEndTestFloat32")
{
    DepthwiseConvolution2dEndToEnd<armnn::DataType::Float32, armnn::DataType::Float32>(gpuFsaDefaultBackends,
                                                                                       armnn::DataLayout::NHWC);
}

}
