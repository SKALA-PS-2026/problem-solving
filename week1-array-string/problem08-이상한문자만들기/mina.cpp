// 문제: 이상한 문자 만들기
// 접근 방식: 단어 시작부분 인덱스를 따로 기록해서 현재 인덱스와의 차이를 2로 나눈 나머지 -> 홀수면 소문자, 짝수면 대문자로
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int diff = 'a'-'A';
    int idx=0;
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ') {
            idx = i+1;
        }
        else {
            if ((i-idx)%2){
                s[i]=s[i]<'a'?s[i]+diff:s[i];
            }
            else {
                s[i]=s[i]<'a'?s[i]:s[i]-diff;
            }
        }
    }
    return s;
}
