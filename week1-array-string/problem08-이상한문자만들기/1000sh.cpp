// 문제: 이상한 문자 만들기
// 접근 방식: 홀짝 판단해서 대문자 소문자 번갈아 가면서 만듬
// 시간복잡도: O(n)

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int size=s.size();
    bool index=true;
    for(int i=0;i<size;i++)
    {
        if(s[i]==' '){
            answer.push_back(' ');
            index=true;
            continue;
        }
        answer.push_back(index?toupper(s[i]):tolower(s[i]));
        index =!index;
    }
    return answer;
}
