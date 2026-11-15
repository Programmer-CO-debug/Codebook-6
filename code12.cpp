#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int main() {
    std::unordered_set<int> ids{1, 2, 2};
    std::unordered_multiset<int> visits{1, 2, 2};
    std::unordered_map<std::string, int> frequency;
    for (const std::string word : {"cpp", "stl", "cpp"}) {
        ++frequency[word];
    }

    std::cout << "Unique: " << ids.size() << '\n';
    std::cout << "Visits: " << visits.count(2) << '\n';

    // Hashed containers have no guaranteed order. Copy the pairs into a
    // vector and sort them to get the same report every time.
    std::vector<std::pair<std::string, int>> report(frequency.begin(), frequency.end());
    std::sort(report.begin(), report.end(),
              [](const auto& a, const auto& b) { return a.first < b.first; });

    std::cout << "Sorted report:\n";
    for (const auto& row : report) {
        std::cout << row.first << ' ' << row.second << '\n';
    }
    return 0;
}
