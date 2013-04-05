/*
 * IOModule.h
 *
 *  Created on: 05.04.2013
 *      Author: ihetterich
 */

#ifndef IOMODULE_H_
#define IOMODULE_H_

#define MAX_QUEUE_SIZE 10
#include <string>
#include <iostream>
#include <queue>
#include "Task.h"

class IOTask;

class BufferedIOModule {
public:
	BufferedIOModule();
	virtual ~BufferedIOModule();
	int send(std::string);
	std::string receive();

protected:
    IOTask *ioTask;

private:
	virtual std::string parseMessage(std::string msg);
	virtual std::string read();
	virtual void write(std::string);
    friend class IOTask;

};

class IOTask : public Tasks::Task {
public:
	IOTask(BufferedIOModule ioModule);
	virtual void *DoWork(void*);
	int send(std::string);
	std::string receive();
private:
    std::queue<std::string> incomingQueue;
    std::queue<std::string> outgoingQueue;
    BufferedIOModule ioModule;

};

#endif /* IOMODULE_H_ */
