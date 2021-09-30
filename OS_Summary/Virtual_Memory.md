### Virtual Memory
-------------------------------------------
1. Virtual 메모리 사용의 장점
    - 프로세스마다 data 공유가 쉬워짐
    - 프로세스 생성이 쉬움, 많은 프로그램이 동시에 로딩이 가능하다.
    - Swapping이 자주 일어나지 않기에 I/O operation이 많지 않음

2. page fault를 처리하는 과정
    - page fault 발생 -> 주기억장치에 free frame이 있는지 확인하고 -> free frame이 남아있으면 free frame에 해당 페이지를 올리고 사용, but free frame이 충분하지 않으면 page replacement 알고리즘에 의해 replacement를 통해 해당 페이지를 올리고 사용

3. Copy-on-Write
    - copy를 다하고 수행하려하면 속도가 너무 느리기에 일단 처음에 서로 다른 프로세스끼리 공유를 하여 copy의 효과를 얻고 프로그램이 진행되면서 write가 일어나면 그때서 copy를 수행한다. copy시간을 줄일 수 있음

4. page replacement 알고리즘 (FIFO, Optimal, LRU, LRU-approx., LFU)
    - FIFO – 구현 쉬움/ page fault 多
    - Optimal – 구현 중간/ page fault 少
    - LRU – 구현 중간/ page fault 中 / overhead 多
    - LRU-approx – 구현 어려움 / page fault 少
    - LFU – 구현 어려움 / page fault 少

5. 프로세스 page frame
    - 시간이 지남에 따라 process에서 사용하는 page 부분이 달라 working-set이 계속 달라진다. 하지만 프로그램의 locality 특성이 있기 때문에 Working-set이 달라지는 주기가 생기고 항상 그 초반에는 처음 reference되기 때문에 page fault가 발생한다.

6. 일반적으로 적당한 page 크기 & 커널의 경우 적당한 page 크기
    - 커널의 경우는 buddy system 또는 slab 과도 같은 연속적인 커다란 페이지로 관리 하며 Fragmentation, page table size, resolution 등 여러 고려사항을 봤을 때 2^n(n = positive integer)크기의 page size를 사용하는 것이 좋다.

    - 일반적으로 2^12가 general size이며 동적으로 slab allocator를 통해 커널 사이즈를 조절하는 것이 좋다. 프로그램의 page size는 프로그램의 크기에 따라 동적으로 사이즈를 결정하는 것이 좋다.

7. Demand paging & prepaging 비교
    - Demand paging은 paging이 필요할 때 paging을 해주는 것이라 자원 활용도는 높지만 page fault가 많이 발생한다.

    - prepaging은 미리 필요할것이 예상되는 page를 미리 메모리에 올려두는 것으로 page fault수 자체는 적지만 예측을 잘못하면 메모리 낭비가 심해진다.