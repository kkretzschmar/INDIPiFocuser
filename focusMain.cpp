/*
 * focusMain.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: klaus
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "PiFocuser.h"

using namespace std;

int main(int argc, char* argv[]){
	PiFocuser piFocuser;
        int duration=100;
        int delay=1;
        PiFocuser::Direction direction=PiFocuser::left;
        //Parse arguments 
	while (argc-->1){
           if (strcmp(argv[argc-1],"--direction")==0){
             if (strcmp(argv[argc],"right")==0){
                direction=PiFocuser::right;
             }
           }
           if (strcmp(argv[argc-1],"--duration")==0){
              duration=atoi(argv[argc]);
           }
           if (strcmp(argv[argc-1],"--delay")==0){
              delay=atoi(argv[argc]);
           }
           argc--;
        }
	PiFocuser::verbosity=false;
	cout <<"PiFocuser object created."<<endl;
	
	
	if (direction==PiFocuser::left)
	   cout <<"PiFocuser move "<<duration<<" steps in left direction with delay "<<delay<<endl;
        else
	   cout <<"PiFocuser move "<<duration<<" steps in right direction with delay "<<delay<<endl;

	piFocuser.move(direction,duration,delay);
	cout <<"PiFocuser move finished."<<endl;
}


