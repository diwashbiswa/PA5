#include <iostream>
#include <queue>

using namespace std;

class Tick
{
public:

//some functions needed for this Tick operations //not sure the parameters
	//prompts the user for submitting a new job
	void Prompt();

	//inserts the job into the wait queue (if the user submitted a valid job)
	void Insert();

	//decrements the timer for all running jobs in the running queue
	void Decrement();

	//release all the processors corresponding to the completed/expired jobs from the
	//running queue to the free pool. "expired" job means its timer becomes zero during this
	//tick. Also, any expired job should be automatically removed from the running job queue
	void Release();

	//finds the next shortest job (<ji, pi, ti>) from the wait queue and check if sufficient
	//number of processors are available in the free pool to run it. If so:
	//	a. remove job Ji from the wait queue;
	//	b. insert job Ji into the running queue and assign pi processors (from free pool) to that job.
	//	   if after this first job allocation, there are still more jobs in the wait queue that have sufficient
	//	   processors to run on, then iteratively keep moving all the next shortest jobs until no mroe processors
	//	   are available for the next shortest job, or the wait queue becomes empty.
	void Find();
private:

};