### Process
-------------------------------------------

1. 쓰레드와 프로세스
    - 프로세스는 컴퓨터에서 연속적으로 실행되고 있는 컴퓨터 프로그램으로 메모리에 올라와 실행되고 있는 프로그램의 인스턴스이다. 운영체제로부터 시스템 자원을 할당받는 작업의 단위.
    -  쓰레드는 프로세스 내에서 실행되는 여러 흐름의 단위로 프로세스가 할당받은 자원을 이용하는 실행의 단위이다. 즉 프로그램을 수행하는 최소 단위이다.

2. 멀티프로세스와 비교한 멀티쓰레드의 장점
    - 프로세스 생성 보다 쓰레드를 생성하는 것이 더 빠르다.
    - 코드를 단순화 하여 효율적이다.
    - 프로세스간의 통신 (IPC) 보다 file, code, data를 공유하는 쓰레드간의 통신 속도(context switching)가 더 빠르다.
    - 응답성이 좋으며 리소스를 적게 차지한다.

3. 멀티쓰레드를 이용한 응용(또는 시스템) 소프트웨어의 예시, 왜 이 방법이 싱글 쓰레드에 비하여 성능면에서 우수한 이유
    - Window, Linux 등이 OS들
        Context Swithching시 쓰레드는 Stack 영역만 처리하기 때문에 프로세스 간의 전환 속도보다(single Thread) 쓰레드 간의 전환 속도가 더 빠르기에 싱글 쓰레드에 비해 멀타 쓰레드의 성능이 우수하다.

4. 병렬처리시 처리기(코어, 프로세서, 컴퓨터)가 N개가 있을 때, speed up이 N 배가 되지 못하는 이유
    - 프로그램을 병렬처리 해도 serial 한 components 들은 꼭 순차적으로 수행해야 하기 때문에, 병렬 처리기의 수가 선형으로 증가해도 speed up도 선형으로 증가하는 것은 아니다.

5. 병렬처리시 데이터 분할 방법과 테스크 분할방법
    - 병렬처리시 데이터는 부분부분 나눠서 각 부분을 독립적인 core가 수행한다.
    - 병렬처리시 Task는 각 core가 처리해야할 데이터는 같지만 각 core마다 해야하는 일이 다름 (ex, +, -, *, /)
    
6. Pthread API를 이용하여 간단한 멀티쓰레드 예제 프로그램을 C언어로 작성하시오.
    - 
            #include <pthread.h>
            #include <stdio.h>
            #include <stdlib.h>
            int sum; // 생성된 threads의 합계
            void* runner(void* param); // 쓰레드가 runner 함수를 불러옴
            int main(int argc, char* argv[]) {
                pthread_t tid; // 쓰레드의 id
                pthread_attr_t attr; // 쓰레드 속성값 set
                pthread_attr_init(&attr); // pthread 속성을 초기화하는 API
             
                pthread_create(&tid, &attr, runner, argv[1]); // pthread 하나 생성
                // parameter : pthread의 id, 속성, 생성된 스레드 argv[1]와 함께(runner의 parameter) runner 함수로 보냄
                pthread_join(tid,NULL); // runner 함수가 끝날때 까지 기다리는 함수
                
                printf("sum = %d\n", sum);
            }
            void* runner(void *param){
                int i, upper = atoi(param);
                sum = 0;
                for(i = 1;i <= upper; i++) sum += i;
                pthread.exit(0);
            }
