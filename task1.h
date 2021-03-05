#include <iostream>
#include <stdarg.h>
#ifndef TASK_1_H
#define TASK_1_H

namespace hw_5 {
    void invertArray(int count, ... ){
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            std::cout << !va_arg(args, int) << " ";
        }
        va_end(args);
    }
}
#endif
