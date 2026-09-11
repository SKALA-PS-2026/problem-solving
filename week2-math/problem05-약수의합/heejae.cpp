// 문제: 약수의 합
// 접근 방식: 1부터 n까지 숫자들에 대하여 n을 해당 숫자로 나눈 나머지가 0이라면 answer에 더한다.
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i<=n; i++) {
        if(n % i == 0) answer+= i;
    }
    
    return answer;
}
