#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
protected:
    string country_code;
    double price;
public:
    Product(string code, double p) : country_code(code), price(p) {}
    string get_country_code() { return country_code; }
    double get_price() { return price; }
};

class Toy : public Product {
private:
    string name;
    int min_age;
    int max_age;
public:
    Toy(string code, double p, string n, int min_a, int max_a) : Product(code, p), name(n), min_age(min_a), max_age(max_a) {}
    string get_name() { return name; }
    int get_min_age() { return min_age; }
    int get_max_age() { return max_age; }
};

int main() {
    // Example usage
    vector<Toy> toys;
    toys.push_back(Toy("US", 19.99, "Lego", 4, 10));
    toys.push_back(Toy("CN", 9.99, "Barbie", 3, 8));
    toys.push_back(Toy("JP", 29.99, "Nintendo Switch", 7, 16));
    
    int min_age, max_age;
    double min_price, max_price;
    cout << "Enter minimum age: ";
    cin >> min_age;
    cout << "Enter maximum age: ";
    cin >> max_age;
    cout << "Enter minimum price: ";
    cin >> min_price;
    cout << "Enter maximum price: ";
    cin >> max_price;
    
    cout << "Toys recommended for ages " << min_age << " to " << max_age << " and priced between $" << min_price << " and $" << max_price << ":" << endl;
    
    double total_price = 0;
    for (Toy t : toys) {
        if (t.get_min_age() <= max_age && t.get_max_age() >= min_age && t.get_price() >= min_price && t.get_price() <= max_price) {
            total_price += t.get_price();
            cout << t.get_name() << " (Country Code: " << t.get_country_code() << ", Price: $" << t.get_price() << ")" << endl;
        }
    }
    
    cout << "Total price of recommended toys: $" << total_price << endl;
    
    return 0;
}
