#include "test_registry.h"
#include <iostream>
#include <string>
#include <algorithm> // 用于排序

int main(int argc, char* argv[]) {
    // 如果指定了测试名称或命令
    if (argc > 1) {
        std::string arg = argv[1];

        // 检查是否是list命令
        if (arg == "list") {
            std::cout << "可用的测试列表：\n";
            auto testNames = TestRegistry::getInstance().getTestNames();

            // 按字母顺序排序测试名称
            std::sort(testNames.begin(), testNames.end());

            for (const auto& name : testNames) {
                std::cout << "  " << name << "\n";
            }
            return 0;
        }

        // 运行特定测试
        if (TestRegistry::getInstance().hasTest(arg)) {
            return TestRegistry::getInstance().runTest(arg, argc - 1, argv + 1);
        } else {
            std::cout << "测试 '" << arg << "' 未找到。\n";
            std::cout << "使用 'list' 命令查看可用的测试。\n";
            return -1;
        }
    }

    // 否则运行所有测试
    return TestRegistry::getInstance().runAllTests(argc, argv);
}