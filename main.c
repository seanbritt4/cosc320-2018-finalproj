#include "deSort.h"
#include "arr.h"

// #include <unistd.h>
#include <pthread.h>

int main(){
	int* a = genArr();
	int i;
	
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, frontEnd, NULL);
	// pthread_create(&threads[1], NULL, backEnd, NULL);
	
	for(i = 0; i < 2; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	
	writeArr(a, "sort.txt");
	
	return 0;
}
