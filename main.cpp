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

void testCaseRemove(int k){
    for (int i = 0; i < k; i++) {
        tree.remove(rand()%1000000);
    }
}

int main() {
    int n = 5000000; //число повторений операции

    Treap tree;
    for (int j = 0; j < 100; ++j) {


        auto start_time = std::chrono::steady_clock::now();
        for (int i = 0; i < n; i++) {
            tree.insert(rand());
        }
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        std::cout << elapsed_ns.count() /n<< "\n"; //вывод времени в наносекундах на 1 операцию insert
        start_time = std::chrono::steady_clock::now();
        for (int i = 0; i < n; i++) {
            tree.find(rand());
        }
        end_time = std::chrono::steady_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        std::cout << elapsed_ns.count() /n<< "\n"; // вывод времени в наносекундах на 1 операцию find
        start_time = std::chrono::steady_clock::now();
        for (int i = 0; i < n; i++) {
            tree.remove(rand());
        }
        end_time = std::chrono::steady_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        std::cout << elapsed_ns.count() /n<< " \n"; //вывод времени в наносекундах на 1 операцию remove
        tree.clear();
    }

    return 0;
}