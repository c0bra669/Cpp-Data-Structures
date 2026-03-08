#include "../bin-tree.hpp"
#include <iostream>

int main() {
    using namespace DataStructures;

    BinTree<int> tree;

    // Insert nodes using the public 2-arg insert
    tree.insert(10, LEFT);   // root will be created automatically
    tree.insert(5, LEFT);    // inserts left child of root
    tree.insert(15, RIGHT);  // inserts right child of root

    std::cout << "Tree after insertion:" << std::endl;
    tree.print();   // in-order traversal: 5 10 15

    // Optional: remove left leaf
    // tree.removeValue(5);  // if you implement remove by value

    std::cout << "\nTree after removing left leaf (if supported):" << std::endl;
    tree.print();

    std::cout << "\nTest finished." << std::endl;
    return 0;
}
