### Main Memory
-------------------------------------------
1. logical address와 physical address의 차이
    - logical address : 프로세스마다 자기가 필요로하는 공간이 연속하여 있다고 생각하는 것. (가상의 주소/ 상대적 주소)
    - physical address : 시스템에서 관리하는 하드웨어 메모리 공간주소 (실제 주소)

2. swapping 이란
    - 메모리 계층에서 HDD 와 주 기억장치 간의 데이터 이동으로 HDD 공간에서 주 기억장치로 데이터를 올리는 것을 swap in, 그 반대는 swap out 이라고 한다. 다수의 프로세스를 수행 중에 데이터정보를 저장하는 주 기억장치에 있는 메모리 공간을 확보하기 위해서는 그 프로세스들을 swapping 해줘야한다.

3. 모바일 시스템의 특징과 swapping (메모리관리)
    - 모바일 시스템은 flash memory를 사용하고, 이 flash memory는 경량화, 저전력에 도움을 준다. read는 상대적으로 빠르지만 write는 상대적으로 느리고 write operation을 수행할 수 있는 한계가 존재한다. 이러한 Flash memory가 메모리 관리를 할 때 swap을 하 되 모바일에서 사용하는 app 들이 자발적으로 종료하여 메모리의 공간을 확보한다. 또 이 app들이 자발적으로 종료하더라도 application state를 저장해 놓아서 재시작시 빠르게 restart할 수 있게 한다.

4. About partition - static (fixed sized) partition (equal size와 unequal size) 과 dynamic (variable) partition
    - static partition은 하드웨어가 partition size를 미리 설정해 놓은 것이고 일관된 사이즈인 equal size, 일관되지 않은 size를 unequal size라 한다.

    - dynamic partition은 메모리 공간이 있을 때, 여러 프로세스간 각각의 경계를 설정한다. 프로세스마다 필요한 공간의 크기가 다르기 때문에 variable partition이라고도 함.

5. paging과 segmentation을 설명하시오. 각각 어느 partition 방법과 유사한지 (어느 점이 다른지) 주소변환 과정에서 사용되는 자료구조는 뭔지
    - paging은 external fragmentation 발생을 피하기위해 메모리를 fixed sized blocks로 잘게 쪼개서 page number와 page offset으로 page table을 구성하여 logical memory에서 page table을 통해 physical memory로 대칭시키는 것이다. static partition과 유사하다.

    - segmentation은 어떠한 모듈 또는 성질 별로 나누어 paging을 하는 것이다. cpu에서 logical address를 생성하고 segment descriptor를 통해 segment number와 LDT/GDT bit, 그리고 read/wrtie 상태를 표시하는 protection bits로 구성된 leaner address로 변환한다. dynamic partition과 유사하다.

6. paging과 segmentation 의 차이점 & 두 가지 개념을 동시에 이용할 수 있는 방안
    - segmentation은 paging과 달리 어떠한 모듈 또는 성질 별로 나누어 paging을 한다는 차이가 있으며 인텔 cpu는 실제로 이 두가지 개념을 동시에 이용하여 logical address를 physical address로 변환한다.

    - 인텔 cpu에선 logical address를 생성하고 segmentation unit을 통해 linear address로 변환하고 paging unit을 거쳐 physical address로 변환하여 physical memory에 할당한다. 

7. page table 을 억세스 하는 시간을 줄일 수 있는 메카니즘
    - TLB(Translation Look-Aside Buffer)를 사용하는 것이다. address translation을 할 때 page table을 먼저 찾는 것이 아니라 TLB table을 먼저 찾는다. cache를 통해 cache hit가 되면 메모리에 있는 page table을 찾을 필요없이 physical address가 있는 메모리에 바로 access하게 되어 access 시간을 줄일 수 있다.

8. 일반적인 paging 기법의 page table 크기가 너무 커지는 단점을 극복하기 위한 기법
    - Hierarchical Paging : page table을 page로 쪼개서 관리하는 것. (n level paging (n>1 int))
    - Hashed Page Tables : Hash 함수의 index를 이용하여 page table을 구성하는 것.
    - Inverted Page Table : page table에 logical address 의 정보가 담겨있다기 보다는 logical address의 process id 와 physical address의 정보를 담는 것.