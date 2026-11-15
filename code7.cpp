#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> serviceQueue;
    serviceQueue.push("Asha");
    serviceQueue.push("Ravi");
    serviceQueue.push("Meena");

    int position = 1;
    while (!serviceQueue.empty()) {
        std::cout << position++ << ". Serving " << serviceQueue.front() << '\n';
        serviceQueue.pop();
    }
    return 0;
}
