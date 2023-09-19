#define FILE_OK 0
#define FILE_NOT_EXIST 1
#define FILE_TO_LARGE 2
#define FILE_READ_ERROR 3

char * get_value(char * ctx, char * name);
char * get_area(char * ctx, char * name);
char * readlines(const char * filename);
int iseq(char * str1, char * str2);