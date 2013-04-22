/*
 * Task.h
 *
 *  Created on: 23.03.2013
 *      Author: uwalter
 */

#ifndef TASK_H_
#define TASK_H_

#include <stdio.h>
#include <iostream>

#include <string>
using namespace std;

namespace Tasks
{

	class Task
	{
		public:
		int m_Counter;
		pthread_t m_ThreadId;
		void* m_Arg;

		protected:
		string m_Name;
		private:
		static void* m_ThreadFunction(void* This) { return ((Task*)This)->DoWork(This); }

		public:
		Task();
		Task(string);
		Task(string,void*);
		virtual ~Task();

		public:
		void Run();
		virtual void *DoWork(void *arg);
	};

} /* namespace Task */
#endif /* TASK_H_ */
