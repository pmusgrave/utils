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
	VebTree<int> test_veb_tree(16);

	test_veb_tree.insert(2);
	test_veb_tree.insert(5);
	test_veb_tree.insert(3);
	test_veb_tree.insert(8);
	test_veb_tree.insert(1);
	test_veb_tree.insert(7);

	REQUIRE(test_veb_tree.successor(1) == 2);
	REQUIRE(test_veb_tree.successor(2) == 3);
	REQUIRE(test_veb_tree.successor(3) == 5);
	REQUIRE(test_veb_tree.successor(5) == 7);
	REQUIRE(test_veb_tree.successor(7) == 8);
}

TEST_CASE("deleting", "[veb-tree]") {
	VebTree<int> test_veb_tree(16);

	test_veb_tree.insert(2);
	test_veb_tree.insert(5);
	test_veb_tree.insert(3);
	test_veb_tree.insert(8);
	test_veb_tree.insert(1);
	test_veb_tree.insert(7);

	REQUIRE(test_veb_tree.get(1) == 1);
	REQUIRE(test_veb_tree.get(2) == 1);
	REQUIRE(test_veb_tree.get(3) == 1);
	REQUIRE(test_veb_tree.get(5) == 1);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 1);
	test_veb_tree.del(8);
	REQUIRE(test_veb_tree.get(1) == 1);
	REQUIRE(test_veb_tree.get(2) == 1);
	REQUIRE(test_veb_tree.get(3) == 1);
	REQUIRE(test_veb_tree.get(5) == 1);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 0);
	test_veb_tree.del(2);
	REQUIRE(test_veb_tree.get(1) == 1);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 1);
	REQUIRE(test_veb_tree.get(5) == 1);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 0);
	test_veb_tree.del(5);
	REQUIRE(test_veb_tree.get(1) == 1);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 1);
	REQUIRE(test_veb_tree.get(5) == 0);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 0);
	test_veb_tree.del(1);
	REQUIRE(test_veb_tree.get(1) == 0);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 1);
	REQUIRE(test_veb_tree.get(5) == 0);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 0);
	test_veb_tree.del(3);
	REQUIRE(test_veb_tree.get(1) == 0);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 0);
	REQUIRE(test_veb_tree.get(5) == 0);
	REQUIRE(test_veb_tree.get(7) == 1);
	REQUIRE(test_veb_tree.get(8) == 0);
	test_veb_tree.del(7);
	REQUIRE(test_veb_tree.get(1) == 0);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 0);
	REQUIRE(test_veb_tree.get(5) == 0);
	REQUIRE(test_veb_tree.get(7) == 0);
	REQUIRE(test_veb_tree.get(8) == 0);
	
	// test deleting a value from an empty tree
	test_veb_tree.del(3);
	REQUIRE(test_veb_tree.get(1) == 0);
	REQUIRE(test_veb_tree.get(2) == 0);
	REQUIRE(test_veb_tree.get(3) == 0);
	REQUIRE(test_veb_tree.get(5) == 0);
	REQUIRE(test_veb_tree.get(7) == 0);
	REQUIRE(test_veb_tree.get(8) == 0);
}
