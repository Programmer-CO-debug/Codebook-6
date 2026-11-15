#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> values{40, 10, 30, 20, 20};
    std::sort(values.begin(), values.end());   // binary search requires sorted input

    auto found = std::find(values.begin(), values.end(), 30);
    if (found != values.end()) {
        std::cout << "Found: " << *found << '\n';
    }

    std::cout << "Present (20): " << std::binary_search(values.begin(), values.end(), 20) << '\n';

    auto range = std::equal_range(values.begin(), values.end(), 20);
    std::cout << "Matches: " << (range.second - range.first) << '\n';

    // Absent value 25: binary_search reports false.
    std::cout << "Present (25): " << std::binary_search(values.begin(), values.end(), 25) << '\n';

    // lower_bound returns the first position where 25 could be inserted
    // without breaking the sorted order. Here that position is the element 30.
    auto position = std::lower_bound(values.begin(), values.end(), 25);
    std::cout << "Insertion index for 25: "
              << std::distance(values.begin(), position) << '\n';
    return 0;
}
