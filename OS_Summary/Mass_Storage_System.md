### Mass Storage System
-------------------------------------------
1. Disk storage를 여러 시스템이 공유하는 방법
    - 여러 client들이 network를 통해 공유하는 형태인 Network-Attached Storage(NAS), cloud가 storage를 제공하는 Cloud Storage, Client가 바로 access하는게 아닌 server 또는 data-processing center를 통해 storage를 access하는 Storage Area Network(SAN) 이 있다.

2. NVM의 특징 & 콘트롤러 알고리즘
    - NVM 은 비휘발성 메모리로, SSD가 이에 속하며, 일반적인 메모리는 read write 에 대해 속도가 같은데, NVM 은 write가 상대적으로 느리다. 또 overwrite시 기존에 있던 내용을 지우고 write 해야한다.

    - NAND Flash Controller Algorithms를 사용하며 새로운 블록(overprovisioning)을 garbage collection할 때 사용하여 dirty block을 clean 하고 다시 있던 내용을 가져온다.

3. 디스크(HDD) 스케쥴링의 특징과 디스크 스케쥴링을 다양한 알고리즘과 비교
    - seek time을 최소화 하는게 주목적이다.

    - 먼저 요청한 것을 먼저 처리하는 FCFS, 맨 처음부터 맨 끝까지 scan해 나가면서 게중에 위치한 내용들을 처리하는 SCAN, SCAN의 단 방향 처리를 C-SCAN 이라한다. FCFS는 movement가 너무 발생하여 효율이 떨어진다. 이를 위해 사용하는게 SCAN인데 SCAN에서도 queue에 대한 starving이 심해져서 개선한 것이 C-SCAN 이다.

4. RAID의 목적과 구조들(levels)
    - Raid 구조를 통해 빠른 속도, 데이터 안정성, 신뢰성, 을 확보한다.
    - Raid 0 :  striping을 통해 속도를 높이지만 데이터 안정성이 낮다
    - Raid 1 : mirroring을 통해 데이터 안정성을 높인다
    - Raid 4 :일부 error detection. but 한 parity bit에 대한 병목현상이 우려된다.
    - Raid 5 : parity bit를 분산해서 가지고 있기에 parity bit에 대한 병목현상 우려가 낮다.
    - Raid 6 : Q 라는 error를 복구하는 bit를 집어 넣는 것

5. Disk storage는 운영체제에서 파일을 저장하는 목적 이외에 어떠한 용도로 사용되고 있는지
    - storage에 있는 파일의 한순간의 상태를 말하는 snapshot을 통해 파일의 상태를 볼 수 있다.