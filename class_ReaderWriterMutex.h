#ifndef H_RWM
#define H_RWM

#include <queue>
#include <mutex>

// Мьютекс чтения-записи
class ReaderWriterMutex {
public:
    // Конструктор
    ReaderWriterMutex();

    // Деструктор
    ~ReaderWriterMutex();

    // Конструктор копирования
    ReaderWriterMutex(const ReaderWriterMutex& obj) = delete;

    // Оператор присваивания
    ReaderWriterMutex& operator = (const ReaderWriterMutex& obj) = delete;

    // Запрос на чтение
    void readRequest();

    // Запрос на запись
    void writeRequest();

    // Закончить чтение
    void readFinish();

    // Закончить запись
    void writeFinish();

private:
    // Кол-во чтецов
    int _nReaders;

    // Очередь писцов
    std::queue<int*> _qWriters;

    // Мьютекс на запросы
    std::mutex _mRequest;

    // Мьютекс на функцию readFinish()
    std::mutex _mReadFinish;

    // Мьютекс на функцию writeFinish()
    std::mutex _mWriteFinish;
};

#endif // H_RWM
