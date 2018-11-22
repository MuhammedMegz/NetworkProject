#ifndef __VERIFIER__H
#define __VERIFIER__H

#include <iostream>
#include <vector>

using namespace std;

class Verifier{

	vector<bool>msg;
	vector<bool>polynomial;

public:

	Verifier(string msg, string polynomial);
	void setMsg(string msg);
	void setPolynomial(string polynomial);
	bool crcCheck();
};

#endif