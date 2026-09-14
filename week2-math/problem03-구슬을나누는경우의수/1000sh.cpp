// 문제: 구슬을 나누는 경우의 수
/*
접근 방식: 절반이 넘으면 약분되는 것을 제거하고 곱함.
  최대치 30C15 < 2^30=10^9
  int =10^9
  중간 계산은 최대값 /최소의 곱으로 진행 안전하게 => long long 사용
*/
// 시간복잡도: O(n) n<=15

#include <string>
#include <vector>

using namespace std;


int solution(int balls, int share) {
    int answer = 1;
    
    if(balls<share)return 0;
    if(balls==share)return 1;
    if(balls/2.0 < share) share=balls-share;
    int sh=1;
    
long long ans=1;
    for(int i=0;i<share;i++)
    {
        ans=ans*balls--/sh++;
    }
    
    
    
    return answer=ans;
}
