#include "dijkstra.h"
#include "priorityqueue.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_Q_SIZE 50

void relax(node* current_node, edge* current_edge, node* min_node) {
	if (current_node->distance > current_node->distance + current_edge->weight) {
		current_node->distance = current_node->distance + current_edge->weight;
        current_node->previous = (struct node*)min_node;
	}
}

graph* dijkstra(graph* g, unsigned int source) {
	unsigned int i, min_key, e, edge_count;
	node *min_node, *current_node;
	edge *current_edge;
	priority_queue *Q;

	g->nodes[source].distance = 0;
	Q = create_priority_queue(MAX_Q_SIZE);
	for (i = 0; i < g->node_count; i++) {
            insert(Q, i);
    }
	while (!is_empty(Q)) {
		min_key = poll(Q);
		min_node = &g->nodes[min_key];
		edge_count = min_node->edge_count;
		for (e = 0; e < edge_count; e++) {	
			current_edge = &min_node->edges[e];	
			current_node = &g->nodes[current_edge->destination];
			relax(current_node, current_edge, min_node);
		}
	}
	destroy_priority_queue(Q);

    return g;
}

double get_shortest_path(graph* g, unsigned int source, unsigned int target) {
    double path_distance = 0;
    struct node* current_node;
    g = dijkstra(g, source);

    for (current_node = (struct node*)g->nodes[target]; current_node != NULL; current_node = current_node->previous) {
        path_distance += current_node->distance;
    }

    return path_distance;
}
