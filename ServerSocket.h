// Definition of the ServerSocket class

#ifndef ServerSocket_class
#define ServerSocket_class

#include "Socket.h"


class ServerSocket : private Socket
{
 public:

  ServerSocket ( int port );
  ServerSocket (){};
  virtual ~ServerSocket();

  ServerSocket& operator << ( char* );
  ServerSocket& operator >> ( char* );

  void accept ( ServerSocket& );

};


#endif
