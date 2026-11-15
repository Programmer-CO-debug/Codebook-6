#include <deque>
#include <iostream>
#include <string>

int main() {
    std::deque<std::string> tasks;

    tasks.push_back("Email client");        // normal task joins the back
    tasks.push_back("Update report");       // normal task joins the back
    tasks.push_front("Fix server outage");  // urgent task goes to the front
    tasks.push_back("Backup files");        // normal task joins the back

    // Always process the front. Check empty before removing.
    while (!tasks.empty()) {
        std::cout << "Processing: " << tasks.front() << '\n';
        tasks.pop_front();
    }
    return 0;
}
