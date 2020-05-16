#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include "Socket.h"
#define BUFSIZE 512
#define PACKETSIZE sizeof(MSG)
#define NDEBUG 

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		NDEBUG std::cout << " Inside while loop of main simpleserver" << std::endl;
		NDEBUG MSG* temp = new MSG;
		NDEBUG char data[512];
		
		new_sock >> data;
		
		NDEBUG deserialize(data, temp);
		
		NDEBUG printMsg(temp);
		
		new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
