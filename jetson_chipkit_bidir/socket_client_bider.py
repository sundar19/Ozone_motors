#!/usr/bin/env python3

import socket
import struct
import time

HOST = '10.0.0.20'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        data = s.recv(4096)
        print(struct.unpack('BBBBBBBB',data))
        s.sendall(b'a')
        
        


