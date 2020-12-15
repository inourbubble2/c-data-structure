# Linkded List
## Linear Linked List
https://github.com/inourbubble2/c-data-structure/blob/main/03-LinkedList/1-LinearLinkedList.c
> Q. 연결리스트란? 배열과 다른 점은?
> > A. 연결리스트는 자기참조를 하는 자료구조입니다. 연결리스트의 노드는 데이터와 함께 연결된 노드의 포인터를 가지고 있습니다. 연결리스트는 배열과 달리 물리적으로 연속된 저장소에 있지 않습니다. 


## Circular Linked List
https://github.com/inourbubble2/c-data-structure/blob/main/03-LinkedList/2-CircularLinkedList.c
> Q. 원형연결리스트의 장점은?
> > A. 단순연결리스트의 마지막 노드의 링크 필드는 null 값을 가집니다. 원형 연결리스트는 이 공간을 헤드 노드와 연결함으로 활용합니다. 그리고 단순연결리스트는 앞쪽의 노드로 이동할 수 없지만 원형연결리스트를 사용하면 특정 노드보다 앞쪽에 있는 노드에도 접근할 수 있습니다.

> Q. 원형연결리스트의 사용 예제를 말하시오.
> > A. 컴퓨터에서 여러 응용 프로그램을 하나의 CPU를 이용해 실행할 때 필요합니다. 실행중인 모든 프로그램은 원형 연결 리스트에 보관되고, CPU는 프로그램 실행을 위해 고정된 시간 슬롯을 제공합니다. 운영 체제는 모든 프로그램의 실행이 끝날때까지 리스트를 순회합니다.


## Double Linked List
https://github.com/inourbubble2/c-data-structure/blob/main/03-LinkedList/3-DoubleLinkedList.c
> Q. 이중연결리스트란?
> > A. 이중연결리스트는 단순연결리스트와 달리 한 노드가 앞 노드, 뒤 노드의 링크 필드를 모두 가지고 있는 리스트를 말합니다. 이때문에 삽입과 삭제 연산이 다소 복잡해지지만, 어떤 노드에서든 리스트 내 모든 노드에 접근할 수 있다는 장점이 있습니다.


## Linked List Stack
https://github.com/inourbubble2/c-data-structure/blob/main/03-LinkedList/4-LinkedListStack.c

## Linked List Queue
https://github.com/inourbubble2/c-data-structure/blob/main/03-LinkedList/4-LinkedListQueue.c

> Q. 연결리스트로 만든 스택/큐의 장단점은 무엇입니까?
> > A. 연결리스트 스택/큐의 가장 큰 장점은 스택/큐의 최대 사이즈를 지정하지 않아도 된다는 것입니다. 다만 연결리스트 스택/큐는 동적 메모리 할당을 요구하므로, 삽입이나 삭제 연산의 시간이 더 수행됩니다.
