//
// Created by timer on 17.04.2022.
//

#ifndef CARTESIANTREE_NODE_HPP
#define CARTESIANTREE_NODE_HPP


#include <cstdlib>

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


#endif //CARTESIANTREE_NODE_HPP
