//
// Created by ilyalezhnin on 31.05.24.
//

#include <gtest/gtest.h>
#include <sstream>
#include "../Classes/CMyArray.h"
#include "../Classes/CMyArrayIterator.h"

TEST(CMyArrayTest, DefaultConstructor) {
    CMyArray<int> myArray;
    EXPECT_EQ(myArray.Size(), 1);
    EXPECT_EQ(myArray.Count(), 0);
}

// Test size and count after resizing
TEST(CMyArrayTest, Resize) {
    CMyArray<int> myArray;
    myArray.Resize(10);
    EXPECT_EQ(myArray.Size(), 10);
    EXPECT_EQ(myArray.Count(), 5); // Resizing doesn't change count

    myArray.Resize(3);
    EXPECT_EQ(myArray.Size(), 3);
    EXPECT_EQ(myArray.Count(), 3); // Count should be reduced after resizing
}

// Test clearing the array
TEST(CMyArrayTest, Clear) {
    CMyArray<int> myArray;
    myArray.Clear();
    EXPECT_EQ(myArray.Size(), 1);
    EXPECT_EQ(myArray.Count(), 0);
}

// Test iterator functionality
TEST(CMyArrayTest, Iterator) {
    // Test forward iteration
    CMyArray<int> myArray;
    int expectedValue = 0;
    for (auto it = myArray.begin(); it != myArray.end(); ++it) {
        EXPECT_EQ(*it, expectedValue++);
    }

    // Test reverse iteration
    expectedValue = 4;
    for (auto it = myArray.rbegin(); it != myArray.rend(); ++it) {
        EXPECT_EQ(*it, expectedValue--);
    }

    // Test dereferencing and indexing
    auto it = myArray.begin();
    EXPECT_EQ(*it, 0);
    EXPECT_EQ(it[2], 2);

    // Test arithmetic operations
    it += 2;
    EXPECT_EQ(*it, 2);
    it -= 1;
    EXPECT_EQ(*it, 1);
    auto it2 = it + 2;
    EXPECT_EQ(*it2, 3);
    auto it3 = it2 - 2;
    EXPECT_EQ(*it3, 1);
    EXPECT_EQ(*it2 - *it, 2);
    EXPECT_EQ(it2 - 2, it);
    EXPECT_EQ(2 + it, it2);
    EXPECT_EQ(it - 2, it3);

    // Test comparison operators
    EXPECT_TRUE(it == it3 + 1);
    EXPECT_TRUE(it != it2);
    EXPECT_TRUE(it < it2);
    EXPECT_TRUE(it <= it2);
    EXPECT_TRUE(it2 > it);
    EXPECT_TRUE(it2 >= it);
}

// Test copy constructor
TEST(CMyArrayTest, CopyConstructor) {
    CMyArray<int> myArray1;
    myArray1.Resize(3);
    myArray1[0] = 1;
    myArray1[1] = 2;
    myArray1[2] = 3;

    CMyArray<int> myArray2(myArray1);
    EXPECT_EQ(myArray2.Size(), 3);
    EXPECT_EQ(myArray2.Count(), 3);
    EXPECT_EQ(myArray2[0], 1);
    EXPECT_EQ(myArray2[1], 2);
    EXPECT_EQ(myArray2[2], 3);
}

// Test move constructor
TEST(CMyArrayTest, MoveConstructor) {
    CMyArray<int> myArray1;
    myArray1.Resize(3);
    myArray1[0] = 1;
    myArray1[1] = 2;
    myArray1[2] = 3;

    CMyArray<int> myArray2(std::move(myArray1));
    EXPECT_EQ(myArray2.Size(), 3);
    EXPECT_EQ(myArray2.Count(), 3);
    EXPECT_EQ(myArray2[0], 1);
    EXPECT_EQ(myArray2[1], 2);
    EXPECT_EQ(myArray2[2], 3);

    // After move, original array should be in valid but unspecified state
    EXPECT_EQ(myArray1.Size(), 1);
    EXPECT_EQ(myArray1.Count(), 0);
}

// Test assignment operator
TEST(CMyArrayTest, AssignmentOperator) {
    CMyArray<int> myArray1;
    myArray1.Resize(3);
    myArray1[0] = 1;
    myArray1[1] = 2;
    myArray1[2] = 3;

    CMyArray<int> myArray2;
    myArray2 = myArray1;
    EXPECT_EQ(myArray2.Size(), 3);
    EXPECT_EQ(myArray2.Count(), 3);
    EXPECT_EQ(myArray2[0], 1);
    EXPECT_EQ(myArray2[1], 2);
    EXPECT_EQ(myArray2[2], 3);
}

// Test move assignment operator
TEST(CMyArrayTest, MoveAssignmentOperator) {
    CMyArray<int> myArray1;
    myArray1.Resize(3);
    myArray1[0] = 1;
    myArray1[1] = 2;
    myArray1[2] = 3;

    CMyArray<int> myArray2;
    myArray2 = std::move(myArray1);
    EXPECT_EQ(myArray2.Size(), 3);
    EXPECT_EQ(myArray2.Count(), 3);
    EXPECT_EQ(myArray2[0], 1);
    EXPECT_EQ(myArray2[1], 2);
    EXPECT_EQ(myArray2[2], 3);

    // After move assignment, original array should be in valid but unspecified state
    EXPECT_EQ(myArray1.Size(), 1);
    EXPECT_EQ(myArray1.Count(), 0);
}

// Test out of bounds exception in iterator indexing
TEST(CMyArrayTest, IteratorOutOfBoundsException) {
    CMyArray<int> myArray;
    auto it = myArray.begin();
    ASSERT_NO_THROW(it[0]);
    ASSERT_NO_THROW(it[4]);

    ASSERT_ANY_THROW(it[-1]);
    ASSERT_ANY_THROW(it[5]);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}