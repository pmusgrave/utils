// #ifndef CLUSTER_HPP
// #define CLUSTER_HPP

// #include <vector>

// template<typename T>
// class Cluster {
// public:
// 	T min;
// 	T max;

// 	Cluster(long cluster_size) {
// 		this->cluster_size = cluster_size;
// 		this->data.reserve(cluster_size);

// 		for (int i = 0; i < cluster_size; i++) {
// 			bool d = 0;
// 			this->data.push_back(d);
// 		}
// 	}
// 	~Cluster() {}

// 	void insert(T val) {
// 		std::cout << "cluster index: " << val 
// 			<< " high: " << high(val)
// 			<< " low: " << low(val)
// 			<< std::endl;

// 		if (!this->min_set) {
// 			this->min = val;
// 			this->max = val;
// 			this->min_set = true;
// 			this->max_set = true;
// 		}

// 		if (val < this->min) {
// 			T temp = val;
// 			val = this->min;
// 			this->min = temp;
// 		}

// 		if (val > this->max) {
// 			this->max = val;
// 		}

// 		this->data[val] = 1;
// 	}

// 	T successor(T val) {
// 		int i = high(val);
// 		int j;
// 		if (low(val) < this->max) {
// 			j = this->data[i].successor(low(val));
// 		}
// 		else {
// 			i = this->summary.succesor(high(val));
// 			j = this->data[i].min;
// 		}

// 		return index(i,j);
// 	}

// 	T get(int index) {
// 		if (index == this->min) {
// 			return 1;
// 		}
// 		else if (index == this->max) {
// 			return 1;
// 		}
// 		else {
// 			return this->data[index];
// 		}
// 	}

// 	bool is_min_set() {
// 		return this->min_set;
// 	}

// 	bool is_max_set() {
// 		return this->max_set;
// 	}

// private:
// 	bool min_set;
// 	bool max_set;
// 	long cluster_size;
// 	std::vector<bool> data;

// 	T high(T x) {
// 		return floor(x / (int)ceil(sqrt(cluster_size)));
// 	}

// 	T low(T x) {
// 		return x % (int)ceil(sqrt(cluster_size));
// 	}

// 	T index(T i, T j) {
// 		return i* (int)ceil(sqrt(cluster_size)) + j;
// 	}
// };

// #endif