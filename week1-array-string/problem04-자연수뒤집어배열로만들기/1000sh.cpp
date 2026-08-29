// 문제: 자연수 뒤집어 배열로 만들기
// 접근 방식: 10으로 나눈 나머지 그냥 배열로 넣고 10나눔
// 시간복잡도: O(n) n<=11

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    for(int i=0;i<11;i++)
    {
        answer.push_back(n%10);
        n/=10;
        if(n<=0)break;
    }
    return answer;
}
