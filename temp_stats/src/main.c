#include <stdio.h>
#include <parse_csv.h>
#include <util.h>
#include <temp_functions.h>
SCOPE_t state = {
    .csv_path = NULL,
    .need_mouth = 0
};


int main(int argc, char** argv){
    if(!parse_args(argc, argv, &state)){
        usage();
        return 1;
    }
    read_csv(&state);
    free(state.data);
}

