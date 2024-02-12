#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define byte unsigned char
#define u64 unsigned long long
#define i64 long long
#define f64 double

void file_not_found(int argc, char* argv[])
{
    printf("%s", argv[0]);
    if (argv[0] == "./main") {
        printf("Impeccable!");
    }
    else {
        printf("Le fichier n'existe pas cogno!");
    }
}