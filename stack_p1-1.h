#ifndef stack_p1_h
#define stack_p1_h
using namespace std;

template <typename T>
class stack_p1{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *top=nullptr;
    
public:
    bool isEmpty();
    T pop();
    void push(T item);
    T peek();
    
};


template <typename T>
bool stack_p1<T>::isEmpty(){
    // COMPUTATIONAL COMPLEXITY:O(1) // REVIEW
    // Indicates whether no elements are stored.
    return (top==nullptr);
};
////
template <typename T>
T  stack_p1<T>::pop(){
    ////     // COMPUTATIONAL COMPLEXITY: O(1)
    ////    // Removes and returns the last inserted element.
    
    T item=top->data; //Pull data from the top
    top=top->next; //reset top to top-next
    return item;     //return data
    
};


template <typename T>
T  stack_p1<T>:: peek(){
    ////    // COMPUTATIONAL COMPLEXITY: O(1) // REVIEW
    ////    // Returns the last inserted element without removing it.
    return (top->data);
};



////
template <typename T>
void stack_p1<T>::push(T item){
    ////   // COMPUTATIONAL COMPLEXITY: O(1)
    ////    // Inserts an element onto the stack.
    ////
    Node *newNode;//Create a new node
    newNode= new Node;
    newNode->data=item; //Set data to inputted item.
    newNode->next=top;//Make top its next
    top=newNode; //Reset Top
};

#endif /* stack_p1_h */
