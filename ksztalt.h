#include <iostream>

using namespace std;

class Ksztalt{
protected:
    string nazwa;
    float pktX, pktY;
public:
    Ksztalt(string, float, float);
    string wyswietl();
    virtual float pole()=0;
};

class Prostokat;
class Kolo;

class Punkt : public Ksztalt{
public:
    Punkt(string, float=0, float=0);
    float pole();
    friend void polozeniePunktu(Punkt &pkt, Prostokat &p);
    friend void polozeniePunktu(Punkt &pkt, Kolo &k);
};

class Prostokat :Ksztalt{
    float bokX, bokY;
public:
    Prostokat(string, float=0, float=0, float=1, float=1);
    float pole();
    friend void polozeniePunktu(Punkt &pkt, Prostokat &p);
};

class Kolo :Ksztalt{
    float promien;
public:
    Kolo(string, float=0, float=4.8, float=5);
    float pole();
    friend void polozeniePunktu(Punkt &pkt, Kolo &k);
};
