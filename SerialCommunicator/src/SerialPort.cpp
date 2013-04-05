/*
 * SerialPort.cpp
 *
 *  Created on: 04.04.2013
 *      Author: ihetterich
 */

#include <string>
#include <iostream>

#include "boost/asio.hpp"

#include "IOModule.h"
#include "SerialPort.h"

SerialPort::SerialPort() : BufferedIOModule(),
	serialPort(ioService),
	baudRate(9600),
	device("/dev/ttyS0")
{
}

SerialPort::SerialPort(std::string device) : BufferedIOModule(),
	serialPort(ioService),
	baudRate(9600),
	device(device)
{
}

int SerialPort::setBaudRate(int baud)
{
	baudRate = baud;
	return 0;
}

int SerialPort::open()
{
	using namespace boost::asio;
	serialPort.open(device);
	serialPort.set_option(serial_port::baud_rate(baudRate));
	ioTask->Run();
	return 0;
}

int SerialPort::close() {
	serialPort.close();
	return 0;
}

std::string SerialPort::read() {
    std::string result = "";
	/*
    using namespace boost;
    char c;
    std::string result;
    for(;;)
    {
        asio::read(serialPort,asio::buffer(&c,1));
        switch(c)
        {
            case '\r':
                break;
            case '\n':
                return result;
            default:
                result+=c;
        }
    }
    */
    return result;
}

void SerialPort::write(std::string msg) {
    using namespace boost::asio;
	std::cout << msg << std::endl;
    //serialPort.write_some(buffer(msg));
}





