#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include "class-11.h"
#include <stdexcept>

int main (){
    cout << "a" << endl;
    // longs
    SortedList<long> sl_l({6,4,3,2,7});
    cout << sl_l << endl;
    cout << "length: " << sl_l.length() << endl;
    // test front, back, mid
    sl_l.insert(1);
    sl_l.insert(10);
    sl_l.insert(5);
    cout << sl_l << endl;

    // find, useful for del
    Node<long>* n;
    n = sl_l.find(5);
    cout << ((n == nullptr) ? "not found" : "found") << endl;
    n = sl_l.find(20);
    cout << ((n == nullptr) ? "not found" : "found") << endl;

    // test front, back, mid
    sl_l.del(1);
    sl_l.del(10);
    sl_l.del(4);
    cout << sl_l << endl;
    cout << "Length:"<<sl_l.length()<<endl;
    cout << "Min:"<<sl_l.min()<<endl;
    cout << "Max:"<<sl_l.max()<<endl;
    cout << "Mid:"<<sl_l.mid()<<endl;

    // strings too
    SortedList<string> sl_s({"mom", "dad", "brother", "sister"});
    cout << sl_s << endl;
    sl_s.insert("aunt");
    sl_s.del("brother");
    cout << sl_s << endl;
    cout << "Length:"<<sl_s.length()<<endl;
    cout << "Min:"<<sl_s.min()<<endl;
    cout << "Max:"<<sl_s.max()<<endl;
    cout << "Mid:"<<sl_s.mid()<<endl;

    // copy constructor
    SortedList<string>slcopy_s(sl_s);
    cout << slcopy_s << endl;
    slcopy_s.insert("xyzzy");
    cout << slcopy_s << endl;
    slcopy_s.del("mom");
    cout << slcopy_s << endl;
    cout << sl_s << endl;

    // assignment
    SortedList<string> slassign_s;
    slassign_s = sl_s;
    slassign_s.insert("aaa");
    slassign_s.del("mom");
   cout << slassign_s << endl;
    cout << sl_s << endl;
    cout << "b" << endl;

}
