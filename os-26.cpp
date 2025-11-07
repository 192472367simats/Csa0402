#include <stdio.h>

int main(){
    FILE *f;
    char text[50];

    f = fopen("data.txt","w");
    printf("Enter text to store in file: ");
    scanf("%s", text);
    fprintf(f,"%s", text);
    fclose(f);

    f = fopen("data.txt","r");
    printf("\nFile Content: ");
    fscanf(f,"%s", text);
    printf("%s\n", text);
    fclose(f);

    return 0;
}

