# Hashing
## 데이터가 저장될 위치(인덱스)를 간단한 연산을 이용해 구하는 것

## Hash Table
> Q. 해싱이란 무엇입니까?
> > A. 해싱은 키에 산술적인 연산을 적용하여 항목이 저장되어 있는 테이블의 주소를 계산하여 항목에 접근합니다. 이렇게 키에 대한 연산에 의해 직접 접근이 가능한 구조를 해시 테이블(Hash Table)이라고 부르고, 해시 테이블을 이용한 탐색을 해싱(Hashing) 이라고 합니다. 해싱은 컴파일러가 사용하는 심볼 테이블, 철자 검사기, 데이터베이스 등에서 사용됩니다. 해싱의 시간 복잡도는 O(1)입니다. 

> Q. 해싱의 구조에 대해서 설명하시오.
> > A. 해싱에서 자료를 저장할 때는 배열을 사용합니다. 배열은 단점도 있지만 만약 원하는 항목이 들어 있는 위치를 알고 있다면 매우 빠르게 자료를 삽입하거나 꺼낼 수 있습니다. 해싱은 어떤 항목의 키만을 가지고 바로 항목이 들어있는 배열의 인덱스를 결정하는 기법입니다. 해시 함수라는 키를 입력으로 받아 해시 주소를 생성하고 그 해시 주소를 해시 테이블의 인덱스로 사용합니다. 해시 테이블에서 하나의 버킷은 여러 개의 슬롯을 가질 수 있으며 하나의 슬롯에는 하나의 항목이 저장됩니다. 하나의 버킷에 여러 슬롯을 두는 이유는 서로 다른 두 개의 키가 해시함수에 의해 동일한 해시 주소로 변환될 수 있으므로 여러 개의 항목을 동일한 버킷에 저장하기 위함입니다. 그러나 대부분의 경우 하나의 버킷은 하나의 슬롯을 가집니다. 해시 테이블에 존재하는 버킷의 수가 M 이므로 해시함수 h는 모든 키에 대해 0 <= h(x) <= M-1의 범위 값을 가집니다. 대부분 해시 테이블의 버킷 수는 모든 키의 경우 수보다 작으므로 다른 키가 해시함수에 의해 같은 해시 주소로 사상(mapping)되는 경우가 잦습니다. 이런 경우를 충돌(collision)이라고 하며, 이러한 키들을 동의어(synonym)이라고 합니다. 만약 이러한 충돌이 버킷에 할당된 슬롯 수보다 많이 발생하게 되면 버킷에 더 이상 항목을 저장할 수 없는 오버플로우(overflow)가 발생합니다. 


## Hash Function
https://github.com/inourbubble2/c-data-structure/blob/main/09-Hashing/1-HashFunction.c
> Q. 좋은 해시 함수의 조건을 정의하시오.
> > A. 1) 충돌이 적어야 한다. 2) 해시함수 값이 해시 테이블의 주소 영역 내에서 고르게 분포되어야 한다. 3) 계산이 빨라야 한다.

> Q. 제산 함수에 대해서 정의하시오.
> > A. 제산 함수는 나머지 연산자(mod)를 이용하여 키를 해시 테이블의 크기로 나눈 나머지를 해시 주소로 사용하는 방법입니다. 즉 해시함수 h(k) = h mod M 인 것입니다. 여기서 M은 해시 테이블의 크기로 해시 테이블의 인덱스로 사용하기에는 이상적인 값이 됩니다. 이는 가장 일반적인 해시 함수로서 해시 테이블의 크기 M은 주로 소수(prime number)로 사용합니다. 이 방법은 다양한 응용 분야에서 쉽게 적용할 수 있고, 해시 주소를 고르게 분포시키는 좋은 방법입니다. 

> Q. 폴딩 함수에 대해서 정의하시오.
> > A. 폴딩 함수는 주로 탐색 키가 해시 테이블의 크기보다 더 큰 정수일 경우에 사용합니다. 예를 들어 탐색 키는 32비트, 해시 테이블의 인덱스는 16비트 정수인 경우입니다. 이런 경우 탐색 키의 16비트를 무시하고 뒤의 16 비트를 해시코드로 사용한다면 충돌이 발생할 수 있을 것입니다. 따라서 탐색 키의 일부만 사용하는 것이 아니고 탐색 키를 몇 개의 부분으로 나누어 더하거나 XOR 연산을 하는 것이 좋은 방법인데 이것을 폴딩이라고 부릅니다. 즉 해시 함수 h(k) = (key ^ (key >> 16)) 인 것입니다. 탐색 키를 나누고 더하는 방법에는 이동폴딩과 경계폴딩이 대표적인데, 이동폴딩은 탐색 키를 여러 부분으로 나눈 값들을 더하여 해시 주소로 사용하고, 경계 폴딩은 탐색 키를 이웃한 부분을 거꾸로 더하여 해시 주소를 얻습니다.

