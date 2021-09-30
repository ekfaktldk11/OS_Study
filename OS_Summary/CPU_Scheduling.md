### CPU Scheduling
-------------------------------------------
1. CPU 스케줄링 & Dispatching
    - CPU 스케줄링은 여러 프로세스를 CPU에 어떤 프로세스에 우선순위를 주어 순서를 정하고 또 각 프로세스에게 얼마만큼의 시간을 주어 CPU를 필요로하는 프로세스들에게 CPU 사용을 넘기는 것이다.

    - Dispatching은 현재 프로세스를 CPU에서 제거하고 다른 프로세스를 전환하는 것이다.

    - interrupt가 발생하면 우선순위가 높은 프로세스에 의해 프로세스 스케쥴링을 하는데 시간이 걸리는데 이 시간을 dispatch laterncy라고 한다.

2. CPU 스케줄링 알고리즘의 평가 기준 (어떠한 환경에서 또는 어떠한 측면에서 중요한지)
    - process 가 스케쥴된 시간 내에 즉, deadline 전에 일을 마치면 성능이 높다고 평가하는데 Soft real-time system 과 Hard real-time systems가 있다.

    - Soft real-time system은 real-time task라 높은 우선순위를 가지지만 언제 scheduled 되는지 보장은 없는 것들이다. 영상, 노래 미디어 등 deadline 이 약간 지난거에 대해 성능은 급격히 떨어지지만 그래도 쓸만한 환경에 적합하다.

    - Hard real-time system은 deadline 전에 꼭 끝내야 되는 것들이다. 의료장비, 항공운용장비 등 deadline을 맞추지 못하면 성능이 – 값으로 곤두박질 치는 엄격한 조건에 적합하다.

3. FCFS, SJF, RR의 장단점

    - FCFS(~>fifo) : 구현이 간단함 / 긴일이 먼저 수행되면 짧은 일이 너무 오래기다림

    - SJF(shortesst job first) : 평균 waiting time을 최소화함 / ready queue 에 있는 프로세스들 중 어떤 것이 burst 시간이 짧은지 긴지 알기 어려움

    - RR(round robin - time slice를 사용한 ~) : 프로세스들이 균등하게 처리되어 긴일이 먼저 수행되어도 짧은 일이 오래 기다릴 일이 없음 / time quantum(q) 값이 너무 길면 FIFO 와 다를게 없고 너무 짧으면 context switch가 너무 많음

4. FCFS, SJF, RR의 장단점을 상호 보완하기 위한 스케쥴링 방안들
    - Multilevel Feedback Queue처럼 RR, SJF, FCFS 의 장점을 섞어서 각 알고리즘의 단점을 보완한다.

    - Dynamic programming을 적용하여 time complexity를 낮춘 CPU burst 시간을 예측하는 알고리즘을 적용한 SJF 알고리즘을 이용한다.

5. 실시간 스케쥴의 특징과 해당 알고리즘들
    - Deadline 전에 일을 마치면 성능이 높다고 평가한다. 더 빨리 응답한다고 더 좋은 성능을 가지는 것이 아니고 시간안에만 응답을 하면 좋은 성능이라 한다.
    - 우선순위가 있고 우선순위를 가진 프로세스가 먼저 처리되며 일정한 주기를 두고 프로세스를 처리한다.

    - Rate Montonic Scheduling 은 주기가 짧은 프로세스에게 우선권을 주며 P_1과 P_2의 주기를 합친 시간이 P_2 의 Deadline 값보다 크면 Deadline을 넘길 위험이 있다.
    - Earliest Deadline First Scheduling 은 deadline에 임박한 것을 먼저 수행한다.
    - Propotional Share Scheduling은 모든 프로세스드에게 T개의 시간 지분을 할당하여 동작한다. 한 개의 프로세스가 N개의 시간 지분을 할당 받으면 그 프로세스는 모든 프로세스 시간 중 N/T 시간을 할당 받는다.

6. multi-core/CPU/computer scheduling의 주요 고려점
    - 결국 성능은 총 스레드의 수에 따라 결정되는데, core, cpu, computer 각각의 수를 얼마만큼 설정하여 최소한의 cost로 높은 성능을 낼 수 있는 지가 주요 고려점이다.

7. 상용 운영체제에서 사용되는 스케쥴링의 주요 공통점
    - Real-time 프로세스가 normal 프로세스 보다 처리 우선권을 갖는다는 것이다.