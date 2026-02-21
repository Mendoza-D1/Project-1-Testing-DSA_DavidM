//
// Created by David on 2/13/2026.
//
#include "Project1AVLTree.h"
std::string AVLTree::insert(std::string& name, std::string& ufid) {
    if (!isValid(name, ufid)) {
        return "unsuccessful";
    }
    root = insertHelper(root, name, ufid);
    return "successful";
}
AVLTree::Node* AVLTree::leftRotation(Node *root) {
    Node* oneT = root->right->left;
    Node* twoT = root->right;
    twoT->left = root;
    root->right = oneT;
    root->height -= 2;
    twoT->height +=1;
    return twoT;
}

AVLTree::Node* AVLTree::rightRotation(Node *root) {
    Node* oneT = root->left->right;
    Node* twoT = root->left;
    twoT->right = root;
    root->left = oneT;
    root->height -= 2;
    twoT->height +=1;
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

AVLTree::Node* AVLTree::insertHelper(Node* node, std::string& name, std::string& ufid) {
    if (node == nullptr) {
        return new Node(name, ufid);
    }

    if (stoi(ufid) < stoi(node->ufid)) {
        node->left = insertHelper(node->left, name, ufid);
    } else if (stoi(ufid) > stoi(node->ufid)) {
        node->right = insertHelper(node->right, name, ufid);
    }

    node->height = 1 + std::max(node->left ? node->left->height:0, node->right ? node->right->height : 0);

    int balance = (node->left ? node->left->height : 0) - (node->right ? node->right->height : 0);
    if (balance >= 2) {
        int leftBal = (node->left->left ? node->left->left->height:0) - (node->left->right ? node->left->right->height:0);
        if (leftBal == 1){ //leftHeavy
            node= rightRotation(node);

        }
        else {
            node= lrRotation(node);
        }
    }
    else if (balance <= -2) { //rightHeavy
        int rightBal = (node->right->left ? node->right->left->height:0) - (node->right->right ? node->right->right->height:0);
        if (rightBal == -1) {
            node = leftRotation(node);
        }
        else {
            node = rlRotation(node);
        }
    }

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

AVLTree::Node* AVLTree::removeHelper(Node* curr, std::string& ufid){
    if (curr == nullptr) {
        return curr;
    }
    int Ids = stoi(ufid);
    if (Ids < stoi(curr->ufid)){
        curr->left = removeHelper(curr->left, ufid);
    }
    else if (Ids > stoi(curr->ufid)) {
        curr->right = removeHelper(curr->right, ufid);
    }
    else {
        if (curr->left == nullptr && curr->right == nullptr) {
            delete curr;
            return nullptr;
        }
        if ((curr->right == nullptr) != (curr->left == nullptr)) {
            if (curr->left) {
                Node* PH = curr->left;
                delete curr;
                return PH;
            }
            else {
                Node* PH = curr->right;
                delete curr;
                return PH;
            }
        }
        if (curr->left && curr->right) {
            Node* successor = curr->right;
            while(successor->left){
                successor = successor->left;
            }
            curr->name = successor->name; //swap values inside of curr into the inorder successor
            curr->ufid = successor->ufid;
            curr->right = removeHelper(curr->right, curr->ufid);

        }

    }

    return curr;
}

std::string AVLTree::remove(std::string& ufid){
    if (searchidHelper(root, ufid) == "unsuccessful") {
        return "unsuccessful";
    };
    Node* newCurr = removeHelper(root, ufid);
    if (searchidHelper(newCurr, ufid) == "unsuccessful") {
        return "successful";
    }
    return "unsuccessful";
}

std::string AVLTree::searchidHelper(Node* node, std::string& ufid) {
    if (node == nullptr) {
        return "unsuccessful";
    }
    if (node->ufid == ufid) {
        return node->name;
    }
    if (stoi(ufid) < stoi(node->ufid)) {
        return searchidHelper(node->left, ufid);
    } else if (stoi(ufid) > stoi(node->ufid)) {
        return searchidHelper(node->right, ufid);
    }
    return "successful";
}
std::string AVLTree::searchID(std::string& ufid) {
    std::string res = searchidHelper(root, ufid);
    return res;
}

void AVLTree::searchnameHelper(Node* node, std::string& name, std::vector<std::string>& Hvec) {
    if (node == nullptr) {
        return;
    }
    if (node->name == name) {
        Hvec.push_back(node->ufid);
    }
    searchnameHelper(node->left, name, Hvec);
    searchnameHelper(node->right, name, Hvec);
}

std::vector<std::string> AVLTree::searchN(std::string& name) {
    std::vector<std::string> ufids;
    searchnameHelper(root, name, ufids);
    if (ufids.empty()) {
        std::cout << "unsuccessful" << std::endl;
    }
    return ufids;
}


int AVLTree::levelcountHelper(Node* node) {
    if (node == nullptr) return 0;
    int leftLevels = levelcountHelper(node->left);
    int rightLevels = levelcountHelper(node->right);
    return 1 + std::max(leftLevels, rightLevels);
}

int AVLTree::printLevelCount(){
    return levelcountHelper(root);
}

std::string AVLTree::removeInorder(int N){
    std::vector<std::pair<std::string, std::string>> Hvec = printInOrder();
    std::string eliminate = Hvec[N].second;
    return remove(eliminate);
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

void AVLTree::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

AVLTree::~AVLTree() {
    deleteTree(root);
}






