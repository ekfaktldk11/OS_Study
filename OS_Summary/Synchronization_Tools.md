### Synchronization Tools
-------------------------------------------
1. Race condition이란
    - 두 개 이상의 프로세스가 같이 진행될 때 프로세스 충돌로 인해 프로세스 오작동이 일어 나는 것.
    - 예를 들어 producer / consumer 에 있어서 프로듀서는 레지스터를 생산하고 컨슈머가 그것을 사용할 때 프로듀서가 레지스터를 늘려서 레지스터 카운터를 하나 늘렸는데 동시에 컨슈머도 레지스터를 사용하여 레지스터 카운터를 하나 줄였을 때 레지스터 카운터의 수가 맞지 않는 상황이 race conditiion의 하나이다.

2. critical-section problem을 해결하기 위한 세 가지 요구조건
    - Mutual Exclusion : 서로 다른 프로세스를 상호 배제하여 한 프로세스에게 critical section에 대하여 독점권을 주는 것
    - Progress : critical section에 수행중인 프로세스가 없으면 그 어떤 것도 프로세스가 들어가려는 것을 막아서는 안된다는 것
    - Bounded Waiting : critical section을 수행하기 위하여 한 프로세스가 critical section에 있을 수 있는 일정 시간을 두어 다른 프로세스가 기다리는 시간이 무한정 늘어나서는 안된다는 것

3. peterson’s solution 이란
    - 서로 다른 두 개의 프로세스가 critical section을 사용함에 있어서 critical section을 사용할 의지를 ‘flag[i or j]’, 차례를 ‘turn’ 으로 두어서 critical section 사용에 critical-section problem을 일으키지 않도록하는 s/w 레벨의 방법

4. Atomic instruction (test_and_set, compare_and_swap)을 이용한 mutual exclusion 구현 방법
    - test_and_set(&lock) / compare_and_swap(&lock, 0, 1)을 이용하여 이 함수들의 리턴 value가 ‘0’이면 critical section이 비어있고 ‘1’이면 critical section에 한 프로세스가 수행중임을 나타내어 서로다른 프로세스에게 비어있다, 들어와도 된다는 것을 해주어 상호배제함.

5. counting semaphore 의 2가지 용도 
    - busy waiting : 비교적 짧게 끝나는 프로세스들에 대하여 한 프로세스가 critical section에 들어가려할 때 계속 그것을 기다리면서 CPU를 자발적으로 놓지 않는 것
    - no busy waiting : 비교적 길게 끝나는 process들에 대하여 한 프포세스가 critical section에 들어가려할 때 block() 으로 인해 list에 들어가 CPU 상태가 wait 상태로 되고 critical section에 있었다 프로세스가 끝나면 wakeup()을 통해 기다리던 프로세스를 깨워주는 것

6. monitor란
    - semaphore operations의 잘못된 사용으로 인해 생기는 문제들을 해결해줄 OS level 이 아닌 middle ware에서 제공해주는 기능인 monitor를 사용하면 모니터안에 있는 한번에 하나의 함수만 active하게 하는 것이 보장되고 critical section으로 보호해줘야하는 함수들을 monitor 에 집어 넣으면 컴파일러가 알아서 critical section으로 보호해줄 수 있다.