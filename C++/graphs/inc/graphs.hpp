#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include <iostream>
#include <vector>
#include <map>
#include <limits>

template<typename T>
class Vertex {
public:
	Vertex(T key) {
		this->key = key;
	}
	Vertex() {}
	~Vertex() {}

	T key;
	std::map<Vertex<T>*, int> weights;
};

template<typename T>
class Graph {
public:
	Graph(){}
	~Graph(){}

	std::map<Vertex<T>*, std::vector<Vertex<T>*>> adj;
	std::map<Vertex<T>*, Vertex<T>*> dfs_parent;

	void bfs(Vertex<T> *s) {
		std::map<Vertex<T>*, int> level;
		std::map<Vertex<T>*, Vertex<T>*> parent;
		int i = 1;

		std::vector<Vertex<T>*> frontier;
		frontier.push_back(s);
		while(frontier.size() > 0) {
			std::vector<Vertex<T>*> next;
			for (auto u : frontier) {
				for (auto v : adj[u]) {
					std::cout << "BFS: Edge found between " << u->key << " and " << v->key << std::endl;
					if (level.count(v) == 0) {
						level[v] = i;
						parent[v] = u;
						next.push_back(v);
					}
				}
			}

			frontier = next;
			i++;
		}
		std::cout << "BFS complete" << std::endl << std::endl;
	}

	void dfs() {
		std::map<Vertex<T>*, Vertex<T>*> parent;

		std::vector<Vertex<T>*> vertices;
		typename std::map<Vertex<T>*, std::vector<Vertex<T>*>>::iterator it;
		for(it = adj.begin(); it != adj.end(); ++it) {
			vertices.push_back(it->first);
		}

		for (auto s : vertices) {
			if (parent.count(s) == 0) {
				parent[s] = nullptr;
				dfs_visit(s);
			}
		}
		std::cout << "DFS complete" << std::endl << std::endl;
	}

	void dijkstras() {
		std::vector<Vertex<T>*> vertices;
		typename std::map<Vertex<T>*, std::vector<Vertex<T>*>>::iterator it;
		for(it = adj.begin(); it != adj.end(); ++it) {
			vertices.push_back(it->first);
		}

		for (auto start : vertices) {
			std::map<Vertex<T>*, Vertex<T>*> predecessor;
			std::map<Vertex<T>*, double> distance;
			for (auto v : vertices) {
				distance[v] = std::numeric_limits<float>::infinity();
				predecessor[v] = nullptr;
			}
			distance[start] = 0;

			std::vector<Vertex<T>*> S;
			std::vector<Vertex<T>*> Q;
			for (auto v : vertices) {
				Q.push_back(v);
			}

			Vertex<T> *u = start;
			while (Q.size() != 0) {
				u = extract_min(u, Q, distance);
				if (u == nullptr) {
					continue;
				}

				std::cout << "Moving to vertex " << u->key << std::endl;
				S.push_back(u);
				for (auto v : adj[u]) {
					update_distance(u,v, distance, predecessor);
					std::cout << "distance between " << start->key << " and " << v->key
						<< " is " << distance[v] << std::endl;
				}
				std::cout << "Dijkstra: " << u->key << std::endl;
			}
			std::cout << std::endl;
		}
	}

	double get_edge_weight(Vertex<T>* u, Vertex<T>* v) {
		bool v_has_edge = false;
		for (auto outgoing_vertex : adj[u]) {
			if (outgoing_vertex == v) {
				v_has_edge = true;
			}
		}

		if (!v_has_edge) {
			return std::numeric_limits<float>::infinity();
		}
		else {
			return u->weights[v];
		}
	}

	void set_edge_weight(Vertex<T>* u, Vertex<T>* v, int weight) {
		u->weights[v] = weight;
	}

private:
	void dfs_visit(Vertex<T>* start) {
		for (auto v : adj[start]) {
			if (dfs_parent.count(v) == 0) {
				dfs_parent[v] = start;
				std::cout << "DFS: Edge found between " << start->key << " and " << v->key << std::endl;
				dfs_visit(v);
			}
		}
	}

	void update_distance(Vertex<T>* u, 
			Vertex<T>* v, 
			std::map<Vertex<T>*, double> &distance,
			std::map<Vertex<T>*, Vertex<T>*> &predecessor) {
		if (distance[v] > (distance[u] + get_edge_weight(u,v))) {
			distance[v] = distance[u] + get_edge_weight(u,v);
			predecessor[v] = u;
		}
	}

	Vertex<T>* extract_min(Vertex<T>* current, std::vector<Vertex<T>*> &Q, std::map<Vertex<T>*, double> &distance) {
		Vertex<T> *min_vertex = Q.front(); 
		for (auto v : Q) {
			if (distance[v] < distance[min_vertex]) {
				min_vertex = v;
			}
		}

		Q.erase(std::remove(Q.begin(), Q.end(), min_vertex), Q.end());
		std::vector<Vertex<T>*> vec = adj[current];
		if (std::find(vec.begin(), vec.end(), min_vertex) != vec.end()) {
			return min_vertex;	
		}
		else if (min_vertex == current) {
			return min_vertex;
		}
		else {
			return nullptr;
		}
	}
};

#endif
