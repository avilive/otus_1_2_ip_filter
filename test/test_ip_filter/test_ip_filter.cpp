/*#include "ip_filter.h"
#include "test_ip_filter.h"

using ::testing::Return;

FooTest::FooTest() {
    // Have qux return true by default
    ON_CALL(m_bar, qux()).WillByDefault(Return(true));
    // Have norf return false by default
    ON_CALL(m_bar, norf()).WillByDefault(Return(false));
}

FooTest::~FooTest() {};

void FooTest::SetUp() {};

void FooTest::TearDown() {};

TEST_F(FooTest, ByDefaultBazTrueIsTrue) {
    Foo foo(m_bar);
    EXPECT_EQ(foo.baz(true), true);
}

TEST_F(FooTest, ByDefaultBazFalseIsFalse) {
    Foo foo(m_bar);
    EXPECT_EQ(foo.baz(false), false);
}

TEST_F(FooTest, SometimesBazFalseIsTrue) {
    Foo foo(m_bar);
    // Have norf return true for once
    EXPECT_CALL(m_bar, norf()).WillOnce(Return(true));
    EXPECT_EQ(foo.baz(false), true);
}

*/
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(IP_SPLIT, BasicSplit) {
  //arrange
  
  //act
  //assert

  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
