#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> myList;

    myList.push_back("Apple");
    myList.push_back("Banana");
    myList.push_back("Orange");

    for (const auto& fruit : myList) {
        std::cout << fruit << std::endl;
    }

    return 0;
}
