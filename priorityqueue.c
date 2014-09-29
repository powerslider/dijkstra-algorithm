#include "priorityqueue.h"


int poll(priority_queue * Q) {
	int i,c;
	int t = Q->keys[1];
	Q->keys[1] = Q->keys[Q->count--];
	for (i = 1; (c = 2 * i) <= Q->count; i = c) {
		if ((c + 1 <= Q->count) && (Q->keys[c + 1] < Q->keys[c])) {
			c++;
		}
		if (Q->keys[i] <= Q->keys[c]) {
			break;
		}
		swap(Q, c, i);
	}
	return t;
}

priority_queue create_priority_queue(int maxsize) {
	priority_queue Q;
	Q.maxsize = maxsize;
	Q.keys = (int *) malloc((Q.maxsize + 1) * (sizeof(int *)));
	Q.count = 0;
	return Q;
}

void insert(priority_queue* Q, int key) {
	int i,p;
	Q->count++;
	Q->keys[Q->n] = key;
	for (i = Q->n; (i > 1) && (Q->keys[p = i / 2] > Q->keys[i]); i = p) {
		swap(Q, p, i);
	}
}

void swap(priority_queue* Q, int i, int j) {
	int temp = Q->keys[i];
	Q->keys[i] = Q->keys[j];
	Q->keys[j] = temp;
}

void is_empty(priority_queue* Q) {
    return Q.count == 0;
}

void destroy_priority_queue(priority_queue* Q) {
    if(!is_empty(Q)) {
        free(Q->keys);
    }
    free(Q);
}
