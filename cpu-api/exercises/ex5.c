#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  pid_t rc = fork();
  if(rc == 0) {
    pid_t pid = wait(NULL);
    printf("Children wait result: %d\n", pid);
  } else {
    pid_t pid = wait(NULL);
    printf("Child process id: %d\n", rc);
    printf("Children wait result: %d\n", pid);
  }
  return 0;
}