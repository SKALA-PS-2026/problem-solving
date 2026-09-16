// 문제: 종이 자르기
// 접근 방식: 세로로 M-1 번 자른 후 M개의 종이에 대해 N-1번씩 다시 자른다.
// 시간복잡도: O(1)

#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    
    // 일단 세로로 자른 후 생각
    // 세로로 heightCount 번 자른다
    int heightCount = M - 1;
    
    // M개에 대해서 (가로길이 - 1)씩 자른다 
    int widthCount = M * (N-1);
    
    answer = heightCount + widthCount;
    
    
    return answer;
}
