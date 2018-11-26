#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>

 #include <unistd.h>

//global int- one million
int oneMil = 15;//1000000;


// writes array to screen
// currently unused
void printArr(int *arr)
{
    int i;
    for(i =0; i<oneMil; i++){
        if(i == oneMil - 1)  printf("%d: %d\n", i, arr[i]);      //formatting, writes new line instead of ,
        else        printf("%d: %d, ", i, arr[i]);               //formatting, writes , instead of new line

    }
}

//writes array to FILE passed 
// TODO- test for 1,000,000... file too large for c9 lol
//     - works for 50,000
void writeArr(int* arr, char* file)
{
    
    umask(0);
    FILE* des = fopen(file, "w");    //using FOPEN to use FPRINTF
    
    // fopen validation - remove if not wanted/needed
    if(des < 0)
    {
        printf("Open File Error\n");
        exit(0);
    }
    
    lseek(des, 0, SEEK_SET);
    int i;
    printf("Writing to \"%s...\"", file);
    for(i =0; i<oneMil; i++)
    {
        lseek(des, 0, SEEK_CUR);            
        char str[20];                       //string buffer
        // str[0] = 'd';                       //stack overflow said to initialize first ele. but seems to work lol
        sprintf(str, "%d: %d", i, arr[i]);  //format string to print
        fprintf(des, "%s\n", str);          //print str to file
    }    
    
    fclose(des);
    printf("Done\n");   
}


// takes an array as argument named arr
// randomize order of array passed as argument
//  return randomized array
int* shuffle(int *arr)
{
    srand(time(NULL));
    printf("Shuffling array...");
    int i = 0, count = 0;
    

    for(;i<oneMil * 10; i++)
    {
        int temp;
        int a = arr[rand() % oneMil];
        int b = arr[rand() % oneMil];
        
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }


    printf(" Done\n");
    writeArr(arr, "shuf.txt");

    return arr;
}

// generates 1,000,000 element array with numbers 0-999,999 in DESCENDING order
//  then calls shuffle() to  the array
//  returns array
int* genArr()
{
    printf("Generating array...");
    int i;
    int *arr = malloc(oneMil * sizeof(arr));

    for(i = 0; i < oneMil; i++)
    {
        arr[i] = oneMil - i;
    }
    
    printf(" Done\n");
    writeArr(arr, "orig.txt");
    return shuffle(arr);
}


#endif