> Q. 중간 제곱 함수에 대해서 정의하시오.
> > A. 정수 키값을 사용하는 경우 가장 좋은 함수는 중간 제곱 함수입니다. 중간 제곱 함수는 탐색 키를 제곱한 다음 중간의 몇 비트를 취해서 해시 주소로 생성합니다. 제곱한 값의 중간 비트들은 대개 탐색 키의 모든 문자들과 관련이 있기 때문에 서로 다른 탐색 키는 몇 개의 문자가 같을지라도 서로 다른 해싱 주소를 갖게 됩니다. 따라서 탐색키 값을 제곱한 중간 비트들의 값은 비교적 고르게 분산됩니다.

> Q. 비트 추출 방법에 대해서 정의하시오.
> > A. 비트 추출 방법은 해시 테이블의 크기가 M = 2n일 때 탐색 키를 이진수로 간주하여 임의의 위치에 n개의 비트를 해시주소로 사용하는 것입니다. 이 방법은 아주 간단하지만 탐색 키의 일부 정보만을 사용하므로 해시 주소의 집중 현상이 일어날 가능성이 높습니다.

> Q. 숫자 분석 방법에 대해서 정의하시오.
> > A. 숫자 분석 방법은 숫자로 구성된 키에서 각각의 위치에 있는 수의 특징을 미리 알고 있을 때 유용합니다. 키의 각각 위치의 숫자 중에서 편중되지 않은 수들을 해시 테이블의 크기에 적합한 만큼 조합하여 주소로 사용하는 방법입니다. 예를들어 학생의 학번을 사용한다면 입학년도를 의미하는 4자리수를 제외하고 나머지 수를 조합하여 해시 주소로 사용하는 것입니다.

> Q. 탐색키가 문자열일 경우 주의할 점에 대해서 말하시오.
> > A. 키들이 정수일 때는 비교적 쉽게 해시 주소로 변환할 수 있지만, 많은 경우 키들은 문자열입니다. 이러한 경우 가장 보편적인 방법은 문자의 아스키 코드값이나 유니코드 값을 사용하는 것인데, 하지만 충돌이 발생할 가능성이 높습니다. 그래서 각 문자의 아스키 코드값을 모두 더하거나 아스키 코드 값에 위치에 기초한 값을 곱해야 합니다.


## Open Addressing
https://github.com/inourbubble2/c-data-structure/blob/main/09-Hashing/2-OpenAddressing.c
> Q. 개방주소법이 필요한 이유는 무엇입니까?
> > A. 서로 다른 키를 갖는 항목들이 같은 해시주소를 가지면 충돌이 생기는데, 충돌이 발생했을 때 해시 주소에 더 이상 빈 버킷이 남아있지 않으면 오버플로우가 발생합니다. 오버플로우가 발생하면 해시테이블에 항목을 더 저장하는 것이 불가능해집니다. 이러한 경우를 해결하기 위해서 개방주소법이나 체이닝이 필요합니다.

> Q. 선형조사법에 대해서 정의하시오.
> > A. 선형조사법은 만약 충돌이 ht[k]에서 발생했다면 ht[k+1]가 비어있는지 검사하고, 비어있지 않다면 ht[k+2]를 조사합니다. 이런 식으로 비어있는 공간이 나올 때까지 계속해서 조사를 하고 비어있는 공간에 저장하는 방법입니다. 만약 테이블의 끝에 도달하면 다시 테이블의 처음으로 갑니다. 

