#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include <iostream>
#include <vector>
#include <map>

template<typename T>
class Vertex {
public:
	Vertex(T key) {
		this->key = key;
		this->parent = nullptr;
	}
	Vertex() {}
	~Vertex() {}

	T key;
	Vertex<T> *parent;
};

template<typename T>
class Graph {
public:
	Graph(){}
	~Graph(){}

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
					std::cout << "Edge found between " << u->key << " and " << v->key << std::endl;
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
	}

	std::map<Vertex<T>*, std::vector<Vertex<T>*>> adj;
};

#endif
