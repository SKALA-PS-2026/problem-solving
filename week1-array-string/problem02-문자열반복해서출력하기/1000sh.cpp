// 문제: 종이 자르기
// 접근 방식: 문자열 더해주는 함수 생성 후 생성
// 시간복잡도: O(n) n<=5*10000

#include <iostream>
#include <string>

using namespace std;

string rollString(string str, int n)
{
    string str2=str;
    for(int i=0;i<n-1;i++)
    {
        str2.append(str);
    }
    return str2;
}


int main(void) {
    string str;
    int n;
    cin >> str >> n;
    cout<<rollString(str,n);
    return 0;
}
