// 문제: 구슬을 나누는 경우의 수
// 접근 방식: 기존에 팩토리얼을 구하는 함수를 통해 푸려고 했으나.. 시간이 오래 걸려서
// ai가 알려준 방법을 알게되었음. 
// 시간복잡도: O(min(share, balls - share))

#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {    
    long long answer = 1;
        
    int minShare = min(share, balls-share);
    
    for(int i=1; i<=minShare; i++) {
        answer = answer * (balls - i + 1) / i;
    }
    
    return answer;
}
