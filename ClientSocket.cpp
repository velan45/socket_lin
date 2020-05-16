// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"
#include <cstring>
#include <iostream>
#include <string>





ClientSocket::ClientSocket ( std::string host, int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Could not create client socket." );
    }

  if ( ! Socket::connect ( host, port ) )
    {
      throw SocketException ( "Could not bind to port." );
    }

}


ClientSocket& ClientSocket::operator << ( char* s ) 
{
NDebug std::cout << " in client_socket.cpp insertion overload\n" <<std::endl;
NDebug MSG* temp1 = new MSG;
NDebug deserialize(s, temp1);
NDebug printMsg(temp1);

  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


ClientSocket& ClientSocket::operator >> ( char* s ) 
{



  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Could not read from socket." );
    }
NDebug std::cout << " in client_socket.cpp extraction  overload\n" <<std::endl;
NDebug MSG* temp1 = new MSG;
NDebug deserialize(s, temp1);
NDebug printMsg(temp1);
  return *this;
}
