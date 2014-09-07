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

	piFocuser.move(PiFocuser::left,10000);
	cout <<"PiFocuser move finished."<<endl;
}


