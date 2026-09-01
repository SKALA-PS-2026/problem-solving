// 문제: 폰켓몬
// 접근 방식: 중복 안되는 자료형에 넣고 개수를 최대개수 절반과 비교해서 작은거 반환
// 시간복잡도: O(n) n<=10^4

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> alls;
    for(int i=0;i<nums.size();i++)
    {
        alls.insert(nums[i]);
    }
    return answer=min((int)alls.size(),(int)nums.size()/2);
}
