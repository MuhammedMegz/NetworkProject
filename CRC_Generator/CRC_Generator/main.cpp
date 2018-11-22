//
//  main.cpp
//  CRC_Generator
//
//  Created by Megz on 11/20/18.
//  Copyright © 2018 Muhammed Magdy Taha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> message;
vector<int> div_;
vector<int> divisor;
vector<int> reminder;
vector<int> crc;
int mBits, divBits, tLength;

string messageStr;
string divisorStr;

void divide();
string vector_to_string(vector<int> intVector);

int main() {
    
    //cout<<"enter the message";
    getline(cin, messageStr);
    
    //cout << "enter the divisor";
    getline(cin, divisorStr);
    
    for (int i = 0 ; i < messageStr.length(); i++) {        //convert message string to binary vector
        if(messageStr[i] == '0')
            message.push_back(0);
        else if(messageStr[i] == '1')
            message.push_back(1);
    }
    
    for (int i = 0 ; i < divisorStr.length() ; i++) {       //convert divisor string to binary vector
        if(divisorStr[i] == '0')
            divisor.push_back(0);
        else if(divisorStr[i] == '1')
            divisor.push_back(1);
    }
    
    mBits = messageStr.length();
    divBits = divisorStr.length();
    tLength = mBits + divBits - 1;
    
    for (int i = 0 ; i < message.size(); i++)
        div_.push_back(message[i]);
    
    for(int i = 0 ; i < div_.size() ; i++)
        reminder.push_back(div_[i]);
    
    for (int i =0 ; i < divBits-1; i++){
        reminder.push_back(0);
        div_.push_back(0);
    }
    
    
    divide();
    
    for (int i = 0 ; i < div_.size(); i++)
        crc.push_back(div_[i] ^ reminder[i]);
    
    string crc_code  = vector_to_string(crc);
    cout << crc_code << "\n";
    cout << vector_to_string(divisor) << "\n";
    
    return 0;
}


void divide(){
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
        char c = '0' + intVector[i];
        returnstring += c;
    }
    return returnstring;
}
