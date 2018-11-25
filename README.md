# cosc320-proj
# Double Ended Selection Sort and Recursive Binary Search vs Hash Tables in Parallel Computing
Sean Brittingham, Alex Titus

	Selection sort is a very simple algorithm used to sort arrays, which iterates through an array finding the smallest element and placing it at array[i], then running again on array[i+1] until the entire array is sorted. One of the first algorithms learned in this class was the Double Ended Selection sort, in which for every iteration the algorithm found the smallest and largest elements in that pass and then placing them at array[front+i] and array[end-i]. In an attempt to improve the runtime of the Double Ended Selection sort we are proposing to run the single pass in parallel between two sister processes. One process would find the smallest element in the array and place it at array[front+(# of iterations)], and the other process would find the largest element in the array and place it at array[end-(# of iterations)].
	Further, we will also implement a hash table using separate chaining as another method of sorting and searching the array. We believe that the results will be of interest because of the differences in runtime complexities between the algorithms (listed below). 

 Selection sort: O(n^2)	
 DES sort: O(n^2)	
 Binary Search: O(log n)	
 Hash table:  O(n)		
 Hash Search:  O(n)	
	
	If there is any improvement in the runtime of the double ended selection sort, perhaps it will be more apparent when competing against the hash table.
A few problems that are currently arising in this are the possibility of overlapping digits when the smallest and the largest element in the array are at the same location / the same number, as well as one of the processes working faster than the other on. A solution we have come up for the process speeds is to use threads, and join the threads in order to not have them proceed without the other one running faster.
We are interested in comparing the efficiency of this type of Double Ended Selection Sort (using parallel computing) versus a standard serial Double Ended Selection Sort versus a normal Selection Sort (Single Ended). To do so we will write a program which will generate a large (possibly 1,000,000+ element) array of random integers which will be saved and written to a .txt file for posterity, then execute each sorting algorithm on the array while monitoring real time durations and possibly other methods of analysis. Further we will compare this entire process against a third: a hashing of the array into a hash table. We will compare the time that it takes to sort the original array through single and double ended selection sorts and to search for an element using binary search against the time needed to search the element in a hash table.

Pseudo-Code for Process One (finding smallest):

for j ← 1 to n-1
    smallest ← j
        for i ← j + 1 to n
            if A[ i ] < A[ smallest ]
    smallest ← i
        Swap A[ j ] ↔ A[ smallest ]

Pseudo-Code for Process Two (finding largest):

for j ← 1 to n-1
    largest ← j
        for i ← j + 1 to n
            if A[ i ] < A[ largest ]
    largest ← i
        Swap A[ j ] ↔ A[ largest ]

We will be using pthread_create() for each of the two processes running, as well as a pthread_join() in order to make sure they’re going to run at the same time and not run into errors of overlapping digits / array insertions. These threads will be running in the background as different processes in hopes of speeding up the time needed to sort an array. 
    


