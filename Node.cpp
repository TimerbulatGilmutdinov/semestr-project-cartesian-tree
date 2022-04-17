//
// Created by timer on 17.04.2022.
//

#include "Node.hpp"
Node(int n_key = 0) {
    key = n_key;
    left = nullptr;
    right = nullptr;
    priority = (rand() << 16) ^ rand();
    size = 1;
}