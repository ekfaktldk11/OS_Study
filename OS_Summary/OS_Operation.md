### OS Operation
-------------------------------------------
1. 명령어(예, 화일 copy)가 수행되는 과정

        (1) 명령어 사용자는 명령어 프로그램에 A라는 파일을 B라는 파일로 copy하는 명령어를 침.
        (2) 명령어 프로그램은 ‘copy()’로 시스템 콜 인터페이스에 trap을 검
        (3) OS mode는 user mode에서 kernel mode로 바뀌고 ‘copy()’ 가 있는 주소를 찾아 system call을 수행
        (4) system은 A파일을 한줄 씩 읽으며 B파일로 복사하고 종료되면 리턴함
        (5) 명령어 사용자는 명령어 프로그램에서 완료됐다는 것을 보고 마무리

2. system call 이 처리되는 과정
    - user application에서 요청(trap)을 하면 system call을 보내 OS kernel mode 에 접근하게 되어 해당 system call 의 index를 확인하여 주소의 index번째 있는 system call을 수행하게 되고 결과를 리턴하고 종료된다.

3. Linker 와 Loader를 포함하여 원천코드로부터 프로그램이 수행되는 과정
    - 소스 프로그램을 컴파일러로 실행하면 소스파일이 object 파일로 변경되며 이 파일은 다른 libraries에 있는 obj 파일과 함께 링커를 통해 executable file로 합쳐지고 이것은 로더를 통해 프로그램이 수행되는데, 이때 DLL(dynamically linked libraries)로 인해 프로그램에서 모듈이나 함수가 콜될 때 program에 해당 함수를 실행시키도록 도와준다.
4. Layered 구조와 micro kernel 구조의 장단점
    - layered 구조는 각 기능별로 OS를 나누어서 쉽게 수정가능하고 유연성이 높다. 하지만 단점으로는 하나의 layer가 망가지면 망가진 layer를 기점으로 위아래 소통이 불가능해짐.

    - micro kernel 구조는 기본적인 기능만 kernel에 두어 kernel을 최소화 하고 나머지는 user mode로 작동되어 확장에 용이하다. 또한 기능 별로 서버가 나누어 져있어 유연성이 높아진다. 하지만 단점으로는 각 서버(driver) 끼리 소통단계가 생기기에 속도(성능)이 낮아진다.

5. module
    - module은 각 core component가 분리되어 있고 각각의 components는 인터페이스를 통해 소통한다.

    - 모듈을 쉽게 떼고 붙였다 할 수 있어서 유연성이 높다.
    
    - 현대의 많은 OS는 LKMS(loadable kernel modules)로 설계되며 Linux, Solaris 등에 사용된다.

6. VM(Virtual Machine)이 유용한 이유
    - VM은 가상 머신으로 컴퓨팅 환경을 소프트웨어로 구현하여 VM위에서 OS나 system software를 실행할 수 있게 해준다.
    
    - 예를들어 Java Virtual Machine을 서로다른 OS, OS-1과 OS-2가 있을 때, OS-1 위에서 JavaVM을 Java로 코딩한 것을 OS-2 위에서도 돌아가게 할 수 있다.

7. 모바일 운영체제인 iOS와 Android의 특징
    - iOS는 애플사 모바일에 사용되는 OS로 iPhone, iPad 가 대표적이다. 앱개발할 때, Objective-C API를 사용하는 Cocoa Touch layer가 있고, graphics, audio, video 기능을 하는 Media services layer가 있으며, 클라우드 컴퓨팅과 데이터베이스를 제공하는 Core services layer, 그리고 Mac OS X 커널 기반 Core OS가 있다.

    - 대부분이 구글에서 개발되었으며 iOS와 양대산맥을 이루는 대표 모바일 OS 이다. 리눅스 커널을 좀 수정한 것을 기반으로 한다. 프로세스, 메모리, 디바이스 드라이버 관리에 전력관리 기능을 추가 하였다.