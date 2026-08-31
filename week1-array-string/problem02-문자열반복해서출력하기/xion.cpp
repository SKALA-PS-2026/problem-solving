// 문제: 문자열 반복해서 출력하기
// 접근 방식: 
// 시간복잡도: 

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;
    
    for(int i=0; i < n; i++ ){
        cout << str;
    }
    return 0;
}
