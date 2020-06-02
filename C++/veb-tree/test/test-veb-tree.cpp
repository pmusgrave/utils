#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <cmath>
#include "veb-tree.hpp"

using namespace std;

TEST_CASE("initialization", "[veb-tree]"){
	VebTree<int> test_veb_tree(1);
	// VebTree<int> test_veb_tree_2(pow(2, 32));
	REQUIRE(1 == 1);
}

TEST_CASE("inserting into van Emde Boas tree", "[veb-tree]"){
	VebTree<int> test_veb_tree(16);

	REQUIRE(test_veb_tree.get(2) == 0);
	test_veb_tree.insert(2);
	REQUIRE(test_veb_tree.get(2) == 1);
	test_veb_tree.insert(3);
	REQUIRE(test_veb_tree.get(1) == 0);
	REQUIRE(test_veb_tree.get(3) == 1);
}

TEST_CASE("finding successor", "[veb-tree]") {
	// VebTree<int> test_veb_tree(16);

	// test_veb_tree.insert(2);
	// test_veb_tree.insert(3);

	// REQUIRE(test_veb_tree.successor(2) == 3);		
}