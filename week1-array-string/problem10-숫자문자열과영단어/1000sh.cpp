// 문제: 숫자 문자열과 영단어
// 접근 방식: 영단어 특정 자리수만 보고 판단. 숫자는 그냥 판단
// 시간복잡도: O(n) n<=50

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        answer*=10;
        if(s[i]<='9')answer+=s[i]-'0';
        else if(s[i]=='z'){i+=3;} //0
        else if(s[i]=='o'){answer+=1;i+=2;} //1
        else if(s[i]=='e'){answer+=8;i+=4;}//8
        else if(s[i]=='n'){answer+=9;i+=3;}//9
        else if(s[i+1]=='w'){answer+=2;i+=2;} //2
        else if(s[i+1]=='h'){answer+=3;i+=4;} //3
        else if(s[i+1]=='o'){answer+=4;i+=3;} //4
        else if(s[i+2]=='x'){answer+=6;i+=2;} //6
        else if(s[i+1]=='i'){answer+=5;i+=3;} //5
        else if(s[i+3]=='e'){answer+=7;i+=4;} //7
    }
    return answer;
}
