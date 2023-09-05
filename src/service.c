#include <stdio.h>
#include <iniparser.h>

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
