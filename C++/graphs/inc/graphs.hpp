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

private:
	void dfs_visit(Vertex<T>* s) {
		for (auto v : adj[s]) {
			if (dfs_parent.count(v) == 0) {
				dfs_parent[v] = s;
				std::cout << "DFS: Edge found between " << s->key << " and " << v->key << std::endl;
				dfs_visit(v);
			}
		}
	}
};

#endif
