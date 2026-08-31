# Week 4: 스택, 큐, 힙

<br>

## 🎯 이번 주 핵심 개념

### 1. 스택(Stack)

**LIFO(Last In First Out)** — 마지막에 넣은 게 먼저 나오는 자료구조입니다. 쌓아 올린 접시를 떠올리면 됩니다: 맨 위에 놓은 접시를 맨 먼저 뺍니다.

<details>
<summary>Python (펼치기)</summary>

<br>

```python
# 파이썬은 별도 자료구조 없이 리스트로 스택을 구현
stack = []
stack.append(1)     # push: 넣기
stack.append(2)
stack.append(3)
stack.pop()          # pop: 꺼내기 → 3 (마지막에 넣은 것부터)
stack[-1]            # peek: 맨 위 원소 확인 (꺼내지 않고 보기만)
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.Stack;

Stack<Integer> stack = new Stack<>();
stack.push(1);
stack.push(2);
stack.push(3);
stack.pop();          // 3
stack.peek();          // 맨 위 원소 확인
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <stack>

stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.pop();            // 꺼내기만 함 (반환값 없음, 주의)
s.top();             // 맨 위 원소 확인 (pop 전에 top()으로 값을 먼저 봐야 함)
```

</details>

<br>

**언제 쓰나**: 괄호 짝 맞추기, 최근 방문한 것부터 되돌아가기(뒤로가기 기능), 재귀 호출을 흉내내서 반복문으로 바꿀 때(재귀는 사실 내부적으로 스택을 씀) 등, "가장 최근 것부터 처리해야 하는" 상황에서 사용합니다.

<br>

### 2. 큐(Queue)

**FIFO(First In First Out)** — 먼저 넣은 게 먼저 나오는 자료구조입니다. 줄 서기를 떠올리면 됩니다: 먼저 줄 선 사람이 먼저 나갑니다.

<details>
<summary>Python (펼치기)</summary>

<br>

```python
from collections import deque

# 리스트로도 큐를 구현할 수 있지만, list.pop(0)은 O(n)이라 느림
# deque(데크)는 양쪽 끝에서 추가/제거가 모두 O(1)이라 큐 구현에 훨씬 적합
q = deque()
q.append(1)          # 뒤에 넣기
q.append(2)
q.append(3)
q.popleft()           # 앞에서 꺼내기 → 1 (먼저 넣은 것부터)
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.LinkedList;
import java.util.Queue;

Queue<Integer> q = new LinkedList<>();
q.offer(1);          // 뒤에 넣기
q.offer(2);
q.offer(3);
q.poll();             // 앞에서 꺼내기 → 1
q.peek();             // 맨 앞 원소 확인
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <queue>

queue<int> q;
q.push(1);           // 뒤에 넣기
q.push(2);
q.push(3);
q.pop();             // 앞에서 꺼내기만 함 (반환값 없음)
q.front();            // 맨 앞 원소 확인
```

</details>

<br>

**언제 쓰나**: 순서대로 처리해야 하는 작업(대기열), 너비 우선 탐색(BFS, 7주차에서 다룸)의 핵심 도구로 쓰입니다. "먼저 온 것부터 순서대로 처리"해야 하는 모든 상황에 해당합니다.

<br>

### 3. 우선순위 큐(Priority Queue)와 힙(Heap)

**우선순위 큐**는 "먼저 넣은 순서"가 아니라 **"우선순위가 높은 것부터"** 나오는 큐입니다. 이걸 효율적으로 구현하는 자료구조가 **힙(Heap)**입니다.

힙은 **완전 이진 트리** 형태를 가지며, 부모 노드와 자식 노드 사이에 항상 일정한 크기 관계(최소 힙이면 부모 ≤ 자식, 최대 힙이면 부모 ≥ 자식)를 유지합니다. 그 덕분에 **가장 작은 값(또는 가장 큰 값)을 O(log n)에 꺼낼 수 있습니다.**

<details>
<summary>Python (펼치기)</summary>

<br>

```python
import heapq

heap = []
heapq.heappush(heap, 3)
heapq.heappush(heap, 1)
heapq.heappush(heap, 2)
heapq.heappop(heap)     # 1 (가장 작은 값부터 나옴, 파이썬 heapq는 최소 힙만 지원)

# 최대 힙이 필요하면 부호를 뒤집어서 넣는 트릭 사용
heapq.heappush(heap, -3)
-heapq.heappop(heap)     # 꺼낼 때 다시 부호를 뒤집어서 원래 값 복원
```

</details>

<details>
<summary>Java (펼치기)</summary>

<br>

