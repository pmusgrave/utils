#ifndef VEB_TREE_HPP
#define VEB_TREE_HPP

#include <vector>
#include <cmath>
#include <iostream>

template<typename T>
class VebTree {
public:
	VebTree(long universe_size) {
		// std::cout << universe_size << std::endl;
		min_set = false;
		max_set = false;
		min = 0;
		max = 0;
		this->universe_size = universe_size;

		if (universe_size <= 2 ) {
			return;
		}
		else {
			// there should be sqrt(universe_size) clusters, each of which has
			// sqrt(universe_size) elements.
			long cluster_size = ceil(sqrt(universe_size));
			this->clusters.reserve(cluster_size);
			this->summary = new VebTree<T>(cluster_size);

			for (int i = 0; i < cluster_size; i++) {
				VebTree<T>* cluster = new VebTree<T>(cluster_size);
				this->clusters.push_back(cluster);
			}	
		}
	}
	~VebTree() {
		if (this->universe_size <= 2) {
			return;
		}

		delete this->summary;
		long cluster_size = ceil(sqrt(universe_size));
		for (int i = 0; i < cluster_size; i++) {
			delete this->clusters[i];
		}
	}

	void insert(T val) {
		// std::cout << "summary index: " << val 
		// 	<< " high: " << high(val)
		// 	<< " low: " << low(val)
		// 	<< std::endl;

		if (this->universe_size <= 2) {
			if (!this->min_set) {
				this->min = val;
				this->max = val;
				this->min_set = 1;
				this->max_set = 1;
			}

			if (val < this->min) {
				this->max = this->min;
				this->min = val;
			}

			if (val > this->max) {
				this->min = this->max;
				this->max = val;
			}

			return;
		}

		if (!this->min_set) {
			this->min = val;
			this->max = val;
			this->min_set = 1;
			this->max_set = 1;
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

		// std::cout << "min " << this->min 
		// 	<< " max " << this->max << std::endl;

		if (!this->clusters[high(val)]->min_set) {
			this->summary->insert(high(val));
		}

		this->clusters[high(val)]->insert(low(val));
	}

	void del() {}

	T successor(T val) {
		// std::cout << "summary index: " << val 
		// 	<< " high: " << high(val)
		// 	<< " low: " << low(val)
		// 	<< std::endl;
		// std::cout << "successor, index: " << val 
		// 	<< " min: " << this->min
		// 	<< " max: " << this->max
		// 	<< std::endl;

		if (this->universe_size <= 2) {
			if (val == this->min) {
				return this->max;
			}
			else if (val == this->max) {
				return this->max;
			}
		}

		if (val < this->min) {
			return this->min;
		}

		int i = high(val);
		int j;
		if (low(val) < this->clusters[i]->max) {
			j = this->clusters[i]->successor(low(val));
		}
		else {
			i = this->summary->successor(high(val));
			j = this->clusters[i]->min;
		}

		return index(i,j);
	}

	T get(int index) {
		// std::cout << "size: " << universe_size << " looking for " << index << std::endl;
		if (this->universe_size <= 2 ) {
			if (index == this->min && this->min_set) {
				return 1;
			}
			else if (index == this->max && this->max_set) {
				return 1;
			}
			else {
				return 0;
			}
		}

		if (index == this->min) {
			return 1;
		}
		else if (index == this->max) {
			return 1;
		}
		else {
			return this->clusters[high(index)]->get(low(index));	
		}
	}

private:
	T min;
	T max;
	bool min_set;
	bool max_set;
	long universe_size;
	std::vector<VebTree<T>*> clusters;
	VebTree<T> *summary;

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
