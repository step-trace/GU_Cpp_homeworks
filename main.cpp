#include <iostream>

void fillArray(int size, int *arr){
    for (int i = 1; i <= size; ++i) {
        arr[i-1] = i*3 - 2;
    }
}


bool isItLucky(int size, int *arr){
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


void shiftArray(int size, int *arr, int shift){
    int pos = 0;
    int temp;
    shift %= size;
    if (shift < 0) shift = size + shift;
    temp = arr[0];
    for (int i = 0; i < size; ++i) {
        pos = (pos + shift) % size;
        //exchange values arr[pos] and temp
        arr[pos] ^= temp;
        temp ^= arr[pos];
        arr[pos] ^= temp;
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
    //Task 3. Написать функцию, в которую передается не пустой одномерный целочисленный массив,
    // функция должна вернуть истину если в массиве есть место,
    // в котором сумма левой и правой части массива равны.
    // Примеры: checkBalance([1, 1, 1, || 2, 1]) → true,
    // checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
    // Абстрактная граница показана символами ||, эти символы в массив не входят.
    int luckyArray[5] = {10, 1, 2, 3, 4};
    bool result = isItLucky(5, luckyArray);
    std::cout << result << "\n";
    //Task 4. Написать функцию, которой на вход подаётся одномерный массив и число n
    // (может быть положительным, или отрицательным), при этом
    // функция должна циклически сместить все элементы массива на n позиций.
    int arr[5] = {1,2,3,4,5};
    shiftArray(5,arr, -2);
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout <<"\n";
    return 0;
}
