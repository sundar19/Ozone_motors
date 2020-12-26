For connecting Jetson,Chipkit & Curtis

Procedure for running without BUGS:
1.Switch on Curtis
2.Upload nmt_TCP to Chipkit
3.Run socket_client_orq.py in Jetson (use the commands)
4.Now upload sdo_TCP to chipkit
5.Now rerun socket_client_orq.py in Jetson

What are the BUGS?
CONSIDERING CURTIS TO BE SWITCHED ON AND IN OPERATIONAL STATE
1. Chipkit is reset & Jetson is running
Jetson cannot reestablish connection(Jetson ethernet should keep searching for connection and reestablish)
solution:try to put socket connection in a while loop, so that it keeps searching for connection even if there is a break in connection.


2.Jetson is reset & Chipkit is running
Jetson cannot reestablish connection (Chipkit ethernet should keep searching for connection and reestablish)
solution: In the timeout part of chipkit try to put chipkit in the initial(search for connection) state so that the chipkit keeps searching for a connection even if there is a timeout.

Other BUGS:
1.With curtis in operational state by default , it should be switched on and off and checked what happens to chipkit and jetson.
If in that case initialize CAN everytime when the connnection is cut between chipkit and curtis
2. The variable pushes dummy data which must be updated. The SDO values are found even if curtis is switched off.
Variable update is required
3. The sdo messages should not be got on request. It should be sent as a datastream.
4.Hex values must be decoded
