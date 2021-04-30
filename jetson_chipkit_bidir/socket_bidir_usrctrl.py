import socket
import struct
import time 
from smbus2 import SMBus

HOST = '10.0.0.20'  # The server's hostname or IP address
PORT = 65432        # The port used by the server

bus = SMBus(1)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        data = s.recv(4096)
        print(struct.unpack('BBBBBBBB',data))
        r = bus.read_byte_data(0x29,0x03)
        p1,p2,p3,p4,p5,p6,p7,p8 = tuple([bool(r >> i & 0x01) for i in range(8)])
        if p1 == True:
            s.sendall(b'a')
        else:
            pass
        bus.write_byte_data(0x29,0x00,0x00)
