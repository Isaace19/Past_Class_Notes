#include <iostream>

/*
Name: Isaac Abella
Implement Single Linked Class Functions: Push_Front, pop_front, const in &front().
*/

struct Node
{
    int data;
    Node *next;
    // initialize the node so it can hold new data from insert
    Node(int data = 0) : data(data), next(NULL) {}
};

class LinkedList
{
    // implement the head of the list head is the first node and tail is the last node
    Node *head, *tail;

public:
    // initalize the constructor to null + a deconstructor for the end of the code
    LinkedList() : head(NULL), tail(NULL), N(0) {}
    ~LinkedList();

    // functions ripped from in class handout implementations
    bool empty() const { return N == 0; }
    int size() const { return N; }

    void clear();
    void insert(const int &);
    void erase(int value);
    void print_list();

    // all these functions print to the front of the list
    void push_front(const int &data);
    void pop_front();
    const int &front();
    const int &back();

private:
    int N; // tracks the nodes
};

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::clear()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    head = tail = NULL;
    N = 0;
}

void LinkedList::insert(const int &value)
{
    // new dynamically allocated memory in the heap
    Node *new_node = new Node(value);

    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    N++;
}

void LinkedList::erase(int value)
{
    Node *current = head;
    Node *second_last = NULL;

    while (current != NULL && current->data != value)
    {
        second_last = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (second_last != NULL)
        {
            second_last->next = current->next;
        }
        else
        {
            head = current->next;
        }

        if (current == tail)
        {
            tail = second_last;
        }
        delete current;
        N--;
    }
}
void LinkedList::print_list()
{
    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}

void LinkedList::push_front(const int &data)
{
    /*
    Implement a push to the front function. We make a temp value that attempts to
    fill the head node, we set the temp to the previous head node and then
    increase the node count
    */
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;

    if (tail == NULL)
    {
        tail = head; // if list was empty, then our tail can be the new node;
    }
    N++;
}

void LinkedList::pop_front()
{
    /*
    Implement a pop function to delete the front of the list. We will have
    to set the head to the next node before deleting all the data, then decrementing
    the node count.
    */

    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;

    if (head == NULL)
        tail = NULL;

    if (temp == tail)
        tail = NULL;

    delete temp;
    N--;
}

// fix the front and back display calls.

const int &LinkedList::front()
{
    std::cout << "Printing out the head node...   \n";
    return head->data;
    if (head == NULL) // assuming the head is nullptr and there is no list
        throw std::runtime_error("Empty list\n");
}

const int &LinkedList::back()
{
    std::cout << "Printing out the tail node... \n";
    return tail->data;

    if (tail == NULL)
        throw std::runtime_error("Empty list\n");
}

int main()
{
    std::cout << "Here's the list on the stack: \n";
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    std::cout << "printing the list of initial inserts\n";
    list.print_list();

    std::cout << "Front: " << list.front() << "\n";
    std::cout << "Back: " << list.back() << "\n";

    list.pop_front();

    std::cout << "The node after calling pop_front: " << list.front() << "\n";
    list.print_list();

    list.push_front(777);
    std::cout << "Here is the push_front function....\n";
    list.print_list();

    // don't technically have to call clear because the stack allocation will automatically destroy the list after we're done.
    list.clear();

    /*
    however if you want to test, we can call the list as a dynamic allocation to the heap memory then we have more
    control of the list itself, then we can use erase and delete for specific nodes. And this method
    will extend the lifetime of the list and allow us to edit it more.
    */

    std::cout << "Here's the list on the heap: \n";
    LinkedList *list_heap = new LinkedList;

    // do code again here

    list_heap->insert(1);
    list_heap->insert(2);
    list_heap->insert(3);

    list_heap->print_list();

    list_heap->erase(1);
    list_heap->erase(2);
    list_heap->erase(3);

    std::cout << "erasing and deleting the list...\n";
    list_heap->print_list();
    delete list_heap;

    return 0;
}
