#include "graph.hpp"

Graph read_graph(string filepath)
{
    std::ifstream file(filepath);
    if (!file.good()) {
        cout << "file not found" << endl;
        exit(-1);
    }

    Graph graph;

    int u, v;
    // Add edge to the graph object
    while (file >> u >> v)
        graph.add_edge(u, v);

    file.close();

    return graph;
}