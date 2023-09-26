#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
int main(){
    struct stat st = {0};
    if (stat("/run/systemd/system/", &st) == -1) {
        mkdir("/run/systemd/system/", 0700);
    }
    if (stat("/sys/fs/cgroup/systemd/", &st) == -1) {
        symlink("elogind", "/sys/fs/cgroup/systemd");
    }
    if(getpid()==1){
        char *a[] = {"/sbin/compat-init" , NULL};
        execvp("/sbin/compat-init",a);
    }else {
        return 0;
    }
    printf("%s\n", "Error: Compat init not found!");
    while(1);
}
