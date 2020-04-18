#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

struct S
{
	int a;
	int b;
};


int main ( int argc, int argv[] )
{
	
	struct S s1={2,3};
	
	
	std:: cout << "s1.a\n";

 	std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server (30000 );
      std::cout << "Created Server" << std::endl;

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );
	 // std::cout << "server accepted " << std::endl;

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  new_sock << data;
		  std::cout << "Data Recieved : " << data << std::endl;
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
