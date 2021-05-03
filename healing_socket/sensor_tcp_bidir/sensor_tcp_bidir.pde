/************************************************************************/
/*                                                                      */
/*  TCPEchoServer                                                       */
/*                                                                      */
/*  A chipKIT DNETcK TCP Server application to                          */
/*  demonstrate how to use the TcpServer Class.                         */
/*  This can be used in conjuction with TCPEchoClient                   */    
/*                                                                      */
/************************************************************************/
/*  Author:     Keith Vogel                                             */
/*  Copyright 2011, Digilent Inc.                                       */
/************************************************************************/
/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/
/*                                                                      */
/*                                                                      */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*  12/19/2011(KeithV): Created                                         */
/*    11/13/2012(KeithV): Modified to be generic for all HW libraries   */
/*                                                                      */
/************************************************************************/

//******************************************************************************************
//******************************************************************************************
//***************************** SET YOUR CONFIGURATION *************************************
//******************************************************************************************
//******************************************************************************************

/************************************************************************/
/*                                                                      */
/*              Include ONLY 1 hardware library that matches            */
/*              the network hardware you are using                      */
/*                                                                      */
/*              If your base chipKIT board has a network adaptor        */
/*              manufactured on the board, such as the MX7cK,           */
/*              then you do not need to specify any hardware library    */
/*              for that network hardware on the board.                 */
/*              However, if you are using alternate network hardware,   */
/*              then you will need to specify the hardware library      */
/*              for the hardware you are using.                         */
/*                                                                      */
/*              Refer to the hardware library header file               */
/*              for supported boards and hardware configurations        */
/*                                                                      */
/************************************************************************/
#include <NetworkShield.h>
// #include <PmodNIC.h>
// #include <PmodNIC100.h>

/************************************************************************/
/*                    Required library, Do NOT comment out              */
/************************************************************************/
#include <DNETcK.h>

/************************************************************************/
/*                                                                      */
/*              SET THESE VALUES FOR YOUR NETWORK                       */
/*                                                                      */
/************************************************************************/

IPv4 ipServer = {10,0,0,20};
unsigned short portServer = 65432;    
   
//******************************************************************************************
//******************************************************************************************
//***************************** END OF CONFIGURATION ***************************************
//******************************************************************************************
//******************************************************************************************

typedef enum
{
    NONE = 0,
    LISTEN,
    ISLISTENING,
    AVAILABLECLIENT,
    ACCEPTCLIENT,
    READ,
    WRITE,
    CLOSE,
    EXIT,
    DONE
} STATE;

STATE state = LISTEN;

unsigned tStart = 0;
unsigned tWait = 5000;

TcpServer tcpServer;
TcpClient tcpClient;

DNETcK::STATUS status;

int x;
byte rgbRead[1024];
int cbRead = 0;
int count = 0;
byte dataRead[1024];
int dataSize = sizeof(dataRead);
byte easywrite[8] = {'a','b','c','d','e','f','g','h'};
int easysize = sizeof(easywrite);
int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8;
/***    void setup()
 *
 *    Parameters:
 *          None
 *              
 *    Return Values:
 *          None
 *
 *    Description: 
 *    
 *      Arduino setup function.
 *      
 *      Initialize the Serial Monitor, and initializes the
 *      the IP stack for a static IP of ipServer
 *      No other network addresses are supplied so 
 *      DNS will fail as any name lookup and time servers
 *      will all fail. But since we are only listening, who cares.
 *      
 * ------------------------------------------------------------ */
void setup() {
  
    Serial.begin(115200);
    Serial.println("TCPEchoServer 1.0");
    Serial.println("Digilent, Copyright 2011");
    Serial.println("");

    // intialize the stack with a static IP
    DNETcK::begin(ipServer);
}

