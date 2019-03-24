#include <iostream>
#include "ksztalt.h"

using namespace std;

int main()
{
    Punkt pkt1("A", 5.6, 7.8);
    Punkt pkt2("B");
    Prostokat p1("PROST1", 1.2, 3.4 , 7.8 , 9.487);
    Prostokat p2("PROST2", 3.2, 7.8 , 4 , 2.2);
    Kolo k1("KOLO1", 1, 4, 10.3);
    Kolo k2("KOLO1", 1.6);
    polozeniePunktu(pkt1,p1);
    polozeniePunktu(pkt1,k1);
    polozeniePunktu(pkt1,p2);
    polozeniePunktu(pkt1,k2);
    polozeniePunktu(pkt2,p1);
    polozeniePunktu(pkt2,k2);

    return 0;
}
