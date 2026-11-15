#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    int marks;
};

int main() {
    // Kiran is added to show the filter at work.
    std::vector<Student> students{
        {102, "Neha", 90},
        {101, "Amit", 90},
        {103, "Ravi", 80},
        {104, "Kiran", 35}
    };

    // Marks descending. Equal marks: ID ascending. Strict comparisons only.
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks != b.marks ? a.marks > b.marks : a.id < b.id;
    });

    for (const auto& s : students) {
        std::cout << s.id << ' ' << s.name << ' ' << s.marks << '\n';
    }

    const int passMark = 40;
    auto passing = std::count_if(students.begin(), students.end(),
                                 [passMark](const Student& s) { return s.marks >= passMark; });
    std::cout << "Passing students (marks >= " << passMark << "): " << passing << '\n';
    return 0;
}
