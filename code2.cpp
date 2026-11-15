#include <iostream>
#include <vector>

int main() {
    std::vector<int> values;
    values.reserve(10);

    // The standard guarantees capacity is at least the reserved amount.
    // The exact number is implementation-defined, so we test the guarantee
    // instead of printing an assumed value.
    std::cout << "Size after reserve: " << values.size() << '\n';
    std::cout << std::boolalpha;
    std::cout << "Capacity is at least 10: " << (values.capacity() >= 10) << '\n';

    values.push_back(10);
    values.push_back(20);
    values.resize(3, 30);

    std::cout << "Capacity is at least size: " << (values.capacity() >= values.size()) << '\n';

    for (int n : values) std::cout << n << ' ';
    std::cout << '\n';
    return 0;
}
