#include "../array.hpp"  // your Array<T,S> header
#include <iostream>
#include <cassert>
#include <algorithm>

int main() {
    using DataStructures::Array;

    // 1️ Create arrays
    Array<int, 5> arr1;
    Array<int, 5> arr2;

    // 2️ Test indexing and assignment
    for (size_t i = 0; i < 5; ++i) {
        arr1[i] = static_cast<int>(i * 10);
        arr2[i] = static_cast<int>(i * 10);
    }

    for (size_t i = 0; i < 5; ++i) {
        assert(arr1[i] == static_cast<int>(i * 10));
        assert(arr2[i] == static_cast<int>(i * 10));
    }

    // 3️ Test size (compile-time known)
    static_assert(arr1.size() == 5, "Array size should be 5");

    // 4️ Test begin()/end() and iterator increment
    int expected = 0;
    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        assert(*it == expected);
        expected += 10;
    }

    // 5️ Test range-for loop
    expected = 0;
    for (int value : arr1) {
        assert(value == expected);
        expected += 10;
    }

    // 6️⃣ Test STL algorithm (std::sort)
    arr1[0] = 50;
    arr1[1] = 10;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 20;

    std::sort(arr1.begin(), arr1.end());
    for (int i = 0; i < 5; ++i) {
        assert(arr1[i] == (i + 1) * 10); // sorted: 10 20 30 40 50
    }

    // 7️ Test arr_cmp function (value comparison)
    // First arrays are different
    assert(!DataStructures::arr_cmp(arr1, arr2));

    // Make arr2 identical to arr1
    for (size_t i = 0; i < 5; ++i) arr2[i] = arr1[i];
    assert(DataStructures::arr_cmp(arr1, arr2)); // arrays are now equal

    // 8️ Test const iterator
    const Array<int, 5>& const_arr = arr1;
    expected = 10;
    for (auto it = const_arr.begin(); it != const_arr.end(); ++it) {
        assert(*it == expected);
        expected += 10;
    }

    // 9️ Test print function
    std::cout << "Array contents using print(): \n";
    arr1.print();
    std::cout << "\n";

    std::cout << "All tests passed successfully!\n";
    return 0;
}
