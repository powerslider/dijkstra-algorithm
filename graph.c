#include "graph.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void resize_graph(graph* g) {
    if (g->node_space == 0) { 
        g->node_space = 1; 
    } else { 
        g->node_space *= 2; 
    }
    g->nodes = realloc(g->nodes, sizeof(node) * (g->node_space));
}

void resize_node_edges(node* n) {
    if(n->edge_space == 0) { 
        n->edge_space = 1; 
    } else {
        n->edge_space *=2;
    }
    n->edges = realloc(n->edges, sizeof(edge) * (n->edge_space));
}

graph* create_graph() {
    graph* g = malloc(sizeof(graph));
    g->node_space = 0;
    g->node_count = 0;
    g->nodes = NULL;
    return g;
}


void add_node(graph* g, char* c) {
    unsigned int count;
	node *n;

    if (g->node_space == g->node_count) {
        resize_graph(g);
    }

	count = g->node_count;
	n = &g->nodes[count];
    n->value = c;
	n->edges = NULL;
	n->edge_count = 0;
	n->edge_space = 0;
	n->distance = INFINITY;
	n->previous = -1;
    
    g->node_count++;
} 


void add_edge(graph* g, unsigned int source, unsigned int destination, double weight) {
	edge *e;
	node *n;
	
	n = &g->nodes[i];
    if(n->edge_space == n->edge_count) {
        resize_node_edges(n);
    }
	e = &n->edges[n->edge_count];
	e->source = source;
	e->destination = destination;
	e->weight = weight;
	g->nodes[i].edge_count++;
}


void destroy_graph(graph* g) {
	unsigned int i;
    for (i = 0; i < g->node_count; i++) {
		free(g->nodes[i].edges);
		free(g->nodes[i].value);
    }
    free(g->nodes);
    free(g);
}
