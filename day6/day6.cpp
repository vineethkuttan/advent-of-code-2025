#include "day6.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>  
#include <vector>  
//https://adventofcode.com/2025/day/6

#define ull unsigned long long
ull version1(std::ifstream& file)
{
    std::string line;
    std::vector<ull> add,mul;
    ull final_ans=0;
    while (getline(file, line)) {        
        std::stringstream ss(line);
        std::string data;
        int i=0;
        bool empty=false;
        if(add.empty()) empty=true;
        while(getline(ss, data, ' '))
        {
            if(data=="") continue;
            if(data=="*")
            {
                final_ans+=mul[i++];
                continue;
            }
            else if(data=="+")
            {
                final_ans+=add[i++];
                continue;
            }
            ull uData=std::stoull(data);
            if(empty)
            {
                add.push_back(uData);
                mul.push_back(uData);
            }
            else
            {
                add[i]+=uData;
                mul[i]*=uData;
            }
            //std::cout<<"Version->"<<data<<"\n";
            i++;
        }
    }
    return final_ans;
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
    int m=static_cast<int>(data.size()),n=static_cast<int>(data[0].size());
    m--;
    for(int i=0;i<n;i++)
    {
        if(data[m][i]=='*' || data[m][i]=='+')
        {
            bool empty_column_found=false;
            bool multiply=(data[m][i]=='*')?true:false;
            ull ans=(data[m][i]=='*')?1:0;
            while(!empty_column_found && i<n)
            {
                std::string col="";
                for(int j=0;j<m;j++)
                {
                    if(data[j][i]!=' ')
                    {
                        col+=data[j][i];
                    }
                }
                if(col.empty())
                {
                    empty_column_found=true;
                }
                else
                {
                    if(multiply)
                    {
                        ans*=std::stoull(col);
                    }
                    else
                    {
                        ans+=std::stoull(col);
                    }
                    i++;
                }                
            }
            final_ans+=ans;
        }
    }
    std::cout<<"Answer Version->"<<final_ans<<"\n";
}