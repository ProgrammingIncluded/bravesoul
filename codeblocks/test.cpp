
#include <iostream>

#include <stack>

int main() {
    std::stack<int> s;

    s.push(10);
    s.push(20);

    std::cout << "s.top() = " << s.top() << "\n";
    s.pop();
    std::cout << "s.top() = " << s.top() << "\n";
    s.pop();
    std::cout << "s.top() = " << s.top() << "\n";


    return 0;
}
