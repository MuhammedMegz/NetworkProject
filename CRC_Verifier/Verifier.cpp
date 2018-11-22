#include "Verifier.h"

Verifier::Verifier(string msg, string polynomial){

	setMsg(msg);
	setPolynomial(polynomial);

}

void Verifier::setMsg(string msg){

	this->msg.clear();
	for(int i=0, n=msg.length(); i<n; i++){
		if(msg[i] == '1')
			this->msg.push_back(1);
		else if(msg[i] == '0')
			this->msg.push_back(0);
	}

}

void Verifier::setPolynomial(string polynomial){

	this->polynomial.clear();
	for(int i=0, n=polynomial.length(); i<n; i++){
		if(polynomial[i] == '1')
			this->polynomial.push_back(1);
		else if(polynomial[i] == '0')
			this->polynomial.push_back(0);
	}

}

bool Verifier::crcCheck(){

	int cursor = 0;
	int msgLength = this->msg.size();
	int polyLength = this->polynomial.size();
	while(cursor < (msgLength-polyLength)){
		if(this->msg[cursor] == 0){//align with the next 1 in the dividend
			cursor++;
			continue;
		}
		for(int i=0; i<polyLength; i++){
			if(this->msg[cursor + i] == this->polynomial[i]){
				this->msg[cursor + i] = 0;
			}else{
				this->msg[cursor + i] = 1;
			}
		}
	}

	for(int j=msgLength-1; j>=msgLength-polyLength; j--){
		if(this->msg[j] == 1){
			return false;
		}
	}
	return true;
}