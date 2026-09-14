// 문제: 3진법 뒤집기
// 접근 방식: 3진수 배열에 넣고 꺼내서 역계산
// 시간복잡도: O(n) n<18

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> rev;
    for(int i=0;n>0;i++)
    {
        rev.push_back(n%3);
        n/=3;
    }
    int size=rev.size();
    for(int i=0;i<size;i++)
    {
        answer+=(rev[i]*pow(3,size-i-1));
    }
    return answer;
}
