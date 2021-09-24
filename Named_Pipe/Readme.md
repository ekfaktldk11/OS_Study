# Topic
Implementing a file server using a client-server model. (By Named_Pipe)

# Implement Orders *OS : Linux (ubuntu - VMware)*
1. [~$ gcc -g code.c] 를 이용하여 code.c 가 수행파일로 만들어진 'a.out' 생성
2. 이 a.out 파일을 [~$ gdb a.out] 로 실행
3. 'run' 명령어를 입력하여 해당 수행파일을 실행
4. 'q'를 통해 해당 수행파일 gdb를 종료 가능

# Result
- Working
        named-pipe의 형성
        
        client로부터 파일명, 파일 엑세스 r/w
        
        Write할 value, byte 값 받기
        
        child-process 생성

- Not Working
        원래 있는 파일을 r(읽기) 하려할 때 이미 파일이 있다는 오류

        child process가 종료되지 않는 오류

- TakeAway

        하나의 c 파일 내에 fork()로 child process를 만들어서 서버와 클라이언트간의 통신을 수행하게 하는 파일 서버를 만들려고 하니 서버와 클라이언트를 각각 함수로 만들어야 할지, 아니면 메인을 서버라고 여겨야 하는지 아니면 클라이언트라고 여겨야 하는지 고민을 정말 많이 했다. 무엇으로 했어도 각각의 방법은 있었겠지만 어떠한 방법도 절대 쉽지 않았을 것이다. 결국엔 메인을 데이터 송신역할을 하는 client, server는 따로 server함수를 만들지 않고 child process 자체에 서버를 구현을 하려했다.

        가장 어렵고 기억에 남는 것은 부모프로세스와 자식프로세스 간의 코드 수행 순서이다. 서버에서 namepipe가 형성되기 전에 client에서 open()하려 하면 바로 file open error가 발생 했다. 이 것 외에도 서로 언제 한줄한줄 실행될지 예측하기 어려워서 usleep() 함수를 통해 먼저 우선되어야 할 코드를 우선시 하게 했다. 지금 생각해보니 파일을 읽고 쓰는 것을 critical section으로 여겨 그것을 처리하는 기능들을 이용하면 좋았을 것 같다.
