#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ComRecip {
    double cr_1011849;
    double cr_777555;
};


struct Ru {
    string Name;
    double RedA;
    int VisDelay;
    double VolMatched;
};

struct Settler {
    bool p1 = true;
    bool p777555 = true;
    bool p777889 = true;
};


class Market
{
public:
    Market() {}
    int CatID;
    string ClosD;
    ComRecip com_recip;
    double Comm;
    string Comp;
    string Descr;
    unsigned long int	ID;
    string LastCh;
    string LastSoftCh;
    string LogBugs;
    double Margin;
    double MaxVal;
    double MinVal;
    string OrdBStr;
    double Pop;
    vector<Ru> ru;
    string SettlD;
    int SettlT;
    Settler settler;
    int Status;
    string Title;
    unsigned char Period;
    unsigned char _Type;
};






#endif // MARKET_H
