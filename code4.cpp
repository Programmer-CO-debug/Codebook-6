#include <algorithm>
#include <iostream>
#include <list>

void printList(const std::list<int>& values, const char* label) {
    std::cout << label;
    for (int n : values) std::cout << ' ' << n;
    std::cout << '\n';
}

int main() {
    std::list<int> values{3, 1, 2};
    auto first = values.begin();
    values.insert(first, 4);
    values.sort();                       // list has its own sort; std::sort needs random access
    printList(values, "Sorted:");

    auto target = std::find(values.begin(), values.end(), 2);
    if (target != values.end()) {
        // Only the iterator to the erased node (target) becomes invalid.
        // Iterators to the other nodes stay valid.
        // erase() returns an iterator to the next element, so use that one afterward.
        auto next = values.erase(target);
        printList(values, "Remaining:");
        if (next != values.end()) {
            std::cout << "Iterator returned by erase points to: " << *next << '\n';
        }
    }
    return 0;
}
