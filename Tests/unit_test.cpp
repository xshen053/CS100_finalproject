#include "gtest/gtest.h"

#include "../Tests/task_test.hpp"
#include "../Tests/select_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
