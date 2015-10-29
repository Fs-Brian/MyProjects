#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::swap;

#ifndef CLASS_11_H
#define	CLASS_11_H
// Node Class
template<typename T>
struct Node{
public:
    T data_;
    Node* next_;
    Node() : data_(T()), next_(nullptr) {};
    Node(T d) : data_(d), next_(nullptr) {};
    bool operator<(Node n){return this->data_ < n.data_;}
};
// SortedList declaration
template<typename T>
class SortedList{
private:
    Node<T> *head_;
    Node<T> *tail_;

public:
    SortedList() : head_(nullptr), tail_(nullptr) {};
    SortedList(initializer_list<T>);
    SortedList(SortedList&);
    ~SortedList();
    SortedList& operator=(SortedList s);
    void insert(T);
    Node<T>* find(T val);
    bool del(T);
    size_t length();
    T min();
    T max();
    T mid();

    // inline, easiest for templates
    friend ostream& operator<<(ostream& out, SortedList<T>& sa){
        Node<T> *e = sa.head_;
        long length = 0;
        out << "{";
        while(e != nullptr){
            out << e->data_;
            e = e->next_;
            if (e != nullptr){
                out << ",";    
            }
        }
        out << "}" << endl;
	return out;
    }
};


template<typename T>
//Takes in an initializer list and creates a SortedList
SortedList<T>::SortedList(initializer_list<T> e) : head_{nullptr} {
    //gets the first value in initializer list
    auto i = e.begin();
    //creates a node with that value, it will be our current head
    head_ = new Node<T>(*i);
    //increments to the next value in e
    ++i;
    //initializes 2 pointer nodes
    Node<T> *curr = nullptr;
    Node<T> *n = nullptr;
    //increments till end of e
    for (; i != e.end(); ++i) {
                //sets n to next value in e
                 n = new Node<T>(*i);
                //loops through start at the current head until
                //it reaches a value that the next value is less than
                for (curr = head_; curr->next_ && curr->next_->data_ < *i;
                        curr = curr->next_){ 
                }
                //checks if i value is less than current value
                 //(Checks if we have a new head)
                if (*i < curr->data_) {
                    //sets value n points to to the current value
                    n->next_ = curr;
                    //sets n to head
                    head_ = n;
                } else {
                    //sets n next value to current next value
                    n->next_ = curr->next_;
                    //sets current next value to n
                    curr->next_ = n;
                }
    }
}
template<typename T>
//takes in a SortedList and creates a new one
SortedList<T>::SortedList(SortedList& e){
    //sets head to the head of the SortedList we took in
    head_ = new Node<T>(e.head_->data_);
    //creates a node we will increment through starting at head that we will
    //store our info in
    Node<T> *e_curr = head_;
    //we increment through the SortedList e's nodes until end
    for (Node<T> *x = e.head_->next_; x!= nullptr; x = x->next_){
        //sets e's next node to the data in x node
        e_curr->next_ = new Node<T>(x->data_);
        //increments e_curr node
        e_curr = e_curr->next_;
    }
}
template<typename T>
//takes in a SortedList and returns a copied List
SortedList<T>& SortedList<T>::operator=(SortedList s){
    //swaps the heads of the SortedList with the one we are creating
    swap(s.head_,head_);
    //Returns a copied list
    return *this;
}
template<typename T>
//destructor
SortedList<T>::~SortedList(){
    //n is the current header node
   Node<T>* n = head_;
   //creates a node that is a null pointer
   Node<T>* curr=nullptr;
   //loops through n
   while(n != nullptr){
       //current node is n
       curr = n;
       //n is the next node
       n=n->next_;
       //then deletes the current node
       delete(curr);
   } 
   //sets head and tail to null pointers   
   head_ = tail_ = nullptr;
}
template<typename T>
//takes in a value to insert
void SortedList<T>::insert(T val){
    //creates a node of the value
    Node<T>* e = new Node<T>(val);

    //checks if at end or val is less then head data
    if(head_ == nullptr || head_->data_  >= e->data_){
        //sets e link to old head
        e->next_ = head_;
        //sets e to new head
        head_ = e;
    }else{
        //creates a current node that points to head
        Node<T>* curr = head_;
        //loops until at end or data inbetween values
        while (curr->next_ != nullptr && curr->next_->data_ < e->data_){
            //sets curr to the next
            curr = curr->next_;
        }
        //e's next node links to the current next node
        e->next_ = curr->next_;
        //current's next node links to e
        curr->next_ = e;
    }
}
template<typename T>
//returns the size of the SortedList
size_t SortedList<T>::length(){
    //initializes pointer node to the head
    Node<T> *e = head_;
    //starts length at 0
    long length = 0;
    //loops through list
    while(e != nullptr){
        //each time increments length by 1 
        ++length;
        //each tiem increments current node by 1
        e = e->next_;
    }
    //returns the length
    return length;
}
template<typename T>
//Takes in a value to find and returns a pointer node to the node of the first 
//value
Node<T>* SortedList<T>::find(T val){
    //initializes final node as a nullptr
    Node<T> *final_node = nullptr;
    //initializes starting node as the head
    Node<T> *e = head_;
    //loops until the end
    while(e != nullptr){
        //checks if data is equal to the value we want
        if (e->data_ == val){
            //stores that node and breaks the while
            final_node = e;
            break;
        }
        //increments the while loop
        e = e->next_;
    }
    //returns the node we found, if none found, returns nullptr
    return final_node;    
}
template<typename T>
//Returns a data type T that is the smallest value
T SortedList<T>::max(){
    //checks if length is 0 throws error
    if (length() == 0){
        throw std::runtime_error("Length is 0.");
    }else{
    //initializes node starting at head
    Node<T> *e = head_;
    //loops to the end
    while (e->next_ != nullptr){
        e = e->next_;
    }
    //gets data from end
    T val = e->data_;
    //returns that value
    return val;
    }
}
template<typename T>
//Returns a data type T that is the smallest value
T SortedList<T>::min(){
    //checks if length is 0 throws error
    if (length() == 0){
        throw std::runtime_error("Length is 0.");
    }else{
        //gets first value because list is sorted so it will be smallest
        T val = head_->data_;
        return val;
    }
}
template<typename T>
//Returns a data type T that is the middle value
T SortedList<T>::mid(){
    //checks if length is 0 and throws error
    if (length() == 0){
        throw std::runtime_error("Length is 0.");
    }else{
    //initializes a node pointer as the head
    Node<T> *e = head_;
    //gets length
    long length_list = length();
    //mid pos is length/2
    int mid_pos = length_list/2;
    //counter to count until we are at mid node
    long counter = 0;
    while(counter < mid_pos){
        e = e->next_;
        counter ++;
    }
    //gets value of middle node
    T val = e->data_;
    //returns middle node value
    return val;
    }
}
template<typename T>
//Takes in a value and returns a boolean if it was successfully deleted or not
bool SortedList<T>::del(T val){
    //initializes a pointer node to the value we want to delete
    Node<T> *del_node = find(val);
    //initializes a boolean 
    bool deleted = false;
    //the node exists, it will be deleted
    if(del_node != nullptr){
        deleted = true;
    }
    //initializes previous node as head
    Node<T> *last = head_;
    //checks if we are deleted the head
    if(head_ == del_node){
        //checks if we have a length of 1
        if (length() == 1){
            head_ = nullptr;
        }else{
        //if it is not length 1, we change data of head to next data
        //and head next to next next
        head_->data_ = head_->next_->data_;
        head_->next_ = head_->next_->next_;
        }
    }else{
    //if not head, we loop through till we find the node
    while (last->next_ != nullptr && last->next_ != del_node){
        //once we find the node, we change it to the next node
        last = last->next_;
    }
    //and change the next node to point to next next node
    last->next_ = last->next_->next_;
    }
    //returns if deleted or not
    return deleted;
}

#endif	/* CLASS_11_H */
