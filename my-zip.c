//Source
//https://www.demo2s.com/g/c/how-to-create-a-zip-file-in-c.html
//https://stackoverflow.com/questions/17598572/how-to-read-write-a-binary-file
//https://stackoverflow.com/questions/4358728/end-of-file-eof-in-c
//https://www.geeksforgeeks.org/fgetc-fputc-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// luo automaattisesti zip tiedoston6

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *file;

    int currentChar = EOF;
    int previousChar = EOF;
    int count = 0;

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("my-zip: cannot open file\n");
            exit(1);
        }

        while ((currentChar = fgetc(file)) != EOF) {
            if (currentChar == previousChar) {
                count++;
            } else {
                if (previousChar != EOF) {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fputc(previousChar, stdout);
                }
                count = 1;
                previousChar = currentChar;
            }
        }
        fclose(file);
    }

    if (previousChar != EOF) {
        fwrite(&count, sizeof(int), 1, stdout);
        fputc(previousChar, stdout);
    }

    return(0);
}