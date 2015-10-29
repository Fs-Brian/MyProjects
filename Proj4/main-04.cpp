#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
#include "functions-04.h"

int main (){
    string first  = "AATAACGAAA";
    string second = "AAAACGAAAA";
    cout << "First:"<<first<<", Second:"<<second<<endl;
    cout << "Match Score:"<<score_string(first,second)<<endl;

    first = insert_indel(first,10);
    cout <<"insert indel at 10 in first:"<<first<<endl;
    second = insert_indel(second, 2);
    cout <<"insert indel at 2 in second:"<<second<<endl;    

    cout << "Match Score:"<< score_string(first,second) <<endl;

    first = delete_indel(first,10);
    cout <<"remove indel at 10 in first:"<<first<<endl;
}
