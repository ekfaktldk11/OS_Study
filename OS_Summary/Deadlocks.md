### Deadlocks
-------------------------------------------
1. deadlock이 발생하는 4가지 조건
    - Mutual exclusion 
    - Hold and Wait
    - No preemption
    - Circular Wait

2. deadlock을 prevention 하기 위한 방법
    - 위의 deadlock이 발생하는 4가지 조건 중 하나만 해결해도 deadlock이 발생하지 않는다. (race condition을 발생시킬 우려가 있는 Mutual exclusion은 제외)

    - Hold and wait -> 프로그램이 시작될 때 모든자원을 한꺼번에 allocation하고 프로그램이 종료가될 때 모든자원을 한꺼번에 release 시킴

    - No preemption -> preemption enable

    - Circular wait -> 자원을 사용하는것에 대해 일정한 순서를 정해서 그 순서에 맞게 프로세스가 자원을 사용하도록 함

3. Safety 알고리즘 & Banker’s 알고리즘
    - 두 알고리즘 모두 deadlock을 avoid 하기 위한 알고리즘으로 모든 프로세스가 deadlock 없이 잘 끝날 수 있는지 check하고 safe state라면 프로세스에게 자원을 할당함

    - Safety Algorithm : 
        - OS 가 가지고 있는 비어있는 자원을 ‘work’ 로 copy함 
        - i번째 프로세스가 아직 끝나지 않앗는데 이 프로세스가 앞으로 요구하는 것이 OS가 가지고 있는 것보다 작거나 같으면 그 프로세스에게 리소스를 할당해 줄 수 있음
        - 각 프로세스의 need(i)가 work(i)(각각의 벡터값) 보다 작거나 같으면 자원을 할당할 수 있음
        - 프로세스 i 에게 자원을 할당해주고 그 프로세스가 끝나면 그 프로세스에 할당 되어있던 자원을 work에 더해줌
        위 과정을 반복하면서 모든 프로세스가 끝날 수 있으면 safe state로 판별

    - Banker’s Algorithm
        - 실제로 위와 같은 Safety Algorithm을 실제 예시에 적용해보면서 모든 프로세스가 safe state 로 끝날 수 있는 프로세스들의 sequence가 존재하면 OS에서 프로세스에게 그 sequence에 맞게 자원을 할당해줌.

4. deadlock detection 알고리즘 & recovery 방법
    - 단일 프로세스에 대해서는 wait-for graph로 간단히 구분하지만 multi process에 대해서는 Safety Algorithm & Banker’s Algorithm을 사용하여 deadlock 판별을 하다가 deadlock에 기여하는 프로세스가 발생하면 프로세스를 abort 또는 rollback을 통해 프로세스를 중단 및 종료 시켜서 recovery함.

5. deadlock을 해결하는 방법 (1) prevention, (2) avoidance, (3) detection & recovery, (4) 무시 등 네 가지를 어느 환경에서, 어느 방법이, 왜 적절한지 ?
    - (1) prevention & (2) avoidance 는 자원낭비가 너무 심하기에 적절하지 못하지만 데드락이 발생하면 절대 안되는 상황에선 자원낭비가 심하더라도 데드락을 예측하는 과정이 필요하기에 이 상황에선 적절하다.

    - (3) detection & recovery 는 time complexity level이 높기에 수많은 operation덕에 효율적이지 못하지만 적은 수의 프로세스 및 자원 / 단일 프로세스에 대해선 짧은 시간내에 해결할 수 있기에 이럴 때 적절하게 사용할 수 있다.

    - (4) 무시는 프로그램의 deadlock이 일어나면 간단하게 작업관리자로 그 프로세스를 종료 시켜버리는 경우 적절하다.