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

    Node *merge(Node *root_l, Node *root_r) {
        if (root_l == nullptr) {
            return root_r;
        }
        if (root_r == nullptr) {
            return root_l;
        }

        if (root_l->priority < root_r->priority) {
            root_l->right = merge(root_l->right, root_r);
            recalculate(root_l);
            return root_l;
        } else {
            root_r->left = merge(root_l, root_r->left);
            recalculate(root_r);
            return root_r;
        }

    }

    std::pair<Node *, Node *> split(Node *root, int k) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }

        if (root->key < k) {
            auto[l, r] = split(root->right, k);
            root->right = l;
            recalculate(root);
            return {root, r};
        } else {
            auto[l, r] = split(root->left, k);
            root->left = r;
            recalculate(root);
            return {l, root};
        }

    }

    Node *insert(Node *root, Node *v) {
        if (root == nullptr) {
            return v;
        }

        if (v->priority < root->priority) {
            auto[l, r] = split(root, v->key);
            v->left = l;
            v->right = r;
            recalculate(v);
            return v;
        }

        if (v->key < root->key) {
            root->left = insert(root->left, v);
        } else {
            root->right = insert(root->right, v);
        }
        recalculate(root);
        return root;

    }

    Node *remove(Node *root, int k) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->key == k) {
            return merge(root->left, root->right);
        }

        if (k < root->key) {
            root->left = remove(root->left, k);
        } else {
            root->right = remove(root->right, k);
        }

        recalculate(root);
        return root;

    }

    bool find(Node *root, int k) {
        if (root == nullptr) {
            return false;
        }

        if (root->key == k) {
            return true;
        }

        if (k < root->key) {
            return find(root->left, k);
        } else {
            return find(root->right, k);
        }
    }

    int count(Node *root, int k) {
        if (root == nullptr) {
            return 0;
        }

        if (root->key >= k) {
            return count(root->left, k);
        } else {
            return count(root->right, k) + 1 + size(root->left);
        }
    }


};




int main() {

    return 0;
}
