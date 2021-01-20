from smbus2 import SMBus
import time

# Open i2c bus 1 and read one byte from address 0x29, offset 0x03
bus = SMBus(1)

while True:
 r = bus.read_byte_data(0x29,0x03)
 p1,p2,p3,p4,p5,p6,p7,p8 = tuple([bool(r >> i & 0x01) for i in range(8)])
 #print(p1,p2,p3,p4,p5,p6,p7,p8)

 if p1 == True:
  print("PIN 1 is touched..")
 elif p2 == True:
  print("PIN 2 is touched..")
 elif p3 == True:
  print("PIN 3 is touched..")
 elif p4 == True:
  print("PIN 4 is touched..")
 elif p5 == True:
  print("PIN 5 is touched..")
 elif p6 == True:
  print("PIN 6 is touched..")
 elif p7 == True:
  print("PIN 7 is touched..")
 elif p8 == True:
  print("PIN 8 is touched..")
  
 bus.write_byte_data(0x29,0x00,0x00)
 time.sleep(1)
