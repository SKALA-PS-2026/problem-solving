# Week 3: 해시, 정렬

<br>

## 🎯 이번 주 핵심 개념

### 1. 해시(Hash) 활용

해시맵(딕셔너리)은 **key-value 쌍으로 데이터를 저장**하고, key를 통해 **평균 O(1)**에 값을 찾을 수 있는 자료구조입니다. "존재하는지 확인", "개수 세기" 같은 작업이 반복문(O(n))보다 훨씬 빨라집니다.

<details>
<summary>Python (펼치기)</summary>

<br>

```python
# 기본 사용
d = {}
d["apple"] = 3
d.get("apple")            # 3
d.get("banana", 0)         # 없는 key 조회 시 기본값 0 반환 (에러 안 남)

# 빈도수 세기 (자주 쓰는 패턴)
from collections import Counter
count = Counter(["a", "b", "a", "c", "a"])
# Counter({'a': 3, 'b': 1, 'c': 1})

# 존재 여부 확인 (set 활용, key만 필요할 때)
s = set([1, 2, 3])
2 in s      # True, 평균 O(1)
```

> **참고**: Python 3.7+부터는 기본 `dict`가 삽입한 순서를 그대로 유지합니다. 정렬된 순서로 보고 싶으면 `sorted(d.items())`처럼 그때그때 정렬하면 되므로, 별도의 "정렬 유지형 딕셔너리"가 따로 필요하지 않습니다.

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.HashMap;
import java.util.HashSet;

HashMap<String, Integer> map = new HashMap<>();
map.put("apple", 3);
map.get("apple");                     // 3
map.getOrDefault("banana", 0);        // 없는 key 조회 시 기본값 0 반환

// 빈도수 세기 (자주 쓰는 패턴)
map.put(key, map.getOrDefault(key, 0) + 1);

// 존재 여부 확인
HashSet<Integer> set = new HashSet<>();
set.add(1);
set.contains(1);    // true, 평균 O(1)
```

> **참고**: `HashMap`/`HashSet`은 순서를 보장하지 않습니다. **key 기준으로 자동 정렬된 상태를 유지하고 싶으면 `TreeMap`/`TreeSet`**(내부는 이진 탐색 트리, 조회 O(log n))을, **삽입한 순서 그대로 유지하고 싶으면 `LinkedHashMap`/`LinkedHashSet`**을 씁니다.

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <unordered_map>   // 해시맵
#include <unordered_set>   // 해시셋

unordered_map<string, int> m;
m["apple"] = 3;
m["apple"];                        // 3 (없는 key 접근 시 자동으로 0 생성됨, 주의)
m.count("banana");                  // 0이면 없음, 1이면 있음 (존재 확인 시 자주 씀)

// 빈도수 세기
m[key]++;                            // 없으면 0에서 시작해서 1이 됨

// 존재 여부 확인
unordered_set<int> s;
s.insert(1);
s.count(1);      // 1이면 존재, 평균 O(1)
```

> **참고**: `unordered_map`/`unordered_set`은 순서를 보장하지 않습니다(내부는 해시 테이블). **key 기준으로 자동 정렬된 상태를 유지하고 싶으면 `map`/`set`**(내부는 균형 이진 탐색 트리, 조회 O(log n))을 씁니다. 대부분의 해시 문제(빈도수 세기, 존재 확인)는 순서가 필요 없어서 `unordered_map`/`unordered_set`이 더 빠르고 적합합니다.

</details>

<br>

**언제 쓰나**: 배열을 for문으로 매번 훑으면서 "이 값 있나?"를 확인하면 O(n)이 반복될 때마다 곱해져서 느려집니다. 해시맵/셋에 미리 넣어두면 조회가 O(1)이라 전체 시간복잡도를 크게 줄일 수 있습니다.

<br>

### 2. 정렬 커스터마이징

기본 정렬은 오름차순이지만, **정렬 기준을 직접 정의**해서 원하는 순서로 정렬할 수 있습니다.

<details>
<summary>Python (펼치기)</summary>

<br>

