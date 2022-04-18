#include "treap.cpp"
#include <bits/stdc++.h>
using namespace std;

Treap tree;

void testCaseInsert(int k) {
    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        tree.insert(i);
    }
}

void testCaseFind(int k) {
    for (int i = 0; i < k; i++) {
        tree.find(rand() % 1000000);
    }
}

int main() {

    clock_t start = clock();
    testCaseInsert(5000000);
    cout << fixed << (double)(clock() - start) / CLOCKS_PER_SEC << '\n';
    start = clock();
    testCaseFind(10000000);
    cout << fixed << (double)(clock() - start) / CLOCKS_PER_SEC << '\n';

    return 0;
}