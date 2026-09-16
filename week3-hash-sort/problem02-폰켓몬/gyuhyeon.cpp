// 문제: 폰켓몬
// 접근 방식: 해시 집합으로 종류 수를 구하고, 종류 수와 전체 마릿수의 절반 중 작은 값을 반환한다.
// 시간복잡도: 평균 O(N) (N: 폰켓몬 수, 해시 연산 평균 기준)

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int n = nums.size();
    
    if (s.size() >= n/2) {
        return n/2;
    }
    
    return s.size();
}