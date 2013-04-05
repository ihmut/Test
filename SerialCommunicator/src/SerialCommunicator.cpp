//============================================================================
// Name        : SerialCommunicator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include "boost/asio.hpp"
#include "boost/system/system_error.hpp"
#include "SerialPort.h"

void readTest()
{
    using namespace boost::system;
    using namespace boost::asio;

    io_service ioService;
    serial_port serialPort(ioService);

    try
    {
        serialPort.open("/dev/ttyS0");

        serialPort.set_option(serial_port::baud_rate(9600));

        std::string s;
        using namespace boost;
        char c;
        std::string result = "";
        int testcounter = 3;
        while(testcounter>0)
        {
            asio::read(serialPort,asio::buffer(&c,1));
            switch(c)
            {
                case '\r':
                    break;
                case '\n':
                	std::cout << result << std::endl;
                	result = "";
                	testcounter--;
                	break;
                default:
                    result+=c;
            }
        }

        serialPort.close();
    }
    catch (system_error& error)
    {
        std::cout << error.what() << std::endl;
    }
}

void writeTest() {
    using namespace boost::system;
    using namespace boost::asio;

    io_service ioService;
    serial_port serialPort(ioService);

    try
    {
        serialPort.open("/dev/ttyS0");

        serialPort.set_option(serial_port::baud_rate(9600));

        std::string s = "test\r\n";
        serialPort.write_some(buffer(s));

        serialPort.close();
    }
    catch (system_error& error)
    {
        std::cout << error.what() << std::endl;
    }

}

void communicatorTest() {
    SerialPort sp;
    sp.open();
    sp.send("bla");
    std::string msg=sp.receive();
}

int main(int argc, char **argv)
{
    readTest();
    writeTest();
    communicatorTest();

}
