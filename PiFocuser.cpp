/*
 * PiFocuser.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: klaus
 */
#include <iostream>

#include "PiFocuser.h"

using namespace std;

#define PIN1 18
#define PIN2 17
#define PIN3 22
#define PIN4 27


	const int PiFocuser::StepperPins[] = {PIN1,PIN2,PIN3,PIN4};

	const int PiFocuser::shortSequence[] = { HIGH,LOW,LOW,LOW,
			                           LOW,HIGH,LOW,LOW,
			                           LOW,LOW,HIGH,LOW,
			                           LOW,LOW,LOW,HIGH};

	const int PiFocuser::longSequence[] = { HIGH,LOW,LOW,LOW,
			                          HIGH,HIGH,LOW,LOW,
				                      LOW,HIGH,LOW,LOW,
				                      LOW,HIGH,HIGH,LOW,
	                                  LOW,LOW,HIGH,LOW,
	                                  LOW,LOW,HIGH,HIGH,
	                                  LOW,LOW,LOW,HIGH,
	                                  HIGH,LOW,LOW,HIGH};




	PiFocuser::PiFocuser():m_direction(PiFocuser::left){
		wiringPiSetup();
		for (int pin = 0 ; pin < 4 ; ++pin)
		    pinMode (StepperPins[pin], OUTPUT) ;
	}

	bool PiFocuser::move(Direction direction, int stepCount){
		int count=0;
		while (count<stepCount){


			for (int stepPin=0; stepPin<PiFocuser::shortSequenceCount; stepPin++){
				int value=shortSequence[stepPin];
				if (value)
					cout <<"Enable pin"<<StepperPins[stepPin]<<endl;
				else
					cout <<"Disable pin"<<StepperPins[stepPin]<<endl;
				digitalWrite(StepperPins[stepPin], value);
			}

			delay(500); //ms
			count++;
		}
		return true;

	}


