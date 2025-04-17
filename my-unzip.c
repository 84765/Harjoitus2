//Source
//https://www.demo2s.com/g/c/how-to-create-a-zip-file-in-c.html
//https://stackoverflow.com/questions/17598572/how-to-read-write-a-binary-file
//https://stackoverflow.com/questions/4358728/end-of-file-eof-in-c
//https://www.geeksforgeeks.org/fgetc-fputc-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *file;

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("my-unzip: cannot open file\n");
            exit(1);
        }

        int count = 0;

        while (fread(&count, sizeof(int), 1, file) == 1) {
            
            int charecter = fgetc(file);

            if (charecter == EOF) {
                fprintf(stderr, "my-unzip: unexpected end of file\n");
                exit(1);
            }

            for (int j = 0; j < count; j++) {
                putchar(charecter);
            }
        }

        fclose(file);
    }

    return(0);
}