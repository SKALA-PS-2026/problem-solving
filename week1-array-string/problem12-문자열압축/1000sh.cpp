// 문제: 문자열 압축
// 접근 방식: 문자열 쪼개서 for 돌리기
// 시간복잡도: O(n^2) n<=10^3

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string s, int n)
{
    vector<string> result;

    for (int i = 0; i < s.size(); i += n)
    {
        result.push_back(s.substr(i, n));
    }

    return result;
}

int solution(string s) {
    int size=s.size();
    int answer = size;
    for(int i =1;i<=size/2+1;i++)//쪼갤 문자열 개수
    {
        int lowAnser=size;
        vector<string> spl=split(s,i);
        int compressNum=1;
        for(int j=1;j<spl.size();j++)//쪼개진 문자열 순회
        {
            if(spl[j-1]==spl[j])
            {
                lowAnser-=i;
                compressNum++;
            }
            else 
            {
                if(compressNum>1)
                {
                    lowAnser+=to_string(compressNum).size();
                    compressNum=1;
                }
            }
            
            
        }
        
        if(compressNum>1)
        {
            lowAnser+=to_string(compressNum).size();
            compressNum=0;
        }
        if(answer>lowAnser)answer=lowAnser;
    }
    
    return answer;
}
