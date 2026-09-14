// 문제: 시저 암호
// 접근 방식: 오프셋으로 0-26로 정규화 한다음 변환하고 다시 오프셋 시킨다.
// 시간복잡도: O(n) n<=8000

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int num='z'-'a'+1;
    for(char &c:s)
    {
        if(c==' ')continue;
        int offset='a';
        if(c<'a') offset='A';
        c-=offset;
        c+=n;
        c=c%num;
        c+=offset;
        
    }
    
    return s;
}
