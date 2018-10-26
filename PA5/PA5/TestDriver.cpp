/**********************************************************************************************************
Programmers: Diwash Biswa, Drew McLaurin
Programming Assignment: PA5 Priority Queue
Date Started: 10/24/18
Date Due: 10/26/18
Comments:
***********************************************************************************************************/

#include "Scheduler.h"

int main(void)
{
	Scheduler schedule;

	//schedule.ReadFromFile();
	
	for (int i = 0; i < 3; i++)
	{
		schedule.Tick();
	}
	

	schedule.printRunningQueue();

	//input.close();

	return 0;
}