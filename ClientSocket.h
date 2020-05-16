// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"
#define NDebug 



class ClientSocket : private Socket
{
 public:

  ClientSocket ( std::string host, int port );
  virtual ~ClientSocket(){};

  ClientSocket& operator << ( char* ) ;
  ClientSocket& operator >> ( char* ) ;

};


#endif
