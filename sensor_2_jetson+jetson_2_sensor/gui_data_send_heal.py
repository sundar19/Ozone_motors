#!/usr/bin/env python3
from multiprocessing import Process
import sys
import os
from PyQt4.QtCore import pyqtSlot 
from PyQt4.QtGui import *
import socket
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

def connection_recv():
    while True:
        try:
            data = s.recv(4096)
            print(struct.unpack('BBBBBBBB',data))
        except socket.timeout:
            print("disconnected...")
            os.system("python3 /home/ubuntu/gui_data_send_heal.py")

def connection_send():

    def on_click():
        s.sendall(b'a')
        print("light toggled")
    app = QApplication(sys.argv)
    w = QWidget()
    w.setWindowTitle('lights')
    btn = QPushButton('send data',w)
    btn.clicked.connect(on_click)

    btn.move(100,80)    
    w.show()
    app.exec_()

p1 = Process(target = connection_recv)
p1.start()               

p2 = Process(target = connection_send)
p2.start()



        


