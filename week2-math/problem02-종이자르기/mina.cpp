// 문제: 종이 자르기
// 접근 방식: 식을 세워본 결과.. M-1 + M(N-1) 이 나왔는데 더 정리해서 M*N-1으로 하면 더 굿
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    answer+=M-1;
    answer+=M*(N-1);
    return answer;
}
