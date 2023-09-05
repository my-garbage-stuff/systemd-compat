#define TYPE_START      1
#define TYPE_STOP       0
#define TYPE_START_PRE  2
#define TYPE_STOP_PRE   3
#define TYPE_RESTART    4

void load_service(char* name);
char* get_service_value(char* section, char* element);
int run_action(int type);