#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../bst.hpp"

int main() {
    using namespace DataStructures;

    // Test with int
    Bst<int> bst;

    // Test insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(15);
    bst.insert(30);

    assert(bst.min_value() == 5);
    assert(bst.max_value() == 30);
    std::cout << "Insert and min/max test passed.\n";

    // Test remove leaf node
    bst.remove(5);
    assert(bst.min_value() == 10);
    assert(bst.max_value() == 30);
    std::cout << "Remove leaf test passed.\n";

    // Test remove node with one child
    bst.insert(12); // 15 has one child now
    bst.remove(15);
    assert(bst.min_value() == 10);
    assert(bst.max_value() == 30);
    std::cout << "Remove node with one child test passed.\n";

    // Test remove node with two children
    bst.insert(25);
    bst.insert(35);
    bst.remove(20); // Node with two children (25,30)
    assert(bst.min_value() == 10);
    assert(bst.max_value() == 35);
    std::cout << "Remove node with two children test passed.\n";

    // Test removing non-existent value does not crash
    bst.remove(999);
    assert(bst.min_value() == 10);
    assert(bst.max_value() == 35);
    std::cout << "Remove non-existent value test passed.\n";

    // Test with double type
    Bst<double> bstDouble;
    bstDouble.insert(1.5);
    bstDouble.insert(0.5);
    bstDouble.insert(2.5);

    assert(bstDouble.min_value() == 0.5);
    assert(bstDouble.max_value() == 2.5);
    std::cout << "Template type test passed.\n";

    // Test empty tree exception handling
    Bst<int> emptyBst;
    try {
        emptyBst.min_value();
        assert(false); // Should not reach here
    } catch (const std::runtime_error&) {
        std::cout << "Empty tree min_value() throws exception as expected.\n";
    }

    try {
        emptyBst.max_value();
        assert(false); // Should not reach here
    } catch (const std::runtime_error&) {
        std::cout << "Empty tree max_value() throws exception as expected.\n";
    }

    std::cout << "All tests passed successfully.\n";
    return 0;
}
