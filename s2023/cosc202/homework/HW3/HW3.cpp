/*
Name: Isaac Abella
Description: Make a stack implementation based on a list, meaning it should mimic the function of
a linked list but the memory is now heap based and dynamically allocated. Assume all data
is integer (int filler) and provide basic functions.
*/

#include <iostream>
#include <string>
#include <iomanip>

class stack
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node(int filler) : data(filler), next(0) {}
    };

    stack() : top(0) {}
    ~stack();

    bool empty();
    const int size();
    void push(int filler);
    void pop();
    // had to rechange the top function to display top to avoid name collision.
    const int &display_top();

private:
    Node *top;
};

stack::~stack()
{
    while (!empty())
    {
        pop();
    }
}

bool stack::empty()
{
    return top == NULL;
}

const int stack::size()
{
    int counter = 0;
    Node *tracker = top;
    while (tracker != NULL)
    {
        counter++;
        tracker = tracker->next;
    }
    return counter;
}

void stack::push(int filler)
{
    Node *pusher = new Node(filler);
    pusher->next = top;
    top = pusher;
}

void stack::pop()
{
    if (!empty())
    {
        Node *burner = top;
        top = top->next;
        delete burner;
    }
}

const int &stack::display_top()
{
    while (top != NULL)
    {
        return top->data;
    }
}

/*
QUESTION TWO
==========================================
What type of error checking should member functions push(), pop() and top() include if the code were
to be used in real application?
==========================================
*/

/*
ANSWER:
==========================================
For push you would want to monitor memory allocation, such as checking for bad allocations. I guess if you're working with
little amount of memory or perhaps memory fragmentation when calling New in your specific system could lead to this error?

If our list was a fixed size you would also want to check for a stack overflow (the funny website name lol)

For the pop function you would want to ensure you're not trying to delete an empty list, so underflow

For the top function you would want to check for empty stacks, so you wouldn't want to try to print a nullptr.
If you did so the program would crash. Since you don't want us to check Null/0/nullptr, the code would just
straight up cause a runtime error and crash because you would be printing a garbage mem address.

(I would assume that the error checks in a stack would be the same as a linked list if we're doing a stack based on a list.
Other than that, you could be checking the increments and decrements of the push and pop functions, but for a basic single link list application,
this is inherently understood to be happening when we update the top pointer.)

However, if this isn't right, please let me know!
==========================================
*/
