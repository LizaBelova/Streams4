#include "class_ReaderWriterMutex.h"

// Конструктор
ReaderWriterMutex::ReaderWriterMutex() {
    _nReaders = 0;
}

// Деструктор
ReaderWriterMutex::~ReaderWriterMutex() {}

// Запрос на чтение
void ReaderWriterMutex::readRequest() {
    std::lock_guard<std::mutex> guard(_mRequest);

    while (!_qWriters.empty());

    ++_nReaders;
}

// Запрос на запись
void ReaderWriterMutex::writeRequest() {
    std::lock_guard<std::mutex> guard(_mRequest);

    int id;
    _qWriters.push(&id);

    while (_qWriters.front() != &id || _nReaders > 0);
}

// Закончить чтение
void ReaderWriterMutex::readFinish() {
    std::lock_guard<std::mutex> guard(_mReadFinish);

    --_nReaders;
}

// Закончить запись
void ReaderWriterMutex::writeFinish() {
    std::lock_guard<std::mutex> guard(_mWriteFinish);

    _qWriters.pop();
}
