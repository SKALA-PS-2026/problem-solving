// 문제: 하노이의 탑
// 접근 방식: n-1개를 중간으로 옮긴다. -> 제일 큰 원판을 목적지로 옮긴다. -> n-1개를 다시 목적지로 옮긴다. (재귀)
// 시간복잡도: O(2ⁿ)

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi(int n, int from, int to);

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 3);
     
    return answer;
}

void hanoi(int n, int from, int to) {
    
    int other = 6 - from - to;
    
    if(n == 1) {
        // 종료
        answer.push_back({ from, to });
        return;
    }
    
    // n-1개를 중간으로 옮김
    hanoi(n-1, from , other);
    
    // 제일 큰 원판을 to로 옮김
    answer.push_back({ from, to });
    
    // n-1개를 목적지로
    hanoi(n-1, other, to); 
}
