#ifndef CLASS_09_H
#define	CLASS_09_H
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<initializer_list>
using std::initializer_list;
#include <utility>
using std::pair;
#include <map>
using std::map;
//declare class
class SparseMatrix{
//declare private variables
private:
    long rows;
    long cols;
    map<pair<long,long>, long> matrix;
//declare my functions, explained in my source fle    
public:
    SparseMatrix() = default;
    SparseMatrix(long row, long col);
    SparseMatrix(long row, long col, vector<long> v);
    long operator()(long row, long col);
    SparseMatrix operator+ (long e);
    SparseMatrix operator+ (SparseMatrix e);
    SparseMatrix operator*(SparseMatrix e);
    friend SparseMatrix operator+ (long e, SparseMatrix mat);
    friend SparseMatrix operator* (long e, SparseMatrix mat);
    SparseMatrix operator*(long e);
    void set(long row, long col, long val);
    pair<long,long> dimensions();
    long element_count();
    friend std::ostream& operator<<(ostream &os, SparseMatrix &mat);
};


#endif	

