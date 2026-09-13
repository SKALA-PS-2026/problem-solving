# Week 7: DFS/BFS

<br>

## 🎯 이번 주 핵심 개념

### 1. DFS (깊이 우선 탐색)

**한 방향으로 갈 수 있는 데까지 갔다가, 막히면 되돌아와서 다른 방향을 탐색**하는 방식입니다. 재귀로 구현하거나, 스택을 직접 써서 구현할 수도 있습니다.

**재귀로 구현**

```python
def dfs(v, visited, graph):
    visited[v] = True
    for next_node in graph[v]:
        if not visited[next_node]:
            dfs(next_node, visited, graph)
```

**스택으로 구현**

```python
def dfs_stack(start, visited, graph):
    stack = [start]
    while stack:
        v = stack.pop()
        if not visited[v]:
            visited[v] = True
            for next_node in graph[v]:
                if not visited[next_node]:
                    stack.append(next_node)
```

재귀는 코드가 짧고 직관적이지만, 탐색 범위가 아주 깊으면 재귀 깊이 제한에 걸릴 수 있습니다. 이럴 때는 스택으로 직접 구현하는 게 안전합니다.

<br>

### 2. BFS (너비 우선 탐색)

**가까운 곳부터 한 단계씩 순서대로** 탐색하는 방식입니다. 큐로 구현합니다.

```python
from collections import deque

def bfs(start, visited, graph):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        for next_node in graph[v]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)
```

<br>

### 3. 언제 뭘 쓰나

**최단 거리를 구해야 하면 BFS.** 가까운 곳부터 퍼져나가기 때문에, 어딘가에 처음 도착한 순간이 곧 최단 거리입니다. 그 외의 경우(모든 경로 탐색, 조합 찾기 등)는 DFS를 씁니다.

<br>

### 4. 방문 체크(visited)가 필요한 이유

**같은 곳을 다시 방문하면 무한루프에 빠질 수 있어서** 필요합니다. 예를 들어 1→2→3→1처럼 순환하는 구조가 있으면, 방문 체크 없이는 영원히 반복됩니다. 트리는 이런 순환이 없는 구조라 방문 체크가 필요 없었지만, 그 외 대부분의 구조(그래프, 2차원 격자 등)는 필요합니다.

<br>

### 5. 2차원 격자 탐색: dx, dy 배열

미로나 지도 같은 2차원 배열에서 상하좌우로 탐색할 때 쓰는 패턴입니다.

```python
dx = [-1, 1, 0, 0]   # 위, 아래, 그대로, 그대로
dy = [0, 0, -1, 1]    # 그대로, 그대로, 왼쪽, 오른쪽

def dfs(x, y, grid, visited):
    visited[x][y] = True
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and not visited[nx][ny]:
            dfs(nx, ny, grid, visited)
```

네 방향을 if문 4개로 따로 안 쓰고, `dx`/`dy` 배열과 반복문으로 한 번에 처리합니다. 범위를 벗어나는지 확인하는 조건을 꼭 같이 넣어야 합니다.

<br>

### 6. 연결 요소(Connected Component) 개수 구하기

전체 정점을 훑다가, 아직 방문 안 한 정점을 만날 때마다 DFS/BFS를 한 번씩 돌리고 개수를 세면 됩니다.

```python
def count_components(n, graph):
    visited = [False] * (n + 1)
    count = 0
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i, visited, graph)
            count += 1
    return count
```

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.2 | 타겟 넘버 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/43165) | DFS |
| 2 | Lv.2 | 게임 맵 최단거리 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/1844) | BFS(2차원 격자, dx/dy 활용, 최단거리) |
| 3 | Lv.3 | 네트워크 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/43162) | DFS/BFS(연결 요소) |
| 4 | Lv.3 | 단어 변환 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/43163) | **심화**: BFS(최단거리) |
| 5 | Lv.3 | 여행경로 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/43164) | **심화**: DFS |
| 6 | Lv.3 | 카드 짝 맞추기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/72415) | **심화**: DFS(순열) + BFS 결합, 2021 카카오 블라인드, 이번 주에서 가장 난이도가 높음, 여유 있을 때 도전 |

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

폴더명은 아래처럼 **problem숫자-문제이름** 형식으로 통일해주세요. (숫자는 위 문제 목록과 동일, 정렬이 꼬이지 않게 한 자리도 0을 붙여 두 자리로)

```
week7-dfs-bfs/
├── README.md
├── problem01-타겟넘버/
│   └── 이름.py
├── problem02-게임맵최단거리/
│   └── 이름.py
```