#define _GNU_SOURCE
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("./measure.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  int nloops = 10000000;
  struct timeval startTime;
  gettimeofday(&startTime, NULL);
  for(size_t i = 0; i < nloops; i++) {
    write(fd, NULL, 0);
  }
  struct timeval endTime;
  gettimeofday(&endTime, NULL);
  const int MICRO_MULT = 1000000;
  printf("system call: %f microseconds\n\n", (float) (endTime.tv_sec * MICRO_MULT + endTime.tv_usec - startTime.tv_sec * MICRO_MULT - startTime.tv_usec) / nloops);
  close(fd);
}