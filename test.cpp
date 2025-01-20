#include "pch.h"
#include "..//stack.h"

TEST(StackTests, DefaultConstructor) {
    Stack<int> myStack;
    EXPECT_EQ(0, myStack.getSize());
}
TEST(StackTests, CheckGetSize) {
    Stack<int> myStack;
    EXPECT_EQ(0, myStack.getSize());
    myStack.push(1);
    EXPECT_EQ(1, myStack.getSize());
    myStack.push(2);
    EXPECT_EQ(2, myStack.getSize());
}
TEST(StackTests, TestPushMethod) {
    Stack<int> myStack;
    myStack.push(1);
    EXPECT_EQ(1, myStack.getSize());
    myStack.push(2);
    EXPECT_EQ(2, myStack.getSize());
    
    for (int i = 0; i < 13; ++i) {
        myStack.push(i);
    }
    EXPECT_EQ(15, myStack.getSize());
    myStack.push(16);
    EXPECT_EQ(16, myStack.getSize());
}
TEST(StackTests, TestPopMethod) {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    
    EXPECT_EQ(2, myStack.pop());
    EXPECT_EQ(1, myStack.getSize());
    EXPECT_EQ(1, myStack.pop());
    EXPECT_EQ(0, myStack.getSize());
}
TEST(StackTests, CheckIsEmpty) {
    Stack<int> myStack;
    EXPECT_TRUE(myStack.isEmpty());
    myStack.push(1);
    EXPECT_FALSE(myStack.isEmpty());
}
TEST(StackTests, PushOperatorOverload) {
    Stack<int> myStack;
    myStack << 10;
    EXPECT_EQ(1, myStack.getSize());
    myStack << 2;
    EXPECT_EQ(2, myStack.getSize());

    for (int i = 0; i < 13; ++i) {
        myStack << i;
    }
    EXPECT_EQ(15, myStack.getSize());
    myStack << 16;
    EXPECT_EQ(16, myStack.getSize());
}
TEST(StackTests, PopOperatorOverload) {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    
    EXPECT_EQ(2, myStack.pop());
    EXPECT_EQ(1, myStack.getSize());
    EXPECT_EQ(1, myStack.pop());
    EXPECT_EQ(0, myStack.getSize());
}
TEST(StackTests, AssignmentOperator) {
    Stack<int> original;
    original.push(1);
    original.push(2);
    
    Stack<int> copy;
    copy = original;

    EXPECT_EQ(2, copy.getSize());
    EXPECT_EQ(2, copy.pop());
    EXPECT_EQ(1, copy.pop());
}
TEST(StackTests, ComparisonOperators) {
    Stack<int> stackA;
    stackA.push(1);
    stackA.push(2);

    Stack<int> stackB;
    stackB.push(1);

    EXPECT_TRUE(stackA > stackB);
    EXPECT_FALSE(stackA < stackB);

    stackB.push(2);
    
    EXPECT_TRUE(stackA == stackB);
    
    Stack<int> stackC;
    stackC.push(1);
    
    EXPECT_FALSE(stackA == stackC);
}
TEST(StackTests, SquareBracketAccess) {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    
    EXPECT_EQ(1, myStack[0]);
    EXPECT_EQ(2, myStack[1]);
}
TEST(StackTests, LastElementCheck) {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    
    EXPECT_EQ(2, myStack.lastElement());
}
