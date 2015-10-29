#include<iostream>
#include<string>
#include<utility>
using std::cout; using std::endl; using std::cin; using std::string;
#include "functions-04.h"


int score_string (string first, string second){
    int my_range = 0;
    int my_score = 0;
    //converts both to lower
    for(int x=0 ; x < first.length() ; x++){
        first[x] = tolower(first[x]);
    }
    for(int x=0 ; x < second.length() ; x++){
        second[x] = tolower(second[x]);
    }
    //gets proper range from shortest string
    if(first.length() > second.length()){
        my_range = first.length();
    }else{
        my_range = second.length();
    }
    
    
    for(int x=0 ; x < my_range; x++){
        //checks if either are a indel, if so, it skips
        if( (first[x] == '-') || (second[x] == '-') ){
        //checks if both are equal, then increments the score   
        } else if(first[x] == second[x]){
            my_score += 1;
        }     
    }

    return my_score;
}

string insert_indel(string first, int insert_index){
    //I allow for an indel after the last character,I wasn't sure if we were
    //suppose to do this or not.  If we were not, simply remove the = sign from
    //the second part of the and statement.(The specifications were unclear 
    //to me)
    
    //checks if in range
    if(insert_index >= 0 && insert_index <= first.length()){
        //inserts a - and shifts
        first.insert(insert_index,1,'-');        
    }
  
    return first;
}

string delete_indel(string first,int delete_index){
    //Checks if in range
    //checks if character is a -
    if(delete_index >= 0 && delete_index < first.length() && 
        first[delete_index] == '-'){
            //deletes and shifts
            first.erase(delete_index,1);
        }    
    return first;
}