```python
arr = [3, 1, 2]

sorted(arr)                          # 오름차순: [1, 2, 3]
sorted(arr, reverse=True)            # 내림차순: [3, 2, 1]

# key로 정렬 기준 직접 지정
words = ["banana", "kiwi", "apple"]
sorted(words, key=len)                # 길이 기준: ['kiwi', 'apple', 'banana']

# 여러 조건으로 정렬 (튜플 사용, 앞 조건 우선)
data = [(3, "c"), (1, "b"), (1, "a")]
sorted(data, key=lambda x: (x[0], x[1]))   # [(1, 'a'), (1, 'b'), (3, 'c')]

# 문자열 비교 기반 정렬 (직접 비교 함수가 필요할 때)
from functools import cmp_to_key
def compare(a, b):
    if a + b > b + a:
        return -1   # a가 앞에 와야 함
    else:
        return 1
sorted(["3", "30", "34"], key=cmp_to_key(compare))
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.Arrays;
import java.util.Comparator;

Integer[] arr = {3, 1, 2};   // Comparator 쓰려면 배열이 객체 타입이어야 함 (int[]는 불가)

Arrays.sort(arr);                                       // 오름차순
Arrays.sort(arr, Comparator.reverseOrder());              // 내림차순

// 길이 기준 정렬
String[] words = {"banana", "kiwi", "apple"};
Arrays.sort(words, Comparator.comparingInt(String::length));

// 여러 조건으로 정렬 (thenComparing으로 이어붙임)
Arrays.sort(data, Comparator.comparingInt((int[] x) -> x[0])
                              .thenComparingInt(x -> x[1]));

// 직접 비교 함수 (compare 메서드 오버라이드)
Arrays.sort(strArr, (a, b) -> (b + a).compareTo(a + b));   // 이어붙였을 때 큰 쪽이 앞
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <algorithm>

vector<int> arr = {3, 1, 2};

sort(arr.begin(), arr.end());                          // 오름차순
sort(arr.begin(), arr.end(), greater<int>());           // 내림차순

// 직접 비교 함수 (기준 정의)
bool compare(const string& a, const string& b) {
    return a + b > b + a;   // 이어붙였을 때 큰 쪽이 앞
}
sort(arr.begin(), arr.end(), compare);

// 여러 조건으로 정렬 (람다 안에서 직접 비교)
sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
});
```

</details>

<br>

**언제 필요한가**: 단순히 숫자/문자 크기 순이 아니라 "특정 기준으로" 정렬해야 하는 문제에서 커스텀 비교 기준이 필요합니다. 예를 들어 문자열을 길이순으로, 혹은 두 값을 이어붙였을 때 더 큰 쪽을 앞에 오게 하는 식입니다.

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.1 | 완주하지 못한 선수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42576) | 해시(Counter) |
| 2 | Lv.1 | 폰켓몬 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/1845) | 해시(set) |
| 3 | Lv.1 | 신고 결과 받기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/92334) | 해시맵+해시셋 조합 활용 (2022 카카오 기출) |
| 4 | Lv.1 | 문자열 내림차순으로 배치하기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12917) | 정렬(reverse) |
| 5 | Lv.1 | 문자열 내 마음대로 정렬하기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12915) | 정렬 커스터마이징(key) |
| 6 | Lv.1 | 실패율 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42889) | **심화**: 해시 + 정렬 결합 |
| 7 | Lv.2 | 영어 끝말잇기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12981) | 해시(set) 응용 — 등장한 단어 추적 |
| 8 | Lv.2 | H-Index | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42747) | **심화**: 정렬 응용(내림차순 정렬 후 인덱스 비교) |
| 9 | Lv.2 | 가장 큰 수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42746) | **심화**: 정렬 커스터마이징(비교 함수) |
| 10 | Lv.3 | 베스트앨범 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42579) | **심화**: 해시 + 정렬 결합, 다소 어려울 수 있어 여유 있을 때 도전 |

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

폴더명은 아래처럼 **problem숫자-문제이름** 형식으로 통일해주세요.

```
week3-hash-sort/
├── README.md
├── problem01-완주하지못한선수/
│   └── 이름.py
├── problem02-폰켓몬/
│   └── 이름.py
```