#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> undo;
    undo.push("Type A");
    undo.push("Bold");
    undo.push("Delete line");

    // Read top() before pop(). pop() returns void.
    while (!undo.empty()) {
        std::cout << "Undo: " << undo.top() << '\n';
        undo.pop();
    }
    return 0;
}
