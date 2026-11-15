#include <forward_list>
#include <iostream>
#include <iterator>

int main() {
    std::forward_list<int> values{2, 3};
    values.insert_after(values.before_begin(), 1);   // insert at the front
    values.erase_after(values.begin());              // erase the element after 1

    for (int n : values) std::cout << n << ' ';
    std::cout << '\n';

    // forward_list has no size() in C++17. distance walks the list from begin
    // to end once, so the cost is linear in the number of elements.
    std::cout << "Element count: "
              << std::distance(values.begin(), values.end()) << '\n';
    return 0;
}
