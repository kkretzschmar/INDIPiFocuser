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


bool PiFocuser::verbosity=false;

const int PiFocuser::StepperPins[] = { PIN1, PIN2, PIN3, PIN4 };

const int PiFocuser::shortSequence[] = { HIGH, LOW, LOW, LOW,
                                         LOW, HIGH, LOW, LOW,
                                         LOW, LOW, HIGH, LOW,
                                         LOW, LOW, LOW, HIGH };



const int PiFocuser::longSequence[] = { HIGH, LOW, LOW, LOW,
                                        HIGH, HIGH, LOW, LOW,
                                        LOW, HIGH, LOW, LOW,
                                        LOW, HIGH, HIGH, LOW,
                                        LOW, LOW, HIGH, LOW,
                                        LOW, LOW, HIGH, HIGH,
                                        LOW, LOW, LOW, HIGH,
                                        HIGH, LOW, LOW, HIGH };

PiFocuser::PiFocuser() :
		m_direction(PiFocuser::left) {
	wiringPiSetupGpio();
	for (int pin = 0; pin < 4; ++pin)
		pinMode(StepperPins[pin], OUTPUT);
}

void PiFocuser::setCycleCount(Direction dir, int& cycleCount){
	switch (dir){
	case PiFocuser::left:
		cycleCount=0;
		break;
	case PiFocuser::right:
		cycleCount=8-1;
		break;
	default:
		break;
	}
}

void PiFocuser::updateCycleCount(Direction dir, int& cycleCount){
	switch (dir){
	case PiFocuser::left:
		cycleCount++;
		break;
	case PiFocuser::right:
		cycleCount--;
		break;
	default:
		break;
	}
}

bool PiFocuser::move(Direction direction, int stepCount, int delayMillis) {
	int count = 0;
	int cycleCount;
	setCycleCount(direction,cycleCount);
	while (count < stepCount) {

		for (int stepPin = 0; stepPin < 4; stepPin++) {
			int value = longSequence[cycleCount * 4 + stepPin];
			if (verbosity) {
				if (value)
					cout << "Enable pin" << StepperPins[stepPin] << endl;
				else
					cout << "Disable pin" << StepperPins[stepPin] << endl;
			}
			digitalWrite(StepperPins[stepPin], value);
		}
		if ((cycleCount < 8) && (cycleCount > -1)) {
			updateCycleCount(direction,cycleCount);
		} else {
			setCycleCount(direction,cycleCount);
		}
		delay(delayMillis); //ms
		count++;
	}
	return true;

}

