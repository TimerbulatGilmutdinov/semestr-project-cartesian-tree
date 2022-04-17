#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int key;
    int priority;
    int size; // Размер поддерева

    Node(int n_key = 0) {
        key = n_key;
        left = nullptr;
        right = nullptr;
        priority = (rand() << 16) ^ rand();
        size = 1;
    }
};
struct Treap {

public:

    Treap() {
        root = nullptr;
    }

    ~Treap() {
        clear();
        root = nullptr;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }



private:

    Node *root;

    void clear(Node *root) {
        if (root != nullptr) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }



};




int main() {

    return 0;
}
