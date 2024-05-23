#include <util.h>

static int atoi(char* str){
    int res = 0;
    while(*str){
        res = res * 10 + *str -'0';
        str++;
    }
    return res;
}

int parse_args(int argc, char** argv, SCOPE_t* state){
    if( argc < 3 ){
        return 0;
    }
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], FILE_PATH) == 0 && i + 1 < argc){
            state->csv_path = argv[i + 1];
        } else if(strcmp(argv[i], MOUNTH) == 0 && i + 1 < argc){
            state->need_mouth = atoi(argv[i + 1]);
        }
    }
    return state->csv_path != NULL;
}

void usage(){
    printf("Usage: temp_statistics -f <filename.csv> [-m <month>] [-y <year>]\n");
}
