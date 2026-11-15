#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> values{10, 20, 30};

    // Forward traversal: [cbegin, cend) is a half-open range.
    for (auto it = values.cbegin(); it != values.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Reverse traversal: crbegin starts at the last element, crend is before the first.
    for (auto it = values.crbegin(); it != values.crend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    auto second = values.begin();
    std::advance(second, 1);
    std::cout << "Second: " << *second << '\n';
    return 0;
}
