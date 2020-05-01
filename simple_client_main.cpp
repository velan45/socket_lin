#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

struct packet{
		int Number;
		std::string s;
	};
int main ( int argc, int argv[] )
{
	struct packet my_packet, reply_packet;
char *var1= " hey";
std::string reply;
	
  try
    {

      ClientSocket client_socket ( "localhost", 30000 );

      

      try
	{
	  client_socket << var1;
	  client_socket >>reply ;
	}
      catch ( SocketException& ) {}

      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
