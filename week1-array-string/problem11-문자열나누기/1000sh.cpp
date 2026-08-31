// 문제: 문자열 나누기
// 접근 방식: 처음 문자열 넣고 같으면 첫문자변수 증가 감소로 변수 1개로 통합 처리
// 시간복잡도: O(n) n<=10^4

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size=s.size();
    int CharNum=0;
    char firstChar;
    for(int i=0;i<size;i++)
    {
        if(CharNum==0)
        {
            answer++;
            firstChar=s[i];
            CharNum++;
        }
        else if(s[i]==firstChar) CharNum++;
        else CharNum--;
    }
    return answer;
}
