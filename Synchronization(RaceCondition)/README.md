# TakeAway (Synchronization)

- pthread 또는 fork()를 사용하여 서로 다른 프로세스에서 프로그램을 실행 시키면 언제 어떤 프로세스가 실행될지 알기 힘들기에 critical section을 가진 프로그램들은 이런 상황에서 동기화 기능이 없으면 race condition이 발생하여 오류가 생기거나, 불필요한 overhead, overwrite로 인해 프로그램이 정상 작동이 되지 않는다. 

- 이를 방지하기 위해 동기화 기능인 mutex_lock, mutex_unlock 또는 semaphore wait, semaphore post 를 통해 critical section의 주도권을 주고 놓으면서 프로그램의 오류발생을 미연에 방지할 수 있다. 이 것은 이미 현존하는 OS들에 적용되는 기술이다. 이 수준에서 속도 및 성능이 더 발전하려면 어떻게 해야할까 생각을 해보았다.

- 우리는 이미 critical section에 누가 들어갈 차례인지 알고 있다. 하지만 OS는 그것을 알 수 없고 내부 코드에 적혀있기에 race condition을 미연에 방지할 수 있는 결과론적인 것이다. 인공지능이 발전하여 OS에도 인공지능이 탑재된다면 동기화 기능으로 학습을 시킨다면 결국엔 동기화 기능 없이도 알아서 critical section에 대한 처리를 race condition 없이도 처리할 수 있으며 더 빠른 속도 및 더 좋은 성능을 낼 수 있지 않을까 하는 생각을 했다. 