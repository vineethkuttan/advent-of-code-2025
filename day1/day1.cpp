#include "day1.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//https://adventofcode.com/2025/day/1
// #define ull unsigned long long

typedef long long ll;

bool check_cross(ll dial)
{
    return (dial>99 || dial<0);
}

void version1(char &side,ll &dial,ll& val,ll&ans)
{
    if(side=='L')
    {
        dial=(dial-val)%100;//if value is hundred we should set it to zero so we are using modulo
    }
    else if(side=='R')
    {
        dial=(dial+val)%100;
    }
    if(!dial) ans++;
}

void version2(char &side,ll &dial,ll& val,ll&ans)
{
    ans+=val/100;//if rotation are more than hundred we can assure that one time it will cross the zero. 
    //Don't know: if dial is already at 0 and 1000 rotations made means it wil be treated as 10 but I think it should be 
    //treated as nine rotation
    val=val%100;
    if(side=='L')
    {
        dial-=val;
        if(check_cross(dial) && (dial+val!=0)) ans++;
    }
    else if(side=='R')
    {
        dial+=val;
        if(check_cross(dial) && (dial-val!=0)) ans++;
    }
    if(dial==100) ans--;
    if(dial<0) dial+=100;
    else if(dial>99) dial-=100;
    // std::cout<<dial<<" "<<ans<<"\n";
}
int main() {
    ll dial_startv1=50,dial_startv2=50,count=0,count_cross=0;
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string line;
    while (std::getline(file, line)) {
        char side=line[0];
        ll number_str=std::stoll(line.substr(1));
        version1(side,dial_startv1,number_str,count);
        version2(side,dial_startv2,number_str,count_cross);
    }
    std::cout<<"Password->"<<count<<"\n";    //-> First one answer.
    std::cout<<"ActualPassword->"<<count_cross+count<<"\n";    //-> Second one answer.
}