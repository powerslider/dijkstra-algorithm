#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    unsigned int source;
    unsigned int destination;
    double weight;
} edge;
 
typedef struct {
    edge* edges;
    unsigned int edge_count;
    unsigned int edge_space;
    char* value;
    double distance;
	node* previous;
} node; 

typedef struct {
    node* nodes;
    unsigned int node_count;
    unsigned int node_space;
} graph;

graph* create_graph();

void add_node(graph*, char*);

void add_edge(graph*, unsigned int, unsigned int, double);

void destroy_graph(graph*);

#endif 
