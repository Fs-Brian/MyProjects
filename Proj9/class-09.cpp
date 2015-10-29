#include "class-09.h"
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
using std::make_pair;
#include<iostream>
using std::cout; using std::endl;
#include <stdexcept>

//takes in 2 longs
SparseMatrix::SparseMatrix(long row, long col){
    //sets the 2 long values
    rows = row;
    cols = col;
    //declares a pair
    pair<long,long> mypair;
    //loops through row and column setting all to 0
    for(int x=0; x<row;x++){
        for(int y=0;y<col; y++){
            mypair.first =x;
            mypair.second = y;
            matrix[mypair] = 0;
            
        }
    }
}
//takes in 2 longs and a vector
SparseMatrix::SparseMatrix(long row, long col, vector<long> v){
    //sets the 2 long values
    rows = row;
    cols = col;
    //declares a pair
    pair<long,long> mypair;
    //loops through row and column setting all to 0
    for(int x=0; x<row;x++){
        for(int y=0;y<col; y++){
            mypair.first =x;
            mypair.second = y;
            matrix[mypair] = 0; 
        }
    } 
    //loops through vector, sets the values in vector to the matrix
    //by first getting pair value
    for(int i=0; i<v.size(); i+=3){
        mypair.first = v[i];
        mypair.second = v[i+1];
        matrix[mypair] = v[i+2];
    }
   
}
//takes in 3 longs
void SparseMatrix::set(long row, long col, long val){
    //creates a pair out of first 2 longs,
    pair<long,long> mypair;
    mypair.first = row;
    mypair.second = col;
    //sets value at that pair
    matrix[mypair] = val;    
}
//returns a pair value
pair<long,long> SparseMatrix::dimensions(){
    //gets the value rows/cols and creates a pair out of them
    pair<long,long> finals;
    finals.first = rows;
    finals.second = cols;
    return finals;
}
//returns a long value
long SparseMatrix::element_count(){
    //initializes pair and count
    long count = 0;
    pair<long,long> mypair;
    //loops through all elements to see if they are default value or not
    for (int x=0; x<rows;x++){
        for(int y=0;y<cols;y++){
            mypair.first = x;
            mypair.second = y;
            //if it is not default value, increases count by 1
            if(matrix[mypair] != 0){ 
                count += 1;
            }
        }
    } 
    return count;    
}
//returns an print output, takes in a matrix
std::ostream& operator<<(std::ostream &os, SparseMatrix &mat){
    string a;
    long i;
    pair<long,long> mypair;
    
    for (int x=0; x< mat.rows;x++){
        for(int y=0; y<mat.cols;y++){
            mypair.first = x;
            mypair.second = y;
            i = mat.matrix[mypair];
            if (i != 0){
            a += "{" + std::to_string(x) + "," + std::to_string(y) + "}:" +
                    std::to_string(i) + ",";
            }
        }
        

        
    }   
    
    a = a.substr(0, a.size()-1);
    
    return os << a;
}
//takes in 2 longs
long SparseMatrix::operator()(long row, long col){
    //creates a pair and returns the value of the matrix at that pair
    long x;
    pair<long,long> mypair;
    mypair.first = row;
    mypair.second = col;
    x = matrix[mypair];
    return x;
}
//takes in a long, returns a matrix
SparseMatrix SparseMatrix::operator+ (long e){
//creates an empty matrix    
SparseMatrix q(rows,cols);
long val;
long curval;
pair<long,long> mypair;
    //loops through old matrix and adds the value to the old matrix value
    //then sets that value to the new matrix
    for (int x=0; x< rows;x++){
        for(int y=0; y< cols;y++){
            mypair.first = x;
            mypair.second = y;
            curval = matrix[mypair];
            val = curval + e;
            q.set(x,y,val);
        }
        
    } 

return q;
}
//takes in matrix and long, returns matrix
SparseMatrix operator+ (long e, SparseMatrix mat){
//gets matrix dimensions
pair<long,long> mypairdim = mat.dimensions();
long row = mypairdim.first;
long col = mypairdim.second;
//creats an empty matrix
SparseMatrix q(row,col);
long val;
long curval;
pair<long,long> mypair;

    //loops through matrix adding the old value to the long value
    for (int x=0; x< row;x++){
        for(int y=0; y< col;y++){
            mypair.first = x;
            mypair.second = y;
            curval = mat.matrix[mypair];
            
            val = curval + e;
            q.set(x,y,val);
        }
        
    } 

return q;
}
//takes in matrix and long, returns matrix
SparseMatrix operator* (long e, SparseMatrix mat){
//gets matrix dimensions
pair<long,long> mypairdim = mat.dimensions();
long row = mypairdim.first;
long col = mypairdim.second;
//creats an empty matrix
SparseMatrix q(row,col);
long val;
long curval;
pair<long,long> mypair;

    //loops through matrix multipying the old value to the long value
    for (int x=0; x< row;x++){
        for(int y=0; y< col;y++){
            mypair.first = x;
            mypair.second = y;
            curval = mat.matrix[mypair];
            
            val = curval * e;
            q.set(x,y,val);
        }
        
    } 

return q;   
}
//takes in matrix and long, returns matrix
SparseMatrix SparseMatrix::operator+ (SparseMatrix e){
    //initializes empty matrix
SparseMatrix q(rows,cols);    
//checks if dimensions are equal
if(dimensions() == e.dimensions()){

long val;
long curvala;
long curvalb;
pair<long,long> mypair;
    //loops through matrix and adds the numbers to each other and 
    //stores in new matrix
    for (int x=0; x< rows;x++){
        for(int y=0; y< cols;y++){
            mypair.first = x;
            mypair.second = y;
            curvala = matrix[mypair];
            curvalb = e.matrix[mypair];
            val = curvala + curvalb;
            q.set(x,y,val);
        }
        
    }     
}else{
    //throws an error if sizes are not equal
     throw std::runtime_error( "Addition matrix dimensions were different." );      
}


return q;    
}
//takes in long, returns matrix
SparseMatrix SparseMatrix::operator* (long e){
//declares new matrix
SparseMatrix q(rows,cols);
long val;
long curval;
pair<long,long> mypair;
    //loops through matrix multipying the matrix by the value
    for (int x=0; x< rows;x++){
        for(int y=0; y< cols;y++){
            mypair.first = x;
            mypair.second = y;
            curval = matrix[mypair];
            val = curval*e;
            q.set(x,y,val);
        }
        
    } 

return q;    
}
//takes in matrix, returns matrix
SparseMatrix SparseMatrix::operator* (SparseMatrix e){
//declares matrix
SparseMatrix q(rows,cols);
//checks if dimensions are equal
if(dimensions() == e.dimensions()){    

long val;
long curvala;
long curvalb;
//create pair
pair<long,long> mypair;
    //loop through matrix multipy values by each other
    for (int x=0; x< rows;x++){
        for(int y=0; y< cols;y++){
            mypair.first = x;
            mypair.second = y;
            curvala = matrix[mypair];
            curvalb = e.matrix[mypair];
            val = curvala * curvalb;
            q.set(x,y,val);
        }
        
    } 
}else{
    //throws an exeption if sizes are not equal
   throw std::runtime_error( "Multiplication matrix dimensions were different." );    
}

return q;     
    
}



