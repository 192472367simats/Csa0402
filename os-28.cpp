#include <stdio.h>
#include <string.h>

int main(){
    FILE *f;
    char word[20], line[200];

    f = fopen("data.txt", "r");
    if(f == NULL){
        printf("Cannot open data.txt\n");
        return 0;
    }

    printf("Enter word to search: ");
    scanf("%s", word);

    while(fgets(line, sizeof(line), f) != NULL){
        if(strstr(line, word) != NULL){
            printf("%s", line);
        }
    }

    fclose(f);
    return 0;
}

