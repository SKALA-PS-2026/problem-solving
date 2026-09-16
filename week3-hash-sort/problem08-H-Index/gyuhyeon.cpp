// 문제: H-Index
// 접근 방식: 인용 횟수를 오름차순 정렬하고, 현재 인용 횟수가 남은 논문 수 이상이 되는 첫 지점의 남은 논문 수를 반환한다.
// 시간복잡도: O(N log N) (N: 논문 수)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i=0; i<n; i++) {
        if (citations[i] >= n-i) {
            return n-i;
        }
    }
    
    return 0;
}