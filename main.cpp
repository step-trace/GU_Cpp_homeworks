#include <iostream>

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
    std::cout << "\n";
    return 0;
}
