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

    int size() {
        return size(root);
    }

    void insert(int k) {
        root = insert(root, new Node(k));
    }

    void remove(int k) {
        root = remove(root, k);
    }

    bool find(int k) {
        return find(root, k);
    }

    int count(int k) {
        return count(root, k);
    }
    int find_by_id(int id) {
        int res = find_by_id(root, id);
        if (res == std::numeric_limits<int>::min()) {
            throw std::invalid_argument("There is no element with such id");
        }
        return res;
    }


private:

    Node* root;

    void clear(Node* root) {
        if (root != nullptr) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }

    int size(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        return root->size;
    }

    void recalculate(Node *root) {
        if (root == nullptr) {
            return;
        }
        root->size = size(root->left) + size(root->right) + 1;
    }



};




int main() {

    return 0;
}
