#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NUM 20

//global integer array for use by all threads
int* arr;


// writes array to screen
// currently unused or used only for debugging

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArr()
{
    int i;
    for(i = 0; i < MAX_NUM; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

//writes array to FILE passed
// TODO- test for 1,000,000... file too large for c9 lol
//     - works for 50,000
void writeArr(char* file)
{

    umask(0);
    FILE* des = fopen(file, "w");    //using FOPEN to use FPRINTF

    // fopen validation - remove if not wanted/needed
    if(des < 0)
    {
        printf("Open File Error\n");
        exit(0);
    }

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


// takes an array as argument named arr
// randomize order of array passed as argument
//  return randomized array
void shuffle()
{
    srand(time(NULL));
    printf("Shuffling array.........");
    int i = 0, j = 0, count = 0;
    for(count; count < 10; count++){
        for(i = MAX_NUM-1; i > 0 ; i--)
        {
            int j = arr[rand() % MAX_NUM];
            swap(&arr[i], &arr[j]);
        }
    }
    printf("Complete\n");
    writeArr("shuf.txt");
}

// generates 1,000,000 element array with numbers 0-999,999 in DESCENDING order
//  then calls shuffle() to  the array
//  returns array
void genArr()
{
    printf("Generating array........");
    int i;
    arr = malloc(MAX_NUM * sizeof(arr));

    for(i = 0; i < MAX_NUM; i++)
    {
        arr[i] = MAX_NUM - i;
    }

    printf("Complete\n");
    writeArr("orig.txt");
    shuffle();
}


#endif
