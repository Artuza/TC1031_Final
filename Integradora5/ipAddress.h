#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <cmath>
#include <iostream>
#include <vector>

class ipAddress {
    private:
      std::string ipString;
      int ipIndex;
      int value;
      unsigned int ipValue;
      int degreeIn; // Total de direcciones que acceden al vértice de esta ip
      int degreeOut; // Total de direcciones que el vértice de esta ip accede

    public:
      ipAddress();
      ipAddress(std::string _ip, int idx);
      std::string getIp();
      unsigned int getIpValue();
      int getIpIndex();
      void setDegreeIn(int g);
      void addToDegreeIn();
      int getDegreeIn();
      void setDegreeOut(int g);
      void addToDegreeOut();
      int getDegreeOut();
      std::string toString();


      bool operator ==(const ipAddress&) const;
      bool operator !=(const ipAddress&) const;
      bool operator >(const ipAddress&) const;
      bool operator >=(const ipAddress&) const;
      bool operator <(const ipAddress&) const;
      bool operator <=(const ipAddress&) const;
};


#endif
