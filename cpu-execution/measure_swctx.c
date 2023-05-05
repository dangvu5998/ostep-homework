#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>

int main() {
  // use 2 pipes and read write back-and-forth between parent and child process
  int pipefd1[2];
  int pipefd2[2];
  pipe(pipefd1);
  pipe(pipefd2);
  
  // config use the same cpu with both parent and child
  cpu_set_t cpuSet;
  CPU_ZERO(&cpuSet);
  CPU_SET(0, &cpuSet);
  size_t nloops = 1000000;
  int pid = fork();
  if(pid == 0) {
    sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuSet);
    for(size_t i = 0; i < nloops; i++) {
      write(pipefd1[1], NULL, 0);
      read(pipefd2[0], NULL, 0);
    }
  } else {
    sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuSet);
    struct timeval startTime;
    struct timeval endTime;
    gettimeofday(&startTime, NULL);
    for(size_t i = 0; i < nloops; i++) {
      read(pipefd1[0], NULL, 0);
      write(pipefd2[1], NULL, 0);
    }
    gettimeofday(&endTime, NULL);
    const int MICRO_MULT = 1000000;
    printf("switch ctx: %f microseconds\n", (float) (endTime.tv_sec * MICRO_MULT + endTime.tv_usec - startTime.tv_sec * MICRO_MULT - startTime.tv_usec) / nloops);
  }

}