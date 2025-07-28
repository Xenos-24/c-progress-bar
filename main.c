#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_BARS 50
#define TASKS 5
/*
Changes to make Make a """ int tasks_incomplete(Task task[]); """
Prototype : 
int tasks_incomplete(Task task[]){
                int tasks_incomplete = 0;

                for (int i=0; i < TASKS; i++){    
                        tasks_incomplete = 1;

                        if(task[i].progress == 100){
                            tasks_incomplete = 0;
                            continue;
                        
                        }
                }
                
                return tasks_incomplete;
            }

*/
typedef struct{
    int id;
    int progress;
    int step;
}Task;

void print_bars(Task task); 
void clear_screen();
int assign_random_step();


int main(){
    srand(time(NULL));
    Task task[TASKS];
    for (int i=0; i < TASKS; i++){
        task[i].id = i+1;
        task[i].progress = 0;
        task[i].step = assign_random_step();
    }

    int tasks_incomplete, j = 1;
    int temp = 0;
    
    while (tasks_incomplete){
        
       
        
        clear_screen();
        temp = tasks_incomplete; 
        for (int i=0; i < TASKS; i++){    
            tasks_incomplete = 1;
            
            if(temp == 5){
                tasks_incomplete = 0;
                break;
                exit;
            }
            if(task[i].progress == 100){
                temp +=1;
                continue;
                
            }
            else {
                temp = 0;
            }
            
        }
        
        
        for (int i=0; i < TASKS; i++){ 
            
            
            if (task[i].progress + task[i].step > 100){
               
                task[i].progress += 100 - task[i].progress;
                print_bars(task[i]);
                continue;
            }    
            
            task[i].progress += task[i].step;
            print_bars(task[i]);
        }
       
        
        usleep(500000);
        j++;
    }   
    
    return 0;
}

void print_bars(Task task){
    float bars = MAX_BARS*task.progress / 100;
    printf("Task %d: [",task.id);
    for(int i=0; i<=MAX_BARS; i++){
        if (i<= bars) printf("=");
        else printf(" ");
    }
    printf("] %d%% \n", task.progress);
}

void clear_screen(){
    #ifdef _Win32
        system("cls");
    #else
        system("clear");
    #endif

}

int assign_random_step(){
    int step;
    step = rand() % 10 + 1;
    return step;
}

