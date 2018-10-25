#include "Tick.h"

class Event
{
public:
//some functions required. parameters???

	//checks if (0 < n_procs <= p) and (n_ticks > 0). If so, it inserts
	//the job into a "wait queue". Otherwise, a job submission error is raised
	//with an appropriate message
	void InsertJob();

	//a job with the mimimum value for n_ticks
	void FindShortest();

	//checks if there are at leat pi processors currently available in the processor
	bool CheckAvailability();

	//removes ji from the wait queue
	void DeleteShortest();

	//executes the job from the next tick
	void RunJob();
};