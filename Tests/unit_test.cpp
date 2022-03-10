#include "gtest/gtest.h"

#include "../Tests/task_test.hpp"
#include "../Tests/select_test.hpp"
#include "../Tests/sub_test.hpp"
//#include "../Tests/tasktest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
