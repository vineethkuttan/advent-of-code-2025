#include "day2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//https://adventofcode.com/2025/day/2

#define ull unsigned long long

bool isinvalidv1(ull data)
{
    std::string sData=std::to_string(data);
    ull size=sData.size();
    ull half=size>>1;
    if(size&1) return false;//if size is odd return false
    for(int i=0;i<half;i++)
    {
        if(sData[i]!=sData[i+half]) return false;
    }
    return true;
}

bool isinvalidv2(ull data)
{
    std::string sData=std::to_string(data);
    ull size=sData.size();
    std::vector<ull> hash(10,0);
    for(int i=0;i<size;i++)
    {
        hash[sData[i]-'0']++;
    }
    ull nonZero=0;
    for(int i=0;i<10;i++)
    {
        if(hash[i] && !nonZero) 
        {
            nonZero=hash[i];
        }
        else if(hash[i] && nonZero!=hash[i])
        {
            return false;
        }
    }
    if(nonZero==1)
    {
        return false;
    }
    ull divideSize=size/nonZero;
    std::vector<std::string> parts;
    for(ull i = 0; i < size; i += divideSize)
    {
        std::string part = sData.substr(i, divideSize);
        // std::cout<<"Vector->"<<part<<"-"<<divideSize<<"\n";
        parts.push_back(part);
    }
    if(parts.empty()) return false;
    std::string firstPart = parts[0];
    for(const auto& part : parts)
    {
        if(part != firstPart) return false;
    }
    
    return true;
}
int main() {
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string range;   
    ull ans=0;
    while (getline(file, range, ',')) {
        std::string start,end;
        std::stringstream ss(range);
        getline(ss, start, '-');
        getline(ss, end, '-');
        ull uStart=std::stoull(start);
        ull uEnd=std::stoull(end);
        for(ull i=uStart;i<=uEnd;i++)
        {
            //if(isinvalidv1(i)) -> Version 1
            if(isinvalidv1(i) || isinvalidv2(i)) //-> Version 2
            {
                std::cout<<i<<"\n";
                ans+=i;
            }
        }
    }
    std::cout<<"Answer->"<<ans<<"\n";
}