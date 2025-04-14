//Source
//https://www.w3schools.com/c/ref_string_strstr.php

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

int searchFile(const char *term, FILE *file);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }

    char *term = argv[1];

    if (argc == 2) {
        searchFile(argv[1], stdin);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
    
            if (file == NULL) { // pitääkö feilata jos ei voi avaa toista tiedostoa
                perror("my-grep: cannot open file\n");
                exit(1);
            }

            if (searchFile(term, file) == 0) {
                printf("No matches found in file %s\n", argv[i]);
            }
            
            fclose(file);
        }
    }

    return 0;
}

int searchFile(const char *term, FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int found = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        if(strcasestr(line, term) != NULL) {
            printf("%s", line);
            found = 1;
        } 
    } 

    free(line);
    return(found);
}

// mitä jos hakutermiä ei löydy