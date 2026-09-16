// 문제: 3진법 뒤집기
// 접근 방식: n을 3으로 계속해서 나누었을때의 나머지를 list에 push_back한다. 이후 list의 오른쪽 원소부터 차례대로 10진법으로 바꾸는 과정을 실행한다. 
// 시간복잡도: O(log n)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> list;
    
    while(n > 0) {
        list.push_back(n % 3);
        n /= 3;
    }
    
    int powNum = 0;
    for(int i=list.size()-1; i>=0; i--) {
        answer += pow(3, powNum) * list[i];
        powNum++;
    }
    
    return answer;
}
