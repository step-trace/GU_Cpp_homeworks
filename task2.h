#ifndef TASK_2_H
#define TASK_2_H

namespace hw_5 {
    void fillArray(int size, int *arr){
        for (int i = 1; i <= size; ++i) {
            arr[i-1] = i*3 - 2;
        }
    }
}
#endif