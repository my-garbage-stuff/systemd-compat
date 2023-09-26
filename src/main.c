#include <iniparser.h>
#include <service.h>
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h>
#include <fcntl.h>

int main(int argc, char **argv){
    load_service(basename(argv[0]));
    if(0 == fork()){
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
    }
    return 0;
}
