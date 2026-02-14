//
// Created by David on 2/13/2026.
//

#ifndef PROJECT1AVLTREE_H
#define PROJECT1AVLTREE_H
#include <iostream>
#include <vector>
#include <string>

struct Node {
    std::string name;
    std::string ufid;
    Node* left;
    Node* right;
    int height;

    Node(std::string name, std::string ufid) {
        this->name = name;
        this->ufid = ufid;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    }
};

class AVLTree {
private:
    Node* root = nullptr;
    Node* insertHelper(Node* node, std::string name, std::string ufid);
public:
    std::string insert(std::string name, std::string ufid);
    std::string remove(std::string name);
    std::string searchID(std::string ufid);
    std::string searchN(std::string name);
    std::vector<Node*> printInOrder();
    std::vector<Node*> printPreOrder();
    std::vector<Node*> printPostOrder();
    int printLevelCount();
    std::string removeInorder(int N);


};

#endif //PROJECT1AVLTREE_H