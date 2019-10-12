/**
 * ALBRIT BENDO
 * ADS HW 7
 * PROBLEM 7.1
 * STACKS & LINKED LIST
 **/

#include <iostream>

using namespace std;

template<class T>
class Stack
{
    private:
        typedef struct StackNode { // linked list
            T data; // data of any type
            StackNode *next;
        }Node;

        Node *top; // top of stack
        int size; // -1 if not set, value otherwise
        int current_size; // unused if size = -1

    public:
        Stack(); // default constructor
        Stack(int new_size); // set the stack size 

        void push(T element); // if size set, check for overflow
        T pop(); // return element if not in underflow
        bool isEmpty(); // true if empty, false otherwise
};
// O(1)
template<class T>
Stack<T>::Stack() {
    size = -1;
    current_size = -1;
}
// O(1)
template<class T>
Stack<T>::Stack(int new_size) {
    this->size = new_size; 
    this->current_size = 0;
}
// time complexity of isEmpty() function is O(1) as do not check for all 
// the elements, but only for the top 
template<class T>
bool Stack<T>::isEmpty() {
    if(top == NULL) {
        return true; // underflow
    }
    else
        return false; // not underflow
}
// time complexity to push is O(1) as we are inserting elements
// only from the top and no need to iterate
template<class T>
void Stack<T>::push(T element) {
    Node *ptr;
    ptr = (Node*)malloc(sizeof(Node)); // new node

    if(ptr == NULL) {
        cout << "no data" << endl;
    }

    ptr->data = element;
    ptr->next = top; // will link the next element with the last one
    top = ptr; // top and ptr will point to the same node
    
    if(current_size > size) {
        cout << "overload" << endl;
        exit(1);
    }
}
// time complexity to pop an element is O(1) as we do not need to iterate 
// just change the pointer direction and free the memory.
template<class T>
T Stack<T>::pop() {
    Node *ptr;

    if(isEmpty())
        cout << "underflow" << endl;Node *top; // top of stack
    else {
        ptr = top;
        top = top->next;
        ptr->next = NULL;      
        delete(ptr); // free() instead of delete if we use malloc(sizeof())
        current_size--;
    }

    if(!isEmpty()) 
        return top->data; 
    else
        return 0;
}

int main(int argc, char** argv)
{
    // int int_nr1 = 34;
    // int int_nr2 = 23;
    // int int_nr3 = 45;

    // Stack<int> integer;
    // integer.push(int_nr1);
    // integer.push(int_nr2);
    // integer.push(int_nr3);

    // integer.pop() << endl;

    float float_nr1 = 3.4;
    float float_nr2 = 5.2;
    float float_nr3 = 4.1;

    Stack<float> floating(5);
    floating.push(float_nr1);
    floating.push(float_nr2);
    floating.push(float_nr3);

    floating.pop() << endl;
    return 0;
}