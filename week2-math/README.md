# Week 2: 수학 기초

<br>

## 🎯 이번 주 핵심 개념

### 1. 최대공약수 / 최소공배수 (유클리드 호제법)

**최대공약수(GCD)**: 두 수의 공통 약수 중 가장 큰 값
**최소공배수(LCM)**: 두 수의 공통 배수 중 가장 작은 값

일일이 약수를 다 구해서 비교하면 느립니다. **유클리드 호제법**을 쓰면 훨씬 빠르게 구할 수 있습니다.

```python
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

# Python: math.gcd(), math.lcm() (3.9+)
# C++17: std::gcd(), std::lcm() (<numeric>)
# Java: BigInteger.gcd()
```

**원리**: `a`를 `b`로 나눈 나머지가 `r`이면, `a`와 `b`의 최대공약수는 `b`와 `r`의 최대공약수와 같습니다. 이 과정을 나머지가 0이 될 때까지 반복하면 최대공약수가 나옵니다. 최소공배수는 `(두 수의 곱) / 최대공약수`로 바로 구해집니다.

<br>

### 2. 소수 판별과 에라토스테네스의 체

**소수**: 1과 자기 자신으로만 나누어지는 수 (1은 소수가 아님)

**단순 판별법** — 하나의 수가 소수인지 확인
```python
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):  # 제곱근까지만 확인해도 충분
        if n % i == 0:
            return False
    return True
```

**에라토스테네스의 체** — 1부터 N까지 범위 안의 소수를 한 번에 다 찾을 때 훨씬 빠름
```python
def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, n + 1, i):  # i의 배수를 전부 지워나감
                is_prime[j] = False
    return [i for i in range(2, n + 1) if is_prime[i]]
```

**언제 무엇을 쓰나**: 소수 하나만 판별하면 단순 판별법으로 충분하지만, 범위 안의 소수를 여러 개 찾아야 하면 에라토스테네스의 체가 압도적으로 빠릅니다 (하나씩 나눠보는 것보다 배수를 지워나가는 방식이 효율적).

<br>

### 3. 약수 구하기

```python
def get_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:               # 제곱수가 아니면 짝도 추가
                divisors.append(n // i)
    return sorted(divisors)
```

`n`까지 다 확인할 필요 없이, **제곱근까지만 확인하고 짝을 같이 추가**하면 훨씬 빠릅니다.

<br>

### 4. 진법 변환

```python
def to_base(n, base):
    if n == 0:
        return "0"
    digits = []
    while n > 0:
        digits.append(str(n % base))
        n //= base
    return "".join(reversed(digits))

# 파이썬 내장 함수로도 가능 (2, 8, 16진법 한정)
bin(10)   # '0b1010'
oct(10)   # '0o12'
hex(10)   # '0xa'
```

<br>

### 5. 팩토리얼 / 조합 / 하노이의 탑 (1주차 재귀와 연결되는 수학)

**팩토리얼(Factorial)**: `n! = n × (n-1) × ... × 1`

```python
def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

# Python: math.factorial()
```

**조합(Combination, nCr)**: `n`개 중 `r`개를 순서 상관없이 뽑는 경우의 수. 공식 안에서 팩토리얼 사용.

```python
def combination(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))

# Python: itertools.combinations() (조합 자체를 나열), itertools.permutations() (순열)
```

**하노이의 탑**: 재귀로 풀리는 대표 문제입니다. "n개를 옮기려면, n-1개를 옮기는 문제가 먼저 해결되어야 한다"는 재귀적 사고를 그대로 요구합니다.

```python
def hanoi(n, start, end, via, moves):
    if n == 1:
        moves.append([start, end])
        return
    hanoi(n-1, start, via, end, moves)   # n-1개를 보조 기둥으로
    moves.append([start, end])            # 가장 큰 원판 이동
    hanoi(n-1, via, end, start, moves)   # n-1개를 목표 기둥으로
```

<br>

## 📝 이번 주 문제

가능한 선에서 최대한 풀어보세요~~

| 번호 | 난이도 | 문제 | 링크 | 관련 개념 |
|:---:|:---:|---|---|---|
| 1 | Lv.0 | 팩토리얼 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/120848) | 팩토리얼 |
| 2 | Lv.0 | 종이 자르기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/120922) | 공식 도출 |
| 3 | Lv.0 | 구슬을 나누는 경우의 수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/120840) | 조합(nCr) 공식 |
| 4 | Lv.1 | 최대공약수와 최소공배수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12940) | 유클리드 호제법 |
| 5 | Lv.1 | 약수의 합 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12928) | 약수 구하기 |
| 6 | Lv.1 | 3진법 뒤집기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/68935) | 진법 변환 |
| 7 | Lv.2 | 소수 찾기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12921) | 에라토스테네스의 체 |
| 8 | Lv.2 | 하노이의 탑 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12946) | 재귀 |
| 9 | Lv.2 | N개의 최소공배수 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/12953) | GCD/LCM을 배열 전체로 확장 적용 |
| 10 | Lv.2 | k진수에서 소수 개수 구하기 | [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/92335) | 진법 변환 + 소수 판별 결합 |

<br>

## 💡 풀이 올릴 때

문제별 폴더 안에 본인 이름으로 파일을 올려주세요. (깃허브 웹에서 업로드 추천)

```
week2-math/
├── README.md
├── problem01-팩토리얼/
│   └── 이름.py
├── problem02-종이자르기/
│   └── 이름.py
```
