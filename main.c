#include <stdio.h>
#include "graph.h"


int main() {
    graph* g;
    int i, nodes, connections, edge_weight;
    int node_source, node_destination;

    g = create_graph();
    nodes = g->node_space;
    connections = g->nodes->edge_space;
    node_source = g->nodes->edges->source;
    node_destination = g->nodes->edges->destination;
    edge_weight = g->nodes->edges->weight;

    scanf("%d %d", &nodes, &connections);

    for (i = 0; i < connections; i++) {
        scanf("%d %d %d", &node_source, &node_destination, &edge_weight);
    }
}
