### Synchronization Examples
-------------------------------------------
1. Bounded-buffer problem (Producer-consumer)에서 사용한 세마포의 종류와 용도.
    - mutex : 버퍼를 사용하는데 독점권을 주기 위해서 사용
    - full : producer가 item을 만들 빈공간이 있는지 확인하기 위해서 사용
    - empty : comsumer가 사용할 item이 있는지 확인하기 위해서 사용

2. Reader/writer problem program에서 사용한 세마포의 종류와 용도
    - rw_mutex : 리더가 독점권을 갖게되면 다른 리더들도 계속들어 올 수 있게함, 하지만 라이터가 독점권을 갖게되면 다른 리더들은 물론 다른 라이터 또한 접근 불가하게 한다.
    - mutex : read_count access의 독점권을 얻기위한 mutex
    - 리더들끼리 race condition이 생기지 않도록 하며 리더들이 다 빠져 나갈 때 까지 read_count를 확인하여 critical section의 독점권을 놓지 않게 한다.

3. Monitor의 구성 요소
    - 프로세스 queue, critical section으로 보호되는 함수들, condition variable이 있다

4. Dining-Philosophers problem을 세마포와 모니터를 이용하여 구현 by c-language
        while(true){
            wait(chopstick[i]); // 왼쪽 젓가락
            wait(chopstick[(i + 1) % 5]); // 오른쪽 젓가락
            // 두 젓가락을 잡아야 Eating 가능
            // 여기서 왼쪽만 잡았을 때 계속 기다리게 되면 deadlock 문제가 발생할 수 있음
            /* eat for a while */
            signal (chopstick[i]);
            signal (chopstick[(i + 1) % 5]);
            /* think for a while */
        }

        monitor Dining Philosotphers
        {
            // 젓가락을 잡는데 신경쓰기보다는 철학자의 상태에 집중
            enum (THINKING; HUNGRY, EATING) state[5]; // 철학자의 상태
            condition self[5]; // 기다리는 상태인지 아닌지
            void pickup (int i){
                state[i] = HUNGRY;
                test(i); // i 번째 철학자에 대해 젓가락을 사용할 수 있는 상태인지 아닌지
                if(state[i] != EATING) self[i].wait;
                // 배고픈데 Eating 상태가 아니면 Eating하기 위해 기다림
            }
            void putdown(int i){
                state[i] = THINKING; // Eating에서 Thinking 으로 바꿈
                test((i+4) % 5); // 왼쪽 오른쪽 철학자의 상태를 test
                test((i+1) % 5);
            }
            void test(int i){
                if((state[(i + 4) % 5] != EATING) && // 왼쪽 오른쪽 eating이 아니고 i가 Hungry면 Eating 가능
                (state[i] == HUNGRY) &&
                (state[(i + 1) % 5] != EATING) ) {
                    state[i] = EATING; // i의 기다리던 상태를 없앰
                    self[i].signal();
                }
            }
            initialization_code() { // 모든 철학자의 상태를 Thingking 으로 초기화
                for(int i = 0; i < 5; i++) state[i] = THINKING;
            }
        }
        DiningPhilosophers.pickup(i); // 자원사용
         /** EAT **/
        DiningPhilosophers.putdown(i); // 자원사요우건을 내려놓음
        // monitor를 이용한 Dining Philosophers는 deadlock은 생기지 않지만  우선순위가 낮은
        // 프로세스가 계속 기다리게되는 starvation 현상이 발생할 순 있음

5. 다양한 운영체제에서 제공하는 동기화를 위한 API를 나열하고 설명하시오.
    -  window
        - interrupt masks : time over 또는 프로세스가 끝나기 전까지 interrupt를 발생하지 못하게 하여 독점권을 얻게함
        - spinlocks : 독점권을 얻기위해 지속해서 사용권을 놓지않고 wait 상태가 아닌 ready 상태에 계속 머물러 있는 것 (짧은 프로세스들을 다룰 때 유용함)
        - dispatcher objects : mutx, semaphores, events, timers 등 condition variable처럼 사용 가능한 기능
        
    - Linux
        - semaphores
        - atomic integers : variable을 atomic interger로 선언하면 증가 또는 감소할 때 critical section으로 자동으로 보호해줌
        - spinlocks
        - reader-writer versions of both