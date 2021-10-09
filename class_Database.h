#ifndef H_DATABASE
#define H_DATABASE

//#include "class_ReaderWriterMutex.h"
#include <map>
#include <string>
#include <mutex>

// База данных
class Database {
public:
    // Конструктор
    Database();

    // Деструктор
    ~Database();

    // Конструктор копирования
    Database(const Database& obj) = delete;

    // Оператор присваивания
    Database& operator = (const Database& obj) = delete;

    // Функция чтения
    void read();

    // Функция записи
    void write();

private:
    // База данных
    std::map<std::string, int> _data;

    #ifdef H_RWM
        ReaderWriterMutex _rwm;
    #else
        std::mutex _m;
    #endif //H_RWM

    // Отчёт о действиях потока
    void report(const char* str);
    std::mutex _mReport;
};

#endif // H_DATABASE
