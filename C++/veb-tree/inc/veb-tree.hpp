#ifndef VEB_TREE_HPP
#define VEB_TREE_HPP

#include <vector>
#include <cmath>
#include "cluster.hpp"
#include <iostream>

template<typename T>

class VebTree {
public:
	VebTree() {
		min_set = false;
		max_set = false;
	}
	VebTree(long universe_size) {
		min_set = false;
		max_set = false;
		this->universe_size = universe_size;

		// there should be sqrt(universe_size) clusters, each of which has
		// sqrt(universe_size) elements.
		long cluster_size = ceil(sqrt(universe_size));
		this->clusters.reserve(cluster_size);
		this->summary.reserve(cluster_size);

		for (int i = 0; i < cluster_size; i++) {
			Cluster<T> c(cluster_size);
			this->clusters.push_back(c);
		}
	}
	~VebTree() {}

	void insert(T val) {
		std::cout << "summary index: " << val 
			<< " high: " << high(val)
			<< " low: " << low(val)
			<< std::endl;

		if (!this->min_set) {
			this->min = val;
			this->max = val;
			this->min_set = true;
			this->max_set = true;
			return;
		}

		if (val < this->min) {
			T temp = val;
			val = this->min;
			this->min = temp;
		}

		if (val > this->max) {
			this->max = val;
		}

		std::cout << "min" << this->min 
			<< "max " << this->max << std::endl;

		if (!this->clusters[high(val)].is_min_set()) {
			this->summary[high(val)] = 1;
		}

		this->clusters[high(val)].insert(low(val));
	}

	void del() {}

	T successor() {}

	T get(int index) {
		if (index == this->min) {
			return 1;
		}
		else if (index == this->max) {
			return 1;
		}
		else {
			return this->clusters[high(index)].get(low(index));	
		}
	}

private:
	T min;
	T max;
	bool min_set;
	bool max_set;
	long universe_size;
	std::vector<Cluster<T>> clusters;
	std::vector<bool> summary;

	T high(T x) {
		return floor(x / (int)ceil(sqrt(universe_size)));
	}

	T low(T x) {
		return x % (int)ceil(sqrt(universe_size));
	}

	T index(T i, T j) {
		return i* (int)ceil(sqrt(universe_size)) + j;
	}
};

#endif
