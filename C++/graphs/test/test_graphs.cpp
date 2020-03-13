#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "graphs.hpp"
#include <vector>
#include <limits>

using namespace std;

TEST_CASE("vertices", "[graphs]"){
	Vertex<int> test_vertex(1);
	REQUIRE(test_vertex.key == 1);
	// REQUIRE(test_vertex.parent == nullptr);
}

TEST_CASE("bfs/dfs algorithms", "[graphs]"){
	Graph<char> test_graph;
	Vertex<char> test_vertex_a('a');
	Vertex<char> test_vertex_s('s');
	Vertex<char> test_vertex_d('d');
	Vertex<char> test_vertex_f('f');
	Vertex<char> test_vertex_z('z');
	Vertex<char> test_vertex_x('x');
	Vertex<char> test_vertex_c('c');
	Vertex<char> test_vertex_v('v');

	std::vector<Vertex<char>*> adj_a;
	adj_a.push_back(&test_vertex_s);
	adj_a.push_back(&test_vertex_z);

	std::vector<Vertex<char>*> adj_s;
	adj_s.push_back(&test_vertex_a);
	adj_s.push_back(&test_vertex_x);

	std::vector<Vertex<char>*> adj_d;
	adj_d.push_back(&test_vertex_x);
	adj_d.push_back(&test_vertex_c);
	adj_d.push_back(&test_vertex_f);

	std::vector<Vertex<char>*> adj_f;
	adj_f.push_back(&test_vertex_d);
	adj_f.push_back(&test_vertex_c);
	adj_f.push_back(&test_vertex_v);

	std::vector<Vertex<char>*> adj_z;
	adj_z.push_back(&test_vertex_a);

	std::vector<Vertex<char>*> adj_x;
	adj_x.push_back(&test_vertex_s);
	adj_x.push_back(&test_vertex_d);
	adj_x.push_back(&test_vertex_c);

	std::vector<Vertex<char>*> adj_c;
	adj_c.push_back(&test_vertex_x);
	adj_c.push_back(&test_vertex_d);
	adj_c.push_back(&test_vertex_f);
	adj_c.push_back(&test_vertex_v);

	std::vector<Vertex<char>*> adj_v;
	adj_v.push_back(&test_vertex_c);
	adj_v.push_back(&test_vertex_f);

	test_graph.adj[&test_vertex_a] = adj_a;
	test_graph.adj[&test_vertex_s] = adj_s;
	test_graph.adj[&test_vertex_d] = adj_d;
	test_graph.adj[&test_vertex_f] = adj_f;
	test_graph.adj[&test_vertex_z] = adj_z;
	test_graph.adj[&test_vertex_x] = adj_x;
	test_graph.adj[&test_vertex_c] = adj_c;
	test_graph.adj[&test_vertex_v] = adj_v;

	REQUIRE( test_graph.adj[&test_vertex_a].size() == 2 );
	REQUIRE( test_graph.adj[&test_vertex_s].size() == 2 );
	REQUIRE( test_graph.adj[&test_vertex_d].size() == 3 );
	REQUIRE( test_graph.adj[&test_vertex_f].size() == 3 );
	REQUIRE( test_graph.adj[&test_vertex_z].size() == 1 );
	REQUIRE( test_graph.adj[&test_vertex_x].size() == 3 );
	REQUIRE( test_graph.adj[&test_vertex_c].size() == 4 );
	REQUIRE( test_graph.adj[&test_vertex_v].size() == 2 );

	test_graph.bfs(&test_vertex_s);
	test_graph.dfs();
}

TEST_CASE("dijkstra's algorithm", "[graphs]"){
	Graph<char> test_graph;
	Vertex<char> test_vertex_a('a');
	Vertex<char> test_vertex_b('b');
	Vertex<char> test_vertex_c('c');
	Vertex<char> test_vertex_d('d');
	Vertex<char> test_vertex_e('e');

	std::vector<Vertex<char>*> adj_a;
	adj_a.push_back(&test_vertex_b);
	adj_a.push_back(&test_vertex_c);

	std::vector<Vertex<char>*> adj_b;
	adj_b.push_back(&test_vertex_c);
	adj_b.push_back(&test_vertex_d);

	std::vector<Vertex<char>*> adj_c;
	adj_c.push_back(&test_vertex_b);
	adj_c.push_back(&test_vertex_d);
	adj_c.push_back(&test_vertex_e);

	std::vector<Vertex<char>*> adj_d;
	adj_d.push_back(&test_vertex_e);

	std::vector<Vertex<char>*> adj_e;
	adj_e.push_back(&test_vertex_d);

	test_graph.adj[&test_vertex_a] = adj_a;
	test_graph.adj[&test_vertex_b] = adj_b;
	test_graph.adj[&test_vertex_c] = adj_c;
	test_graph.adj[&test_vertex_d] = adj_d;
	test_graph.adj[&test_vertex_e] = adj_e;

	test_graph.set_edge_weight(&test_vertex_a, &test_vertex_b, 10);
	test_graph.set_edge_weight(&test_vertex_a, &test_vertex_c, 3);
	test_graph.set_edge_weight(&test_vertex_b, &test_vertex_c, 1);
	test_graph.set_edge_weight(&test_vertex_b, &test_vertex_d, 2);
	test_graph.set_edge_weight(&test_vertex_c, &test_vertex_b, 4);
	test_graph.set_edge_weight(&test_vertex_c, &test_vertex_d, 8);
	test_graph.set_edge_weight(&test_vertex_c, &test_vertex_e, 2);
	test_graph.set_edge_weight(&test_vertex_d, &test_vertex_e, 7);
	test_graph.set_edge_weight(&test_vertex_e, &test_vertex_d, 9);

	REQUIRE( test_graph.get_edge_weight(&test_vertex_a, &test_vertex_b) == 10 );
	REQUIRE( test_graph.get_edge_weight(&test_vertex_a, &test_vertex_c) == 3 );
	REQUIRE( test_graph.get_edge_weight(&test_vertex_a, &test_vertex_e) == std::numeric_limits<float>::infinity() );

	test_graph.dijkstras();
}
