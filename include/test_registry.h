#ifndef TEST_REGISTRY_H
#define TEST_REGISTRY_H

#pragma once
#include <functional>
#include <map>
#include <string>

class TestRegistry {
public:
    static TestRegistry& getInstance() {
        static TestRegistry instance;
        return instance;
    }

    void registerTest(const std::string& name, std::function<int(int, char**)> testFunc) {
        tests[name] = testFunc;
    }

    int runTest(const std::string& name, int argc, char* argv[]) {
        if (tests.find(name) != tests.end()) {
            return tests[name](argc, argv);
        }
        return -1; // 测试不存在
    }

    int runAllTests(int argc, char* argv[]) {
        int result = 0;
        for (const auto& test : tests) {
            result |= test.second(argc, argv);
        }
        return result;
    }

    bool hasTest(const std::string& name) {
        return tests.find(name) != tests.end();
    }

private:
    std::map<std::string, std::function<int(int, char**)>> tests;
};

#define REGISTER_TEST(name, func) \
static bool registered_##name = [] { \
TestRegistry::getInstance().registerTest(#name, func); \
return true; \
}();

#endif // TEST_REGISTRY_H