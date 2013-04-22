/*
 * Task.cpp
 *
 *  Created on: 23.03.2013
 *      Author: uwalter
 */

#include <pthread.h>
#include <signal.h>

#include "Task.h"

namespace Tasks
{

	Task::Task()
	{
		m_Counter = 0;
		m_ThreadId = 0;
		m_Name = "Thread";
		m_Arg = NULL;
	}

	Task::Task(string name)
	{
		m_Counter = 0;
		m_ThreadId = 0;
		m_Name = name;
		m_Arg = NULL;
	}

	Task::Task(string name,void* arg)
	{
		m_Counter = 0;
		m_ThreadId = 0;
		m_Name = name;
		m_Arg = arg;
	}

	Task::~Task()
	{
	}

	void Task::Run()
	{
		pthread_create(&m_ThreadId,NULL,&m_ThreadFunction,this);
	}

	void *Task::DoWork(void *arg)
	{
		return 0;
	}

} /* namespace Task */
