# **CppDataStructures** is a hobby project in early development. It provides basic C++ data structures. **Not recommended for production use.**

---

## Available Data Structures

- `Array<T, S>` — Fixed-size array with STL-compatible iterators.
- `Bst<T>` — Simple templated binary search tree with insert, remove, min/max operations.

---
# Usage
You can build and use the library in two ways:

## 1️⃣ Using CMake
```bash
# From project root
mkdir build
cd build
cmake ..
cmake --build . 
```
### This generates shared library and test executables
./array_test
./bst_test
## 2️⃣ Manual Compilation (g++)
```bash
#Compile shared library
g++ -std=c++17 -fPIC -shared datastructures.cpp -o libcppdatastructures.so
```

### Compile tests
```bash
g++ -std=c++17 tests/array_test.cpp -I. -L. -lcppdatastructures -o array_test
g++ -std=c++17 tests/bst_test.cpp -I. -L. -lcppdatastructures -o bst_test
```
### Run tests
```bash
./array_test
./bst_test
```

---
## Examples
### Array
```cpp
#include "array.hpp"
#include <algorithm>
#include <iostream>

int main() {
    Array<int, 5> arr;
    for (int i = 0; i < 5; ++i) arr[i] = (i + 1) * 10;

    // Iterate
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';

    // STL algorithm works
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    arr.print(); // prints sorted array in descending order
}
```
### BST
```cpp
#include "bst.hpp"
#include <iostream>

int main() {
    Bst<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);

    std::cout << "Min: " << bst.min_value() << ", Max: " << bst.max_value() << '\n';

    bst.remove(10);
    bst.print(); // prints remaining tree
}
```
