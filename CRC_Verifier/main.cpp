#include <iostream>
#include <string>
#include "Verifier.h"

using namespace std;

int main(){

	string msg;
	string polynomial;
	getline(cin, msg);
	getline(cin, polynomial);
	Verifier crcVerifier(msg, polynomial);
	bool result = crcVerifier.crcCheck();
	if(result){
		cout << "Message is correct" << endl;
	}else{
		cout << "Message is incorrect" << endl;
	}

}