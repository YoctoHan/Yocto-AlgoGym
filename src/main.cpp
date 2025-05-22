#include "test_registry.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // 如果指定了测试名称，只运行该测试
    if (argc > 1) {
        std::string testName = argv[1];
        if (TestRegistry::getInstance().hasTest(testName)) {
            // 传递剩余的命令行参数给测试函数
            return TestRegistry::getInstance().runTest(testName, argc - 1, argv + 1);
        } else {
            std::cout << "Test '" << testName << "' not found.\n";
            return -1;
        }
    }

    // 否则运行所有测试
    return TestRegistry::getInstance().runAllTests(argc, argv);
}