#ifndef H_THREAD_GUARD
#define H_THREAD_GUARD

#include <thread>

class ThreadGuard{
public:
    // Пустой конструктор
    ThreadGuard();

    // Конструктор
    ThreadGuard(std::thread t);

    // Деструктор
    ~ThreadGuard();

    // Конструктор копирования
    ThreadGuard(ThreadGuard const&) = delete;

    // Оператор присваивания
    ThreadGuard& operator = (ThreadGuard const&) = delete;

    // Соединяет поток с основным потоком
    void join(void);

    // Передаёт владение потоком данному thread guard-у
    void operator () (std::thread t);

private:
    // Ссылка на поток
    std::thread _t;
};

#endif //H_THREAD_GUARD
