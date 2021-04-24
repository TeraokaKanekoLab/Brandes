#include "functions.hpp"

int main(int argc, char* argv[])
{
    Graph g = read_graph(argv[1]);
    auto start = chrono::steady_clock::now();
    g.compute_bc();
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << (double)duration.count() / 1000000 << " s" << endl;
    // g.print_betweeness_centrality();
    return 0;
}
