#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> enrollment;
    enrollment.emplace("CPP", "Amit");
    enrollment.emplace("CPP", "Neha");
    enrollment.emplace("AI", "Ravi");

    for (const std::string course : {"CPP", "ML"}) {
        auto range = enrollment.equal_range(course);

        // If first == second, the range is empty and the loop below runs zero times.
        if (range.first == range.second) {
            std::cout << course << ": no registrations\n";
            continue;
        }

        std::cout << course << ":\n";
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << "  " << it->second << '\n';
        }
    }
    return 0;
}
