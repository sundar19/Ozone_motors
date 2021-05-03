#!/usr/bin/env python3
import socket
#from socket import error as SocketError
import os
import struct
import time


HOST = '10.0.0.20'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

def connect():
    global s
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
connect()
s.settimeout(10)
while True:
    try:
        data = s.recv(4096)
        print(struct.unpack('BBBBBBBB',data))
        s.sendall(b'a')
    except socket.timeout:
        print("disconnected")
        os.system('python3 /home/ubuntu/heal_socket.py')
 