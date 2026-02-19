//
// Created by David on 2/13/2026.
//
#include "Project1AVLTree.h"
std::string AVLTree::insert(std::string name, std::string ufid) {
    if (!isValid(name, ufid)) {
        return "unsuccessful";
    }

    root = insertHelper(root, name, ufid);
    int balance = (root->left ? root->left->height : 0) - (root->right ? root->right->height : 0);
    if (balance >= 2) {
        int leftBal = (root->left->left ? root->left->left->height:0) - (root->left->right ? root->left->right->height:0);
        if (leftBal == 1){ //leftHeavy
            root= rightRotation(root);
        }
        else {
            root= lrRotation(root);
        }
    }
    else if (balance <= -2) { //rightHeavy
        int rightBal = (root->right->left ? root->right->left->height:0) - (root->right->right ? root->right->right->height:0);
        if (rightBal == -1) {
            root = leftRotation(root);
        }
        else {
            root = rlRotation(root);
        }
    }

    return "successful";
}
AVLTree::Node* AVLTree::leftRotation(Node *root) {
    Node* oneT = root->right->left;
    Node* twoT = root->right;
    twoT->left = root;
    root->right = oneT;
    return twoT;
}

AVLTree::Node* AVLTree::rightRotation(Node *root) {
    Node* oneT = root->left->right;
    Node* twoT = root->left;
    twoT->right = root;
    root->left = oneT;
    return twoT;
}

AVLTree::Node* AVLTree::lrRotation(Node* root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

AVLTree::Node* AVLTree::rlRotation(Node* root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

AVLTree::Node* AVLTree::insertHelper(Node* node, std::string& name, std::string ufid) {
    if (node == nullptr) {
        return new Node(name, ufid);
    }

    if (stoi(ufid) < stoi(node->ufid)) {
        node->left = insertHelper(node->left, name, ufid);
    } else if (stoi(ufid) > stoi(node->ufid)) {
        node->right = insertHelper(node->right, name, ufid);
    }

    node->height = 1 + std::max(node->left ? node->left->height:0, node->right ? node->right->height : 0);
    return node;
}

void AVLTree::preorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec) {
    if (curr == nullptr) {
        return;
    }
    Hvec.push_back(make_pair(curr->name, curr->ufid));
    preorderHelper(curr->left, Hvec);
    preorderHelper(curr->right, Hvec);
}

std::vector<std::pair<std::string, std::string>> AVLTree::printPreOrder() {
    std::vector<std::pair<std::string, std::string>> returnVec;
    preorderHelper(root, returnVec);
    return returnVec;
}
void AVLTree::inorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec) {
    if (curr == nullptr) {
        return;
    }
    inorderHelper(curr->left, Hvec);
    Hvec.push_back(make_pair(curr->name, curr->ufid));
    inorderHelper(curr->right, Hvec);
}

std::vector<std::pair<std::string, std::string>> AVLTree::printInOrder() {
    std::vector<std::pair<std::string, std::string>> returnVec;
    inorderHelper(root, returnVec);
    return returnVec;
}
void AVLTree::postorderHelper(Node* curr, std::vector<std::pair<std::string, std::string>>& Hvec) {
    if (curr == nullptr) {
        return;
    }
    postorderHelper(curr->left, Hvec);
    postorderHelper(curr->right, Hvec);
    Hvec.push_back(make_pair(curr->name, curr->ufid));
}

std::vector<std::pair<std::string, std::string>> AVLTree::printPostOrder() {
    std::vector<std::pair<std::string, std::string>> returnVec;
    postorderHelper(root, returnVec);
    return returnVec;
}

std::string AVLTree::remove(std::string name){
    return "";
}
std::string searchID(std::string ufid) {
return "";
}

int AVLTree::levelcountHelper(Node *root) {
    return root->height;
}

int AVLTree::printLevelCount(){
    return levelcountHelper(root);
}

std::string AVLTree::removeInorder(int N){
    return "";
}

bool AVLTree::isValid(std::string& name, std::string& ufid){
    // UFID must be 8 digits
    if (ufid.length() != 8) {
        return false;
    }

    for (char c : ufid) {
        if (!isdigit(c))
            return false;
    }

    // Name must be letters/spaces only
    if (name.empty()) {
        return false;
    }

    bool hasLetter = false;

    for (char c : name) {
        if (isalpha(c)) hasLetter = true;
        else if (c != ' ') return false;
    }

    if (!hasLetter) {
        return false;
    }
    return true;
}




