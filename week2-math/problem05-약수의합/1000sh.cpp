// 문제: 약수의 합
// 접근 방식: 약수로 나누면 반대편 약수가 나옴 중앙값은 1개로 처리 모두더함
// 시간복잡도: O(n^0.5) n<=3001^0.5

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            answer+=i;
            if(n/i!=i)
            {
                answer+=n/i;
            }
        }
    }
    return answer;
}
