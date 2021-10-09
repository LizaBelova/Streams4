#include <iostream>
#include <thread>
#include <chrono>
#include "class_Database.h"
#include "class_ThreadGuard.h"
#include "threadFunction.h"

int main(void) {

    Database db;

    int nThreads = std::thread::hardware_concurrency();
    if (nThreads < 2)
        nThreads = 2;

    ThreadGuard t_guard[nThreads];

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < nThreads; i++)
        t_guard[i](std::thread(threadFunction, std::ref(db)));

    for(int i = 0; i < nThreads; i++)
        db.write();

    for(int i = 0; i < nThreads; i++)
        t_guard[i].join();

    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "time == ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
    std::cout << " milliseconds";

    return 0;
}
