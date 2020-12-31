// 선형조사법
void add(element item, element ht[]) 
 {
 	int i, hashValue;
 	hashValue = i = hashFunction(item.key);
 	printf("hash address = %d\n", i);
 	while(!empty(ht[i])) {
 		if(equal(item, ht[i])) {
 			fprintf(stderr, "탐색 키가 중복되었습니다.\n");
 			exit(1);
		 }
		 i = (i+1) % TABLE_SIZE;
		 if(i == hashValue) {
		 	fprintf(stderr, "테이블이 가득찼습니다.\n");
		 	exit(1);
		 } 		
	}

 	ht[i] = item;
 }



// 이차조사법
 void add(element item, element ht[]) 
 {
 	int i, hashValue, inc = 0;
 	hashValue = i = hashFunction(item.key);
 	printf("hash address = %d\n", i);
 	while(!empty(ht[i])) {
 		if(equal(item, ht[i])) {
 			fprintf(stderr, "탐색 키가 중복되었습니다.\n");
 			exit(1);
		 }
		 i = (hashValue + inc*inc) % TABLE_SIZE;
		inc++;
		 if(i == hashValue) {
		 	fprintf(stderr, "테이블이 가득찼습니다.\n");
		 	exit(1);
		 } 		
	}

 	ht[i] = item;
 }



// 이중해시법
void add(element item, element ht[]) 
 {
 	int i, hashValue, inc;
 	hashValue = i = hashFunction(item.key);
 	inc = hashFunction2(item.key);
 	printf("hash address = %d\n", i);
 	while(!empty(ht[i])) {
 		if(equal(item, ht[i])) {
 			fprintf(stderr, "탐색 키가 중복되었습니다.\n");
 			exit(1);
		 }
		 i = (i+inc) % TABLE_SIZE;
		 if(i == hashValue) {
		 	fprintf(stderr, "테이블이 가득찼습니다.\n");
		 	exit(1);
		 } 		
	}

 	ht[i] = item;
 }
