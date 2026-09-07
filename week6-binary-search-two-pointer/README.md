# Week 6: 이분탐색, 투 포인터, 슬라이딩 윈도우

<br>

## 🎯 이번 주 핵심 개념

### 1. 이분탐색(Binary Search)

**정렬된 데이터**에서 원하는 값을 찾을 때, 범위를 절반씩 줄여나가며 탐색하는 방법입니다. 전체를 다 훑는 O(n)이 아니라 **O(log n)**으로 훨씬 빠릅니다.

<details>
<summary>Python (펼치기)</summary>

<br>

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1     # 오른쪽 절반만 탐색
        else:
            right = mid - 1     # 왼쪽 절반만 탐색
    return -1

# 내장 라이브러리로도 가능
from bisect import bisect_left, bisect_right
bisect_left(arr, target)    # target이 들어갈 가장 왼쪽 인덱스
bisect_right(arr, target)   # target이 들어갈 가장 오른쪽 인덱스
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.Arrays;

int[] arr = {1, 3, 5, 7, 9};
int idx = Arrays.binarySearch(arr, 5);   // 내장 이분탐색, 찾으면 인덱스 반환

// 직접 구현
int left = 0, right = arr.length - 1;
while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) { /* 찾음 */ break; }
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <algorithm>

vector<int> arr = {1, 3, 5, 7, 9};

lower_bound(arr.begin(), arr.end(), target);   // target 이상이 처음 나오는 위치
upper_bound(arr.begin(), arr.end(), target);   // target 초과가 처음 나오는 위치
binary_search(arr.begin(), arr.end(), target);  // 존재 여부만 true/false로 반환
```

</details>

<br>

**파라메트릭 서치(Parametric Search)**: 이분탐색의 응용으로, "정답이 될 수 있는 값의 범위"를 이분탐색으로 좁혀나가는 기법입니다. "이 값이 조건을 만족하는가?"를 판별하는 함수만 있으면, 그 경계값을 이분탐색으로 빠르게 찾을 수 있습니다.

```python
# 예: "이 정도 크기로 자르면 조건을 만족하는가?"를 판별하며 범위를 좁혀나감
def is_possible(mid):
    # mid라는 값이 조건을 만족하는지 확인하는 로직
    pass

left, right = 최소가능값, 최대가능값
answer = 0
while left <= right:
    mid = (left + right) // 2
    if is_possible(mid):
        answer = mid
        left = mid + 1     # 더 큰 값도 가능한지 확인
    else:
        right = mid - 1
```

**언제 쓰나**: 정렬된 배열에서 특정 값을 찾을 때, 혹은 "몇 개 이하로 자르면 되는가?", "최소/최대 얼마까지 가능한가?" 같은 최적화 문제에서 답의 범위 자체를 이분탐색으로 좁혀나갈 때 사용합니다.

<br>

### 2. 투 포인터(Two Pointer)

**두 개의 포인터(인덱스)를 사용해서 배열을 탐색**하는 기법입니다. 상황에 따라 포인터를 각각 다른 방향으로 움직이거나, 조건에 따라 좁혀나갑니다.

```python
# 예: 정렬된 배열에서 합이 target인 두 수 찾기
def two_sum(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return (left, right)
        elif current_sum < target:
            left += 1      # 합이 작으면 왼쪽 포인터를 오른쪽으로 이동(더 큰 값으로)
        else:
            right -= 1      # 합이 크면 오른쪽 포인터를 왼쪽으로 이동 (더 작은 값으로)
    return None
```

**언제 쓰나**: 정렬된 배열에서 두 값의 합/차이 조건을 찾을 때, 배열을 한 번만 훑으면서(O(n)) 브루트포스(O(n²))보다 빠르게 풀 수 있습니다.

<br>

### 3. 슬라이딩 윈도우(Sliding Window)

투 포인터의 한 종류로, **일정한 범위(윈도우)를 유지하며 이동**시키는 기법입니다. 윈도우 크기가 고정될 수도 있고, 조건에 따라 늘었다 줄었다 할 수도 있습니다.

```python
# 예: 크기가 k인 부분 배열의 최대 합 구하기 (고정 크기 윈도우)
def max_sum_window(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i-k]   # 새로 들어온 값 더하고, 빠지는 값 빼기
        max_sum = max(max_sum, window_sum)
    return max_sum
```

**언제 쓰나**: "연속된 구간"에서 조건을 만족하는 최대/최소/개수를 구할 때 사용합니다. 매번 구간 합을 새로 계산하지 않고, 윈도우가 이동할 때 **양 끝의 값만 더하고 빼는 방식**으로 계산량을 크게 줄입니다.

<br>

### 4. 참고: 구간합(Prefix Sum)

슬라이딩 윈도우와 함께 알아두면 좋은 개념입니다. **구간이 고정되어 있고, 여러 번 다른 범위의 합을 반복해서 조회**해야 할 때 씁니다. 미리 누적합 배열을 만들어두면, 어떤 구간의 합이든 O(1)에 구할 수 있습니다.

```python
arr = [1, 2, 3, 4, 5]
prefix_sum = [0] * (len(arr) + 1)
for i in range(len(arr)):
    prefix_sum[i+1] = prefix_sum[i] + arr[i]
# prefix_sum = [0, 1, 3, 6, 10, 15]

# i번째부터 j번째까지의 합 (0-indexed, i~j 포함)
def range_sum(i, j):
    return prefix_sum[j+1] - prefix_sum[i]
```

**슬라이딩 윈도우와의 차이**: 슬라이딩 윈도우는 "구간이 이동하면서" 조건을 확인할 때, 구간합은 "구간 위치가 정해져 있고 반복 조회"할 때 사용합니다. 매번 반복문으로 구간 합을 계산하면 O(n)이 쿼리마다 반복되지만, 구간합을 미리 구해두면 쿼리당 O(1)로 끝납니다.

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.1 | 예산 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12982) | 이분탐색(파라메트릭 서치) 입문 |
| 2 | Lv.1 | 최댓값과 최솟값 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12939) | 투 포인터 |
| 3 | Lv.1 | 로또의 최고 순위와 최저 순위 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/77484) | 투 포인터(정렬 후 두 배열 비교) |
| 4 | Lv.2 | 할인 행사 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/131127) | 슬라이딩 윈도우(고정 크기 10일 구간) |
| 5 | Lv.3 | 입국심사 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/43238) | **심화**: 이분탐색(파라메트릭 서치) |
| 6 | Lv.3 | 보석 쇼핑 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/67258) | **심화**: 투 포인터 + 슬라이딩 윈도우 결합 |
| 7 | Lv.3 | 광고 삽입 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/72414) | **심화**: 슬라이딩 윈도우 + 구간합(누적합) 결합 |
| 8 | Lv.3 | 연속 부분 수열 합의 개수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/131701) | **심화**: 슬라이딩 윈도우(원형 수열), 이번 주에서 가장 난이도가 높음, 여유 있을 때 도전 |

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

폴더명은 아래처럼 **problem숫자-문제이름** 형식으로 통일해주세요. (숫자는 위 문제 목록과 동일, 정렬이 꼬이지 않게 한 자리도 0을 붙여 두 자리로)

```
week6-binary-search-two-pointer/
├── README.md
├── problem01-예산/
│   └── 이름.py
├── problem02-최댓값과최솟값/
│   └── 이름.py
```