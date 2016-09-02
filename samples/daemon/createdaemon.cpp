#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAXFILE 65535
using namespace std;

void sigterm_handler(int arg);
volatile sig_atomic_t _running = 1;
int main(){
    pid_t pc, pid;
    int i, fd, len, flag = 1;
    char* buf=(char*)("this is a Damen \n");
    len = strlen(buf);
    pc = fork();
    if(pc < 0){
        printf("error fork \n");
        exit(1);
    }
    else if(pc > 0){
        exit(0);
    }
    pid = setsid();
    if(pid < 0){
        perror("setsid error");
    }
    chdir("/");
    umask(0);
    for(i = 0; i < MAXFILE; ++i){
        close(i);
    }
    signal(SIGTERM, sigterm_handler);
    while(_running){
        if(flag == 1 && (fd=open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND,0600)) < 0){
            perror("open error");
            flag = 0;
            exit(1);
        }
        write(fd, buf, len);
        close(fd);
        usleep(10*1000);
    }
    return 0;
}
void sigterm_handler(int arg){
    _running = 0;
}
