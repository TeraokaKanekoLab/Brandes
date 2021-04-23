#include "header.hpp"

class Graph {
private:
    typedef pair<int, int> edge;
    unordered_map<int, unordered_set<int>> neighbors;
    int num_edges;

    void add_vertex(int v)
    {
        if (has_vertex(v))
            return;
        neighbors[v] = unordered_set<int>();
    }

public:
    Graph()
    {
        num_edges = 0;
    }

    // getter
    bool has_vertex(int v)
    {
        return neighbors.find(v) != neighbors.end();
    }

    // We assume v is a valid node
    // Otherwise an exception will be triggered
    int get_degree(int v)
    {
        return neighbors[v].size();
    }

    int get_num_edges()
    {
        return num_edges;
    }

    // We assume v is a valid node
    // Otherwise an exception will be triggered
    unordered_set<int> get_neighbors(int v)
    {
        return neighbors[v];
    }

    vector<int> get_vertices()
    {
        vector<int> vertices;
        for (auto [v, nbrs] : neighbors) {
            vertices.push_back(v);
        }
        return vertices;
    }

    void print_graph()
    {
        for (auto [u, nbrs] : neighbors) {
            cout << u << ":";
            for (auto v : nbrs) {
                cout << " " << v;
            }
            cout << endl;
        }
    }

    bool has_neighbor(int u, int v)
    {
        return neighbors[u].find(v) != neighbors[u].end();
    }

    // setter
    void add_edge(int u, int v)
    {
        add_vertex(u);
        add_vertex(v);
        if (!has_neighbor(u, v) and !has_neighbor(v, u))
            ++num_edges;
        neighbors[u].insert(v);
        neighbors[v].insert(u);
    }
};