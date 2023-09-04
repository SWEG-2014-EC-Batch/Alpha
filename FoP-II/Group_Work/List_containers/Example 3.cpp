#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> myList = {10, 20, 30, 40, 50};

    auto it = std::find(myList.begin(), myList.end(), 30);
    if (it != myList.end()) {
        std::cout << "Element found at position: " << std::distance(myList.begin(), it) << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
