#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Part A: the original iterator-based erase, then erase-remove.
    std::vector<int> values{1, -2, 3, -4, 3};
    for (auto it = values.begin(); it != values.end();) {
        if (*it < 0) {
            it = values.erase(it);   // erase returns the next valid iterator
        } else {
            ++it;
        }
    }
    values.erase(std::remove(values.begin(), values.end(), 3), values.end());

    std::cout << "Part A:";
    for (int n : values) std::cout << ' ' << n;
    std::cout << '\n';

    // Part B (modification): remove all even values with remove_if plus erase.
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                                 [](int n) { return n % 2 == 0; }),
                  numbers.end());

    std::cout << "Part B (odd values only):";
    for (int n : numbers) std::cout << ' ' << n;
    std::cout << '\n';

    // remove_if only moves survivors forward. erase removes the leftover tail
    // and actually reduces the vector's size.
    return 0;
}
