#include "ServerGroup.h"

ServerGroup::ServerGroup()
{
  size = 0;
  servers =0;
  spServer = 0;
}

ServerGroup::ServerGroup(int elements)
{
  size = elements;
  servers = new int[size];
  for(int i=0; i<size; i++)
  {
	servers[i] = 0;
  }
  spServer = 0;
}

bool ServerGroup::serverFree() 
{
  for(int i=0; i<size; i++)
  {
	if(servers[i]==0)
	{
	  freeServer = i;
	  return true;
	}
  }
  return false;
}

void ServerGroup::decServers()
{
  if(spServer>0){--spServer;}
  for(int i=0; i<size; i++)
  {
    if(servers[i]>0)
		--servers[i];
  }
}
