#include "dijkstra.h"
#include "priorityqueue.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_Q_SIZE 50

double* distances;

int compare(graph* g, unsigned int i, unsigned int j) {
    if(g->nodes[i].distance == g->nodes[j].distance) { return 0; }
    if(g->nodes[i].distance > g->nodes[j].distance) { return 1; }
    return -1;
}

void dijkstra(graph* g, unsigned int source) {
	unsigned int i, smallest, v, edge_count;
	node *n, *d;
	edge *e;
	priority_queue *Q;

	g->nodes[source].distance = 0;
	Q = create_priority_queue(MAX_Q_SIZE);
    for (i = 0; i < g->node_count; i++) {
        insert(Q, i);
    }
	while(!is_empty(Q)) {
		smallest = poll(Q);
		n = &g->nodes[smallest];
		edge_count = n->edge_count;
		for (v = 0; v < edge_count; v++) {	
			e = &n->edges[v];	
			d = &g->nodes[e->destination];
			if (d->distance > n->distance + e->weight) {
				d->distance = n->distance + e->weight;
				d->previous = smallest;
			}
		}
	}
	destroy_priority_queue(Q);
}
