
// #define BOOST_STACKTRACE_USE_BACKTRACE

#include <cstdlib>
#include <exception>
#include <iostream>
#include "custom_stacktrace.hpp"

void func_c() {
    throw std::runtime_error("Simulated exception to trigger std::terminate");
}

void func_b() {
    func_c();
}

void func_a() {
    func_b();
}

// main 函数
int main() {
    // 注册自定义的终止处理程序
    std::set_terminate(&my_terminate_handler);
    func_a();
    // 模拟一些可能导致 std::terminate 被调用的情况
    // 例如，抛出一个未捕获的异常
    

    // 主函数中的其他代码...
    return 0;
}