#include "day3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  
//https://adventofcode.com/2025/day/3

#define ull unsigned long long

void two_digit(std::string &line , ull &ans)
{
    ull start=0,start_val=0,start_index=0,end=line.size()-1,end_val=0;
    while(start<end)
    {
        if(line[start]-'0'>start_val)
        {
            start_val=line[start]-'0';
            start_index=start;
        }
        start++;
    }
    while(end>start_index)
    {
        if(line[end]-'0'>end_val)
        {
            end_val=line[end]-'0';
        }
        end--;
    }
    ans+=((start_val*10)+end_val);
}
void twelve_digit(std::string &line , ull &ans)
{
    ull size=line.size();
    if(size==12)
    {
        ans=std::stoull(line);
        return;
    }
    int start=0;
    std::string sAns="";
    for(int i=0;i<12;i++)
    {
        int maxi=0,maxi_index=0;
        while(start<size-11+i)
        {
            //maxi=std::max(maxi,line[start]-'0');
            if(maxi<line[start]-'0')
            {
                maxi=static_cast<int>(line[start]-'0');
                maxi_index=start;
            }
            start++;
        }
        start=maxi_index+1;
        sAns+=std::to_string(maxi);
    }
    ans+=std::stoull(sAns);
}
int main() {
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string line;   
    ull ans=0;
    while (getline(file, line)) {
        twelve_digit(line,ans);
    }
    std::cout<<"Answer->"<<ans<<"\n";
}