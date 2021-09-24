# Producer/Consumer Program
--------------------------------------------------

# Implement Orders *OS : Linux (ubuntu - VMware)*
 -  [~$ gcc -o 1 code.c -lpthread] 를 이용하여 code.c 가 수행파일로 만들어진 '1' 생성
 -  이 '1' 파일을 './1' 로 실행

# C files info
 - pro_con.c : 동기화 기능이 있는 생산자/소비자 문제
 - pro_con2.c : 동기화 기능이 없는 생산자/소비자 문제

# Result
- Without Synchronization

     동기화 기능이 없는 프로그램은 race condition이 발생하기에 그것을 확인하기 위한 count를 설정해 주었다. 예를 들어, producer의 counter는 9 또는 10 인데, consumer의 counter는 10으로 증가 또는 그대로인 상태를 확인 가능하다.

     또 다른 문제인 buffer의 size를 100으로 설정했는데 count가 이 buffer 사이즈를 초과할 만큼 producer가 일방적인 생산을 하는 것도 확인 가능하다.

- With Synchronization

     동기화 기능으로 mutex lock을 사용했다. producer는 buffer[100] 안에 item을 생산하고 consumer는 buffer에 생성된 item을 사용한다. buffer 안이 꽉차면 producer의 생산을 잠그고 consumer가 하나 이상의 item을 사용하게 되면 다시 producer가 item을 생산할 수 있다. consumer 또한 빈 공간의 buffer에서 item을 사용할 수 없다.
