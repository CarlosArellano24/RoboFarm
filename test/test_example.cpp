#include <unity.h>
#include "example.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_example_function() {
  TEST_ASSERT_TRUE(example_function());
}

void test_example_value() {
  TEST_ASSERT_EQUAL(5, example_value());
}

int main(int argc, char** argv) {
  UNITY_BEGIN();
  RUN_TEST(test_example_function);
  RUN_TEST(test_example_value);
  UNITY_END();
}