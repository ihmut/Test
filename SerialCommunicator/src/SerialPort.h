/*
 * SerialPort.h
 *
 *  Created on: 04.04.2013
 *      Author: ihetterich
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_
#include <string>
#include <iostream>
#include "boost/asio.hpp"
#include "boost/system/system_error.hpp"
#include "IOModule.h"

class SerialPort : public BufferedIOModule {
public:
	SerialPort();
	SerialPort(std::string device);
	int open();
	int close();
	int setBaudRate(int baud);

private:
    boost::asio::io_service 	ioService;
    boost::asio::serial_port 	serialPort;
    int baudRate;
    std::string device;
    BufferedIOModule ioModule;
	//virtual void parseMessage();
	virtual std::string read();
	virtual void write(std::string);
};
#endif /* SERIALPORT_H_ */

