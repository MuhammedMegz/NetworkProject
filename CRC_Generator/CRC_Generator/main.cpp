//
//  main.cpp
//  CRC_Generator
//
//  Created by Megz on 11/20/18.
//  Copyright © 2018 Muhammed Magdy Taha. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> message = {1,0,1,1,0,0,1};
vector<int> div_;
vector<int> divisor = {1,0,1};
vector<int> reminder;
vector<int> crc;
int mBits, divBits, tLength;

void divide(vector<int> div_, vector<int> divisor, vector<int> reminder);
string vector_to_string(vector<int> intVector);

int main() {
    
    tLength = mBits + divBits - 1;
    
    for (int i = 0 ; i < message.size(); i++)
        div_[i] = message[i];
    
    for(int i = 0 ; i < div_.size() ; i++)
        reminder[i] = div_[i];
    
    divide(div_, divisor, reminder);
    
    for (int i = 0 ; i < div_.size(); i++)
        crc[i] = div_[i] ^ reminder[i];
    
    string crc_code  = vector_to_string(crc);

    return 0;
    
}


void divide(vector<int> div_, vector<int> divisor, vector<int> reminder){
    int current = 0;
    while(1){
        for (int i = 0 ; i < divisor.size(); i++)
            reminder[current + i] = (reminder[current + i] ^ divisor[i]);
        
        while(reminder[current] == 0 && (current != reminder.size()-1))
            current++;
        
        if((reminder.size() - current) < divisor.size())
            break;
    }
}

string vector_to_string(vector<int> intVector) {
    string returnstring = "";
    for (int i = 0 ; i < intVector.size() ; i++){
        char c = intVector[i];
        returnstring += c;
    }
    return returnstring;
}







