#ifndef VEB_TREE_HPP
#define VEB_TREE_HPP

#include <vector>
#include <cmath>
#include <iostream>

class VebTree {
public:
	VebTree(long universe_size);
	~VebTree();

	void insert(int val);
	void del(int val);
  int successor(int val);
	int get(int index);

private:
	int min;
	int max;
	bool min_set;
	bool max_set;
	long universe_size;
	std::vector<VebTree*> clusters;
	VebTree *summary;

	int high(int x) {
		return floor(x / (int)ceil(sqrt(universe_size)));
	}

	int low(int x) {
		return x % (int)ceil(sqrt(universe_size));
	}

	int index(int i, int j) {
		return i* (int)ceil(sqrt(universe_size)) + j;
	}
};

#endif
