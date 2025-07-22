#include <stdio.h>

#define MAX_BARS 50


int main(){
    int task_id = 1, progress = 60;
    float bars = MAX_BARS*progress / 100;
    printf("Task %d: [",task_id);
    for(int i=0; i<=MAX_BARS; i++){
        if (i<= bars) printf("=");
        else printf(" ");
    }
    printf("] %d%%", progress);
    
    return 0;
}