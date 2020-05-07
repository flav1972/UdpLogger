#!/usr/bin/env python
import socket
import sys

UDP_PORT = 12345

#---socket creation
sock = socket.socket(socket.AF_INET,    # Internet (IP)
                          socket.SOCK_DGRAM) # UDP

# Enable port reusage so we will be able to run multiple clients and servers on single (host, port).
# Do not use socket.SO_REUSEADDR except you using linux(kernel<3.9): goto https://stackoverflow.com/questions/14388706/how-do-so-reuseaddr-and-so-reuseport-differ for more information.
# For linux hosts all sockets that want to share the same address and port combination must belong to processes that share the same effective user ID!
# So, on linux(kernel>=3.9) you have to run multiple servers and clients under one user to share the same (host, port).
# Thanks to @stevenreddie
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)

# Enable broadcasting mode
sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

#---Bind
try:
    sock.bind(('', UDP_PORT))
except socket.error:
    print "connexion failed"
    sock.close()
    sys.exit()

#---testing
while True:
    data, (host, port) = sock.recvfrom(1024) # buffer size is 1024 bytes
    print "from : "+host+" : "+data
