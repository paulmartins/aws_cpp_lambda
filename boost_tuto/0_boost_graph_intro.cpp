#include <iostream> // for std::cout
#include <utility>  // for std::pair
#include <typeinfo> // for typeid
#include <iterator>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>


boost::adjacency_list<> build_a_basic_graph()
{
	// Define a graph using the adjacency_list container, with all default parameter
	// https://www.boost.org/doc/libs/1_72_0/libs/graph/doc/adjacency_list.html
	boost::adjacency_list<> g;

	/* ------------------------------------------------------------------------------------------ */
	/* VERTICES
	/* -------------------------------------------------------------------------------------------*/

	// Add 4 vertices to the graph with the add_vertex function. It returns the newly added point 
	// to the graph as an object of type 
	// boost::adjacency_list::vertex_descriptor
	boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g);

	// Print the 4 vertices manually
	std::cout << "Manually print the 4 vertices:" << std::endl;
	std::cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << "\n\n";
	// These numbers are indexes to a vector that is used internally in the adjacency_list

	// Keep adding vertices without saving the descriptor
	boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);

	// We can still print all the vertices index with the vertex descriptor.
	// We access all the (index) vertices of a graph with the boost::vertices function
	// It returns a pair or iterator (start and end indices)
	std::pair < boost::adjacency_list<>::vertex_iterator,
				boost::adjacency_list<>::vertex_iterator
				> vs = boost::vertices(g);

	std::cout << "Print all the " << boost::num_vertices(g) << " vertices with iterators:" << std::endl;
	std::cout << "idx goes from " << *vs.first << " to " << *vs.second << "\n";
	for(auto it = vs.first; it != vs.second; ++it){
		std::cout << *it << std::endl;
		// or boost::adjacency_list<>::vertex_descriptor(*it);
	} 

	// Alternatively we can use the copy function coupled to the ostream_iterator
	// std::copy(vs.first
	// 		, vs.second
	// 		, std::ostream_iterator<int>{std::cout, ", "});
    // std::cout << std::endl;

	/* ------------------------------------------------------------------------------------------ */
	/* EDGES
	/* -------------------------------------------------------------------------------------------*/
	
	// Adding edges between vertices with add_edges
	// It returns the edge descriptor and a flag that is true when the edge is properly added to g
	std::pair<boost::adjacency_list<>::edge_descriptor, bool> e1 = boost::add_edge(v1, v2, g);
	std::pair<boost::adjacency_list<>::edge_descriptor, bool> e2 = boost::add_edge(v2, v4, g);
	// Print the 2 edges manually
	std::cout << "Manually print the 2 edges:" << std::endl;
	std::cout << e1.first << ", " << e1.second << "\n";
	std::cout << e2.first << ", " << e2.second << "\n\n";

	// Keep adding edges
	boost::add_edge(1, 5, g);
	boost::add_edge(4, 6, g);
	boost::add_edge(5, 2, g);

	// Access all the edges with 
	std::pair < boost::adjacency_list<>::edge_iterator, 
				boost::adjacency_list<>::edge_iterator 
				> ei = boost::edges(g);

	std::cout << "Print all the " << boost::num_edges(g) << " edges with iterators:" << std::endl;
    std::copy( ei.first, ei.second,
                std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>{
                    std::cout, "\n"});

	return g;
}


int main()
{
	boost::adjacency_list<> g = build_a_basic_graph();

	std::cout << "Print the graph with graphviz:" << std::endl;
	write_graphviz(std::cout, g);
}


