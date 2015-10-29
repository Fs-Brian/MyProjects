#include<map>
using std::map; 
#include<vector>
using std::vector;
#include<string>
using std::string; 
#include<random>
using std::default_random_engine; 
#include<iostream>
using std::ostream;
#include<fstream>
#include "functions-06.h"
using std::ifstream;
using std::cout;


bool read_index(map<long, string> &index_map, string file_name){
    bool read = true;
    long out_long;
    string out_string;
    ifstream myReadFile;
    //attempts to open file
    myReadFile.open(file_name);
    //checks if file is open
    if (myReadFile.is_open()) {
        //loops while not at end of file
        while (!myReadFile.eof()) {
            //outputs first to out_long, then after space to out_string
            myReadFile >> out_long >> out_string;   
            //stores out_long as key, and out_string to map
            index_map[out_long] = out_string;
            
        }
        
    }else{
        //if file was not open, returns false
        read = false;
    }   
    //closes files
    myReadFile.close();
    
    return read;
}

bool read_arc(map<long, vector<long>> &arc_map, string file_name){
    bool read = true;
    long out_long;
    vector<long> out_vect;
    ifstream myReadFile;
    //attempts to open file
    myReadFile.open(file_name);
     //checks if file is open
    if (myReadFile.is_open()) {
        //loops while not at end of file
        while (!myReadFile.eof()) {
            //outputs first to out_long, then after space to out_vect
            myReadFile >> out_long >> out_vect;  
            //stores out_long as key, and out_vect to map
            arc_map[out_long] = out_vect;
            
        }
        
    }else{
        //if file was not open, returns false
        read = false;
    }   
    //closes files
    myReadFile.close();
    
    return read;    
}

void init_pr_map(map<long,double> &pr_map, size_t sz){
    
}

vector<long> incoming (map<long, vector<long>> &arc_map, long id){
    
}

long outgoing (map<long, vector<long>> &arc_map, long id){
    
}

void page_rank(
    map<long, vector<long>> &arc_map, 
    map<long,double> & pr_map,
    long iters, double damping,
    default_random_engine &dre){
    
}


void print_page_ranks(map<long, double> &pr_map, map<long, string> &index_map,
    ostream &out){
    //    
}
