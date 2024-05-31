//
// Created by ilyalezhnin on 31.05.24.
//

#include <gtest/gtest.h>
#include <sstream>
#include "../Classes/CMyArray.hpp"

TEST(CMyArrayDoubleTest, CreatingDefault) {
    CMyArray<double> arr;
    EXPECT_EQ(arr.Count(), 0);
    EXPECT_EQ(arr.Size(), 1);
}

TEST(CMyArrayDoubleTest, AddingElements) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(5.2222);
    arr.pushBack(100.222);
    arr.pushBack(220);

    EXPECT_EQ(arr.Count(), 4);
    EXPECT_EQ(arr.Size(), 8);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5.2222);
    EXPECT_EQ(arr[2], 100.222);
    EXPECT_EQ(arr[3], 220);
}

TEST(CMyArrayDoubleTest, OutOfBoundsAccess) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(5.2222);
    arr.pushBack(100.222);

    EXPECT_THROW(arr[10], CMyArrayException);
}

TEST(CMyArrayDoubleTest, ModifyElement) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(5.2222);
    arr.pushBack(100.222);
    arr[2] = 10.001;

    EXPECT_EQ(arr[2], 10.001);
}

TEST(CMyArrayDoubleTest, SumElements) {
    CMyArray<double> arr;
    double digit1 = 5;
    double digit2 = 5.2222;
    double digit3 = 100.222;
    arr.pushBack(digit1);
    arr.pushBack(digit2);
    arr.pushBack(digit3);

    double expectedSum = digit1 + digit2 + digit3;
    double generalSum = 0;
    for (const double value : arr) {
        generalSum += value;
    }

    EXPECT_EQ(expectedSum, generalSum);
}

TEST(CMyArrayStringTest, AddingElements) {
    CMyArray<std::string> arr;
    arr.pushBack("Some");
    arr.pushBack("text");
    arr.pushBack("!!!!");

    EXPECT_EQ(arr[0], "Some");
    EXPECT_EQ(arr[1], "text");
    EXPECT_EQ(arr[2], "!!!!");
}

TEST(CMyArrayStringTest, CopyToVector) {
    CMyArray<std::string> arr;
    std::vector<std::string> vector;
    arr.pushBack("Some");
    arr.pushBack("text");
    arr.pushBack("!!!!");
    std::copy(arr.begin(), arr.end(), std::back_inserter(vector));

    EXPECT_EQ(vector[0], "Some");
    EXPECT_EQ(vector[1], "text");
    EXPECT_EQ(vector[2], "!!!!");
}

TEST(CMyArrayStringTest, ReverseCopyToVector) {
    CMyArray<std::string> arr;
    std::vector<std::string> vector;
    arr.pushBack("Some");
    arr.pushBack("text");
    arr.pushBack("!!!!");
    std::copy(arr.rbegin(), arr.rend(), std::back_inserter(vector));

    EXPECT_EQ(vector[0], "!!!!");
    EXPECT_EQ(vector[1], "text");
    EXPECT_EQ(vector[2], "Some");
}

TEST(CMyArrayCopyTest, CopyConstructor) {
    CMyArray<std::string> arr1;
    arr1.pushBack("Some");
    arr1.pushBack("text");
    CMyArray<std::string> arr2(arr1);
    arr2[0] = "New";
    arr2.pushBack("!!!");

    EXPECT_EQ(arr1[0], "Some");
    EXPECT_EQ(arr2[0], "New");
    EXPECT_EQ(arr2[1], "text");
    EXPECT_EQ(arr2[2], "!!!");
    EXPECT_EQ(arr2.Count() - arr1.Count(), 1);
}

TEST(CMyArrayCopyTest, CopyAssignmentOperator) {
    CMyArray<std::string> arr1;
    arr1.pushBack("Some");
    arr1.pushBack("text");
    CMyArray<std::string> arr2 = arr1;
    arr2[0] = "New";
    arr2.pushBack("!!!");

    EXPECT_EQ(arr1[0], "Some");
    EXPECT_EQ(arr2[0], "New");
    EXPECT_EQ(arr2[1], "text");
    EXPECT_EQ(arr2[2], "!!!");
    EXPECT_EQ(arr2.Count() - arr1.Count(), 1);
}

