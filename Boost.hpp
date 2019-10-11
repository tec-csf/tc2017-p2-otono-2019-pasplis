#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <tuple>
#include <vector>

#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost/graph/floyd_warshall_shortest.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/property_map/property_map.hpp>

using namespace boost;
using namespace std;
using namespace std::chrono;

typedef property<vertex_distance_t, int> Vdistance;
typedef property<edge_weight_t, int> EdgeWeight;
typedef adjacency_list <vecS, vecS, bidirectionalS, Vdistance, EdgeWeight> gBoost;
typedef property_map<gBoost, edge_weight_t>::type EdgeWeights;
typedef boost::graph_traits<gBoost>::vertex_descriptor vertex_Boost;
typedef graph_traits<gBoost>::edge_descriptor EDGE;
typedef boost::exterior_vertex_property<gBoost, int> DistanceProperty;
typedef DistanceProperty::matrix_type DistanceMatrix;
typedef DistanceProperty::matrix_map_type DistanceMatrixMap;

class dfsBOOST : public boost::default_dfs_visitor{
  public:

    void discover_vertex(vertex_Boost v, const gBoost& graf) const{
      std::cerr << v << "";

      return;
    }

};

class bfsBOOST : public boost::default_bfs_visitor{
public:
    void discover_vertex(vertex_Boost v, const gBoost& graf) const{
        std::cerr << v << " ";
        return;
    }
};

//Prim y Dijkstra son ávidos