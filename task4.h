#ifndef TASK_4_H
#define TASK_4_H

namespace hw_5 {
    void shiftArray(int size, int *arr, int shift) {
        int pos = 0;
        int temp;
        shift %= size;
        if (shift < 0) shift += size;
        temp = arr[0];
        for (int i = 0; i < size; ++i) {
            pos = (pos + shift) % size;
            //exchange values arr[pos] and temp
            arr[pos] ^= temp;
            temp ^= arr[pos];
            arr[pos] ^= temp;
        }
    }
}
#endif
