#include "arr.h"
#include <pthread.h>

#define RD_END 0
#define WR_END 1

int fd1[2], fd2[2];
int status;
/*
void *frontEnd()
{
    int i;
    int max = 0;
    int fromBackEnd = 0;

    close(fd1[RD_END]);
    close(fd2[WR_END]);

    for(i = 0; i < MAX_NUM/2; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("Max in the first %d is: %d\n", MAX_NUM/2, max);
    write(fd1[WR_END], max, sizeof(max));
    wait(&status);
    read(fd2[RD_END], fromBackEnd, sizeof(fromBackEnd));
    //wait(&status);
    printf("FRONT END Max in the second %d is: %d\n", MAX_NUM/2, fromBackEnd);
    /*
    int i;
    close(fd1[RD_END]);
    close(fd2[WR_END]);

    char* fmsg = "hello from front end";
    char bmsg[30];

    for(i = 0; i < MAX_NUM/2; i++)
    {
    printf("in front end: %d\n", arr[i]);
    write(fd1[WR_END], fmsg, sizeof(fmsg));

    wait(&status);
    read(fd2[RD_END], bmsg, 30);
    printf("%s\n", bmsg);

    //GOAL:
    /*find highest in front half and send to back end
    //if lower than lowest in front end:
    //  swap arr[i] with lowest from back end
    //else:
    //  discard lowest from back end and swap normally
    /
    //}
return NULL;
}

void *backEnd()
{
    wait(&status);
    int i;
    int max = 0;
    int fromBackEnd;

    close(fd1[WR_END]);
    close(fd2[RD_END]);

    for(i = MAX_NUM/2; i < MAX_NUM; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    write(fd2[WR_END], max, sizeof(max));
    //printf("BACK END Max in the second %d is: %d\n", MAX_NUM/2, max);
    //write(fd2[WR_END], max, sizeof(max));


    wait(&status);
    int i;

    close(fd1[WR_END]);
    close(fd2[RD_END]);

    char* bmsg = "hello from back end";
    char fmsg[30];

    // i=1 bc genArr() is creating at least one extra value
    // for(i = 1; i <= MAX_NUM/2; i++), try this to see what i mean
    for(i = 1; i <= MAX_NUM/2; i++)
    {
        wait(&status);
        read(fd2[RD_END], bmsg, 30);

        printf("%s\n", fmsg);

        printf("in back end: %d\n", arr[MAX_NUM - i]);
        write(fd2[WR_END], bmsg, sizeof(bmsg));

        //GOAL:
          /*find highest in back end
          //read highest from front end
          //if highest from front end > highest from back end:
          //  swap arr[i] with highest fron front end
          //else:
          //  swap[i] with highest from back end
          /
    //}
    return NULL;
}
*/

void *minSelectionSort(){
    int i, j, min_index;
    int min = MAX_NUM+1;

    for(i = 0; i < MAX_NUM; i++){
        min_index = i;
        for(j = i+1; j < MAX_NUM; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
                // printf("minSelectionSort: ");
                // printArr();
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

void *maxSelectionSort(){
    int i, j, max_index;
    int max = 0;

    for(i = MAX_NUM; i > 0; i--){
        max_index = i;
        for(j = i+1; j < MAX_NUM; j++){
            if(arr[max_index] > arr[j]){
                max_index = j;
                // printf("maxSelectionSort: ");
                // printArr();
            }
        }
        swap(&arr[max_index], &arr[i]);
    }
}

int main()
{
    genArr();
    int i, p;
    pipe(fd1);
    pipe(fd2);

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, minSelectionSort, NULL);
    pthread_join(threads[0], NULL);

    pthread_create(&threads[1], NULL, maxSelectionSort, NULL);
    pthread_join(threads[1], NULL);

    writeArr("sort.txt");
    
    printf("show: ");
    i = 0;
    while(arr[i] >= 0 && arr[i] <= 215){
        printf("%d: %d, ", i++, arr[i]);
    }

    return 0;
}
