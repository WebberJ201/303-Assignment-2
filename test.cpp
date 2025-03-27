#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack stack;

    cout << "Stack is empty: " << (stack.empty() ? "Yes" : "No") << "\n";

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack after pushing 10, 20, 30:\n";
    stack.display();

    cout << "Top element: " << stack.top() << "\n";

    stack.pop();
    cout << "Stack after popping an element:\n";
    stack.display();

    cout << "Average of elements: " << stack.average() << "\n";

    return 0;
}
