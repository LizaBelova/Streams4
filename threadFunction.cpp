#include "threadFunction.h"

void threadFunction(Database& db) {
    for(int i = 0; i < 10; i++)
        db.read();
}
