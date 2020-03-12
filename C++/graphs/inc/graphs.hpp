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
	}

	void dijkstras(Vertex<T> *start) {
		for (auto v : vertices) {
			dijkstra_initialize();
			std::vector<Vertex<T>*> S;
			std::vector<Vertex<T>*> Q;
			for (auto v : vertices) {
				Q.push_back(v);
			}

			Vertex *u;
			while (Q.size() != 0) {
				u = extract_min(Q);
				S.push_back(u);
				for (auto v : adj[u]) {
					update_weight(u,v);
				}
			}
		}
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

	void dijkstra_initialize() {

	}

	void update_weight(Vertex* u, Vertex* v) {
		
	}
};

#endif
