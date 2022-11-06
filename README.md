
# PS_CounterEx_Generator

> Problem-solving 반례 생성기 

### BOJ, Programmers와 같은 코딩테스트 문제를 풀 때 반례를 찾아주는 프로그램
--- 

## 개요

### PS 도중에 맞왜틀 하다가 ~~빡쳐서~~ 만든 프로그램입니다.

### C++로 제작했고, 현재는 C++코드만 테스트 가능합니다.

반례를 찾는 데 성공하게 되면 프로그램을 종료하고, Log.txt와 Command에 아래와 같이 출력합니다.

```cpp
PS_CounterexampleGenerator_logfile
                        by DevMarks
------------------------------
boj - 22251
[2022.4.1/2:44:9]	1sec

[input]
205 4 37 108

[answer]
204

[wrong]
2040
------------------------------
boj - 22251
[2022.4.1/3:0:47]	0sec

[input]
108075 6 31 46875

[answer]
108074

[wrong]
999880
```

---

## 설명

### 몇 분 만에 뚝딱 찾아주지 않습니다.
- 입력값을 두 파일에 넣고, 출력값을 얻는 과정에서 최소 0.03초 소모 (1초에 약 30개, 1ms 걸리는 실행파일 기준)
- 웬만한 문제들은 입력 가능한 경우의 수가 엄청 많기 때문에, 랜덤으로 최대한 여러 부분을 훑어봅니다.
- 이 프로그램을 사용하기에 앞서, 최소한 **경계값 분석 테스트** 부터 해보시는 것을 추천드립니다.
    - 경계값 분석
        - 입력값 n의 범위가 (0 <= n < 100)인 경우, 0 또는 99 대입
    - 경계값 분석도 가능하게 개선 할 예정

### 문제마다 입력 개수, 범위, 형식에 따른 사용자의 설정이 필요합니다.
- 사용자의 C++ 코딩 능력 요구
- 사용자의 약간의 알고리즘 지식 요구

### 편의성을 위해 자주 쓰이는 입력 형식들은 구현 중입니다.
- 현재는 난수와 영문자(길이, 대소문자 구분, 중복확인) 반환 가능. (ex. boj - 22251, 20006)
- 2022.04.04기준 
- 앞으로 더 개선 할 예정

---

## 사용법

1. 옳은 코드를 code/correct.cpp 에 복붙
2. 반례 찾을 코드를 code/incorrect.cpp 에 복붙
3. SetInput함수에서 문제 번호와 입력 범위를 설정
4. 문제 입력 형식과 똑같이 맞춰서 문자열로 반환
5. 실행

---

## 개선 중

1. 사용자가 건들어야 하는 파일만 따로 분리 (편의성)
2. 멀티스레드 활용 방안 (최적화)
3. 시간 제일 오래걸리는 구간, cpp exe 실행 속도 향상 방법 있는지
4. 순차, 역순으로 반례를 찾는 로직 
5. 경계값 분석을 제일 처음에 시도하도록 만들기
6. 가끔 os, 기기마다 랜덤시드가 변하지 않아서 다시 실행해도 똑같은 난수를 출력하는 문제
7. incorrect.cpp에서 TLE, MLE(Time, Memory Limit Exceeded)나는 경우 
    - 시간,메모리 제한 입력 받기
    - 명령어를 통해 output 파일을 만드는 과정에서 제한이 넘어가는 걸 체크 가능한지 확인
8. 입력 형식을 맞추기 위해 C++로 코드를 짜야 하는 건 어쩔 수 없으나, 다른 언어로 짜여진 코드의 테스트 기능 추가
9. 정수와 실수의 구분
10. 실수의 자릿수 제한

---

## 업데이트 내용

### PSCG (PS_CounterEx_Generator)

v1.0.0 (2022.04.01) - PSCG 제작, 난수 반환 기능

v1.1.0 (2022.04.04) - 영문자(길이, 대소문자 구분, 중복확인) 반환 기능 추가

v1.1.1 (2022.11.05) - 난수 중복확인 기능 추가
