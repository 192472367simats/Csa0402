#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *f1, *f2;
    char c, fname[100];

    printf("Enter source file name: ");
    scanf("%s", fname);
    f1 = fopen(fname, "r");

    if(f1 == NULL) {
        printf("File not found!");
        exit(0);
    }

    printf("Enter destination file name: ");
    scanf("%s", fname);
    f2 = fopen(fname, "w");

    while((c = fgetc(f1)) != EOF)
        fputc(c, f2);

    printf("File copied successfully.");
    fclose(f1);
    fclose(f2);
}

