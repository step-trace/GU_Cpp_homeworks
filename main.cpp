#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(const char* fileName){
    FILE *file = fopen(fileName, "r");
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fclose(file);
    return fileSize;
}

int concat(const char* fileName1, const char* fileName2, const char* fileName3){
    int file_1_size = getFileSize(fileName1);
    int file_2_size = getFileSize(fileName2);
    if (!file_1_size || !file_2_size) {
        printf("Files doesn't exist or empty\n");
        return 1;
    }
    char* buffer = (char*)calloc(file_1_size + file_2_size, sizeof(char));
    FILE *file;
    file = fopen(fileName1, "r");
    int result = fread(buffer, 1, file_1_size, file);
    if (result != file_1_size) {
        printf("Read file error\n");
        free(buffer);
        fclose(file);
        return 1;
    }
    fclose(file);
    file = fopen(fileName2, "r");
    result = fread(buffer + file_1_size, 1, file_2_size, file);
    if (result != file_2_size) {
        printf("Read file error\n");
        free(buffer);
        fclose(file);
        return 1;
    }
    fclose(file);
    file = fopen(fileName3, "w");
    fwrite(buffer, 1, file_1_size + file_2_size, file);
    fclose(file);
    free(buffer);
    return 0;
}

int wordIndex (const char* fileName, const char* word){
    int fileSize = getFileSize(fileName);
    if (!fileSize) {
        printf("Files doesn't exist or empty\n");
        return -1;
    }
    char* buffer = (char*)calloc(fileSize, sizeof(char));
    FILE* file = fopen(fileName, "r");
    if (file == nullptr) {
        printf("Cannot open file\n");
        free(buffer);
        return -1;
    }
    int result = fread(buffer, 1, fileSize, file);
    if (result != fileSize) {
        printf("Read file error\n");
        free(buffer);
        fclose(file);
        return -1;
    }
    fclose(file);
    int i, j;
    int wordSize = strlen(word);
    //brute force search
    for (i = 0; i < fileSize - wordSize; ++i){
        for (j = 0; j < wordSize; ++j){
            if (buffer[i+j] != word[j]) break;
        }
        if (j == wordSize) {
            free(buffer);
            return i + 1;
        }
    }
    free(buffer);
    return -1;
}

int main() {
    //Task 1.
    const char text_1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                          "Aenean tincidunt cursus dolor quis ultricies. Duis facilisis "
                          "sapien nec magna dignissim pretium. Nunc a nunc ipsum. Maecenas "
                          "non orci feugiat, porttitor magna id, interdum orci. Aliquam et "
                          "cursus risus. Fusce porttitor leo eget enim imperdiet vestibulum. "
                          "Proin sodales tortor dui, at.";
    int count = sizeof text_1 / sizeof text_1[0];
    FILE *file = fopen("text.txt", "w");
    fwrite(text_1, sizeof text_1[0], count-1, file);
    fclose(file);
    const char text_2[] = "C (/siː/, as in the letter c) is a general-purpose, procedural "
                          "computer programming language supporting structured programming, "
                          "lexical variable scope, and recursion, with a static type system.";
    file = fopen("text2.txt", "w");
    count = sizeof text_2 / sizeof text_2[0];
    fwrite(text_2, sizeof text_1[0], count-1, file);
    fclose(file);
    //Task 2.
    concat("text.txt", "text2.txt", "output.txt");
    //Task 3.
    int result = wordIndex("output.txt", "at.");
    printf("Word \'at.\' was found at %d position\n", result);
    return 0;
}