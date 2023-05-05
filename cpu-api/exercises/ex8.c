#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int pipef[2];
  pipe(pipef);
  int rc = fork();
  if(rc == 0) {
    // child 1
    close(pipef[0]);
    write(pipef[1], "hello", 5);
    write(pipef[1], " world!", 7);
    printf("Done writing\n");
    close(pipef[1]);
    return 0;
  }
  rc = fork();
  if(rc == 0) {
    // child 2
    close(pipef[1]);
    char buf[BUFSIZ];
    read(pipef[0], buf, BUFSIZ);
    printf("Result child 2: %s\n", buf);
    close(pipef[0]);
  }

}