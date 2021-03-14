#include <stdio.h>

int getFileSize(const char* fileName){
    FILE *file = fopen(fileName, "r");
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fclose(file);
    return fileSize;
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
    return 0;
}