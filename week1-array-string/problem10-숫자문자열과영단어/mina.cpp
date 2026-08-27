// 문제: 숫자 문자열과 영단어
// 접근 방식: replace하면 더 좋았을것같.. 긴한데 이정도는 노가다할만한듯
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i]>='0'&& s[i]<='9') answer = answer*10+s[i]-'0';
        else {
            int num;
            if (s[i]=='z'){
                num=0;
                i+=3;
            }
            else if (s[i]=='o'){
                num=1;
                i+=2;
            }
            else if (s[i]=='t'){
                if (s[i+1]=='w'){
                   num=2;
                    i+=2; 
                }
                else{
                    num=3;
                    i+=4;
                }
            }
            else if (s[i]=='f'){
                if (s[i+1]=='o'){
                   num=4;
                    i+=3; 
                }
                else{
                    num=5;
                    i+=3;
                }
            }
            else if (s[i]=='s'){
                if (s[i+1]=='i'){
                   num=6;
                    i+=2; 
                }
                else{
                    num=7;
                    i+=4;
                }
            }
            else if (s[i]=='e'){
                num=8;
                i+=4;
            }
            else if (s[i]=='n'){
                num=9;
                i+=3;
            }
            answer = answer*10+num;
        }
    }
    return answer;
}
