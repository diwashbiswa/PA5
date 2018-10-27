#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <time.h>

using namespace std;

struct jobs
{
	int jobID;
	int n_procs;
	int n_ticks = 0;
	string job_description;

	bool operator<(const jobs& rhs) const
	{
		return n_ticks > rhs.n_ticks;
	}

};

class Scheduler
{
public:
	Scheduler();

	//promps the user for new job
	void Prompt();

	void ReadFromFile();

	//inserts the job into the wait queue (if the user submitted a valid job)
	//checks if (0 < n_procs <= p) and (n_ticks > 0). If so, it inserts
	//the job into a "wait queue". Otherwise, a job submission error is raised
	//with an appropriate message
	void Insert();

	//checks to see if wait_queue is empty
	bool isEmpty();

	//prints the element in the queue
	void printWaitQueue();
	void printRunningQueue();
	//a job with the mimimum value for n_ticks
	jobs FindShortest();

	//checks if there are at leat pi processors currently available in the processor
	bool Scheduler::CheckAvailability(jobs job);

	//removes ji from the wait queue
	void Scheduler::DeleteShortest(jobs job);

	//executes the job from the next tick
	void RunJob(jobs job);

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

	void Tick();

	void setRunningQueue(priority_queue <jobs> newRunningQueue);
	priority_queue<jobs> getRunningQueue();
	void setTicks(int newNTicks);
	int getTicks();

private:
	int ID;
	int P;
	int free_pool_processors;
	jobs job1;

	priority_queue <jobs> running_queue;
	priority_queue <jobs> wait_queue;
	priority_queue <jobs> wait_queueCopy;
	priority_queue <jobs> running_queueCopy;
};