> Q. 이차조사법에 대해서 정의하시오.
> > A. 이차조사법은 선형조사법과 유사하지만 다음 조사할 위치를 이 식에 의해서 결정합니다. ((h(k) + inc*inc) mod M for inc = 0,1,...M-1 따라서 조사하는 위치는 다음과 같습니다. h(k), h(k) + 1, h(k) + 4, h(k) + 9, … 다만 주의할 점은 모든 위치를 조사하게 만드려면 테이블 크기는 소수여야 합니다. 이 방법은 선형 조사법에서의 문제인 집중과 결합을 크게 완화시킬 수 있습니다. 이차조사법을 구현하려면 다음 조사 위치를 찾는 부분만 변경하면 됩니다.

> Q. 이중해싱법에 대해서 정의하시오.
> > A. 선형주소법, 이차주소법은 오직 1차 클러스트링 문제만 해결하기에 서로 다른 두 키가 동일한 홈 위치를 갖는다면 이들 방법은 모두 동일한 탐사 순서를 가진다는 단점이 있지만, 이중 해싱법은 2차 클러스트링 문제 역시 해결합니다. 그러한 문제를 해결하려면 탐사 순서가 원래 키값을 이용하도록 하는 것이 필요합니다. 이중해싱법(double hashing) 또는 재해싱(rehashing)은 오버플로우가 발생함에 따라서 항목을 저장하는 위치를 결정할 때 원래 해시 함수와 다른 별개의 해시 함수를 이용하는 방법입니다. 이 방법은 항목들을 해시 테이블에 보다 균일하게 분포시킬 수 있고 이차 집중을 피할 수 있으므로 효과적인 방법입니다. 

## Chaining
https://github.com/inourbubble2/c-data-structure/blob/main/09-Hashing/3-Chaining.c
> Q. 체이닝이란 무엇입니까?
> > A. 체이닝은 오버플로우 문제를 해시테이블의 구조를 연결리스트로 바꿔 해결하는 방법입니다. 즉, 각 버켓에 고정된 슬롯을 할당하는 것이 아니라 삽입과 삭제가 용이한 연결리스트를 할당합니다. 버켓 내에서 원하는 항목을 찾을 땐 연결리스트를 순차탐색하면 됩니다. 해시테이블은 한 개의 노드를 가리킬 수 있는 포인터 배열로 선언하고, 탐색 키가 버켓으로 들어올 경우 동적으로 메모리를 할당하여 연결리스트의 노드를 생성한 다음, 새로운 노드에 탐색 키를 복사합니다. 다음 단계로 버켓에 연결되어 있는 기존의 연결리스트에 동일한 탐색 키가 있는지 검사합니다. 동일한 탐색 키가 없으면 연결리스트의 끝에 새로운 탐색키를 포함하는 노드를 연결하고, 없으면 해시테이블의 포인터에 새 노드를 연결합니다. 체이닝은 필요한 만큼의 메모리를 사용하게 되어 공간적 사용 효율이 우수하고, 오버플로우가 발생할 때도 해당 버켓에 할당된 연결리스트만 처리하게 되므로 수행 시간면에서도 효율적입니다. 다만 체이닝은 해시 테이블과 연결 리스트가 주기억장치 내에서 유지될 때 가장 적합합니다. 해시 테이블을 디스크에 효과적으로 저장하는 건 어려운데, 왜냐하면 주어진 연결리스트의 노드가 다른 디스크 블록에 저장될 수 있으므로 특정 키값을 탐색하는 데 다중 디스크 접근을 해야 하기 때문입니다. 

## Deletion in Hash Table
> Q. 해시 테이블에서 레코드를 삭제할 때 고려해야할 사항은 무엇입니까?
> > A. 먼저, 레코드의 삭제가 차후의 탐색을 방해하지 말아야 합니다. 즉 탐색 과정은 삭제로 인해 새롭게 비게 된 슬롯을 통과해서 탐사 순서에 의해 해당 레코드에 도달할 수 있어야 합니다. 따라서 삭제 과정은 슬롯이 빈 것으로 단순히 표시만 해서는 안 됩니다. 왜냐하면 이 삭제된 레코드 때문에 탐사 순서에서 그 이후 레코드를 고립시킬 수 있기 때문입니다. 
그리고 삭제로 인해 해시 테이블의 위치에서 사용할 수 없는 곳을 만들지 말아야 합니다. 삭제로 인해 생긴 빈 슬롯은 나중에 삽입 과정에서 사용되어야 합니다. 

> Q. 위와 같은 문제를 어떻게 해결할 수 있습니까?
> > A. 삭제된 레코드 위치에 비석(tombstone)이라는 특별한 표시를 함으로 해결할 수 있습니다. 비석은 레코드가 슬롯을 차지했다가 이제는 더 이상 해당 슬롯이 레코드에 의해 사용되지 않음을 나타냅니다. 탐사 순서에 따라 탐색을 하는 동안 비석을 만나면 탐색을 계속 이어나가고, 삽입하는 동안 비석을 만나면 해당 슬롯이 새로운 레코드를 저장하기 위해 사용됩니다. 

> Q. 비석이 야기할 수 있는 문제가 있습니까?
> > A. 네. 일련의 삽입과 삭제 연산이 진행된 후 어떤 슬롯은 비석을 가지고 있을 수 있는데 이건 레코드의 홈 위치에서부터 실제 레코드 위치까지의 평균 거리를 증가시킵니다. 예를 들어 초기에 데이터베이스에 레코드를 적재한 후 평균 거리가 1.2 정도일 때, 이것은 홈 위치를 지나서 탐색 당 평균 0.2 접근이 필요함을 의미합니다. 하지만 삽입과 삭제가 발생한 후 평균 거리는 비석 때문에 1.6 가량으로 증가할 수 있습니다. 이건 삭제가 발생하기 전보다 홈 위치를 지나서 평균 3배 정도가 길어진 것입니다. 이러한 문제를 해결하려면 두 가지 방법을 사용할 수 있습니다. 먼저 삭제 후 평균 경로 길이를 줄이기 위해 국부적으로 다시 조직화하는 것입니다. 예를 들어 하나의 키를 삭제한 후 탐사 순서에서 삭제된 키 이후에 있는 레코드를 하나씩 앞으로 이동시키는 것입니다. 다만 이것은 모든 충돌 해결 방법에 적용할 수 있지는 않습니다. 두 번째로, 정기적으로 테이블을 재해시해서 모든 레코드를 새로운 테이블로 다시 삽입하는 것입니다. 이것은 비석을 제거할 수 있을 뿐만 아니라 빈번하게 접근된 레코드를 홈 위치에 위치시킬 수 있는 기회를 제공합니다. 
