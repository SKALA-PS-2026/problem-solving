// 문제: 팩토리얼
// 접근 방식: 
// 시간복잡도: O(n)
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int k = 1;
    while (k*answer <= n) {
        k *= answer++;
    }
    return answer-1;
}