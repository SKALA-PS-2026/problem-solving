// 문제: 문자열 내 p와 y의 개수
// 접근 방식: 각 인덱스를 p, P, y, Y랑 비교해서 카운팅
// 시간복잡도: O(n)

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s)
{
    vector<int> py(2);
    for (int i=0; i<s.size(); i++){
        if (s[i]=='p' || s[i]=='P') py[0]++;
        else if (s[i]=='y' || s[i]=='Y') py[1]++;
    }
    return py[0]==py[1]?true:false;
}
