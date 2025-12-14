#include "day5.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  
#include <vector>  
//https://adventofcode.com/2025/day/5

#define ull unsigned long long

void mergeIntervals(std::vector<std::pair<ull,ull>> vp,std::vector<std::pair<ull,ull>>& ans)
{
    int n=static_cast<int>(vp.size());
    sort(vp.begin(),vp.end());
    int first_pointer=0;
    ull prevStart=vp[first_pointer].first;
    ull prevEnd=vp[first_pointer].second;
    for(int i=1;i<n;i++)
    {
        ull currStart=vp[i].first;
        ull currEnd=vp[i].second;        
        if (prevEnd<currStart)
        {
            ans.push_back({prevStart,prevEnd});
            first_pointer=i;
            prevStart=vp[first_pointer].first;
            prevEnd=vp[first_pointer].second;
        }
        else
        {
            prevStart=std::min(currStart,prevStart);
            prevEnd=std::max(currEnd,prevEnd);
        }
    }
    ans.push_back({prevStart,prevEnd});
}

int main() {
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string line;
    std::vector<std::pair<ull,ull>> vp,ansV;
    ull ans=0,fresh_ingredient_count=0;
    while (getline(file, line) && line.length()) {
        std::string start,end;
        std::stringstream ss(line);
        getline(ss, start, '-');
        getline(ss, end, '-');
        ull uStart=std::stoull(start);
        ull uEnd=std::stoull(end);
        vp.push_back(std::make_pair(uStart,uEnd));
    }
    mergeIntervals(vp,ansV);
    for(auto x:ansV)
    {
        //std::cout<<x.first<<" "<<x.second<<"\n";
        fresh_ingredient_count+=x.second-x.first+1;
    }
    while (getline(file, line))
    {
        // std::cout<<"ingdd->"<<line<<"\n";
        ull ingredient=std::stoull(line);
        for(auto x:vp)
        {
            if(ingredient >=x.first && ingredient<=x.second)
            {
                // std::cout<<"ing->"<<ingredient<<"\n";
                ans++;
                break;
            }
        }
    }
    
    std::cout<<"Answer Version1->"<<ans<<"\nVersion2->"<<fresh_ingredient_count<<"\n";
}