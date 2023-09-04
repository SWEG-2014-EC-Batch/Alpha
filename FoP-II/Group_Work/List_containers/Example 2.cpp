#include <iostream>
#include <list>

int main() {
    std::list<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);
    myList.push_front(30);

    myList.erase(++myList.begin());  // Erase the second element

    for (const auto& num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
