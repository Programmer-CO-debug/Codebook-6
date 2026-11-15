#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> names{{102, "Neha"}, {101, "Amit"}};

    // insert_or_assign replaces the value if the key exists.
    // It returns pair<iterator, bool>; bool is true only when a new key was inserted.
    auto replaced = names.insert_or_assign(101, std::string("Amit Patil"));
    std::cout << "Inserted new key: " << replaced.second << '\n';
    std::cout << "Name for 101: " << names.find(101)->second << '\n';

    auto added = names.insert_or_assign(103, std::string("Ravi"));
    std::cout << "Inserted new key: " << added.second << '\n';

    std::cout << "Size: " << names.size() << '\n';
    return 0;
}
