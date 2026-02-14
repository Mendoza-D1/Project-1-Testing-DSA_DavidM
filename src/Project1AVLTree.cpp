//
// Created by David on 2/13/2026.
//
#include "Project1AVLTree.h"
std::string AVLTree::insert(std::string name, std::string ufid) {

    // UFID must be 8 digits
    if (ufid.length() != 8) {
        return "unsuccessful";
    }

    for (char c : ufid) {
        if (!isdigit(c))
            return "unsuccessful";
    }

    // Name must be letters/spaces only
    if (name.empty()) {
        return "unsuccessful";
    }

    bool hasLetter = false;

    for (char c : name) {
        if (isalpha(c)) hasLetter = true;
        else if (c != ' ') return "unsuccessful";
    }

    if (!hasLetter) {
        return "unsuccessful";
    }

    root = insertHelper(root, name, ufid);
    return "successful";
}
Node* AVLTree::insertHelper(Node* node, std::string name, std::string ufid) {
    if (node == nullptr) {
        return new Node(name, ufid);
    }

    if (ufid < node->ufid) {
        node->left = insertHelper(node->left, name, ufid);
    } else if (ufid > node->ufid) {
        node->right = insertHelper(node->right, name, ufid);
    }
    // if equal, do nothing (but your validation already prevents duplicates)

    return node;
}
std::string AVLTree::remove(std::string name){
    return "";
}

std::vector<Node*> AVLTree::printInOrder(){
    return {};
}

int AVLTree::printLevelCount(){
    return 0;
}

std::string AVLTree::removeInorder(int N){
    return "";
}





