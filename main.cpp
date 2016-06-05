//
//  main.cpp
//  montePI
//
//  Stance Jones
//  CSCI 127
//

#include <random>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    //Pls change this value to 1000, 100000 as required in the assignment to see the difference of the result.
    const int NUMBER_OF_DATA_POINT = 1000000;
    
    //This part is related to the random number generate.
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1,1.0);
    
    
    double number_of_candy_in_A,number_of_candy_in_B,total_number;
    double random_number_x,random_number_y;
    
    number_of_candy_in_A = 0;
    total_number = NUMBER_OF_DATA_POINT;
    
    for (int i=0; i < NUMBER_OF_DATA_POINT; i++){
        
        //generate the candy rain with the scope of 3*3.
        random_number_x = dist(mt);
        random_number_y = dist(mt);
        
        
        //decide whether the candy rain will be caught by bowl A. Also as the candy rain is 3*3 which is exactly the same scope of bowl B, so all the candy rain will be caught by bowl B.
        if(sqrt((pow(random_number_x, 2) + pow(random_number_y,2))) <= 1){
            
            number_of_candy_in_A++;
        }
        
        
    }
    
    // as the candy rain is 3*3 which is exactly the same scope of bowl B, so all the candy rain will be caught by bowl B.
    number_of_candy_in_B=total_number;
    
    cout << "Number of data points: " << total_number << endl;
    cout << "Estimation of PI: " << (4 * (number_of_candy_in_A/number_of_candy_in_B)) << endl;
    cout<<"Ratio of area A to area B is equal to: "<<(number_of_candy_in_A/number_of_candy_in_B)<<endl;
    
    return 0;
}