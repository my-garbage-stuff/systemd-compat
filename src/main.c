#include <stdio.h>
#include <iniparser.h>
#include <service.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
    if(argv[0] == "systemd"){
        puts("You cannot run service directly!");
        return 1;
    }
    struct stat st = {0};
    if (stat("/some/directory", &st) == -1) {
        mkdir("/run/systemd/system/", 0700);
    }
    load_service("test");
    //load_service(argv[0]);
    char* data = get_service_value("Service","ExecStart");
    puts(data);
    return 0;
}
