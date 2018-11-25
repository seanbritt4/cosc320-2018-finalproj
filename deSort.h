#ifndef DESORT_H
#define DESORT_H

#include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

void *frontEnd()
{
	sleep(1);
	printf("in front end");
	return NULL;
}

void *backEnd()
{
	sleep(1);
	printf("in front end");
	return NULL;
}

#endif