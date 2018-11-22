#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	
	int bitNum = 2;
	if(argc == 2){
		bitNum = atoi(argv[1]);
	}else{
		cout << "Please specifiy the bit number to alter" << endl;
		return 1;
	}
	string msg;
	string polynomial;
	getline(cin, msg);
	getline(cin, polynomial);
	if(msg[bitNum-1] == '1'){
		msg[bitNum-1] = '0';
	}else{
		msg[bitNum-1] = '1';
	}
	cout << msg << endl;
	cout << polynomial << endl;

}