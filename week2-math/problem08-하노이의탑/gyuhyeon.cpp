// 문제: 하노이의 탑
// 접근 방식: n-1개를 보조 기둥으로 옮긴 뒤 가장 큰 원판을 옮기고, n-1개를 목적 기둥으로 옮기는 재귀를 사용한다.
// 시간복잡도: O(2^n)
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int mid, int end) {
    if (n == 1) {
        answer.push_back({start, end});
        return;
    }

    hanoi(n - 1, start, end, mid);
    answer.push_back({start, end});
    hanoi(n - 1, mid, start, end);
}

vector<vector<int>> solution(int n) {
    hanoi(n,1,2,3);
    return answer;
}

