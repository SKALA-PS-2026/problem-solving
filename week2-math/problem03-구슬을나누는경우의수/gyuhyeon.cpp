// 문제: 구슬을 나누는 경우의 수
// 접근 방식: 조합 공식 nCr을 곱셈과 나눗셈으로 계산한다.
// 시간복잡도: O(r)
#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    
    share = min(share, balls - share);
    long long answer = 1;
    
    for (int i=0; i<share; i++) {
        answer*=(balls - i);
        answer/=(i+1);
    }

    return (int)answer;
}