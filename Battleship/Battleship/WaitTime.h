#ifndef WAITTIME_H
#define WAITTIME_H

#include "Common.h"

class WaitTime
{
private:
	int hour, minute, sec;
	
public:
	WaitTime();
	~WaitTime();

	void printTime();//����� �������
	void goTime();//��������� �������
};

#endif WAITTIME_H