// 문제: 문자열 내 p와 y의 개수
/*
접근 방식: y면 + p면 -를 해서 총합 0인지 판단
  한쪽에 엄청 몰릴경우 빨리 끝내는 코드로 시간 단축.
*/
// 시간복잡도: O(n) n<=50

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int sameNum=0;
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        if(s[i]=='y' || s[i]=='Y') sameNum++;
        else if(s[i]=='p' || s[i]=='P') sameNum--;
        else if(size-i<abs( sameNum))break; //0.01초 단축하는 경우 존재.
    }
    answer=sameNum==0;
    cout << "Hello Cpp" << endl;

    return answer;
}
