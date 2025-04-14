//Source
//https://www.demo2s.com/g/c/how-to-create-a-zip-file-in-c.html

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

// pakkaus työkalu
// yksinkertainen
// rle coding esim aaaab _> 4a1b
// n tyypistä merkkiä peräkkäin
// stduot, joka on kuten stdint kun ohjelma käynnissä
// kurssilla löytyy

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *file;

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("my-zip: cannot open file\n");
            exit(1);
        }

    return(0);
}