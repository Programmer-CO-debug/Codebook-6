#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <numeric>

int main() {
    // The size 7 is part of the type std::array<double, 7>. It is fixed at
    // compile time, so the array cannot grow or shrink while the program runs.
    std::array<double, 7> temperatures{21.5, 23.0, 22.5, 24.0, 19.5, 18.0, 20.0};

    double total = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Mean: " << total / temperatures.size() << '\n';
    std::cout << "Max: " << *std::max_element(temperatures.begin(), temperatures.end()) << '\n';
    return 0;
}
