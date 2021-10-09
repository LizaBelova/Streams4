#ifndef H_THREAD_SAFE_COUT
#define H_THREAD_SAFE_COUT

#include <mutex>
#include <iostream>

// Мьютекс для стандартного потока вывода
std::mutex mCout;

// Потокобезопасный cout
template<class T>
void threadSafeCout(T x) {
    std::lock_guard<std::mutex> guard(mCout);
    std::cout << x << std::endl;
}

#endif // H_THREAD_SAFE_COUT
