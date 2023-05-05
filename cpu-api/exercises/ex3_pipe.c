#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int pipef[2];
  pipe(pipef);
  int rc = fork();
  if(rc == 0) {
    close(pipef[0]);
    printf("Heeello!\n");
    write(pipef[1], "s", 1);
    close(pipef[1]);
  } else {
    close(pipef[1]);
    char c;
    read(pipef[0], &c, 1); // block
    close(pipef[0]);
    printf("Goodbye!\n");
  }
  return 0;
}
