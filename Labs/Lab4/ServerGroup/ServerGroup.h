#ifndef ServerGroup_h
#define ServerGroup_h

class ServerGroup
{
  public:
  ServerGroup();
  ServerGroup(int); // constructor

  // Extra Functions written for senario constrution
  void setServers(int i, int j){servers[i] = j;}
  void setSpServer(int i){spServer = i;}
  int getServers(int i) {return servers[i];}
  int getSpServer() const {return spServer;}

  bool spServerFree() const {return (spServer==0)?true:false;}
  bool serverFree();
  void useServer(int avTransTime){servers[freeServer]=avTransTime;}
  void usespServer(int avTransTime){spServer=avTransTime;}
  void decServers();

  private:
  int *servers;
  int spServer;
  int freeServer;
  int size;
};

#endif