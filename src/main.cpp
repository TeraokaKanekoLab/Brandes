#include "functions.hpp"

int main(int argc, char* argv[])
{
    Graph g = read_graph(argv[1]);
    g.print_betweeness_centrality();
    return 0;
}
