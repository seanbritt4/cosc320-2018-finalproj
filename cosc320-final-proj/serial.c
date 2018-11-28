#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_NUM 50000

// Dealing with the array
void swap(int *xp, int *yp);
void printArray();
void writeArray(char *file);
void generateArray();

void normalSelectionSort();

int *arr;

int main()
{
    srand(time(NULL));
    arr = malloc(sizeof(int[MAX_NUM]));
    printf("Created new array of %d integer values \n", MAX_NUM);
    generateArray();
    
    clock_t begin = clock();
    
    normalSelectionSort();
    clock_t end = clock();
    printf("Time to sort array: %f seconds\n",
    (double)(end - begin) / CLOCKS_PER_SEC);
    
    writeArray("sort.txt");
    
    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void generateArray(){
    int i = 0;

    for(i; i < MAX_NUM; i++)
    {
        arr[i] = MAX_NUM-i;
    }
    writeArray("serial.txt");

    for(i = MAX_NUM-1; i >= 0 ; i--)
    {
        int r = (rand() % MAX_NUM);
        int s = (rand() % MAX_NUM);
        swap(&arr[r], &arr[s]);
    }
    writeArray("serial-shuf.txt");
}

void writeArray(char* file)
{

    umask(0);
    FILE* des = fopen(file, "w");    //using FOPEN to use FPRINTF

    lseek((long)des, 0, SEEK_SET);
    int i;
    printf("Writing to \"%s\"...", file);
    for(i =0; i<MAX_NUM; i++)
    {
        lseek((long)des, 0, SEEK_CUR);
        char str[20];                       //string buffer
        sprintf(str, "%d: %d", i, arr[i]);  //format string to print
        fprintf(des, "%s\n", str);          //print str to file
    }

    fclose(des);
    printf("Complete\n");
}

void normalSelectionSort(){
    /* GOAL:
    *   This thread will find the minimal value in the array, and
    *   place it at the min_index
    */
    int i, j, min_index;
    int min = MAX_NUM+1;

    for(i = 0; i < min; i++)
    {
        //pthread_mutex_lock(&arr_mutex);
        min_index = i;
        for(j = i+1; j < MAX_NUM; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        //printf("Minimum value %d, placing at front \n", arr[min_index], arr[i]);
        swap(&arr[min_index], &arr[i]);
        //printArray();

    }
}