/***    void loop()
 *
 *    Parameters:
 *          None
 *              
 *    Return Values:
 *          None
 *
 *    Description: 
 *    
 *      Arduino loop function.
 *      
 *      We are using the default timeout values for the DNETck and TcpServer class
 *      which usually is enough time for the Tcp functions to complete on their first call.
 *
 *      This code listens for a connection, then echos any strings that come in
 *      After about 5 seconds of inactivity, it will drop the connection.
 *
 *      This is a simple sketch to illistrate a simple TCP Server. 
 *      
 * ------------------------------------------------------------ */
void loop() {

    switch(state)
    {

    // say to listen on the port
    case LISTEN:
        if(tcpServer.startListening(portServer))
        {
            Serial.println("Started Listening");
            state = ISLISTENING;
        }
        else
        {
            state = EXIT;
        }
        break;

    // not specifically needed, we could go right to AVAILABLECLIENT
    // but this is a nice way to print to the serial monitor that we are 
    // actively listening.
    // Remember, this can have non-fatal falures, so check the status
    case ISLISTENING:
        if(tcpServer.isListening(&status))
        {
            Serial.print("Listening on port: ");
            Serial.print(portServer, DEC);
            Serial.println("");
            state = AVAILABLECLIENT;
        }
        else if(DNETcK::isStatusAnError(status))
        {
            state = EXIT;
        }
        break;

    // wait for a connection
    case AVAILABLECLIENT:
        if((count = tcpServer.availableClients()) > 0)
        {
            Serial.print("Got ");
            Serial.print(count, DEC);
            Serial.println(" clients pending");
            state = ACCEPTCLIENT;
        }
        break;

    // accept the connection
    case ACCEPTCLIENT:
        
        // probably unneeded, but just to make sure we have
        // tcpClient in the  "just constructed" state
        tcpClient.close(); 

        // accept the client 
        if(tcpServer.acceptClient(&tcpClient))
        {
            Serial.println("Got a Connection");
            state = READ;
            tStart = (unsigned) millis();
        }

        // this probably won't happen unless the connection is dropped
        // if it is, just release our socket and go back to listening
        else
        {
            state = CLOSE;
        }
        break;

    // wait fot the read, but if too much time elapses (5 seconds)
    // we will just close the tcpClient and go back to listening
    case READ:
     if((dataSize = tcpClient.available()) > 0)
        {
            dataSize = dataSize < sizeof(dataRead) ? dataSize : sizeof(dataRead);
            dataSize = tcpClient.readStream(dataRead, dataSize);

        if(tcpClient.isConnected())
        {               
            //Serial.println("Writing: ");  
            for(int i=0; i < dataSize; i++) 
            {
                Serial.println((char) dataRead[i]);
            }
           
        }
        }

 state = WRITE;
        // If too much time elapsed between reads, close the connection
   /*     else if( (((unsigned) millis()) - tStart) > tWait )
        {
            state = CLOSE;
        }*/
        break;

    // echo back the string
    case WRITE:
 easywrite[0] = byte(a);
  easywrite[1] = byte(b);
   easywrite[2] = byte(c);
    easywrite[3] = byte(d);
     easywrite[4] = byte(e);
      easywrite[5] = byte(f);
       easywrite[6] = byte(g);
        easywrite[7] = byte(h);
 tcpClient.writeStream(easywrite, easysize); //change
 for (x =0 ;x<=7;x++)
 {
 easywrite[x]=0;
 }

         state = READ;
        // the connection was closed on us, go back to listening
   /*     else
        {
            Serial.println("Unable to write back.");  
            state = CLOSE;
        }*/
        break;
        
    // close our tcpClient and go back to listening
    case CLOSE:
        //tcpClient.close();
        //Serial.println("Closing TcpClient");
        Serial.println("");
        state = ISLISTENING;
        break;

    // something bad happen, just exit out of the program
    case EXIT:
        //tcpClient.close();
        //tcpServer.close();
        Serial.println("Something went wrong, sketch is done.");  
        state = DONE;
        break;

    // do nothing in the loop
    case DONE:
    default:
        break;
    }

     
    //delay(1000);

    // every pass through loop(), keep the stack alive
    DNETcK::periodicTasks(); 
}
