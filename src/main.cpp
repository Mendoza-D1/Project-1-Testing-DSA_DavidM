#include <iostream>
#include <sstream>
#include "Project1AVLTree.h"
using namespace std;

int main() {
    AVLTree tree;

    int commands = 0;
    cin >> commands;
    cin.ignore(); // consume newline after number

    for (int i = 0; i < commands; i++) {
        string line;
        getline(cin, line);

        istringstream in(line);
        string command;
        in >> command;

        if (command == "insert") {
            // insert "Name Here" 12345678
            string name, ufid;
            getline(in >> ws, name, '"');   // read up to first quote
            getline(in, name, '"');         // read the name inside quotes
            in >> ufid;                     // read ufid after name

            cout << tree.insert(name, ufid) << endl;
        }
        else if (command == "remove") {
            string id;
            in >> id;
            cout << tree.remove(id) << endl;
        }
        else if (command == "search") {
            // search "Name"  OR  search 12345678
            string rest;
            getline(in >> ws, rest);

            if (!rest.empty() && rest.front() == '"') {
                // Name search
                istringstream nameStream(rest);
                string name;
                getline(nameStream, name, '"'); // consume first quote
                getline(nameStream, name, '"'); // actual name

                auto results = tree.searchN(name);
                for (const string& item : results) {
                    cout << item << endl;
                }
            } else {
                // ID search (rest may include spaces; trim via stream)
                istringstream idStream(rest);
                string id;
                idStream >> id;
                cout << tree.searchID(id) << endl;
            }
        }
        else if (command == "printInorder") {
            auto vec = tree.printInOrder();
            for (size_t j = 0; j < vec.size(); j++) {
                cout << vec[j].first;
                if (j + 1 < vec.size()) cout << ", ";
            }
            cout << endl;
        }
        else if (command == "printPreorder") {
            auto vec = tree.printPreOrder();
            for (size_t j = 0; j < vec.size(); j++) {
                cout << vec[j].first;
                if (j + 1 < vec.size()) cout << ", ";
            }
            cout << endl;
        }
        else if (command == "printPostorder") {
            auto vec = tree.printPostOrder();
            for (size_t j = 0; j < vec.size(); j++) {
                cout << vec[j].first;
                if (j + 1 < vec.size()) cout << ", ";
            }
            cout << endl;
        }
        else if (command == "printLevelCount") {
            cout << tree.printLevelCount() << endl;
        }
        else if (command == "removeInorder") {
            int n;
            in >> n;
            cout << tree.removeInorder(n) << endl;
        }
    }

    return 0;
}
