#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        return(0);
    }
    
    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");

        if (file == NULL) {
            perror("my-cat: cannot open file\n");
            exit(1);
        }

        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, file)) != -1) {
            printf("%s", line);
        }

        free(line);
        fclose(file);
    }

    return(0);
}