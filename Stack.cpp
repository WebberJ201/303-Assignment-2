#include "Stack.h"
#include <iostream>
#include <numeric>

void Stack::push(int item) {
    data.push_back(item);
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

int Stack::top() const {
    return data.empty() ? -1 : data.back();
}

bool Stack::empty() const {
    return data.empty();
}

double Stack::average() const {
    if (data.empty()) return 0.0;
    return static_cast<double>(std::accumulate(data.begin(), data.end(), 0)) / data.size();
}

void Stack::display() const {
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
