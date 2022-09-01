#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void git_add() {
    char * command;

    printf("Adding all files...");
    strcpy(command, "git add *");
    system(command);
}

void git_commit() {
    time_t t;
    struct tm * ti;
    time(&t);
    ti = localtime(&t);

    char * initial;
    char * command;

    printf("Committing...");
    initial = strcat("git commit -m ", asctime(ti));
    strcpy(command, initial);
}

void git_push() {
    char * command;

    printf("Pushing to main...");
    strcpy(command, "git push origin main");
    system(command);
}

void auto_git() {
    git_add();
    git_commit();
    git_push();
}

int main(int argc, char *argv[]) {
    if(argc == 2) {
        if(strcmp(argv[1], "auto") == 0) {
            auto_git();
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