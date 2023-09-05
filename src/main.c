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
    if( iseq(argv[1],"start")){
        return run_action(TYPE_START);
    } else if( iseq(argv[1],"stop")){
        return run_action(TYPE_STOP);
    } else if( iseq(argv[1],"start_pre")){
        return run_action(TYPE_START_PRE);
    } else if( iseq(argv[1],"stop_pre")){
        return run_action(TYPE_STOP_PRE);
    } else if( iseq(argv[1],"reload")){
        return run_action(TYPE_RESTART);
    }
    puts("aaa");
    return 0;
}
