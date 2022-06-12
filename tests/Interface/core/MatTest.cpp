//===- MatTest.cpp ---------------------------------------------===//
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//
//
// This is the image default encoder/decoder test file.
//
//===----------------------------------------------------------------------===//

// RUN: buddy-mat-test 2>&1 | FileCheck %s

#include "Interface/buddy/core/Mat.h"
#include "Interface/buddy/core/ImageContainer.h"

int main() {
  // The original test image is a gray scale image, and the pixel values are as
  // follows:
  // 15.0, 30.0, 45.0, 60.0
  // 75.0, 90.0, 105.0, 120.0
  // 135.0, 150.0, 165.0, 180.0
  // 195.0, 210.0, 225.0, 240.0
  // The test running directory is in <build dir>/tests/Interface/core, so the
  // `imread` function uses the following relative path.

  //===--------------------------------------------------------------------===//
  // Test image constructor for Buddy Mat.
  //===--------------------------------------------------------------------===//
  Img<float, 2> testMatConstructor(
      "../../../../tests/Interface/core/TestGrayImage.png");
  // CHECK: 15.0
  fprintf(stderr, "%f\n", testMatConstructor.getData()[0]);
  // CHECK: 4, 4
  fprintf(stderr, "%ld, %ld\n", testMatConstructor.getSizes()[0],
          testMatConstructor.getSizes()[1]);
  // CHECK: 4, 1
  fprintf(stderr, "%ld, %ld\n", testMatConstructor.getStrides()[0],
          testMatConstructor.getStrides()[1]);
  // CHECK: 2
  fprintf(stderr, "%ld\n", testMatConstructor.getRank());
  // CHECK: 16
  fprintf(stderr, "%ld\n", testMatConstructor.getSize());
  // CHECK: 60.0
  fprintf(stderr, "%f\n", testMatConstructor[3]);

  //   //===--------------------------------------------------------------------===//
  //   // Test copy constructor.
  //   //===--------------------------------------------------------------------===//
  //   // TODO: Add copy assignment operator test.
  //   Img<float, 2> testCopyConstructor1(testMatConstructor);
  //   // CHECK: 15.0
  //   fprintf(stderr, "%f\n", testCopyConstructor1[0]);
  //   Img<float, 2> testCopyConstructor2 = testMatConstructor;
  //   // CHECK: 15.0
  //   fprintf(stderr, "%f\n", testCopyConstructor2[0]);
  //   Img<float, 2> testCopyConstructor3 = Img<float,
  //   2>(testMatConstructor);
  //   // CHECK: 15.0
  //   fprintf(stderr, "%f\n", testCopyConstructor3[0]);
  //   Img<float, 2> *testCopyConstructor4 =
  //       new Img<float, 2>(testMatConstructor);
  //   // CHECK: 5.0
  //   fprintf(stderr, "%f\n", testCopyConstructor4->getData()[0]);
  //   delete testCopyConstructor4;

  //   //===--------------------------------------------------------------------===//
  //   // Test move constructor.
  //   //===--------------------------------------------------------------------===//
  //   // TODO: Add copy assignment operator test.
  //   Img<float, 2> testMoveConstructor1(std::move(testCopyConstructor1));
  //   // CHECK: 15.0
  //   fprintf(stderr, "%f\n", testMoveConstructor1[0]);
  //   Img<float, 2> testMoveConstructor2 = std::move(testMoveConstructor1);
  //   // CHECK: 15.0
  //   fprintf(stderr, "%f\n", testMoveConstructor2[0]);

  //   //===--------------------------------------------------------------------===//
  //   // Test overloading bracket operator.
  //   //===--------------------------------------------------------------------===//
  //   Img<float, 2> testBracketOperator1(image);
  //   // CHECK: 240.0
  //   fprintf(stderr, "%f\n", testBracketOperator1[15]);
  //   testBracketOperator1[15] = 90.0;
  //   // CHECK: 90.0
  //   fprintf(stderr, "%f\n", testBracketOperator1[15]);
  //   const Img<float, 2> testBracketOperator2(image);
  //   // CHECK: 240.0
  //   fprintf(stderr, "%f\n", testBracketOperator2[15]);

  return 0;
}
