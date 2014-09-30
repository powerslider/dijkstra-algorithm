#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct {
	int count;
    int maxsize;
	int* keys;
} priority_queue;


priority_queue create_priority_queue(int n);

void insert(priority_queue* Q, int key);

int poll(priority_queue * Q);

void is_empty(priority_queue* Q);

void destroy_priority_queue(priority_queue* Q);

