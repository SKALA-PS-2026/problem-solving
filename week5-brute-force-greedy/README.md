# Week 5: 완전탐색, 그리디

<br>

## 🎯 이번 주 핵심 개념

### 1. 브루트포스(완전탐색)

**가능한 모든 경우의 수를 다 확인**해서 답을 찾는 방식입니다. 가장 단순하고 확실하지만, 경우의 수가 많아지면 느려집니다.

```python
# 예: 1부터 n까지 중 두 수를 더해서 target이 되는 쌍 찾기
def brute_force(arr, target):
    n = len(arr)
    for i in range(n):
        for j in range(i+1, n):
            if arr[i] + arr[j] == target:
                return (i, j)
    return None
```

**언제 쓰나**: 데이터 크기가 작을 때(대략 n ≤ 1000~10000 수준)는 굳이 복잡한 알고리즘을 쓰지 않고 브루트포스로 바로 풀어도 시간 안에 통과됩니다. 문제를 풀 때 **가장 먼저 "그냥 다 해보면 되지 않을까?"를 검토**하는 습관이 중요합니다 — 제한사항(N의 크기)을 보고 브루트포스로 충분한지 먼저 가늠하는 것이 실전에서 시간을 아끼는 핵심입니다.

<br>

### 2. 순열과 조합

**순열(Permutation)**: 순서를 구별해서 나열하는 경우의 수 (예: [1,2,3]에서 2개 뽑아 나열 → (1,2), (2,1), (1,3), (3,1), (2,3), (3,2))
**조합(Combination)**: 순서 상관없이 뽑는 경우의 수 (예: [1,2,3]에서 2개 뽑기 → (1,2), (1,3), (2,3))

<details>
<summary>Python (펼치기)</summary>

<br>

```python
from itertools import permutations, combinations

arr = [1, 2, 3]

list(permutations(arr, 2))    # [(1,2),(1,3),(2,1),(2,3),(3,1),(3,2)]
list(combinations(arr, 2))     # [(1,2),(1,3),(2,3)]
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
// Java는 순열/조합 내장 라이브러리가 없어서 재귀나 백트래킹으로 직접 구현
// (아래 백트래킹 코드 참고)
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <algorithm>

// 순열: 정렬된 상태에서 시작해 다음 순열을 반복해서 구함
vector<int> arr = {1, 2, 3};
sort(arr.begin(), arr.end());
do {
    // arr가 매번 다른 순열 상태
} while (next_permutation(arr.begin(), arr.end()));

// 조합은 C++ 표준 라이브러리에 없어서 재귀나 백트래킹으로 직접 구현
```

</details>

<br>

**언제 쓰나**: "가능한 모든 배열/선택을 다 만들어봐야 하는" 문제에서 씁니다. 순서가 결과에 영향을 주면 순열(예: 줄 세우기), 순서가 상관없으면 조합(예: 대표 뽑기)을 씁니다.

<br>

### 3. 백트래킹 기초

백트래킹은 브루트포스의 한 종류이지만, **"가능성이 없는 경로는 더 가지 않고 즉시 되돌아간다(가지치기)"**는 점이 다릅니다. 그냥 다 해보는 브루트포스보다 훨씬 효율적입니다.

```python
def backtrack(current, choices, k, result):
    if len(current) == k:               # 원하는 개수를 다 골랐으면 종료
        result.append(current[:])
        return
    for i, choice in enumerate(choices):
        current.append(choice)                        # 선택
        backtrack(current, choices[i+1:], k, result)    # 다음 단계로 재귀
        current.pop()                                    # 되돌아가기 (백트래킹의 핵심)
```

`current.pop()`으로 선택을 취소하고 되돌아가는 부분이 백트래킹의 정체성입니다. 대부분 재귀로 구현됩니다.

**언제 쓰나**: 조건에 맞는 조합/배열을 찾아야 하는데, 중간에 "이 조건은 이미 불가능하다"는 게 판명되면 그 이후는 확인할 필요가 없는 경우입니다. 예를 들어 N-Queen 문제에서 이미 두 퀸이 같은 줄에 있다면, 그 상태에서 더 깊이 들어가는 건 의미가 없으니 즉시 포기하고 다른 경우를 시도합니다.

<br>

### 4. 그리디(탐욕법)

매 순간 **"지금 이 시점에서 가장 좋아 보이는 선택"**을 하는 방식입니다. 전체를 다 따져보지 않고 눈앞의 최선을 계속 택해나갑니다.

```python
# 예: 동전 개수를 최소화해서 거스름돈 주기 (동전 단위가 배수 관계일 때만 그리디가 정확함)
def min_coins(amount, coins):
    coins.sort(reverse=True)   # 큰 단위부터
    count = 0
    for coin in coins:
        count += amount // coin
        amount %= coin
    return count
```

**주의할 점**: 그리디는 항상 정답을 보장하지 않습니다. **"매 순간의 최선의 선택이 전체의 최선으로 이어진다"는 것이 수학적으로 증명 가능할 때만** 그리디를 써야 합니다. 이 증명 없이 "그냥 될 것 같아서" 그리디로 접근하면 틀린 답이 나올 수 있습니다.

**언제 쓰나**: 최솟값/최댓값을 구하는 문제 중, 부분적으로 최선을 선택해나가도 전체 최적에 도달한다는 것이 보장되는 경우입니다. (반대로 이게 보장 안 되면 완전탐색이나 DP로 접근해야 합니다 — DP는 8주차에서 다룹니다.)

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.1 | 최소직사각형 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/86491) | 완전탐색(브루트포스) |
| 2 | Lv.1 | 모의고사 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42840) | 완전탐색(브루트포스) |
| 3 | Lv.1 | 체육복 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42862) | 그리디 |
| 4 | Lv.2 | 카펫 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42842) | 완전탐색(약수 조합 탐색) |
| 5 | Lv.2 | 피로도 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/87946) | 완전탐색(순열 활용) |
| 6 | Lv.2 | 구명보트 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42885) | 그리디(정렬 + 투 포인터 결합) |
| 7 | Lv.3 | N-Queen | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12952) | **심화**: 백트래킹, 다소 어려울 수 있어 여유 있을 때 도전 |

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

폴더명은 아래처럼 **problem숫자-문제이름** 형식으로 통일해주세요. (숫자는 위 문제 목록과 동일, 정렬이 꼬이지 않게 한 자리도 0을 붙여 두 자리로)

```
week5-brute-force-greedy/
├── README.md
├── problem01-최소직사각형/
│   └── 이름.py
├── problem02-모의고사/
│   └── 이름.py
```