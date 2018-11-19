#ifndef DESORT_H
#define DESORT_H

/*
    params: arr- array to be sorted
            n- size of 'arr'
    
    performs serial(standard) double ended selection sort on 'arr'
    
    returns: void-
*/
int* deSort(int a[],int n){
// 	printf("\nsorting...\n");
	
	for(int i = 0; i < (n-1)/2; i++){
		int min = i,
			max = n-1-i;
		
		for(int j = i+1; j < n-i; j++){
			if(a[j] < a[min])
				min = j;
				
			if(a[j] > a[max])
				max = j;
		}

		if(min != i){
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}	
		
		if(max != n-1-i){
			int temp = a[n-1-i];
			a[n-1-i] = a[max];
			a[max] = temp;
		}
	}
     return a;
}


#endif
