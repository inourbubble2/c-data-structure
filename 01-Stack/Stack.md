# Stack
## Stack
<a> https://github.com/inourbubble2/c-data-structure/blob/main/01-Stack/1-Stack.c </a>
> Q. 스택이란 무엇인가
> > A. 스택은 선형 리스트 중 하나로 가장 최근에 입력된 데이터가 가장 먼저 출력되는 Last In First Out 구조의 자료구조입니다. 스택은 top이라는 변수를 가지고 그 변수에 가장 위에 있는 데이터의 위치를 저장합니다.

> Q. 스택에서의 삽입, 삭제 연산을 설명하시오
> > A. 스택에서 삽입을 하려면 간단하게 top을 먼저 증가시킨 뒤 그 자리에 데이터를 넣습니다. 삭제를 할 때는 top 위치의 데이터를 반환한 뒤 top에 1을 뺍니다.

## Dynamic Stack
https://github.com/inourbubble2/c-data-structure/blob/main/01-Stack/2-DynamicStack.c
> Q. 동적 배열 스택과 일반 스택의 차이점은 무엇인지 설명하시오
> > A. 동적 배열 스택은, 스택의 최대 사이즈를 지정하지 않고 필요한 만큼 데이터를 저장할 수 있는 스택입니다. 기존 스택과 달리 capacity라는 변수를 가지고 그 변수에 스택의 현재 용량을 저장합니다. 스택에 데이터를 삽입하려는데 스택이 꽉 찬 경우에는, 현재 capacity의 2배만큼 스택 배열의 메모리를 reallocate 한 다음에 데이터를 저장합니다. 
