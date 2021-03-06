# Queue
> Q. 큐에 대해서 정의하시오.
> > A. 큐란 선형 자료구조 중 하나로, 먼저 입력된 데이터가 먼저 출력되는 First In First Out 구조의 자료구조입니다. 

## Linear Queue
https://github.com/inourbubble2/c-data-structure/blob/main/02-Queue/1-LinearQueue.c
> Q. 선형큐의 삽입/삭제 연산과 Full/Empty 검증 연산에 대해서 설명하시오
> > A. 삽입 연산(Enqueue)을 할 때는 큐의 rear을 먼저 증가시킨 뒤 그 자리에 데이터를 넣고, 삭제 연산(Dequeue)을 할 때는 큐의 front를 먼저 증가시킨 뒤 그 자리의 데이터를 반환합니다. 큐가 꽉 찼는지 검사하는 방법은, 큐의 rear가 최대 큐 사이즈에서 1을 뺀 수와 같은지를 반환하면 됩니다. 큐가 비었는지 검사하려면 큐의 rear와 front가 같은지를 반환하면 됩니다.

## Circular Queue
https://github.com/inourbubble2/c-data-structure/blob/main/02-Queue/2-CircularQueue.c
> Q. 원형 큐가 필요한 이유를 설명하시오.
> > A. 선형 큐는 큐가 꽉 차지 않았음에도 큐에 데이터를 삽입할 수 없는 현상이 발생할 수 있습니다. 왜냐하면 큐에 데이터를 삽입하면서 rear가 maxQueueSize에 도달했는데 dequeue한 적이 있어서 큐 배열의 뒷부분에만 데이터가 있을 때도 큐가 꽉 찼다고 인식하기 때문입니다. 원형 큐는 그러한 현상을 방지하기 위해서 필요한 자료구조입니다. 

> Q. 원형 큐의공백검출/포화검출/삽입/삭제 연산을 설명하시오.
> > A. 원형 큐의 공백 검출은 선형큐와 마찬가지로 큐의 front와 rear가 같은지를 검증하면 됩니다. 포화 검출은, 큐의 rear에서 1을 더한 값을 최대 큐 사이즈로 나누었을 때 큐의 front와 같다면 큐가 포화상태인 것입니다. 삽입을 할 때는 큐의 rear를 1 증가시킨 것을 최대 큐 사이즈로 나눈 값을 배열의 인덱스로 사용해 데이터를 삽입합니다. 삭제 연산 시 큐의 front를 1 증가 시킨 뒤 최대 큐 사이즈로 나누어 데이터를 삭제합니다.

## Buffer
> Q. 큐의 사용 예시를 설명하시오.
> > A. 큐는 버퍼로 사용될 때가 많습니다. 버퍼는 서로 다른 속도로 실행되는 두 프로세스 사이의 상호 작용을 돕습니다. 특히 CPU 스케줄링 시, 운영체제는 실행 가능한 프로세스들을 저장하거나 이벤트를 기다리는 프로세스들을 저장하기 위해서 큐를 사용합니다.

## Double-ended Queue (Deque)
https://github.com/inourbubble2/c-data-structure/blob/main/02-Queue/3-DeQueue.c
> Q. 덱이란 무엇입니까
> > A. 덱은 Double-ended Queue의 줄임말로서 큐의 front와 rear에서 모두 삽입과 삭제가 가능한 큐를 의미합니다. 덱은 스택과 큐의 모든 연산을 가지고 있습니다. 따라서 덱은 위 두 가지 자료구조보다 융통성이 높습니다.

> Q. 덱의 삽입/삭제 연산을 설명하시오.
> > A. front에 데이터를 삽입할 때는, front를 감소시킨 뒤 최대 덱 크기를 더한 뒤 다시 최대 덱 크기로 나눈 수를 인덱스로 삼아 삽입합니다. front를 삭제할 때는 front를 증가시킨 뒤 최대 덱크기를 더하고 다시 나눈 수를 인덱스로 반환합니다. rear에 데이터를 삽입할 때는 rear를 증가시킨 뒤 위와 같은 연산을 하고, rear에 데이터를 삭제할 때는 rear를 감소시킨 뒤 같은 연산을 합니다.


### 삽입 : --front, ++rear
### 삭제 : ++front, --rear

