/* 
 * File:   main.cpp
 * Author: jonesb63
 *
 * Created on September 11, 2014, 11:18 AM
 */

#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {
    //Declare variables
    int x,y,order_int,start_int;
    //Get user input
    cout << "Order: " << endl;
    cin >> order_int;
    cout << "Start: " << endl;
    cin >> start_int;
    //Checks order
    if(order_int>=2){
        //Checks start int
        if(start_int<=order_int && start_int > 0){
            //first loop, it skips a line after horizontal line is finished
                for (x=1; x<=order_int;x++){
                cout << endl ;
        //second loop, goes through each line prints a number with a space
                        for (y=1; y<=order_int; y++){
                                cout << " " << start_int;
            //Checks if the number is at the order, if it is sets back to 1
            //Otherwise, it will increment it
                                if (start_int==order_int){
                                        start_int=1;
                                }else{
                                        start_int++; 
                                }
                }
        //Since there is a different of 2 between the end of 1 line and start
        //of the next line in the Latin square, you just when another if/else 
        //statement to increment it before starting to print on the new line
                        if (start_int==order_int){
                                start_int=1;
                        }else{
                                start_int++;
                        }
                }      
        }else{
            cout << "Start_int must be > 0 and <= order";
        }        
    }else{
        cout << "Order must be >= 2";
    }
  
  
    
    return 0;
}

