// 문제: 팩토리얼
// 접근 방식: 한 변수에 계속 곱해지면서 다음값을 비교하고 성공할때마다 1증가.
// 시간복잡도: O(n) n<=10

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int yet=1;
    for(int i=2;i<=n;i++)
    {
        yet*=i;
        if(yet>n)break ;
        answer++;
    }
    return answer;
}
