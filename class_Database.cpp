#include "class_Database.h"
#include <cstdlib>
#include <thread>
#include <iostream>

// Конструктор
Database::Database() {}

// Деструктор
Database::~Database() {}

// Чтение
void Database::read() {
    #ifdef H_RWM
        _rwm.readRequest();
        report("reads");
        int t = rand() % 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(t));
        _rwm.readFinish();
    #else
        std::lock_guard<std::mutex> guard(_m);
        report("reads");
        int t = rand() % 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(t));
    #endif //H_RWM
}

// Запись
void Database::write() {
    #ifdef H_RWM
        _rwm.writeRequest();
        report("writes");
        int t = rand() % 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(t));
        _rwm.writeFinish();
    #else
        std::lock_guard<std::mutex> guard(_m);
        report("writes");
        int t = rand() % 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(t));
    #endif //H_RWM
}

// Отчёт о действиях потока
void Database::report(const char* str) {
    std::lock_guard<std::mutex> guard(_mReport);
    std::cout << "thread #";
    std::cout << std::this_thread::get_id() << " ";
    std::cout << str << std::endl;
}
