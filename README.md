# Brandes
## General
Git repository for understanding [Brandes' algorithm](http://www.uvm.edu/pdodds/research/papers/others/2001/brandes2001a.pdf).

## Version History
| Version | Date  | Commit | Notes |
| :-----: | :-: | :-: | :-: |
| 0.0 | April 23, 2021 | [79bd987](https://github.com/TeraokaKanekoLab/Brandes/commit/79bd987ce69408af5acf7b39e5afae254a72edc5) | first commit |
| 0.1 | April 23, 2021 | [cb984f1](https://github.com/TeraokaKanekoLab/Brandes/commit/cb984f11d7de3ad19f8051699f62a073526f040d) | Add graph class |

## Graph Data File Format
The graph data files need to follow the rule below. `<endpoint n>` needs to be an int (node id)

```
<endpoint 1> <endpoint 2>
<endpoint 3> <endpoint 4>
.
.
.
```

Let's say there is a graph like this.
![](https://i.ibb.co/g6F8pfv/images-dragged.jpg)

The following data (`graph/simple_graph.gr`) represents this simple graph with 9 nodes and 12 edges, which are <0, 1>, ..., <7, 8>.

```
0 1
0 2
1 2
1 3
2 3
2 7
3 4
3 5
4 6
5 6
5 8
7 8
```

## How to Run the Program
Try the following command to get an instant result.

```
sh run.sh all graph/simple_graph.gr
```

## References
1. Brandes, Ulrik (2001). [A faster algorithm for betweenness centrality](http://www.uvm.edu/pdodds/research/papers/others/2001/brandes2001a.pdf). Journal of Mathematical Sociology. 25 (2): 163–177. CiteSeerX 10.1.1.11.2024. doi:10.1080/0022250x.2001.9990249. hdl:10983/23603. S2CID 13971996.
