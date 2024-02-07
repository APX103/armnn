//
// Copyright © 2020, 2023-2024 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "TransposeTestHelper.hpp"

#include <doctest/doctest.h>

namespace armnnDelegate
{

void TransposeFP32Test()
{
    // set test input data
    std::vector<int32_t> input0Shape {4, 2, 3};
    std::vector<int32_t> inputPermVecShape {3};
    std::vector<int32_t> outputShape {3, 4, 2};

    std::vector<float> input0Values = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
                                       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    std::vector<int32_t> inputPermVec = {2, 0, 1};
    std::vector<float> expectedOutputValues = {0, 3, 6, 9, 12, 15, 18, 21, 1, 4, 7, 10,
                                               13, 16, 19, 22, 2, 5, 8, 11, 14, 17, 20, 23};

    TransposeTest<float>(input0Shape,
                         inputPermVecShape,
                         outputShape,
                         input0Values,
                         inputPermVec,
                         expectedOutputValues);
}

TEST_SUITE ("TransposeTests")
{

TEST_CASE ("Transpose_Float32_Test")
{
    TransposeFP32Test();
}

}

} // namespace armnnDelegate
