#include "WiFiUdp.h"
#include "UdpLogger.h"
#include "stdlib_noniso.h"

/**
 * constructors
 */
UdpLoggerClass::UdpLoggerClass()
{
    _port = 12345;
}

UdpLoggerClass::UdpLoggerClass(int port)
{
    _port = port;
}

UdpLoggerClass::UdpLoggerClass(const char* prefix, int port)
{
    _port = port;
    _prefix = prefix;
    _current = prefix;
}

void UdpLoggerClass::WriteStartMessage()
{
    println("Logging");
}

void UdpLoggerClass::print(int number)
{
    char buffer[33];
    itoa(number, buffer, 10);
    print(buffer);
}

void UdpLoggerClass::print(String message)
{
    _current += message;
}

void UdpLoggerClass::println(String message)
{
    print(message);
    transmit();
}

void UdpLoggerClass::println(int number)
{
    print(number);
    transmit();
}

void UdpLoggerClass::transmit()
{
    _udp.beginPacket("255.255.255.255", _port);
    _udp.write(_current.c_str());
    _udp.endPacket();
    _current = _prefix;
}
