// 문제: 최대공약수와 최소공배수
// 접근 방식: 최대숫자의 절반만큼 나누기로 최소 공배수를 구하고 최소공배수를 나눈 값들을 최소 공배수에 각각 추가로 곱해줘서 최대 공배수를 구한다.
// 시간복잡도: O(n) n<10^6/2

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int min=1;
    for(int i=2;i<=1000000/2 && i<=n && i<=m;i++)
    {
        if(n%i==0 && m%i==0)
        {
            n/=i;
            m/=i;
            min*=i;
            i--;
        }
    }
    int max=min*n*m;
    answer.push_back(min);
    answer.push_back(max);
    return answer;
}
