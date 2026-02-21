// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
//
// // David Mendoza UFID:90071145
// #include <algorithm>
// #include "Project1AVLTree.h"
//
// TEST_CASE("Invalid input commands that will fail", "[flag]") {
//     AVLTree t;
//
//     std::string name1 = "A11y";
//     std::string id1   = "45679999";
//     REQUIRE(t.insert(name1, id1) == "unsuccessful");
//
//     std::string name2 = "Derek";
//     std::string id2   = "4567";
//     REQUIRE(t.insert(name2, id2) == "unsuccessful");
//
//     std::string name3 = "David";
//     std::string id3   = "4567ABCD";
//     REQUIRE(t.insert(name3, id3) == "unsuccessful");
//
//     std::string name4 = "";
//     std::string id4   = "45671234";
//     REQUIRE(t.insert(name4, id4) == "unsuccessful");
//
//     std::string name5 = "        ";
//     std::string id5   = "45679999";
//     REQUIRE(t.insert(name5, id5) == "unsuccessful");
//
//     std::string name6 = "David";
//     std::string id6   = "45679999";
//     REQUIRE(t.insert(name6, id6) == "successful"); // checking for correct input
// }
//
// TEST_CASE("Searching for missing UFID", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "Ally"; std::string u1 = "10000001";
//     std::string n2 = "Ally"; std::string u2 = "10000002";
//     std::string n3 = "Ally"; std::string u3 = "10000003";
//     REQUIRE(t.insert(n1, u1) == "successful");
//     REQUIRE(t.insert(n2, u2) == "successful");
//     REQUIRE(t.insert(n3, u3) == "successful");
//
//     std::string missing = "10000004";
//     REQUIRE(t.searchID(missing) == "unsuccessful");
// }
//
// TEST_CASE("Searching for missing Name", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "Ally"; std::string u1 = "10000001";
//     std::string n2 = "Ally"; std::string u2 = "10000002";
//     std::string n3 = "Ally"; std::string u3 = "10000003";
//     REQUIRE(t.insert(n1, u1) == "successful");
//     REQUIRE(t.insert(n2, u2) == "successful");
//     REQUIRE(t.insert(n3, u3) == "successful");
//
//     std::string missingName = "Dillon";
//     auto res = t.searchN(missingName);
//     REQUIRE(res.empty());
// }
//
// TEST_CASE("Removing a node that does not exist", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "Ally"; std::string u1 = "10000001";
//     std::string n2 = "Ally"; std::string u2 = "10000002";
//     std::string n3 = "Ally"; std::string u3 = "10000003";
//     REQUIRE(t.insert(n1, u1) == "successful");
//     REQUIRE(t.insert(n2, u2) == "successful");
//     REQUIRE(t.insert(n3, u3) == "successful");
//
//     std::string missing = "10000004";
//     REQUIRE(t.remove(missing) == "unsuccessful");
// }
//
// TEST_CASE("LeftLeft case leads to right rotate", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "30000000";
//     std::string n2 = "B"; std::string u2 = "20000000";
//     std::string n3 = "C"; std::string u3 = "10000000";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     auto pre = t.printPreOrder();
//     REQUIRE(pre.size() == 3);
//     REQUIRE(pre[0].second == "20000000");
//     REQUIRE(pre[1].second == "10000000");
//     REQUIRE(pre[2].second == "30000000");
// }
//
// TEST_CASE("RightRight case leads to a left rotate", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "00000001";
//     std::string n2 = "B"; std::string u2 = "00000002";
//     std::string n3 = "C"; std::string u3 = "00000003";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     auto pre = t.printPreOrder();
//     REQUIRE(pre.size() == 3);
//     REQUIRE(pre[0].second == "00000002");
//     REQUIRE(pre[1].second == "00000001");
//     REQUIRE(pre[2].second == "00000003");
// }
//
// TEST_CASE("LeftRight case leads to a left-right rotate", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "30000000";
//     std::string n2 = "B"; std::string u2 = "10000000";
//     std::string n3 = "C"; std::string u3 = "20000000";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     auto pre = t.printPreOrder();
//     REQUIRE(pre.size() == 3);
//     REQUIRE(pre[0].second == "20000000");
//     REQUIRE(pre[1].second == "10000000");
//     REQUIRE(pre[2].second == "30000000");
// }
//
// TEST_CASE("RightLeft case leads to a right-left rotate", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "00000001";
//     std::string n2 = "B"; std::string u2 = "00000003";
//     std::string n3 = "C"; std::string u3 = "00000002";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     auto pre = t.printPreOrder();
//     REQUIRE(pre.size() == 3);
//     REQUIRE(pre[0].second == "00000002");
//     REQUIRE(pre[1].second == "00000001");
//     REQUIRE(pre[2].second == "00000003");
// }
//
// TEST_CASE("Delete leaf node (no children)", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "20000000";
//     std::string n2 = "B"; std::string u2 = "10000000";
//     std::string n3 = "C"; std::string u3 = "30000000";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     std::string del = "10000000";
//     REQUIRE(t.remove(del) == "successful");
//
//     auto in = t.printInOrder();
//     // you can add checks here if you want, but leaving minimal like your original
// }
//
// TEST_CASE("Delete node with one child", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "20000000";
//     std::string n2 = "B"; std::string u2 = "30000000";
//     std::string n3 = "C"; std::string u3 = "40000000";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//
//     std::string del = "30000000";
//     t.remove(del);
//
//     auto in = t.printInOrder();
//
//     bool found30 = false, found20 = false, found40 = false;
//     for (auto &p : in) {
//         if (p.second == "30000000") found30 = true;
//         if (p.second == "20000000") found20 = true;
//         if (p.second == "40000000") found40 = true;
//     }
//     REQUIRE(found30 == false);
//     REQUIRE(found20 == true);
//     REQUIRE(found40 == true);
//
//     for (size_t i = 1; i < in.size(); i++) {
//         REQUIRE(in[i - 1].second <= in[i].second);
//     }
// }
//
// TEST_CASE("Delete node with two children", "[flag]") {
//     AVLTree t;
//
//     std::string n1 = "A"; std::string u1 = "20000000";
//     std::string n2 = "B"; std::string u2 = "10000000";
//     std::string n3 = "C"; std::string u3 = "30000000";
//     std::string n4 = "D"; std::string u4 = "25000000";
//     std::string n5 = "E"; std::string u5 = "35000000";
//     t.insert(n1, u1);
//     t.insert(n2, u2);
//     t.insert(n3, u3);
//     t.insert(n4, u4);
//     t.insert(n5, u5);
//
//     std::string del = "20000000";
//     t.remove(del);
//
//     auto in = t.printInOrder();
//
//     bool found20 = false;
//     bool found10 = false, found25 = false, found30 = false, found35 = false;
//
//     for (auto &p : in) {
//         if (p.second == "20000000") found20 = true;
//         if (p.second == "10000000") found10 = true;
//         if (p.second == "25000000") found25 = true;
//         if (p.second == "30000000") found30 = true;
//         if (p.second == "35000000") found35 = true;
//     }
//
//     REQUIRE(found20 == false);
//     REQUIRE(found10 == true);
//     REQUIRE(found25 == true);
//     REQUIRE(found30 == true);
//     REQUIRE(found35 == true);
//
//     for (size_t i = 1; i < in.size(); i++) {
//         REQUIRE(in[i - 1].second <= in[i].second);
//     }
// }
//
// TEST_CASE("Bulk: insert 100 nodes, remove 10, verify inorder size is 90 and sorted", "[flag]") {
//     AVLTree t;
//     std::vector<std::string> vec;
//
//     for (int i = 0; i < 100; i++) {
//         std::string ufid = std::to_string(10000000 + i); // 8 digits
//         std::string name = "Smegma";
//         REQUIRE(t.insert(name, ufid) == "successful");
//         vec.push_back(ufid);
//
//     }
//
//     auto Before = t.printInOrder();
//     REQUIRE(Before.size() == 100);
//
//
//     std::vector<std::string> toRemove = {
//         "10000003","10000007","10000012","10000019","10000023",
//         "10000031","10000044","10000058","10000076","10000099"
//     };
//
//     for (auto id : toRemove) {
//         t.remove(id);
//         vec.erase(std::remove(vec.begin(), vec.end(), id), vec.end());
//     }
//
//     auto After = t.printInOrder();
//     REQUIRE(After.size() == 90);
//
//     for (size_t i = 0; i < 90; i++) {
//         REQUIRE(After[i].second == vec[i]);
//     }
//
// }
//
//
//
//
//
