//
// Created by David on 2/13/2026.
//

#ifndef PROJECT1AVLTREE_H
#define PROJECT1AVLTREE_H
#include <iostream>
#include <vector>
#include <string>

class AVLTree {
private:
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
            this->height = 1;
        }
    };
    Node* rightRotation(Node* root);
    Node* leftRotation(Node* root);
    Node* rlRotation(Node* root);
    Node* lrRotation(Node* root);
    Node* root = nullptr;
    Node* insertHelper(Node* node, std::string& name, std::string ufid);
    void preorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec);
    void inorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec);
    void postorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec);
    int levelcountHelper(Node* root);
    std::string searchidHelper(Node* node, std::string& ufid);
    void searchnameHelper(Node* node, std::string& name, std::vector<std::string>& Hvec);
    Node* removeHelper(Node* curr, std::string& ufid);
public:
    std::string insert(std::string name, std::string ufid);
    std::string remove(std::string ufid);
    std::string searchID(std::string ufid);
    std::vector<std::string>  searchN(std::string name);
    std::vector<std::pair<std::string, std::string>> printInOrder();
    std::vector<std::pair<std::string, std::string>> printPreOrder();
    std::vector<std::pair<std::string, std::string>> printPostOrder();
    int printLevelCount();
    std::string removeInorder(int N);
    bool isValid(std::string& name, std::string& ufid);


};

#endif //PROJECT1AVLTREE_H