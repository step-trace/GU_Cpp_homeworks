#include <iostream>
#include <fstream>

int getFileSize(std::string fileName){
    std::ifstream file;
    file.open(fileName.data(), std::ios::in | std::ios::binary);
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        int file_size = file.tellg();
        file.close();
        return file_size;
    }
    return 0;
}

int concat(std::string fileName1, std::string fileName2){
    int file_1_size = getFileSize(fileName1.data());
    if (file_1_size == 0) return 1;
    int file_2_size = getFileSize(fileName2.data());
    if (file_2_size == 0) return 2;
    char* buffer = new char[file_1_size + file_2_size];
    std::ifstream file;
    file.open(fileName1.data(), std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        delete [] buffer;
        return 3;
    }
    file.read(buffer, file_1_size);
    file.close();
    file.open(fileName2.data(), std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        delete [] buffer;
        return 4;
    }
    file.read((buffer + file_1_size), file_2_size);
    file.close();
    std::ofstream outputFile(fileName1.data(), std::ios::out | std::ios::binary);
    if (!outputFile.is_open()) {
        delete [] buffer;
        return 5;
    }
    outputFile.write(buffer, file_2_size + file_1_size);
    outputFile.close();
    delete [] buffer;
    return 0;
}

int wordIndex(std::string word, std::string fileName){
    int fileSize = getFileSize(fileName);
    if (fileSize == 0) {
        std::cout << "File doesn't exist or empty\n";
        return -1;
    }
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open()) {
        std::cout << "Couldn't open file: " << fileName << "\n";
        return -1;
    }
    //с буферизацией должно быть быстрее...
    char *buffer = new char[fileSize];
    file.read(buffer, fileSize);
    file.close();
    int i, j;
    int wordSize = word.size();
    for (i = 0; i < fileSize - wordSize; i++){
        for (j = 0; j < wordSize; j++){
            if (buffer[i+j] != word[j]) break;
        }
        if (j == wordSize) {
            delete [] buffer;
            return i+1;
        }
    }
    delete [] buffer;
    return -1;
}

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
    fos_1.close();
    fos_2.close();
    //Task 2. Написать функцию, «склеивающую» эти файлы,
    // предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера
    int result = concat("lorem.txt", "AAA.txt");
    if (result == 0) std::cout << "Concatenation has done successfully!\n";
    else std::cout << "Concatenation has failed! ErrorCode: " << result << "\n";
    //Task 3. * Написать программу, которая проверяет присутствует ли указанное пользователем
    // при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
    if (argc < 2) {
        std::cout << "Usage: hw6 word [fileName]\n";
        return 1;
    }
    std::string defaultFileName("lorem.txt");
    std::string word(argv[1]);
    std::string fileName = (argc > 2) ? argv[2] : defaultFileName;
    result = wordIndex(word, fileName);
    if (result < 0) std::cout << "Word: \'" << word << "\' was not found\n";
    else std::cout << "Word: \'" << word << "\' was found at " << result << " position\n";
	return 0;
}