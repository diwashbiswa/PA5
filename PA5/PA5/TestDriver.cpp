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
	
/*	clock_t start;
	start = clock();
	double timer = (clock() - start) / (double)CLOCKS_PER_SEC;
*///cout << "MINIMUM: " << schedule.FindShortest() << endl;

	for (int i = 0; i < 3; i++)
	{
		schedule.Tick();
	}
	
	schedule.printQueue();

	return 0;
}