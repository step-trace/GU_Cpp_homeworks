#include <iostream>

#define CHECK_RANGE(a, b) ((((a) >= 0) && ((a) < (b))) ? true : false)

int main(int argc, char* argv[]) {
	std::cout << CHECK_RANGE(5 , 10) << CHECK_RANGE(5 + 10 , 10 + 5);
	return 0;
}