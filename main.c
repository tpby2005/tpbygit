#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void git_add() {
    char * command = "git add *";

    printf("Adding all files...\n");
    system(command);
}

void git_commit() {
    time_t t;
    struct tm * ti;
    time(&t);
    ti = localtime(&t);
    
    char * time = asctime(ti);
    char additional[2] = "\"";
    char dest[100];

    //remove dumbass \n from asctime
    strncpy(dest, time, strlen(time)-1);

    strcat(dest, additional);
    strcat(additional, dest);
    printf("%s", additional);
    char command[100] = "git commit -m ";

    printf("Committing...\n");
    strcat(command, additional);
    system(command);
}

void git_push() {
    char * command = "git push origin main";

    printf("Pushing to main...\n");
    system(command);
}

void git_auto() {
    git_add();
    git_commit();
    git_push();
}

void git_custom(int argc, char * argv[]){
    printf("%d", argc);
    for (int i = 1; i < argc, i++;) {
        printf("%s", argv[i]);
    }
}

int main(int argc, char *argv[]) {
    if(argc >= 2) {
        char * input;

        strcpy(input, argv[1]);

        if (strcmp(input, "auto") == 0) {
            git_auto();
        }

        else if (strcmp(input, "custom") == 0) {
            git_custom(argc, argv);
        }

        else {
            printf("%s is not a valid option.", argv[1]);
        }
    }

    else {
            printf("Usage: ./tpbygit <auto>");
    }

    return 0;
}