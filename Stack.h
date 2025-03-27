#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data;

public:
    void push(int item);
    void pop();
    int top() const;
    bool empty() const;
    double average() const;
    void display() const;
};

#endif