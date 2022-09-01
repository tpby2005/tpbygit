#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void git_add() {
    char * command = "git add *";

    //strcpy(command, "git add *");
    system(command);
}

int main(void) {
    git_add();
    return 0;
}