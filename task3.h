#ifndef TASK_3_H
#define TASK_3_H

namespace hw_5 {
    bool isItLucky(int size, int *arr) {
        for (int i = 0; i < size - 1; ++i) {
            int lsum = 0;
            int rsum = 0;
            for (int j = 0; j <= i; ++j) {
                lsum += arr[j];
            }
            for (int j = i + 1; j < size; ++j) {
                rsum += arr[j];
            }
            if (lsum == rsum) return 1;
        }
        return 0;
    }
}
#endif
