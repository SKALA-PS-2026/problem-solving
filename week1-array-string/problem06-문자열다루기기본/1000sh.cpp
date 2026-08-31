// 문제: 문자열 다루기 기본
// 접근 방식: 문자열 사이즈 4,6만 체크하고 '0' '9' 사이에 모두 있는지 체크 한개라도 아니면 바로 break
// 시간복잡도: O(n) n<=8

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int lsize=s.size();
    cout<<lsize;
    if(lsize!=4&&lsize!=6) {answer =false; }
    else 
    {
        for(int i=0;i<lsize;i++)
        {
            if(s[i]<'0'||s[i]>'9') 
            {
                answer =false;
                break;
            }
        }
    }
    return answer;
}
