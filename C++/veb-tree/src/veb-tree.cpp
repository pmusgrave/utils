#include "veb-tree.hpp"

VebTree::VebTree(long universe_size) {
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
    this->summary = new VebTree(cluster_size);

    for (int i = 0; i < cluster_size; i++) {
      VebTree* cluster = new VebTree(cluster_size);
      this->clusters.push_back(cluster);
    }
  }
}

VebTree::~VebTree() {
  if (this->universe_size <= 2) {
    return;
  }

  delete this->summary;
  long cluster_size = ceil(sqrt(universe_size));
  for (int i = 0; i < cluster_size; i++) {
    delete this->clusters[i];
  }
}

void VebTree::insert(int val) {
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
    int temp = val;
    val = this->min;
    this->min = temp;
  }

  if (val > this->max) {
    this->max = val;
  }

  if (!this->clusters[high(val)]->min_set) {
    this->summary->insert(high(val));
  }

  this->clusters[high(val)]->insert(low(val));
}

void VebTree::del(int val) {
  		// std::cout << "size " << this->universe_size << std::endl;
		// std::cout << "deleting " << val << std::endl;
		// std::cout << "min: " << this->min << " max: " << this->max
		// 	<< " min_set: " << this->min_set << " max_set: " << this->max_set << std::endl;

		if (!this->min_set) {
			return;
		}

		int i;

		if (this->universe_size <= 2) {
			if(val == this->max && this->max != this->min) {
				this->max = this->min;
				this->max_set = this->min_set;
				return;
			}
			if (this->min_set && val == this->min) {
				this->min = 0;
				this->max = 0;
				this->min_set = false;
				this->max_set = false;
				return;
			}
		}

		if (val == this->min){
			i = this->summary->min;

			if (!this->summary->min_set) {
				this->min = 0;
				this->max = 0;
				this->min_set = false;
				this->max_set = false;
				// std::cout << i << " min_set: " << this->summary->min_set << std::endl;
				return;
			}
			// std::cout << i << " min_set: " << this->summary->min_set << std::endl;
			this->min = index(i, this->clusters[i]->min);
			val = this->min;
			// std::cout << "this->min: " << this->min << std::endl;
		}

		// std::cout << "\ndeleting from cluster " << high(val) << std::endl;
		this->clusters[high(val)]->del(low(val));

		if (!this->clusters[high(val)]->min_set) {
			// std::cout << "deleting from summary " << high(val) << std::endl;
			this->summary->del(high(val));
		}
		if (val == this->max) {
			if (!this->summary->max_set) {
				this->max = this->min;
				this->max_set = this->min_set;
			}
			else {
				i = this->summary->max;
				this->max = index(i, this->clusters[i]->max);
			}
		}

		// std::cout << "after\n";
		// std::cout << "size " << this->universe_size << std::endl;
		// std::cout << "deleting " << val << std::endl;
		// std::cout << "min: " << this->min << " max: " << this->max
		// 	<< " min_set: " << this->min_set << " max_set: " << this->max_set << std::endl;
}

int VebTree::successor(int val) {
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

int VebTree::get(int index) {
  // std::cout << "get, size: " << universe_size << " looking for " << index << std::endl;
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

  if (this->min_set && index == this->min) {
    return 1;
  }
  else if (this->max_set && index == this->max) {
    return 1;
  }
  else {
    return this->clusters[high(index)]->get(low(index));
  }
}