TEST(CMyArrayCopyTest, SelfAssignment) {
    CMyArray<double> arr1;
    arr1.pushBack(2.001);
    arr1.pushBack(10.012);
    arr1 = arr1;

    EXPECT_EQ(arr1.Count(), 2);
    EXPECT_EQ(arr1[0], 2.001);
    EXPECT_EQ(arr1[1], 10.012);
}

TEST(CMyArrayMoveTest, MoveConstructor) {
    CMyArray<double> arr1;
    arr1.pushBack(2.001);
    arr1.pushBack(10.012);
    CMyArray<double> arr2(std::move(arr1));

    EXPECT_EQ(arr1.Count(), 0);
    EXPECT_EQ(arr2[0], 2.001);
    EXPECT_EQ(arr2[1], 10.012);
}

TEST(CMyArrayMoveTest, MoveAssignmentOperator) {
    CMyArray<double> arr1;
    arr1.pushBack(2.001);
    arr1.pushBack(10.012);
    CMyArray<double> arr2 = std::move(arr1);

    EXPECT_EQ(arr1.Count(), 0);
    EXPECT_EQ(arr2[0], 2.001);
    EXPECT_EQ(arr2[1], 10.012);
}

TEST(CMyArrayMoveTest, SelfMoveAssignment) {
    CMyArray<double> arr1;
    arr1.pushBack(2.001);
    arr1.pushBack(10.012);
    arr1 = std::move(arr1);

    EXPECT_EQ(arr1.Count(), 2);
    EXPECT_EQ(arr1[0], 2.001);
    EXPECT_EQ(arr1[1], 10.012);
}

TEST(CMyArrayClearTest, ClearEmptyArray) {
    CMyArray<double> arr;
    EXPECT_EQ(arr.Count(), 0);
    arr.Clear();
    EXPECT_EQ(arr.Count(), 0);
}

TEST(CMyArrayClearTest, ClearNonEmptyArray) {
    CMyArray<double> arr;
    arr.pushBack(5.002);
    arr.pushBack(0);
    arr.pushBack(-19);
    EXPECT_EQ(arr.Count(), 3);
    arr.Clear();
    EXPECT_EQ(arr.Count(), 0);
}

TEST(CMyArrayResizeTest, ResizeSameCapacity) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(0);
    arr.pushBack(1);
    EXPECT_EQ(arr.Size(), 4);
    arr.Resize(4);
    EXPECT_EQ(arr.Size(), 4);
}

TEST(CMyArrayResizeTest, ResizeLargerCapacity) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(0);
    arr.pushBack(1);
    EXPECT_EQ(arr.Size(), 4);
    arr.Resize(10);
    EXPECT_EQ(arr.Size(), 10);
}

TEST(CMyArrayResizeTest, ResizeSmallerCapacityButGreaterThanCount) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(0);
    arr.pushBack(1);
    arr.pushBack(1);
    EXPECT_EQ(arr.Size(), 8);
    arr.Resize(6);
    EXPECT_EQ(arr.Size(), 6);
}

TEST(CMyArrayResizeTest, ResizeEqualToCount) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(0);
    arr.pushBack(1);
    arr.pushBack(1);
    EXPECT_EQ(arr.Size(), 8);
    arr.Resize(4);
    EXPECT_EQ(arr.Size(), 4);
    std::vector<double> vector;
    std::copy(arr.begin(), arr.end(), std::back_inserter(vector));
    EXPECT_EQ(vector[0], 5);
    EXPECT_EQ(vector[1], 0);
    EXPECT_EQ(vector[2], 1);
    EXPECT_EQ(vector[3], 1);
}

TEST(CMyArrayResizeTest, ResizeSmallerThanCount) {
    CMyArray<double> arr;
    arr.pushBack(5);
    arr.pushBack(0);
    arr.pushBack(1);
    arr.pushBack(1);
    EXPECT_THROW(arr.Resize(2), std::invalid_argument);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}