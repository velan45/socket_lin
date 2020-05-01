#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#define BUFSIZE 512
#define PACKETSIZE sizeof(MSG)

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
		{MSG* temp = new MSG;

		  char data[PACKETSIZE];
		  new_sock >> data;
		deserialize(data, temp);
		printMsg(temp);
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
