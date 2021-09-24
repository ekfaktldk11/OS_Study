# Topic : Reader/Writer Program

# Implement Orders *OS : Linux (ubuntu - VMware)*
 -  [~$ gcc -o 1 code.c -lpthread] 를 이용하여 code.c 가 수행파일로 만들어진 '1' 생성
 -  이 '1' 파일을 './1' 로 실행

# C files info
 - rw.c : 동기화 기능이 있는 reader/writer 문제
 - rw1.c : 동기화 기능이 없는 reader/writer 문제

# Result
- Without Synchronization

        reader와 write가 critical section에 함께 있는 race condition이 발생한다.

- With Synchronization

        writer 끼리의 주도권은 semaphore / reader & writer 사이의 동기화 기능으로는 mutex lock을 사용했다.

        read 는 한 reader가 사용중에 다른 reader가 critical section에 들어올 수 있지만, write 할 시에는 writer끼리 critical section을 중복사용 할 수 없으며, read할 때 마찬가지로 writer 또한 critical section에 들어갈 수 없도록 하여 race condition이 발생하지 않는다.
        