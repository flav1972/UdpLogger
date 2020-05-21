#include "WiFiUdp.h"

#ifndef _UDPLOGGER_H_
#define _UDPLOGGER_H_

class UdpLogger
{
    public:
        UdpLogger();
        UdpLogger(int port);
        UdpLogger(const char* prefix, int port = 12345);

        void WriteStartMessage();
        void print(int number);
        void print(char c);
        void print(String message);
        void println(String message);
        void println(int number);

    private:
        void transmit();

    protected:
        WiFiUDP _udp;
        int _port;
        String _current;
        String _prefix; 
};

#endif