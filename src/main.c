#include <stdio.h>
#include <iniparser.h>
int main(){
    char* data = get_ini_data("/lib/systemd/system/test.service","Service","ExecStart");
    puts(data);
    return 0;
}
