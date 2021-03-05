#include <iostream>

void fillArray(int size, int *arr){
    for (int i = 1; i <= size; ++i) {
        arr[i-1] = i*3 - 2;
    }
}

int main() {
    //Task 1. Задать целочисленный массив, состоящий из элементов 0 и 1.
    // Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].
    // Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0
    // (** без применения if-else, switch, () ? :);
    int testArray[10] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    for (int i = 0; i < 10; i++){
        testArray[i] = !testArray[i];       //or boolArray[i] ^ 1;
        std::cout << testArray[i] << " ";
    }
    std::cout <<"\n";
    //Task 2. Задать пустой целочисленный массив размером 8.
    // Написать функцию, которая с помощью цикла
    // заполнит его значениями 1 4 7 10 13 16 19 22;
    int toFillArray[8];
    fillArray(8, toFillArray);
    for (int i = 0; i < 8; ++i) {
        std::cout << toFillArray[i] << "  ";
    }
    std::cout <<"\n";
    return 0;
}
