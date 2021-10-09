#include "class_ThreadGuard.h"

// Пустой конструктор
ThreadGuard::ThreadGuard() {}

// Конструктор
ThreadGuard::ThreadGuard(std::thread t) : _t(move(t)) {}


// Деструктор
ThreadGuard::~ThreadGuard() {
    join();
}

// Соединяет поток с основным потоком
void ThreadGuard::join(void) {
    if (_t.joinable()) _t.join();
}

// Передаёт владение потоком данному thread guard-у
void ThreadGuard::operator () (std::thread t) {
    _t=move(t);
}
