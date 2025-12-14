#include "day7.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  
#include <vector>  
//https://adventofcode.com/2025/day/6

#define ull unsigned long long
void version1(std::vector<std::string> data,ull m,ull n, ull &final_ans)
{
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(data[i][j]=='.' && (data[i-1][j]=='S' || data[i-1][j]=='|'))
            {
                data[i][j]='|';
            }
            else if(data[i][j]=='^' && (data[i-1][j]=='S' || data[i-1][j]=='|'))
            {
                final_ans++;
                data[i][j-1]='|';
                data[i][j+1]='|';
            }
        }
    }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(data[i][j]=='|')
    //         {
    //             final_ans++;
    //         }
    //     }
    // }
}
int main() {
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string line;
    ull final_ans=0;
    std::vector<std::string> data;
    while (getline(file, line))
    {
        data.push_back(line);
    }
    ull m=static_cast<int>(data.size()), n=static_cast<int>(data[0].size());
    //version 1
    //version1(data,m,n,final_ans);

    //https://www.reddit.com/r/adventofcode/comments/1pgnmou/2025_day_7_lets_visualize/
    std::vector<ull> ansVector(n,0);
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(data[i][j]=='.' && data[i-1][j]=='S')
            {
                ansVector[j]+=1;
            }
            else if(data[i][j]=='^')
            {
                ansVector[j+1]+=ansVector[j];
                ansVector[j-1]+=ansVector[j];
                ansVector[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        final_ans+=ansVector[i];
    }

    std::cout<<"Answer Version->"<<final_ans<<"\n";
}