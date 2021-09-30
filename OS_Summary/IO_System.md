### I/O System
-------------------------------------------
1. I/O controller와 host(CPU)가 인터렉션하는 프로토콜 세가지(polling, interrupt, DMA)
    - polling : CPU(host)가 device(I/O controller)로 read/write 할 때 발생하는 것으로, busy bit를 사용하여 해당 dev가 일하고 있는지 아닌지를 체크한다.

    - interrupt : dev가 일을 마치면 host에게 보내는 event

    - DMA : CPU가 할 일이 많은데 큰 large size 데이터를 programmed I/O로 한 byte 씩 중계를 하면 시간이 너무 오래걸리기에 이를 해결하기 위한 I/O와 메모리사이의 data 이동을 CPU중재 없이 I/O & 메모리끼리 직접 access하여 CPU loading time을 줄여주는 것이다.
 
2. Kernel I/O 계층 구조 (Kernel, Kernel I/O subsystem, Device Driver, Device Controller, Device)에서 각각의 계층에서 처리하는 기능들
    - Kernel : file access (I/O request)
    - Kernel I/O subsystem : buffering, cache 또는 scheduling 함
    - Device Driver : Device의 status가 Charcater-stream 인지 block 인지, sequential 한지 random access인지 등등 다양성을 처리해줌
    - Device Controller : Device마다 존재하는 Device controller로 Device Driver 코드를 인식
    - Device : 리소스 저장

3. I/O systems device의 다양한 종류 구분
    - Charcater-stream 인지 block 인지
    - sequential 한지 random access인지
    - Synchronous or Asynchronous
    - Sharable or dedicated
    - Speed of operation
    - read-write, read only, or write only

4. Blocking, Nonblocking, Asynchronous I/O 비교
    - Blocking : 원하는 read가 끝날 때 까지 return을 못하게 함

    - Nonblokcin : read하면 바로 return 되는 것으로 read 할 것이 있으면 read하고 return , read할 것이 없으면 read를 못한 상태로 return

    - Asynchronous : read할 때 바로 return이 되지만 나중에 read data가 오면 signal을 보내서 asynchronous하게 read가능

5. I/O 성능 향상을 위한 기법들을 설명하시오.
    - Context switch 수를 줄임
    - data copy를 줄임
    - interrupt를 줄임
    - DMA 사용
    - Use smarter H/W
    - CPU/MEMORY/BUS/I.O 들의 성능의 균형을 맞춤

6. 사용자로 부터의 I/O 요청이 처리되는 과정(life cycle)

        (1) I/O req created
        (2) buffer cache에 해당 내용이 있는지 확인하고 있으면 바로 return 없으면 다음단계 진행
        (3) 자기가 읽고자 하는 data가 어딨는지 확인 후 device driver에 send
        (4) disk의 어떤 부분을 읽을지 설정
        (5) dev controller를 통해 일이다 끝나면 interrupt
        (6) buffer에 해당 내용 가져다 놓음
        (7) return

7. 새로운 알고리즘을 구현할 때 응용 소프트웨어, 커널, 디바이스 드라이버, 디바이스 콘트롤러, 디바이스에 구현하는 방법들이 있는데 어떠한 장단점이 있는지
    - application code – kernel code – device level code 순으로 오른쪽으로 갈수록 처리속도가 느려지고 비용이 증가하며 유연성이 떨어지지만 효율성이 증가하고 추상화가 증가한다.
    
    - 왼쪽으로 갈수록 처리속도가 빨라지고 비용이 적게들며 유연성이 증가하지만 추상화가 감소하고 효율성이 떨어진다.