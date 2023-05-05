/*
 * =====================================================================================
 *
 *       Filename:  fork_tutor.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/23 16:48:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int x = 100;
    printf("Before change x = %d\n", x);
    int rc = fork();
    if(rc == 0) {
        x = 1;
        printf("Children after change x = %d\n", x);
    } else {
        x = 2;
        printf("Parent after change x = %d\n", x);
        printf("rc = %d\n", rc);
    }
}
