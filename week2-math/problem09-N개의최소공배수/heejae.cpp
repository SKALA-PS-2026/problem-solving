# 문제: N개의 최소공배수
# 접근 방식: 먼저 배열의 첫번째, 두번째 원소끼리의 lcm을 구한다. -> 배열의 세번째 원소부터 기존 lcm과의 lcm을 다시 구한다.
# 시간복잡도: O(n × log M)

#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = std::lcm(arr[0], arr[1]);
        
    for(int i=2; i<arr.size(); i++) {
        answer = std::lcm(answer, arr[i]);
    }
        
    return answer;
}
