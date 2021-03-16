#include <iostream>

#define ARRAY_SIZE 5
#define CHECK_RANGE(a, b) ((((a) >= 0) && ((a) < (b))) ? true : false)
#define GET_ELEMENT(arr_name, i, j) (*(*((arr_name) + (i)) + (j)))

int main(int argc, char* argv[]) {
	std::cout << CHECK_RANGE(5 , 10) << CHECK_RANGE(5 + 10 , 10 + 5) << std::endl;
	//create array
	int** arr = new int*[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i){
		arr[i] = new int[ARRAY_SIZE];
	}
	//fill array
	for (int i = 0; i < ARRAY_SIZE; ++i)
		for (int j = 0; j < ARRAY_SIZE; ++j)
			arr[i][j] = j;
	//get elements of array
	for (int i = 0; i < ARRAY_SIZE; ++i)
		for (int j = 0; j < ARRAY_SIZE; ++j)
			std::cout << GET_ELEMENT(arr, i, j);
	return 0;
}