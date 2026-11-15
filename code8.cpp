#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Task {
    int priority;     // larger value = more urgent
    int id;
    std::string name;
};

// Returns true when a has LOWER precedence than b.
// Higher priority comes out first. For equal priority, the smaller id comes first.
struct TaskOrder {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) {
            return a.priority < b.priority;
        }
        return a.id > b.id;
    }
};

int main() {
    std::priority_queue<Task, std::vector<Task>, TaskOrder> tasks;
    tasks.push({2, 103, "Backup"});
    tasks.push({5, 102, "Review"});
    tasks.push({1, 104, "Cleanup"});
    tasks.push({5, 101, "Hotfix"});

    while (!tasks.empty()) {
        const Task& t = tasks.top();
        std::cout << "Serve: " << t.name << " (priority " << t.priority
                  << ", id " << t.id << ")\n";
        tasks.pop();
    }
    return 0;
}
