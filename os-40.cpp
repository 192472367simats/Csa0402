#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char filename[30];
    int choice;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("\n1. Make File Read Only");
    printf("\n2. Make File Read and Write");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        if(_chmod(filename, _S_IREAD) == 0)
            printf("\nFile permission changed to READ ONLY.\n");
        else
            printf("\nError: Unable to change permission.\n");
    }
    else if(choice == 2) {
        if(_chmod(filename, _S_IREAD | _S_IWRITE) == 0)
            printf("\nFile permission changed to READ and WRITE.\n");
        else
            printf("\nError: Unable to change permission.\n");
    }
    else {
        printf("\nInvalid choice.\n");
    }

    return 0;
}

