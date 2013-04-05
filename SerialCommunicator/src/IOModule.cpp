/*
 * IOModule.cpp
 *
 *  Created on: 05.04.2013
 *      Author: ihetterich
 */

#include <queue>

#include "IOModule.h"


BufferedIOModule::BufferedIOModule() : ioTask() {
	// TODO Auto-generated constructor stub

}

BufferedIOModule::~BufferedIOModule() {
	// TODO Auto-generated destructor stub
}

int BufferedIOModule::send(std::string msg) {
	return ioTask->send(msg);
}

std::string BufferedIOModule::receive() {
	return ioTask->receive();
}

std::string BufferedIOModule::read() {
	std::string msg = "";
	return msg;
}

void BufferedIOModule::write(std::string msg) {
}

std::string BufferedIOModule::parseMessage(std::string msg) {
	return msg;
}

IOTask::IOTask(BufferedIOModule ioModule) : Task(), ioModule(ioModule) {}

void *IOTask::DoWork(void *arg) {
	std::string msg;
	while(true) {
		while(!outgoingQueue.empty()) {
			msg = outgoingQueue.front();
			ioModule.write(msg);
			outgoingQueue.pop();
		}
		std::cout << msg << std::endl;
		msg = ioModule.read();
		incomingQueue.push(msg);
	}
	return 0;
}

std::string IOTask::receive() {
	std::string msg = "";
	if(!incomingQueue.empty()) {
		msg = incomingQueue.front();
		incomingQueue.pop();
	}
	return msg;
}

int IOTask::send(std::string msg) {
	if(outgoingQueue.size() < MAX_QUEUE_SIZE) {
		std::cout << msg << std::endl;
		outgoingQueue.push(msg);
		return 0;
	}
	else return 1;
}

