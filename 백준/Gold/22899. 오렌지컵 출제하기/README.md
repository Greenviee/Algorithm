# [Gold II] 오렌지컵 출제하기 - 22899 

[문제 링크](https://www.acmicpc.net/problem/22899) 

### 성능 요약

메모리: 3196 KB, 시간: 0 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐, 정렬

### 문제 설명

<p>당신은 지금 오렌지컵의 첫 번째 문제를 보고 있다. 이 대회의 이름인 "오렌지컵"은 출제진 모두와 검수진 대다수의 코드포스 닉네임 색이 오렌지인 데에서 비롯되었다.</p>

<p>오렌지컵 출제진 $N$명은 총 $N$개의 문제를 만들었고, 이 중 $K$개를 골라 출제하려고 한다. $N$개의 문제에는 차례대로 $1$부터 $N$까지의 번호가 붙어 있다. 오렌지컵 출제진들은 한 명의 출제자가 너무 많은 문제를 낼 경우 대회 준비의 부담이 커지기 때문에, 한 출제자는 최대 $L$개의 문제만 내기로 약속했다. 하지만, 한 문제도 내지 않는 출제자가 생기는 경우는 문제 없이 넘어가기로 했다.</p>

<p>오렌지컵의 출제자 $N$명에게는 차례대로 $1$부터 $N$까지의 번호가 붙어 있다. $i$번 문제의 출제자는 $a_i$번 출제자이고, 이 문제를 출제하기로 결정했을 경우 문제를 준비하는 데 걸리는 시간은 $b_i$이다. 출제진들은 일을 하기 귀찮기 때문에, 출제할 모든 문제의 준비 시간 $b_i$의 합을 최소로 하고자 한다.</p>

<p>$L$이 $1$부터 $N$ 사이의 모든 자연수일 때, 출제한 문제들의 준비 시간 $b_i$의 합의 최솟값을 각각 구하여라.</p>

### 입력 

 <p>첫 번째 줄에는 문제 아이디어의 수 $N$과 출제할 문제의 수 $K$가 주어진다.</p>

<p>두 번째 줄에는 각 문제의 출제자의 번호 $a_1, a_2, \cdots, a_N$이 주어진다.</p>

<p>세 번째 줄에는 각 문제의 준비 시간 $b_1, b_2, \cdots, b_N$이 주어진다.</p>

### 출력 

 <p>$L$이 $1$부터 $N$까지의 정수일 때 문제의 답을 띄어쓰기로 구분하여 출력한다. 단, 조건을 만족하도록 문제 출제가 불가능한 경우 -1을 출력한다.</p>

