#include "WiFiUdp.h"
#include "UdpLogger.h"
#include "stdlib_noniso.h"

/**
 * constructors
 */
UdpLogger::UdpLogger()
{
    _port = 12345;
}

UdpLogger::UdpLogger(int port)
{
    _port = port;
}

UdpLogger::UdpLogger(const char* prefix, int port)
{
    _port = port;
    _prefix = prefix;
    _current = prefix;
}

void UdpLogger::WriteStartMessage()
{
    println("Logging");
}

void UdpLogger::print(int number)
{
    char buffer[33];
    itoa(number, buffer, 10);
    print(buffer);
}

void UdpLogger::print(String message)
{
    _current += message;
}

void UdpLogger::println(String message)
{
    print(message);
    transmit();
}

void UdpLogger::println(int number)
{
    print(number);
    transmit();
}

void UdpLogger::transmit()
{
    _udp.beginPacket("255.255.255.255", _port);
    _udp.write(_current.c_str());
    _udp.endPacket();
    _current = _prefix;
}
