#pragma once
#define BOOST_STACKTRACE_USE_BACKTRACE

#include <cstdlib>
#include <exception>
#include <iostream>
#include <boost/stacktrace.hpp>

// 自定义终止处理程序
void my_terminate_handler() {
    try {
        // 输出堆栈跟踪到标准错误流
        std::cout << "Termination triggered. Stack trace:\n" << boost::stacktrace::stacktrace();
    } catch (...) {
        // 如果在尝试输出堆栈跟踪时发生任何异常，我们选择忽略它
        // 因为程序即将终止，我们不希望因为异常处理而进一步复杂化问题
        // 这里什么也不做，或者可以选择输出一些默认的错误信息
    }
    // 终止程序
    std::abort();
}
