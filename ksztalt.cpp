#include <iostream>
#include "ksztalt.h"
#include <math.h>

using namespace std;

Ksztalt::Ksztalt(string n, float x, float y){
    nazwa = n;
    pktX = x;
    pktY = y;
}

Punkt::Punkt(string n, float x, float y)
:Ksztalt(n, x, y){};

Prostokat::Prostokat(string n, float x, float y, float bX, float bY)
:Ksztalt(n, x, y){
    bokX = bX;
    bokY = bY;
}

Kolo::Kolo(string n, float x, float y, float r)
:Ksztalt(n, x, y){
    promien = r;
}

string Ksztalt::wyswietl(){
    return nazwa;
}

float Punkt::pole(){
    return 0;
}

float Prostokat::pole(){
    return bokX*bokY;
}

float Kolo::pole(){
    return M_PI*promien*promien;
}

float podaniePola(Ksztalt *wsk){
    return wsk -> pole();
}

void polozeniePunktu(Punkt &pkt, Prostokat &p){
    cout << "Punkt " << pkt.wyswietl() <<" ("<<pkt.pktX<<", "<<pkt.pktY<<") " << " znajduje sie: " << endl;
    if((pkt.pktX>p.pktX) && (pkt.pktX<p.pktX+p.bokX) && (pkt.pktY>p.pktY) && (pkt.pktY<p.pktY+p.bokY))
        cout << "       wewnatrz prostokata";
    else if(((pkt.pktX==p.pktX) && (pkt.pktY>p.pktY) && (pkt.pktY<p.pktY+p.bokY)) ||
            ((pkt.pktX==p.pktX+p.bokX) && (pkt.pktY>p.pktY) && (pkt.pktY<p.pktY+p.bokY)) ||
            ((pkt.pktX>p.pktX) && (pkt.pktX<p.pktX+p.bokX) && (pkt.pktY==p.pktY)) ||
            ((pkt.pktX>p.pktX) && (pkt.pktX<p.pktX+p.bokX) && (pkt.pktY==p.pktY+p.bokY)))
        cout << "       dokladnie na obwodzie prostokata";
    else
        cout << "       poza prostokatem";
    cout << " o nazwie " << p.wyswietl() << " i powierzchni " << podaniePola(&p) << endl << endl;
}

void polozeniePunktu(Punkt &pkt, Kolo &k){
    float odlegloscDoKwadratu = pow(k.pktX - pkt.pktX, 2) + pow(k.pktY - pkt.pktY, 2);
    float promienDoKwadratu = pow(k.promien,2);

    cout << "Punkt " << pkt.wyswietl() <<" ("<<pkt.pktX<<", "<<pkt.pktY<<") " << " znajduje sie: " << endl;
    if(odlegloscDoKwadratu < promienDoKwadratu)
        cout << "       wewnatrz okregu ";
    else if(odlegloscDoKwadratu == promienDoKwadratu)
        cout << "       dokladnie na okregu ";
    else
        cout << "       poza okregiem ";
    cout << " o nazwie " << k.wyswietl() << " i powierzchni " << podaniePola(&k) << endl << endl;
}