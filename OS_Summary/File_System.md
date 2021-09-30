### File_System
-------------------------------------------
1. 화일시스템 사용을 일반사용자와 프로그래머 입장에서의 설명
    - 일반사용자의 입장에서는 파일이 연속적인 공간이 있는 것처럼 느껴짐. 
    - 하지만 프로그래머 입장에서는 HDD에 block으로 흩어져 있기에 파일의 파일 테이블을 통해 HDD의 흩어진 파일들을 mapping 시켜야 함.

2. sequential access와 direct access의 차이
    - sequential access 는 말그대로 파일의 순서대로 파일을 access하는 것이다.

    -  direct access는 random access라고도 하며 파일의 특정 위치를 access하는 것이다.

3. directory로 부터 디스크 블록을 찾아가는 과정 
    - 예를 들어 가장 많이 사용되고 있는 트리 구조의 디렉토리를 사용한다면 디렉토리에서 file의 이름과 inode( file에 대한 번호)를 통해 master file directroy, user file directory를 거쳐서 디스크 partiton, 즉 HDD를 쪼갠 한 조각안의 블록안에 있는 파일을 access한다.
 
4. 파일 공유시 문제점과 이를 해결하기 위한 방안
    - 원격지에 있는 파일을 여러 프로세스가 공유를 할 때 하나의 파일에 모든 프로세스가 r/w하면 race condition이 발생할 수 가 있다. Consistency Semantics를 사용하여 여러 프로세스가 동시에 하나의 file에 w/r 할 때 서로가 w/r 하는 순서에 대해 합의를 보는 것으로, 서로 순서가 섞여 있지만 어떠한 일정한 순서로 결과값이 나오게 하여 이 race condition 문제를 해결할 수 있다.

5. Layered 파일 시스템
    - file organiztion module을 사용하여 logical한 파일의 주소를 버퍼 및 캐쉬로 physical한 주소로 mapping하여 I/O 컨트롤러를 통해 디바이스 블록에 찾아가는 시스템이다.
    - 복잡한 것을 기능 별로 나누어 단순화 시킨다는 장점이 있다.

6. 파일 open, read 할 때 파일시스템 구조
    - HDD에 있는 파일을 빨리 access할 수 있도록 Mount table(어디에 마운트 되어있는지?), system-wide open-file table(시스템이 가지고 있는 open file table에 대한 정보), per-process open-file table(System wide open-file table를 process가 pointin 해놓은 것)을 메모리 상위 계층에 해당 정보를 올려 놓는다.

7. Virtual File System
    - file type OS(unix, linux)처럼 네트워크 , IPC, 디바이스 등 모두 file 취급을 하여 access 하는 파일 시스템
 
8. 디스크 allocation 방법들 & 그 방법들의 단점을 보완하고 장점만을 살릴 수 있는 방법들
    - Contiguous Allocation : 간단하게 연속적인 공간을 할당하여 순차적으로 access할 때 성능이 좋지만 중간에 빈공간을 찾기 힘들고 이로인해 흩어져 있는 공간을 모아 사용을 해야되는 overhead가 발생함.
    - Extend-Based Systems : contiguous한 block을 여러개 가질 수 있는 것으로 A라는 block인 연속적인 공간을 확보하려 할 때 다음 블록이 B라면 그 다음 블록에 A` 에 A의 연속적인 공간을 할당받을 수 있게 하는 것 하지만 이것도 Contiguous 방법의 문제점을 시원하게 해결 불가함.

    - Linked allocation : linked list 형태로 블록을 linking 하는 것으로 compaction 이나 external fragmentation 발생은 하지 않고 순차적인 access를 할 때 는 성능이 좋다. 하지만 direct access를 할 때는 중간에 모든 link들을 거쳐야 하기에 성능이 떨어질 수 있다.
    - Indexed allocation : 위 모든 방법들의 장점을 살리고 단점을 없앤 것으로 index block을 통해 1 ~ n 번째 data에 대한 index를 가지고 있어 흩어져 있는 공간을 사용하기에 좋고 순차적 access, random access 모든 경우에 성능이 괜찮음.

9. 디스크 free-space 관리방법
    - 여러 방법이 있지만 대표적으로 bit vector 또는 bit map을 통해 bit값이 1이면 비어있고 0이면 사용중인 상태를 나타낸다. 
    - Block number calculation을 사용하여 비어있는 블락을 찾아 낼 수 있으며, 메모리 블락을 관리 할 때 1개씩 관리하지 않고 n개 씩 묶어서 메모리를 관리하여 메모리 소모를 낮춘다.

10. 파일시스템 성능 향상방안 & 복구(recovery)방안
    - CPU & I/O의 속도 차이 및 data acces하는 크기 차이를 중간에서 완충 작용해주는 버퍼나 캐쉬를 두어 비교적 빠른 CPU가 느린 I/O를 기다리 지 않도록 하여 성능을 향상 시키고, 또 혹시 사용하다가 전원이 꺼지면 buffer가 사라지기 전에 버퍼의 내용물을 HDD에 저장하여 복구 기능을 갖게 한다.

11. NFS을 마치 로컬 파일시스템처럼 이용할 수 있는 이유
    - Client & Server 모드를 이용하여 실제 client내에 있는 NFS Client가 RPC/XDR, socket, tcp/ip를 통해 네트워크와 통신하여 서버에 있는 NFS Server를 이용하여 서버 디스크파일을 가져올 수 있기 때문에 NFS를 마치 로컬 파일 시스템처럼 이용가능하다.

12. 프로세스, 파일시스템, 메모리관리시스템의 유사점과 차이점을 다양한 측면에서 비교
    - 시간-공간 스케쥴링 : 비교적 빠른 CPU가 느린 I/O를 기다리지 않도록 설계 한다는 공통점

    - 메모리계층구조 : 버퍼 및 캐시 사용 한다는 공통점

    - 자료구조 : 유저가 눈으로 보기에는 연속적으로 존재하지만 실제로는 메모리에 흩어져있고 이 것을 logical address to physical address로 매핑하여 이용한다는 공통점
    
    - 동기화 문제 : race condition이 발생하지 않도록 동기화 기능을 사용한다는 공통점이 있다. 하지만 파일 시스템에선 Unix 는 한 사용자가 write 했을 때 다른 사용자도 즉시 볼 수 있도록 하는 기능이 있다는 차이가 있다.