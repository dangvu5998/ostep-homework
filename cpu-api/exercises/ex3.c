/*
 * =====================================================================================
 *
 *       Filename:  fork_tutor_2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/23 17:02:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vudt, 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int rc = fork();
    if(rc == 0) {
        // children
        printf("Hello\n");
    } else {
        wait(NULL);
        printf("Goodbye\n");
    }
}
