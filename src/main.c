#include <stdio.h>
#include <iniparser.h>
#include <service.h>
int main(int argc, char **argv){
    if(argv[0] == "systemd"){
        puts("You cannot run service directly!");
        return 1;
    }
    load_service("test");
    //load_service(argv[0]);
    char* data = get_service_value("Service","ExecStart");
    puts(data);
    return 0;
}
