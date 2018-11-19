/*
    could move to main but made it seperate incase we need to add to it
    


*/

#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//  params: n- size of the arr (could remove if we decide to standardize the size)
//  generates n random integers (0-999,999) and populates array 'arr'
//  returns array
int* genArr(int n)
{
    srand(time(NULL));

    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand()% 100;
    }

    
    return arr;
}

void printArr(int *arr, int n){
    for(int i =0; i<n; i++){
        std::cout << i << ": "<< arr[i] << std::endl;
    }
}

#endif
