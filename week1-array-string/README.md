# Week 1: 문자열/배열 기초

<br>

## 🎯 이번 주 핵심 개념

### 1. 배열/문자열 자주 쓰는 함수

<details>
<summary>Python (펼치기)</summary>

<br>

```python
# 아래는 모두 기본 내장 함수/메서드라 별도 import 불필요

arr = [3, 1, 2]
s = "hello world"

len(arr)               # 길이: 3
arr[0], arr[-1]         # 인덱싱: 첫 원소, 마지막 원소
arr[1:3]                # 슬라이싱: [1, 2]
arr.append(4)           # 끝에 추가
arr.sort()               # 정렬 (제자리)
sorted(arr)              # 정렬된 새 리스트 반환

s.split(" ")             # 공백 기준 분리: ["hello", "world"]
"-".join(["a", "b"])     # 합치기: "a-b"
s.replace("o", "0")      # 치환
s.strip()                 # 양끝 공백 제거
s.upper(), s.lower()     # 대/소문자 변환
s[::-1]                    # 문자열 뒤집기
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.Arrays;   // Arrays.sort, Arrays.toString 사용 시 필요

int[] arr = {3, 1, 2};
String s = "hello world";

arr.length                          // 배열 길이 (메서드 아님, 필드)
Arrays.sort(arr);                    // 정렬 (제자리)
Arrays.toString(arr)                 // 배열 출력용 문자열 변환

s.length()                           // 문자열 길이 (메서드, 괄호 필요)
s.charAt(0)                          // 인덱스로 문자 접근
s.substring(1, 3)                    // 슬라이싱
s.split(" ")                          // 공백 기준 분리 → String[]
String.join("-", "a", "b")           // 합치기: "a-b" (java.lang 기본 포함, import 불필요)
s.replace("o", "0")                  // 치환
s.trim()                              // 양끝 공백 제거
s.toUpperCase(), s.toLowerCase()     // 대/소문자 변환

// StringBuilder는 java.lang 기본 포함이라 import 불필요
new StringBuilder(s).reverse().toString()  // 문자열 뒤집기
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <algorithm>   // sort, reverse 사용 시 필요
#include <vector>       // vector 사용 시 필요
#include <string>       // string 사용 시 필요
#include <sstream>      // stringstream 사용 시 필요

vector<int> arr = {3, 1, 2};
string s = "hello world";

arr.size()                            // 배열(벡터) 길이
sort(arr.begin(), arr.end());          // 정렬 (제자리)
arr.push_back(4);                      // 끝에 추가

s.length()                             // 문자열 길이 (size()도 동일)
s.substr(1, 2)                          // 슬라이싱: 인덱스1부터 길이2
s.find("o")                             // 문자 위치 찾기 (없으면 string::npos)
reverse(s.begin(), s.end());            // 문자열 뒤집기 (제자리)

// split이 내장함수로 없어서 stringstream으로 직접 구현
stringstream ss(s);
string token;
while (getline(ss, token, ' ')) { /* ... */ }
```

</details>

<br>

### 2. 반복문과 재귀 (for / while / 재귀)
 
같은 문제를 세 가지 방식으로 풀어보면서 각각의 차이를 비교합니다.
 
**for문** — 반복 횟수가 정해져 있을 때 가장 직관적
 
```python
def factorial_for(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result
```
 
**while문** — 조건이 만족할 때까지 반복. 반복 횟수가 미리 정해지지 않은 경우에 특히 유용
 
```python
def factorial_while(n):
    result = 1
    while n > 1:
        result *= n
        n -= 1
    return result
```
 
**재귀** — "큰 문제를 더 작은 같은 모양의 문제로 쪼개서" 푸는 방식. 함수가 자기 자신을 호출
 
```python
def factorial_recursive(n):
    if n == 1:                              # base case
        return 1
    return n * factorial_recursive(n - 1)   # 자기 자신을 더 작은 문제로 호출
```

**핵심 포인트**
- 재귀는 **base case**가 반드시 있어야 함 (없으면 무한 재귀 → 스택 오버플로우)
- 재귀는 현 단계에서는 불필요한 경우가 많으나 나중을 위해 재귀 방법으로도 시도해보길 추천

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 난이도 | 문제 | 링크 |
|:---:|---|---|
| Lv.0 | 배열 두 배 만들기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/120809) |
| Lv.0 | 문자열 반복해서 출력하기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/181950) |
| Lv.0 | 배열 만들기 2 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/181921) |
| Lv.1 | 자연수 뒤집어 배열로 만들기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12932) |
| Lv.1 | 같은 숫자는 싫어 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12906) |
| Lv.1 | 문자열 다루기 기본 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12918) |
| Lv.1 | 문자열 내 p와 y의 개수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12916) |
| Lv.1 | 이상한 문자 만들기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12930) |
| Lv.1 | 시저 암호 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12926) |
| Lv.1 | 숫자 문자열과 영단어 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/81301) |
| Lv.1 | 문자열 나누기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/140108) |
| Lv.2 | 문자열 압축 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/60057) |
| Lv.2 | 괄호 변환 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/60058) |

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

```
week1-array-string/
├── README.md
├── problem01-배열 두 배 만들기/
│   └── 이름.py
├── problem02-문자열 반복해서 출력하기/
│   └── 이름.py
```
