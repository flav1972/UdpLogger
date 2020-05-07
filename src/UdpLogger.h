#include "WiFiUdp.h"

class UdpLoggerClass
{
    public:
        UdpLoggerClass();
        UdpLoggerClass(int port);
        UdpLoggerClass(const char* prefix, int port = 12345);

        void WriteStartMessage();
        void print(int number);
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
