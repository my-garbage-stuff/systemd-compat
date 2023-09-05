#define FILE_OK 0
#define FILE_NOT_EXIST 1
#define FILE_TO_LARGE 2
#define FILE_READ_ERROR 3

char ** strsplit(const char * s,
    const char * delim);
int strcount(char * buf, char * c);
char * readlines(const char * filename);
int iseq(char * str1, char * str2);
char* get_ini_data(char* file, char* section, char* variable);
