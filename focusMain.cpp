/*
 * focusMain.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: klaus
 */

#include <iostream>
#include "PiFocuser.h"

using namespace std;

int main(){
	PiFocuser piFocuser;
	cout <<"PiFocuser object created."<<endl;

	cout <<"PiFocuser move 100 steps in left direction."<<endl;
	piFocuser.move(PiFocuser::left,100,50);
	cout <<"PiFocuser move 100 steps in right direction."<<endl;
	piFocuser.move(PiFocuser::right,100,50);
	cout <<"PiFocuser move finished."<<endl;
}


