#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {

  int pid = fork();

  if(pid == 0) {
    int fd = open("quotes.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dup2(fd, 1);
    close(fd);
    execl("boba", "boba", NULL);
    printf("this only happens on failure\n");
  } else {
    wait(NULL);
  }
  return 0;
}
