// Definition of the Socket class

#ifndef Socket_class
#define Socket_class
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#define BUFSIZE 512
#define PACKETSIZE sizeof(MSG)

#define NDebug 

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket
{
 public:
  Socket();
  virtual ~Socket();

  // Server initialization
  bool create();
  bool bind ( const int port );
  bool listen() const;
  bool accept ( Socket& ) const;

  // Client initialization
  bool connect ( const std::string host, const int port );

  // Data Transimission
  bool send ( char* ) const;
  int recv ( char* ) const;


  void set_non_blocking ( const bool );

  bool is_valid() const { return m_sock != -1; }

 private:

  int m_sock;
  sockaddr_in m_addr;


};
typedef struct MSG
{
    int type;
    int priority;
    int sender;
    char message[BUFSIZE];
};

extern void serialize(MSG* msgPacket, char *data);
extern void deserialize(const char *data, MSG* msgPacket);
extern void printMsg(MSG* msgPacket);

#endif
