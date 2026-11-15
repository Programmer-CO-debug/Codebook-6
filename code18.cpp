#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

struct Product {
    int id;
    std::string name;
    int quantity;
};

class Inventory {
    std::map<int, Product> products;
    std::queue<int> requests;
    std::vector<int> cancelledRequests;
public:
    void add(Product p) {
        if (p.id <= 0 || p.name.empty() || p.quantity < 0 || products.count(p.id)) {
            throw std::invalid_argument("Invalid or duplicate product");
        }
        products.emplace(p.id, p);
    }

    void restock(int id, int amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Restock amount must be positive");
        }
        auto it = products.find(id);
        if (it == products.end()) {
            throw std::out_of_range("Unknown product");
        }
        it->second.quantity += amount;
    }

    void request(int id) {
        if (!products.count(id)) {
            throw std::out_of_range("Unknown product");
        }
        requests.push(id);
    }

    // Cancel policy: an out-of-stock front request is removed and recorded
    // as cancelled, so it does not block the requests behind it.
    void serve() {
        if (requests.empty()) {
            std::cout << "No pending requests\n";
            return;
        }

        int id = requests.front();
        requests.pop();
        Product& p = products.at(id);

        if (p.quantity == 0) {
            cancelledRequests.push_back(id);
            std::cout << "Cancelled request for " << p.name << " (out of stock)\n";
            return;
        }

        --p.quantity;
        std::cout << "Served " << p.name << '\n';
    }

    std::size_t cancelledCount() const {
        return cancelledRequests.size();
    }

    void report() const {
        std::vector<Product> rows;
        for (const auto& entry : products) {
            rows.push_back(entry.second);
        }
        std::sort(rows.begin(), rows.end(), [](const Product& a, const Product& b) {
            return a.quantity != b.quantity ? a.quantity < b.quantity : a.id < b.id;
        });
        for (const auto& p : rows) {
            std::cout << p.id << ' ' << p.name << ' ' << p.quantity << '\n';
        }
        std::cout << "Low stock (under 3): "
                  << std::count_if(rows.begin(), rows.end(),
                                   [](const Product& p) { return p.quantity < 3; })
                  << '\n';
    }
};

// Runs one action and prints either "ok" or the exception message.
template<typename Action>
void run(const std::string& label, Action action) {
    try {
        action();
        std::cout << label << ": ok\n";
    } catch (const std::exception& e) {
        std::cout << label << ": " << e.what() << '\n';
    }
}

int main() {
    Inventory inventory;

    run("Add Pen", [&] { inventory.add({101, "Pen", 5}); });
    run("Add Notebook", [&] { inventory.add({102, "Notebook", 2}); });
    run("Duplicate add", [&] { inventory.add({101, "Pen", 9}); });
    run("Invalid add (id 0)", [&] { inventory.add({0, "Ghost", 1}); });

    run("Request Pen", [&] { inventory.request(101); });
    run("Request Notebook 1", [&] { inventory.request(102); });
    run("Request Notebook 2", [&] { inventory.request(102); });
    run("Request Notebook 3", [&] { inventory.request(102); });
    run("Request unknown id", [&] { inventory.request(999); });

    inventory.serve();   // Pen 5 -> 4
    inventory.serve();   // Notebook 2 -> 1
    inventory.serve();   // Notebook 1 -> 0
    inventory.serve();   // Notebook is out of stock: cancelled

    run("Restock Notebook by 3", [&] { inventory.restock(102, 3); });
    run("Restock unknown id", [&] { inventory.restock(999, 1); });
    run("Restock by 0", [&] { inventory.restock(102, 0); });

    inventory.serve();   // queue is empty now
    std::cout << "Cancelled requests: " << inventory.cancelledCount() << '\n';
    std::cout << "Report:\n";
    inventory.report();
    return 0;
}
