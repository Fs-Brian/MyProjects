#include<iostream>
#include<string>
#include<utility>
#include <vector>
#include<ostream>
#include<map>
#include <sstream>
#include "struct-07.h"
#include<cmath>
#include<deque>
#include<initializer_list>
using std::cout; using std::endl;
using std::deque;
using std::initializer_list;
using std::string; 
using std::stringstream;

//Sets c++11 defaults for everything
Polynomial::Polynomial() = default;

Polynomial::Polynomial(std::initializer_list<long> co_list) {
    //sets coef from the start to end of the list
    coefs.assign(co_list.begin(), co_list.end());
    //sets degree to size-1 to account for the x^0
    if (co_list.size() == 0){
        degree = 0;
    }else{
        degree = co_list.size() - 1;
    }
    
}

Polynomial::Polynomial(std::deque<long>& co_list) { 
    //sets coef from the start to end of the list
    coefs.assign(co_list.begin(), co_list.end());
    //sets degree to size-1 to account for the x^0
    if (co_list.size() == 0){
        degree = 0;
    }else{
        degree = co_list.size() - 1;
    }
    
}

string Polynomial::poly_to_string(){
    string final;
    //loops through each degree
    for (int x = 0; x<= degree; x++){
        //checks to make sure there is a coefficient
        if (coefs[x] != 0){
            //includes an add if coefficient is not the last
            if (x>0){
                final += " + ";
            }
            //if degree is 1 there is no power
            if (degree - x == 1){
                final += std::to_string(coefs[x]) + "x";
            //sets power if greater than 1
            }else if(x != degree){
                final += std::to_string(coefs[x]) +"x^" + std::to_string(degree - x);
            //else there is no power so just the coefficient
            }else{
                final += std::to_string(coefs[x]);
            } 
            
        }
        
    }
        
    return final;
}

Polynomial Polynomial::add(Polynomial rhs){
    deque<long> large;
    deque<long> small;
    deque<long> last;
    long size_diff;

    //Finds which one is larger
    //At second look, it would be easier just to use the degree, but this 
    //works perfectly fine
    if (coefs.size() > rhs.coefs.size()){
        large = coefs;
        small = rhs.coefs;
    }else{
        large = rhs.coefs;
        small = coefs;
    }
    //Finds the difference between the two and adds 0s to the front of the 
    //smaller one
    size_diff = large.size() - small.size();
    for (long x=0; x<size_diff;x++){
        small.push_front(0);        
    }
    //Loops through the larger, adding each element to each other
    //and added to a new deque
    for (long x=0; x<large.size(); x++){
        last.push_back(large[x]+small[x]);      
    }

    Polynomial final(last);
    return final;
}

Polynomial Polynomial::mult(long factor){
    
    deque<long> new_coefs;
    //loops through the old coefficients, adding each to a new deque
    //multiplied by the factor
    for (int x=0; x<coefs.size() ;x++){
        new_coefs.push_back(coefs[x]*factor);
    }
    //Declares new polynomial with new coefficients
    Polynomial final(new_coefs);
    
    return final;
}

Polynomial Polynomial::mult(Polynomial rhs){
    
    deque<long> final_coefs;
    deque<long> temp_coefs;
    long second_degree = rhs.degree;
    Polynomial final({});
    Polynomial d;
    long num;
    
    //loops through the first polynomial
    for (int x=0;x<coefs.size();x++){  
        //resets the deque and num for temp polynomial
        temp_coefs = {};
        num = 0;
        //sets the temp_coefs to the length needed for this loops multiplication
        for (int i=0;i<=((degree-x)+(rhs.degree)) ;i++){
            //sets each part to 0
            temp_coefs.push_back(0);
        }
        //loops through the second polynomial multiplying each by
        //the current coefficient in first polynomial that is in use
        for (int y=0;y<=second_degree;y++){
            //multiplies the two numbers
            num = coefs[x] * rhs.coefs[y];
            //The location is equal to degree(size - 1) - current location in
            //the loop because the highest powered is stored first
            temp_coefs[ (temp_coefs.size()-1)-((degree-x)+(rhs.degree-y))] = num;
        }
        //creates a temp polynomial with temp coefficients
        Polynomial temp(temp_coefs);
        //adds to final
        d = final.add(temp);
        //sets final equal to the addition
        final = d;
        
    }
    
    return d;
}








