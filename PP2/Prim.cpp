#include "C:\Users\danie\Programacion\boost\boost_1_71_0\boost\graph\adjacency_list.hpp"
#include "C:\Users\danie\Programacion\boost\boost_1_71_0\boost\graph\graph_utility.hpp"
#include "C:\Users\danie\Programacion\boost\boost_1_71_0\boost\graph\prim_minimum_spanning_tree.hpp"
#include "C:\Users\danie\Programacion\boost\boost_1_71_0\boost\graph\random.hpp"

#include <fstream>
#include <map>
#include <random>
#include <sstream>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::undirectedS> GraphTraits;
typedef GraphTraits::vertex_descriptor Vertex;

struct DijkstraStuff {
	Vertex predecessor;
	double distance;
	boost::default_color_type color; // for use by dijkstra.
};

struct VertexProperty : DijkstraStuff {
	std::string name;
	VertexProperty(const std::string &aName = "") : name(aName) {};
};

struct EdgeProperty {
	double weight; // distance to travel along this edge.
	EdgeProperty(double aWeight = 0.0) : weight(aWeight) {};
};

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, VertexProperty, EdgeProperty> Graph;

struct do_nothing_dijkstra_visitor : boost::default_dijkstra_visitor {};

int main() {
	Graph g;
	std::map<std::string, Vertex> name_map;

	// read graph (random for now)
	{
		std::mt19937 prng{ 42 };
		generate_random_graph(g, 10, 20, prng);

		for (auto vd : boost::make_iterator_range(vertices(g))) {
			name_map[g[vd].name = "NAME" + std::to_string(vd)] = vd;
		}

		std::uniform_real_distribution<double> weight_dist(0, 1);
		for (auto ed : boost::make_iterator_range(edges(g))) {
			g[ed].weight = weight_dist(prng);
		}
	}

	print_graph(g, get(&VertexProperty::name, g));

	Graph::vertex_descriptor start_v;

	std::cout << "Please enter the Vertex you would like to start at: ";
	{
		std::string startName;
		std::cin >> startName;
		std::transform(startName.begin(), startName.end(), startName.begin(),
			[](uint8_t ch) { return std::toupper(ch); });
		start_v = name_map.at(startName);
	}

	boost::prim_minimum_spanning_tree(g, start_v, get(&VertexProperty::predecessor, g),
		get(&VertexProperty::distance, g), get(&EdgeProperty::weight, g),
		boost::identity_property_map(), do_nothing_dijkstra_visitor());


}