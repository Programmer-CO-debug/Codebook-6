#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// Copies passing marks (40 or more) and prints their mean.
void reportPassingMean(const std::vector<int>& marks) {
    std::vector<int> passing;
    std::copy_if(marks.begin(), marks.end(), std::back_inserter(passing),
                 [](int m) { return m >= 40; });

    // Guard the empty case: dividing by zero would be wrong.
    if (passing.empty()) {
        std::cout << "Passing: none (empty case guarded)\n";
        return;
    }

    double total = std::accumulate(passing.begin(), passing.end(), 0.0);
    std::cout << std::fixed << std::setprecision(2)
              << "Passing: " << passing.size() << " student(s), mean "
              << total / passing.size() << '\n';
}

int main() {
    std::vector<int> classMarks{35, 72, 48, 90, 56};
    std::vector<int> failedClass{10, 20, 30};

    std::vector<int> copied;
    std::copy(classMarks.begin(), classMarks.end(), std::back_inserter(copied));
    std::cout << "Copied " << copied.size() << " marks\n";

    reportPassingMean(copied);
    reportPassingMean(failedClass);
    return 0;
}
