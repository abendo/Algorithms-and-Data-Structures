/**
 * ALBRIT BENDO
 * ADS HW 7
 * PROBLEM 7.1
 * QUEUE & STACKS
 **/

#include <iostream>
#include <stack>

using namespace std;

class Queue
{
    public:
        stack<int> stack_1; // using two C++ stacks
        stack<int> stack_2;    
        void push(int element); // push function
        int pop(); // pop function
};
/* the idea is to copy the elements of stack 1 to stack 2 and pop the elmenets of stack 1
 so we can push "like we push in queue" following the FIFO order */
void Queue::push(int element) {
    while(!stack_1.empty()) { // while not empty
        stack_2.push(stack_1.top()); // copy stack 1 to stack 2
        stack_1.pop(); // pop elements of stack 1
    }

    stack_1.push(element); // push the element

    while(!stack_2.empty()) { // do the opposite
        stack_1.push(stack_2.top()); // copy stack 2 to stack 1
        stack_2.pop(); // pop elements of stack 2
    }
}
/* as we want to pop following the FIFO order, it means that we have to pop
the top of stack */
int Queue::pop() {
    if(stack_1.empty()) { // check stack
        cout << "underflow" << endl;
        exit(1); // if empty
    }
    
/* as pop function is a void function I used an element 
to keep track of the top and return it */
    int element = stack_1.top();
    stack_1.pop();
    return element;
}

int main(int argv, char** argc)
{   
    Queue queue;
    
    queue.push(34);
    queue.push(12);
    queue.push(5);

    queue.pop();

    return 0;
}