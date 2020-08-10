//Jason Bonilla
//jbonill4
//PA2
struct List* newList();
void freeList(struct List *tempList);
struct Node* GetNewNode(int x);
int length(struct List *tempList);
int indexx(struct List *tempList);
int front(struct List *tempList);
int back(struct List *tempList);
int get(struct List *tempList);
int equals(struct List *tempList, struct List *tempList2);
void clear(struct List *tempList);
void moveFront(struct List *tempList);
void moveBack(struct List *tempList);
void movePrev(struct List *tempList);
void moveNext(struct List *tempList);
void prepend(struct List *tempList, int data);
void append(struct List *tempList, int data);
void insertBefore(struct List *tempList,int data);
void insertAfter(struct List *tempList,int data);
void deleteFront(struct List *tempList);
void deleteBack(struct List *tempList);
void delete(struct List *tempList);
void moveTail(struct List *tempList);
void printList(struct List *tempList);
void PrintReverse(struct List *tempList);
