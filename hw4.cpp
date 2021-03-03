#include <iostream>

//не забыть спросить про области видимости switch/case

int main(int argc, char* argv[]) {
	//Task 1. Написать программу, проверяющую что сумма двух чисел 
	//лежит в пределах от 10 до 20 (включительно), 
	//если да – вывести true, в противном случае – false;
	int x, y, sum;
	x = 50, y = 10;
	sum = x + y;
	if (sum >= 10 && sum <= 20) std::cout << "True\n";
	else std::cout << "False\n";
	return 0;
}