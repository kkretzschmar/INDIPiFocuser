/*
 * PiFocuser.h
 *
 *  Created on: Sep 6, 2014
 *      Author: klaus
 */

#ifndef PIFOCUSER_H_
#define PIFOCUSER_H_

#include "wiringPi.h"


class PiFocuser {
private:
	static const int shortSequenceCount=16;
	static const int longSequenceCount=32;
	static const int shortSequence[shortSequenceCount];
	static const int longSequence[longSequenceCount];
	static const int StepperPins [4];

public:
	enum Direction {
		left,
		right
	} ;
private:
	Direction m_direction;

public:


	PiFocuser();
	virtual ~PiFocuser(){}

	bool move(Direction direction, int stepCount);

};



#endif /* PIFOCUSER_H_ */
