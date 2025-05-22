//
// Created by YoctoHan on 25-5-22.
//

#include "test_registry.h"
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <test_name>" << std::endl;
    std::cerr << "       " << argv[0] << " list    # to list all tests" << std::endl;
    return 1;
  }

  std::string arg = argv[1];

  if (arg == "list") {
    TestRegistry::getInstance().listTests();
    return 0;
  }

  return TestRegistry::getInstance().runTest(arg);
}