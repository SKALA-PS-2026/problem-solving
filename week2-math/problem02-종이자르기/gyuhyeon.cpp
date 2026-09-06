// 문제: 종이 자르기
// 접근 방식: 가로로 M-1번, 세로로 M*(N-1)번 잘라 총 M*N-1번을 구한다.
// 시간복잡도: O(1)

#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    
    if (M==1) return N-1;
    else if (N==1) return M-1;
    
    return M-1 + M*(N-1);
}
