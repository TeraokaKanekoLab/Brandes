#include "header.hpp"

class Graph {
private:
    typedef pair<int, int> edge;
    unordered_map<int, int> original_to_renumbered;
    vector<int> renumbered_to_original;
    vector<vector<int>> neighbors;
    vector<double> betweenness_centrality;
    int num_nodes;
    int num_edges;
    bool has_computed_bc;

    void add_vertex(int original_id)
    {
        if (original_to_renumbered.find(original_id) != original_to_renumbered.end())
            return;
        original_to_renumbered[original_id] = num_nodes;
        neighbors.push_back(vector<int>());
        betweenness_centrality.push_back(0);
        renumbered_to_original.push_back(original_id);
        ++num_nodes;
    }

public:
    Graph()
    {
        num_nodes = 0;
        num_edges = 0;
        has_computed_bc = false;
    }

    // getter
    // We assume v is a valid node
    // Otherwise an exception will be triggered
    int get_degree(int v)
    {
        assert(0 <= v && v < num_nodes);
        return neighbors[v].size();
    }

    int get_num_edges()
    {
        return num_edges;
    }

    // We assume v is a valid node
    // Otherwise an exception will be triggered
    vector<int> get_neighbors(int v)
    {
        return neighbors[v];
    }

    vector<int> get_vertices()
    {
        vector<int> vertices;
        for (int i = 0; i < num_nodes; ++i) {
            vertices.push_back(renumbered_to_original[i]);
        }
        return vertices;
    }

    void print_graph()
    {
        for (int i = 0; i < num_nodes; ++i) {
            cout << renumbered_to_original[i] << ":";
            for (auto v : neighbors[i]) {
                cout << " " << renumbered_to_original[v];
            }
            cout << endl;
        }
    }

    // compute
    void compute_bc()
    {
        if (has_computed_bc)
            return;
        has_computed_bc = true;
        for (int s = 0; s < num_nodes; ++s) {
            stack<int> stack;
            vector<vector<int>> direct_predecessors = vector<vector<int>>(num_nodes, vector<int>());
            vector<int> num_paths = vector<int>(num_nodes, 0);
            num_paths[s] = 1;
            vector<int> d = vector<int>(num_nodes, -1);
            d[s] = 0;
            queue<int> visited;
            visited.push(s);

            while (!visited.empty()) {
                int v = visited.front();
                visited.pop();
                stack.push(v);
                for (int nbr : neighbors[v]) {
                    if (d[nbr] < 0) {
                        visited.push(nbr);
                        d[nbr] = d[v] + 1;
                    }
                    if (d[nbr] == d[v] + 1) {
                        num_paths[nbr] += num_paths[v];
                        direct_predecessors[nbr].push_back(v);
                    }
                }
            }
            vector<double> delta = vector<double>(num_nodes, 0);
            while (!stack.empty()) {
                int w = stack.top();
                stack.pop();
                for (int pred : direct_predecessors[w])
                    delta[pred] += (double)num_paths[pred] / num_paths[w] * (1 + delta[w]);

                if (w == s)
                    continue;
                betweenness_centrality[w] += delta[w];
            }
        }
    }

    // setter
    void add_edge(int u, int v)
    {
        add_vertex(u);
        add_vertex(v);
        u = original_to_renumbered[u];
        v = original_to_renumbered[v];
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    void print_betweeness_centrality()
    {
        compute_bc();
        double sum = 0;
        for (int i = 0; i < num_nodes; ++i)
            sum += betweenness_centrality[i];
        for (int i = 0; i < num_nodes; ++i)
            cout << renumbered_to_original[i] << ": " << betweenness_centrality[i] / sum << endl;
    }
};