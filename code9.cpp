#include <iostream>
#include <set>

int main() {
    std::set<int> ids{3, 1, 3, 2};          // duplicates are discarded
    std::cout << "Unique ids: ";
    for (int n : ids) std::cout << n << ' ';
    std::cout << '\n';

    std::multiset<int> visits{3, 1, 3, 2, 3};
    std::cout << "Visits to 3 before: " << visits.count(3) << '\n';

    // Erase by iterator: removes exactly one element.
    auto it = visits.find(3);
    if (it != visits.end()) {
        visits.erase(it);
    }
    std::cout << "After iterator erase: " << visits.count(3) << '\n';

    // Erase by key: removes every element equal to 3.
    std::size_t removed = visits.erase(3);
    std::cout << "Removed by key: " << removed << '\n';
    std::cout << "After key erase: " << visits.count(3) << '\n';
    return 0;
}
