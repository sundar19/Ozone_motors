#!/usr/bin/env python3

import socket


HOST = '10.0.0.20'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        print("Enter 'a' for CURTIS and 'b' for NXP")
        x = input()
        if(x == 'a'):
            print("Recieving CURTIS data ...")
            s.sendall(b'a')
        elif (x == 'b'):
            print("Recieving NXP data...")
            s.sendall(b'b')
        else:
            print("invalid")
        data = s.recv(1024)
        print(data)
