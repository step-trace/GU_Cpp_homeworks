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
	//Task 2. Написать программу, проверяющую, 
	//является ли некоторое число - натуральным простым.
	int n = 757;
	bool is_prime = 1;
	if (n % 2 == 0) is_prime = 0;	//отбрасываем четные
	for (int i = 3; i < n; i += 2){
		if (n % i == 0){
			is_prime = 0;			//есть делитель
			break;					//нет смысла дальше проверять
		}
	}
	std::cout << is_prime << "\n";
	return 0;
}