#include <stdio.h>
#include <stdlib.h>
#include <iniparser.h>

#define TYPE_START      1
#define TYPE_STOP       0
#define TYPE_START_PRE  2
#define TYPE_STOP_PRE   3
#define TYPE_RESTART    4


char* service_data;

void load_service(char* name){
    char service_file[1024];
    sprintf(service_file, "/lib/systemd/system/%s.service", name);
    service_data = readlines(service_file);
}

char* get_service_value(char* section, char* element){
    if(!service_data){
        return "";
    }
    char * area = get_area(service_data, section);
    return get_value(area, element);
}
int run_action(int type){
    char* command;
    switch (type){
        case TYPE_START:
            command = get_service_value("Service","ExecStart");
            break;
        case TYPE_STOP:
            command = get_service_value("Service","ExecStop");
            break;
        case TYPE_START_PRE:
            command = get_service_value("Service","ExecStartPre");
            break;
        case TYPE_STOP_PRE:
            command = get_service_value("Service","ExecStopPre");
            break;
        case TYPE_RESTART:
            command = get_service_value("Service","ExecReload");
            break;
    }
    if(command){
        if(iseq(get_service_value("Service","Restart"),"always")){
            while(system(command) != -1);
        }else if(iseq(get_service_value("Service","Restart"),"on-failture")){
            while(system(command));
        }else {
            return system(command);
        }
    }
    return 0;
}