```java
import java.util.PriorityQueue;

// 기본은 최소 힙
PriorityQueue<Integer> pq = new PriorityQueue<>();
pq.offer(3);
pq.offer(1);
pq.offer(2);
pq.poll();               // 1 (가장 작은 값부터 나옴)

// 최대 힙으로 쓰려면 비교 기준을 반대로 지정
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
```

</details>

<details>
<summary>C++ (펼치기)</summary>

<br>

```cpp
#include <queue>

// 기본은 최대 힙 (Python, Java와 반대이니 주의)
priority_queue<int> maxHeap;
maxHeap.push(3);
maxHeap.push(1);
maxHeap.push(2);
maxHeap.top();            // 3 (가장 큰 값부터 나옴)

// 최소 힙으로 쓰려면 별도 템플릿 인자 필요
priority_queue<int, vector<int>, greater<int>> minHeap;
```

</details>

<br>

**언제 쓰나**: "가장 크거나 작은 값을 반복적으로 꺼내야 하는" 상황에서 유용합니다. 예를 들어 데이터가 계속 들어오는 와중에 매번 최댓값/최솟값을 확인해야 할 때, 정렬을 매번 새로 하면 O(n log n)이 반복되지만 힙을 쓰면 삽입/삭제가 각각 O(log n)이라 훨씬 효율적입니다. 나중에(9주차 보류 항목) 다익스트라 알고리즘에서도 핵심 도구로 다시 쓰입니다.

> **주의**: 파이썬(`heapq`)과 자바(`PriorityQueue`)는 기본이 **최소 힙**이지만, C++(`priority_queue`)은 기본이 **최대 힙**입니다. 언어마다 기본값이 반대라 헷갈리기 쉬우니 주의하세요.

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.2 | 올바른 괄호 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12909) | 스택 기초 (카운터로도 풀리지만 스택 감 잡기 좋음) |
| 2 | Lv.2 | 기능개발 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42586) | 스택 |
| 3 | Lv.2 | 다리를 지나는 트럭 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42583) | 큐 |
| 4 | Lv.2 | 주식가격 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42584) | 스택(또는 브루트포스와 비교) |
| 5 | Lv.2 | 쇠막대기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42585) | 스택 (KOI 기출, 스택의 정석 문제) |
| 6 | Lv.2 | 괄호 회전하기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/76502) | 스택 응용 (올바른 괄호의 심화 버전, Kit 외 카카오 월간 챌린지 문제) |
| 7 | Lv.2 | 더 맵게 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42626) | 힙(우선순위 큐) 기본 |
| 8 | Lv.3 | 이중우선순위큐 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42628) | **심화**: 힙 응용, 다소 어려울 수 있어 여유 있을 때 도전 |
| 9 | Lv.3 | 디스크 컨트롤러 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/42627) | **심화**: 힙 + 정렬 결합, 이번 주에서 가장 난이도가 높음 |

> 1번(올바른 괄호)은 스택 개념을 가장 쉽게 시작할 수 있는 입문 문제입니다.
> 2~6번은 각각 스택, 큐 개념과 연결됩니다. 다만 프로그래머스 문제 자체는 상황을 시뮬레이션하는 형태라 조건 파악에 시간이 좀 걸릴 수 있습니다. 5번(쇠막대기)은 괄호를 스택에 쌓아가며 처리하는, 스택 문제의 정석으로 꼽히는 문제입니다. 6번(괄호 회전하기)은 1번(올바른 괄호)의 응용으로, 회전이라는 조건이 추가돼 한 단계 더 복잡합니다.
> 7번(더 맵게)은 힙 개념(개념 3)을 배우고 바로 적용해보기 좋은 기본 문제입니다.
> 8~9번은 심화 문제입니다.
> - 8번(이중우선순위큐)은 "최댓값 삭제"와 "최솟값 삭제"를 모두 지원하는 우선순위 큐를 구현해야 하는 문제로, 7번을 먼저 풀고 도전하시는 걸 추천합니다.
> - 9번(디스크 컨트롤러)은 힙과 정렬(요청 시간 순서 처리)을 함께 다뤄야 하는 문제로, 실제로 시간을 꽤 잡아먹는 난이도라 여유 있을 때 도전하시는 걸 추천합니다.

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

폴더명은 아래처럼 **problem숫자-문제이름** 형식으로 통일해주세요. (숫자는 위 문제 목록과 동일, 정렬이 꼬이지 않게 한 자리도 0을 붙여 두 자리로)

```
week4-stack-queue-heap/
├── README.md
├── problem01-올바른괄호/
│   └── 이름.py
├── problem02-기능개발/
│   └── 이름.py
```