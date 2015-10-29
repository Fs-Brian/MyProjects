#include <cstdlib>
#include <iostream>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
using std::sqrt;
using std::pow;


double bull_to_bill(double bill_x,double bill_y,double bull_x,double bull_y){
        double distance,x_dis,y_dis;
        //get differences
        x_dis=bill_x - bull_x;
        y_dis=bill_y - bull_y;
        //sqrt of differnces squared 
        distance = sqrt(pow(x_dis,2)+pow(y_dis,2));
        
        return distance;
}

void update_bull(double bill_x,double bill_y,double & bull_x,double & bull_y,        
        double bull_speed){
    //Declare
    double distance = bull_to_bill(bill_x, bill_y,bull_x,bull_y);
    double x_dif,y_dif,angle;    
    //Get difference   
    x_dif = bill_x-bull_x;
    y_dif = bill_y-bull_y;    
    //Take the arctan of x/y
    angle = atan2(y_dif,x_dif);
    //Update bull x/y due to new distance vector and the angle
    bull_y += bull_speed * sin(angle);
    bull_x += bull_speed * cos(angle);     
    
}

int main() {
    //Declare
    double bill_x,bill_y,bill_speed;
    double bull_x,bull_y,bull_speed;
    double distance;
    //Prompts
    cout << "bill (x y speed): ";
    cin >> bill_x>> bill_y>> bill_speed;
    cout << "Bull (x y speed): ";
    cin >> bull_x>> bull_y>> bull_speed;
    //get distance
    distance = bull_to_bill(bill_x, bill_y,bull_x,bull_y);
    
    cout << "Hiker(" << bill_x << "," << bill_y << "), Bull:(" <<
                bull_x<<"," << bull_y << "), Dist:" << distance << endl;
    //Increments bill y by his speed   
    bill_y = bill_y + bill_speed;
     
    while (bill_y < 100){
        //get distance
        distance = bull_to_bill(bill_x, bill_y,bull_x,bull_y);        
        //If bulls speed is greater than the distance, bull caught bill
        if (bull_speed >= distance){
            bull_x=bill_x;
            bull_y=bill_y;
            break;
        //else update the bulls speed by a formula
        }else{
            update_bull(bill_x, bill_y,bull_x,bull_y,bull_speed);
        }
        //distance refresh for output
        distance = bull_to_bill(bill_x, bill_y,bull_x,bull_y);
        //output
        cout << "Hiker(" << bill_x << "," << bill_y << "), Bull:(" <<
                bull_x<<"," << bull_y << "), Dist:" << distance << endl;
        //Increments bill y by his speed
        bill_y = bill_y + bill_speed;
       
    }
    //final output
    distance = bull_to_bill(bill_x, bill_y,bull_x,bull_y);
    cout << "Hiker(" << bill_x << "," << bill_y << "), Bull:(" <<
                bull_x<<"," << bull_y << "), Dist:" << distance << endl;            
    //Check if he made it or not
    if(bill_y >= 100){
        cout <<"He made it, good running!";
    }else{
        cout << "The bull got him!";
    }
    
    cout << endl;
    return 0;
}

