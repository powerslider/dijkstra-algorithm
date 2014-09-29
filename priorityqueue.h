#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct {
	int count;
    int maxsize;
	int* keys;
} priority_queue;


int poll(priority_queue * Q);

priority_queue create_priority_queue(int n);

void insert(priority_queue* Q, int key);

void show(priority_queue* Q, int n);

void swap(priority_queue* Q, int i, int j);

void is_empty(priority_queue* Q);

void destroy_priority_queue(priority_queue* Q);

