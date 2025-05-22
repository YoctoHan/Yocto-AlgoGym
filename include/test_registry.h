//
// Created by YoctoHan on 25-5-22.
//

#ifndef TEST_REGISTRY_H
#define TEST_REGISTRY_H

#pragma once
#include <functional>
#include <map>
#include <string>
#include <iostream>

// 测试函数类型
using TestFunction = std::function<int()>;

// 测试注册表单例
class TestRegistry {
public:
  static TestRegistry& getInstance() {
    static TestRegistry instance;
    return instance;
  }

  // 注册测试
  void registerTest(const std::string& name, TestFunction func) {
    tests_[name] = func;
  }

  // 运行测试
  int runTest(const std::string& name) {
    auto it = tests_.find(name);
    if (it == tests_.end()) {
      std::cerr << "Test '" << name << "' not found!" << std::endl;
      return 1;
    }

    std::cout << "Running test: " << name << std::endl;
    return it->second();
  }

  // 列出所有可用测试
  void listTests() {
    std::cout << "Available tests:" << std::endl;
    for (const auto& test : tests_) {
      std::cout << "  " << test.first << std::endl;
    }
  }

private:
  TestRegistry() = default;
  std::map<std::string, TestFunction> tests_;
};

// 测试注册辅助宏
#define REGISTER_TEST(name, func) \
static bool registered_##name = []() { \
TestRegistry::getInstance().registerTest(#name, func); \
return true; \
}();

#endif //TEST_REGISTRY_H
