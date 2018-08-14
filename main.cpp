#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/*
 * Commander: a simple command to send to several processes the same commands
 *  Usefull to control several remote gdb in case of multiple MPI debugging 
 *
 */

/* 
 * TODO interupt handler to exit properly
 */

int main (int argc, char** argv) {
    char* input;
    char prompt [256];
    int  pids   [256];
    for (int i = 1 ; i < argc; i++) {
        strcat (prompt, argv[i]);
        pids[i-1]  = atoi(argv[i]);
        if (i < (argc -1))
            strcat (prompt, ",");
    }
    strcat (prompt, ">");
    while (1) {
        input = readline (prompt);
        add_history(input);
        printf("\n");
    }
    return 0;
}
