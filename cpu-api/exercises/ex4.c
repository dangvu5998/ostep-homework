#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int rc;
  printf("run exec ls -l -a\n");

  rc = fork();
  if(rc == 0) {
    printf("execl\n");
    execl("/bin/ls", "ls", "-l", "-a", (char *) NULL);
    printf("execl error");
    return 0;
  }
  wait(NULL);

  rc = fork();
  if(rc == 0) {
    printf("\n----------------------------------------\n");
    printf("execlp\n");
    execlp("ls", "ls", "-l", "-a", (char *) NULL);
    printf("execp error");
    return 0;
  }
  wait(NULL);

  rc = fork();
  if(rc == 0) {
    printf("\n----------------------------------------\n");
    printf("execv\n");
    char * argv[] = {"ls", "-l", "-a", (char *) NULL};
    execv("/bin/ls", argv);
    printf("execv error");
    return 0;
  }
  wait(NULL);
  return 0;
}