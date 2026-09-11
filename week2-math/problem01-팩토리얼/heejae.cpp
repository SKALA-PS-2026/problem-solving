// 문제: 팩토리얼
// 접근 방식: 제한 사항에 n이 3,628,800 이하라해서.. 10부터 1씩 감소하면서 팩토리얼을 구한 후 n이하라면 return한다.
// 시간복잡도: O(1)

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // n이하의 최대의 팩토리얼
    for(int i=10; i>=1; i--) {
        int temp = 1;
        
        for(int j=1; j<=i; j++) {
            temp *= j;
        }
        
        if(temp <=n) return i;
    }
    
    return answer;
}
