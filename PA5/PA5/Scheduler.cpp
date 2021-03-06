#include "Scheduler.h"

Scheduler::Scheduler()
{
	this->P = 20; //Processor limit for running queue
	this->ID = 0;
	
}

//setter/getters for queue
void Scheduler::setRunningQueue(priority_queue<jobs> newRunningQueue)
{
	this->running_queue = newRunningQueue;
}

priority_queue<jobs> Scheduler::getRunningQueue()
{
	return this->running_queue;
}

void Scheduler::setTicks(int newNTicks)
{
	//this->getRunningQueue().top().n_ticks= newNTicks;
}

int Scheduler::getTicks()
{
	return this->running_queue.top().n_ticks;
}

void Scheduler::Prompt()
{
	cout << "Enter job description (string):";
	cin >> job1.job_description;

	cout << "Enter number of processors (int):";
	cin >> job1.n_procs;

	cout << "Enter number of ticks (int):";
	cin >> job1.n_ticks;
	
	this->ID += 1;
	
	job1.jobID = ID;

}

void Scheduler::Insert()
{
	Scheduler::Prompt();

	if (job1.n_ticks > 0)
	{
		this->wait_queue.push(job1);
	}
	else
	{
		cout << "Insert failed!" << endl;
	}
}

bool Scheduler::isEmpty()
{
	if (this->wait_queue.empty())
	{
		return true;
	}
	return false;
}
void Scheduler::printRunningQueue()
{
	{
		this->running_queueCopy = this->running_queue;

		cout << "---Running Queue---" << endl;
		while (!running_queueCopy.empty())
		{
			cout << "Job ID: " << running_queueCopy.top().jobID << endl;
			cout << "Job Description: " << running_queueCopy.top().job_description << endl;
			cout << "Job Processors: " << running_queueCopy.top().n_procs << endl;
			cout << "Job Ticks Left: " << running_queueCopy.top().n_ticks << endl << endl;
			running_queueCopy.pop();
		}
		cout << endl;

	}

}
void Scheduler::printWaitQueue()
{
	this->wait_queueCopy = this->wait_queue;

	cout << "---Wait Queue---" << endl;
	while (!wait_queueCopy.empty())
	{
		cout << "Job ID: " <<  wait_queueCopy.top().jobID << endl;
		cout << "Job Description: " << wait_queueCopy.top().job_description << endl;
		cout << "Job Processors: " << wait_queueCopy.top().n_procs << endl;
		cout << "Job Ticks Left: " << wait_queueCopy.top().n_ticks << endl;
		wait_queueCopy.pop();
	}
	cout << endl;
	
}

jobs Scheduler::FindShortest()
{
	jobs job;

	if (!isEmpty())
	{
		job = wait_queue.top();
	}
	else
	{
		cout << "Jobs wait queue empty!" << endl;
	}

	return job;
}

bool Scheduler::CheckAvailability(jobs job)
{
	if ((this->P - job.n_procs) >= 0)
	{
		return true;
	}
	return false;
}

void Scheduler::DeleteShortest(jobs job)
{
	if (CheckAvailability(job) == true)
	{
		this->wait_queue.pop();
		this->P = P - job.n_procs;
		RunJob(job);
	}
	/*else
	{
		cout << "Not available!" << endl;
	}*/
}

void Scheduler::RunJob(jobs job)
{
	this->running_queue.push(job);
}

void Scheduler::Decrement()
{
	priority_queue <jobs> pqTemp;
	this->running_queueCopy = this->running_queue; //

	while (!running_queue.empty())
	{
		job1.n_ticks -= 1;

		jobs t = this->running_queue.top();
		this->running_queue.pop();

		t.n_ticks -= 1;

		pqTemp.push(t);

	}
	running_queue = pqTemp;
}

void Scheduler::Release()
{
	if (running_queue.size() != 0) {
		if (this->running_queue.top().n_ticks <= 0)
		{
			this->P += running_queue.top().n_procs;
			this->running_queue.pop();
		}
	}
}

//simulates the program
void Scheduler::Tick()
{
	for (int i = 0; i < 10; i++) {
		Insert();
		
		Decrement();
		Release();
		while (this->P > 0 && wait_queue.size() != 0 && wait_queue.top().n_procs <= this->P) {
			DeleteShortest(job1);
		}
	}

	while (running_queue.size() != 0 || wait_queue.size() != 0) {
		Decrement();
		Release();
		while (wait_queue.size() != 0 && wait_queue.top().n_procs <= this->P  &&  this->P > 0) {
			DeleteShortest(wait_queue.top());
		}
	}
	//both prints should be empty
	printRunningQueue();
	printWaitQueue();
}