#include <iostream>

#include "deSort.h"
#include "arr.h"

int main(){
	srand(time(NULL));

	int n = 20;
	// int oneMil = 1000000;				// for simplicity

	
	int* a = genArr(n);
	// int* a = genArr(oneMil);
	
	std::cout << "Original array:\n";
	printArr(a,n);
	// printArr(a,oneMil);
	
	std::cout << "\nsorting---------------\n\n";
	deSort(a, n);
	// deSort(a, oneMil);
	
	std::cout << "Sorted array:\n";
	printArr(a,n);
	// printArr(a,oneMil);
	
	return 0;
}
