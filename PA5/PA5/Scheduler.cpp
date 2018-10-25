#include "Scheduler.h"

Scheduler::Scheduler()
{
	this->P = 1000;
	this->ID = 0;
	//job1 = nullptr;
	//this->job_description = "";
	//this->n_procs = 0;
	//this->n_ticks = 0;
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

	if ((job1.n_procs > 0 && job1.n_procs <= this->P) && (job1.n_ticks > 0))
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

void Scheduler::printQueue()
{
	this->wait_queueCopy = this->wait_queue;

	//while (!this->wait_queue.empty())
	//{
	//	cout << this->wait_queue.top().n_procs << endl;
	//	cout << this->wait_queue.top().jobID << endl;
	//	cout << this->wait_queue.top().job_description << endl;
	//	cout << this->wait_queue.top().n_ticks << endl;
	//	this->wait_queue.pop();
	//	cout << endl;
	//}
	//cout << endl;

	while (!wait_queueCopy.empty())
	{
		cout << wait_queueCopy.top().jobID << endl;
		cout << wait_queueCopy.top().job_description << endl;
		cout << wait_queueCopy.top().n_procs << endl;
		cout << wait_queueCopy.top().n_ticks << endl;
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
	if ((this->P - job.n_procs) > 0)
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
	this->running_queueCopy = this->running_queue;

	while (!running_queue.empty())
	{
		job1.n_ticks -= 1;

		this->running_queue.top()->n_ticks -= 1;
		this->running_queue.pop();
	}
}

void Scheduler::Release()
{
}

void Scheduler::Find()
{
}

void Scheduler::Tick()
{
	//Prompt();
	Insert();
	DeleteShortest(job1);
	Decrement();
	Release();
	Find();
}


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
