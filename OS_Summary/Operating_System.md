### OS Introduction
-------------------------------------------
1. 운영체제에서 제공하는 기능
    - 운영체제는 컴퓨터시스템의 자원(CPU, Memory, Storage, Process, File, 입출력 장치 등)을 효율적으로 관리하는 동시에 사용자에게 편리한 interface를 제공한다.

2. 메모리 계층
    - 아래부터 백업용, 대용량 저장 장치 magnetic tapes, optical disk -> 보조기억 장치 hard-disk drives, nonvoiatile memory -> 주기억 장치 main memory, cache, registers 가 있다. 계층 위쪽으로 갈수록 speed와 cost가 높아지며 주 기억장치는 휘발성으로 전원이 off 되면 해당 장치에 있던 data가 소멸될 우려가 있다.

3. Interrupt Process
    - Interrupt를 통해 CPU는 I/O 디바이스가 소통을 하는데, 예를 들어 디바이스에 interrupt의 한 종류인 I/O 리퀘스트를 보내고, 디바이스는 그 interrupt를 받으면 idle 상태에서 active low 상태로 해당 interrupt를 해석하여 CPU에 interrupt를 보내면 CPU에선 해당하는 그 디바이스에 해당하는 interrupt service routine을 실행함. 
    - 이 체계가 사라지면 여러 디바이스의 일을 해야하는 CPU가 무분별하게 일을 처리하게 되면서 효율도 떨어지고 CPU 메모리 과부하가 생길 수 있다.

4. dual mode operation이 필요한 이유
    - 운영체제에는 dual-mode는 커널모드와 유저모드가 있다. 유저모드는 일반 프로그램을 처리하는 모드이며, 커널모드는 커널모드 에서만 실행가능한 privileged instructions을 통해 자원제어 역할을 한다. 이렇게 모드를 두 개로 나누어서 커널모드 에서만 실행가능한 명령어들이 있게 함으로써 운영체제가 운영체제와 다른 시스템 컴포넌트들을 보호할 수 있게 한다.

5. 컴퓨터(CPU) 능력의 한계를 극복하기 위한 방안(multicore, multiprocessor, multicomputer)
    - 하나의 CPU의 성능이 제한적이라 CPU를 여러개 사용하고(parallel systems), CPU가 긴밀한 관계가 유지되도록 메모리를 공유하는 형태인 shared memory multiprocessors 로(tightly-coupled systems)CPU능력의 한계를 극복할 수 있다. 

    - 첫 번째로, CPU를 여러개 사용하는 Multi-processor 구조, 두 번째로, 하나의 CPU에 CPU역할을 수행하는 core가 다수개이 Multi-core 구조, 세 번째로 여러 컴퓨터가 하나의 sotrage-area-network와 연결되는 Multi-computer 구조가 있다.

6. multiprogramming 과 timesharing의 차이
    - Multiprogramming은 메모리에 여러 프로그램을 동시에 로딩시키는 것이다.
    - Timesharing은 짧은 CPU시간을 쪼개서 프로그램들에게 공평하게 시간을 할당하여 처리하는 것이다.

7. 운영체제에서 사용되는 자료구조 (list, stack, queue, tree, hash table, bitmap)
    - list는 각 data들을 일방향 또는 상호 연결을 하여 처리하는 구조이다. 
    - stack은 FILO 구조로 먼저 들어갈수록 처리 순번은 낮아지며 가장 최근에 staked 된 것이 가장먼저 처리 된다. 
    - queue는 FIFO 구조로 stack구조와는 다르게 먼저 들어갈수록 가장 먼저 처리된다. 
    - tree는 하나의 노드에서 가지노드로 뻗어나가는 형식이며 어떠한 처리 규칙을 통해 트리 전체에 저장된 자료들을 처리한다. 
    - hash table은 hash function을 사용하여 key값을 받아 hash map에 array로 저장하는 형태 이다. 
    - bitmap은 bit 값이 0또는 1로 나누어서 자료를 처리한다.

8. 컴퓨팅 환경에 대해(traditional, mobile, distributed, client-server, publisher-subscriber, P2P, virtualization, cloud, real-time embedded)

    - traditional은 최사한의 기능만 있는 web terminal 저가 컴퓨터
    - mobile은 휴대가능 하며 사이버세상과 물리적위치(위치, 각속도)를 연결하는 것 
    - distributed는 HardWare적으로는 멀티 컴퓨터로 이루어 졌지만 이위에 미들웨어가 올라가서 마치 한 대의 시스템처럼 보이게 하는 것 
    - client-server는 서버에 모든 자원 및 정보가 있는 형태

    - publisher-subscriber는 기존의 publisher(sender)가 sybscriber(receiver)에게 직접 메시지를 전송하는 것이 아닌, publisher가 어떤 subscriber가 있는지 모르는 상태에서 메시지를 여러개의 클래스로 나누어 subscriber도 publisher에 대한 정보 없이 자신이 필요한 정보만을 전송 받게 되는 형태
    - P2P는 peer to peer로 서버가 따로 없이 client끼리 서로 정보를 공유하는 형태
    - virtualization는 단일한 하드웨어 시스템에서 여러 App 환경이나 다른 OS 환경을 생성함 
    - cloud는 computing 리소스가 흩어져 있고 이를 공유하며 사용하는 것 
    - real-time embedded은 특정한 용도로 사용되는 컴퓨팅으로 시간적 제약이 있는 OS