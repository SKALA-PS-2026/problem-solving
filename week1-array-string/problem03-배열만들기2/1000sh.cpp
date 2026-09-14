// 문제: 배열 만들기 2
// 접근 방식: 5로 나누면 이진수인 모양이 나오므로 2진수에다 5를 곱해서 만드는 형식으로 진행
// 시간복잡도: O(n) n<2^7=128



#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    
    int count=0;
    for(int i=0;i<(1<<7);i++)
    {
        
        int result = 0;
        int digit = 1;

        int n=i;
        while (n > 0) {
            result += (n % 2) * 5 * digit;
            n /= 2;
            digit *= 10;
        }
        if(result<l)continue;
        if(result>r)break;
        answer.push_back(result);
        count++;
    }
    
    if(count<=0) answer.push_back(-1);
    
    
    return answer;
}
