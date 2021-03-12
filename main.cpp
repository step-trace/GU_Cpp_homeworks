#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {
    //Task 1. Написать программу, которая создаст два текстовых файла,
    // примерно по 50-100 символов в каждом (особого значения не имеет);
    std::string text_1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                         "Aenean tincidunt cursus dolor quis ultricies. Duis facilisis sapien "
                         "nec magna dignissim pretium. Nunc a nunc ipsum. Maecenas non orci "
                         "feugiat, porttitor magna id, interdum orci. Aliquam et cursus risus. "
                         "Fusce porttitor leo eget enim imperdiet vestibulum. Proin sodales tortor dui, at.";
    std::string text_2 = std::string(30, 'A');
    std::ofstream fos_1("lorem.txt");
    fos_1.write(text_1.data(), text_1.size());
    std::ofstream fos_2("AAA.txt");
    fos_2.write(text_2.data(), text_2.size());
	return 0;
}