//#include "deSort.h"
#include "arr.h"

#include <pthread.h>

#define RD_END 0
#define WR_END 1

int fd1[2], fd2[2];

void *frontEnd(void *arg)
{
	int *arr = (int *) arg;

    int i;
    close(fd1[RD_END]);
    close(fd2[WR_END]);
    
    printf("in front end\n");
    for(i = 0; i < oneMil/2; i++){
        printf("%d\n", arr[i]);   

        //find highest in front half and send to back end
//        char* str = "hello from front end\n";
//        write(fd1[WR_END], a, sizeof(a));
//        wait();
        
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //read                                                                                                                                                                                                                                                                                                  lowest from bck end and compare
        //if lower than lowest in front end:
        //  swap arr[i] with lowest from back end
        //else:
        //  discard lowest from back end and swap normally
            
    }
    
	return NULL;
}

void *backEnd(void* arg)
{
    
	int *arr = (int *) arg;
//    wait(1);
    int i;
//    char msg[30];
    close(fd1[WR_END]);
    close(fd2[RD_END]);

	printf("in back end\n");
    
    //i=1 bc genArr() is creating at least one extra value
    
	for(i = 1; i <= oneMil/2; i++){
        printf("%d: %d\n", oneMil - i, arr[oneMil - i]); 
//        wait();
        //find highest in back end
        
        //read highest from front end
//        read(fd2, msg, 30);
//        printf("%s\n", msg);
        //if highest from front end > highest from back end:
        //  swap arr[i] with highest fron front end
        //else:
        //  swap[i] with highest from back end
    }
    
    return NULL;
}


/*
int frontEnd(int arr){
    int lo = -999;
    
//    writeArr(arr, "front-end.txt");
    
    return lo + arr;
}

int backEnd(int arr){
    int hi = 999;
    return hi - arr;
}
*/

int main(){
	int* a = genArr();
	int i, p;
    pipe(fd1);
    pipe(fd2);
    
    /*
    pid = fork();
    pipe(pip);
    
    if(pid == 0)
    {
        printf("in child\n");
        printf("front end %d\n", frontEnd(4));
    }
    else
    {
        printf("in parent\n");
        printf("back end %d\n", backEnd(4));
    }
    */
	
	pthread_t threads[2];
    
	pthread_create(&threads[0], NULL, frontEnd, (void*) a);
	pthread_create(&threads[1], NULL, backEnd, (void*) a);
	
	for(i = 0; i < 2; i++)
	{
		(void) pthread_join(threads[i], NULL);
	}
	
	
	writeArr(a, "sort.txt");
	
	return 0;
}
