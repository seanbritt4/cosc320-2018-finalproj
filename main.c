#include "arr.h"
#include <pthread.h>

#define RD_END 0
#define WR_END 1

int fd1[2], fd2[2];

void *frontEnd()
// void frontEnd()
{
    int i;
    close(fd1[RD_END]);
    close(fd2[WR_END]);
    
    char* fmsg = "hello from front end";
    char bmsg[30];
    
    for(i = 0; i < oneMil/2; i++)
    {
        printf("in front end: %d\n", arr[i]); 
        write(fd1[WR_END], fmsg, sizeof(fmsg));

        wait();
        read(fd2[RD_END], bmsg, 30);
        printf("%s\n", bmsg);

        //GOAL:
        /*find highest in front half and send to back end
        //if lower than lowest in front end:
        //  swap arr[i] with lowest from back end
        //else:
        //  discard lowest from back end and swap normally
        */    
    }
	return NULL;
}

void *backEnd()
// void backEnd()
{
    wait();
    int i;

    close(fd1[WR_END]);
    close(fd2[RD_END]);

    char* bmsg = "hello from back end";
    char fmsg[30];
    
    //i=1 bc genArr() is creating at least one extra value
    // for(i = 1; i <= oneMil/2; i++)          ///try this to see what i mean
	for(i = 1; i <= oneMil/2; i++)
	{
        wait();
        read(fd2[RD_END], bmsg, 30);

        printf("%s\n", fmsg);

	    printf("in back end: %d\n", arr[oneMil - i]);
	    write(fd2[WR_END], bmsg, sizeof(bmsg));
	  
	    //GOAL:
        /*find highest in back end
        //read highest from front end
        //if highest from front end > highest from back end:
        //  swap arr[i] with highest fron front end
        //else:
        //  swap[i] with highest from back end
        */
    }
    
    return NULL;
}

int main()
{
    genArr();
	int i, p;
    pipe(fd1);
    pipe(fd2);
    
 	pthread_t threads[2];
    
	pthread_create(&threads[0], NULL, frontEnd, NULL);
	pthread_join(threads[0], NULL);
	
	pthread_create(&threads[1], NULL, backEnd, NULL);
	pthread_join(threads[1], NULL);
	
	writeArr("sort.txt");
	
	return 0;
}
