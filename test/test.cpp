#include <catch2/catch_test_macros.hpp>
#include <iostream>

// David Mendoza UFID:90071145
#include <algorithm>
#include "Project1AVLTree.h"

TEST_CASE("Invalid input commands that will fail"){
	AVLTree t;

	REQUIRE(t.insert("A11y", "45679999") == "unsuccessful");
	REQUIRE(t.insert("Derek", "4567") == "unsuccessful");
	REQUIRE(t.insert("David", "4567ABCD") == "unsuccessful");
	REQUIRE(t.insert("", "45671234") == "unsuccessful");
	REQUIRE(t.insert("Ally", "456799991") == "unsuccessful");
}
TEST_CASE("Left rotation") {
	AVLTree t;
	REQUIRE(t.insert("A", "00000010") == "successful");
	REQUIRE(t.insert("B", "00000020") == "successful");
	REQUIRE(t.insert("C", "00000030") == "successful");

	std::vector<std::pair<std::string, std::string>> res = t.printPostOrder();
	std::cout << t.printLevelCount();
	// REQUIRE(res[0].second == "00000010");
	// REQUIRE(res[1].second == "00000020");
	// REQUIRE(res[2].second == "00000030");
	std::cout << res[0].second << res[1].second << res[2].second << std::endl;

}

// TEST_CASE("Right rotation") {
// 	AVLTree t;
// 	REQUIRE(t.insert("A", "00000030") == "successful");
// 	REQUIRE(t.insert("B", "00000020") == "successful");
// 	REQUIRE(t.insert("C", "00000010") == "successful");
//
// 	std::vector<std::pair<std::string, std::string>> res = t.printInOrder();
// 	REQUIRE(t.printLevelCount() == 2);
// 	REQUIRE(res[0]->ufid == "00000010");
// 	REQUIRE(res[1]->ufid == "00000020");
// 	REQUIRE(res[2]->ufid == "00000030");
// }
//
// TEST_CASE("Right Left rotation") {
// 	AVLTree t;
// 	REQUIRE(t.insert("A", "00000010") == "successful");
// 	REQUIRE(t.insert("B", "00000030") == "successful");
// 	REQUIRE(t.insert("C", "00000020") == "successful");
//
// 	std::vector<std::pair<std::string, std::string>> res = t.printInOrder();
// 	REQUIRE(t.printLevelCount() == 2);
// 	REQUIRE(res[0]->ufid == "00000010");
// 	REQUIRE(res[1]->ufid == "00000020");
// 	REQUIRE(res[2]->ufid == "00000030");
// }
//
// TEST_CASE("Left Right rotation") {
// 	AVLTree t;
// 	REQUIRE(t.insert("A", "00000030") == "successful");
// 	REQUIRE(t.insert("B", "00000010") == "successful");
// 	REQUIRE(t.insert("C", "00000020") == "successful");
//
// 	std::vector<std::pair<std::string, std::string>> res = t.printInOrder();
// 	REQUIRE(t.printLevelCount() == 2);
// 	REQUIRE(res[0]->ufid == "00000010");
// 	REQUIRE(res[1]->ufid == "00000020");
// 	REQUIRE(res[2]->ufid == "00000030");
// }
//
// TEST_CASE("Insert 100 nodes in bulk and then remove 10 random nodes in order") {
// 	AVLTree t;
//
// 	for (int i = 0; i < 100; i++) {
// 		REQUIRE(t.insert("N", std::to_string(i))== "successful");
// 	}
//
// 	std::vector<AVLTree::Node*> resBefore = t.printInOrder();
// 	REQUIRE(resBefore.size() == 100);
//
// 	std::vector<int> random = {2,52,16,17,72,89,4,12,31,58};
//
// 	std::vector<std::string> removeUFIDs;
// 	removeUFIDs.reserve(random.size());
// 	for (int i = 0; i < 10; i++){
// 		removeUFIDs.push_back(resBefore[i]->ufid);
// 	}
//
// 	std::sort(removeUFIDs.begin(), removeUFIDs.end());
// 	for (int i = 0; i < 10; i++) {
// 		REQUIRE(t.removeInorder(i) == "Successful");
// 	}
//
// 	std::vector<AVLTree::Node*> resAfter = t.printInOrder();
// 	REQUIRE(resAfter.size() == 90);
//
// 	for (size_t i = 0; i < resAfter.size(); i++) {
// 		REQUIRE(resAfter[i-1]->ufid < resAfter[i]->ufid);
// 	}
//
// }
//
