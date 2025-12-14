#include "day4.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  
#include <vector>  
//https://adventofcode.com/2025/day/4

#define ull unsigned long long

std::vector<std::vector<int>> adjacent={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void v1(std::vector<std::string>& grid,int m, int n,ull& ans)
{
    std::vector<std::string> temp=grid;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(temp[i][j]=='@')
            {
                int cnt=0;
                for(const std::vector<int> &iter:adjacent)
                {
                    int x=i+iter[0];
                    int y=j+iter[1];
                    if(x<m && y<n && x>-1 && y>-1 && temp[x][y]=='@')
                    {
                        cnt++;
                    }
                }
                if(cnt<4) 
                {
                    ans++;
                    grid[i][j]='.';
                }

            }
        }
    }
}

int main() {
    // Read entire file from parent directory
    std::ifstream file("../input.txt");
    std::string line; 
    ull ans=0,prev_ans=0;
    std::vector<std::string> grid;
    while (getline(file, line)) {
        grid.push_back(line);
    }
    int m=static_cast<int>(grid.size()),n=static_cast<int>(grid[0].size());
    do
    {
        prev_ans=ans;
        v1(grid,m,n,ans);
    } while (prev_ans!=ans);
    
    
    std::cout<<"Answer->"<<ans<<"\n";
}