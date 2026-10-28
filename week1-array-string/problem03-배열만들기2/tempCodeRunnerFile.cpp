#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;


int main() {
    //vector<int> v;
    string str = to_string(203024);
    int num = 123;

    cout << typeid(num).name() << ":" << str << '\n';
}



vector<int> solution(int l, int r) {
    vector<int> answer;
    /*
    for(int i=l; i<=r; i++)
    {
        string str = to_string(i);

    }
    */
    string str = to_string(l);
    string str2 = to_string(r);

    return answer;
}