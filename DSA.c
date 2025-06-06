#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define QUEUE_MAX_SIZE 20
#define DICTIONARY_MAX_SIZE 20
/// @brief Implementation of custom static sized stack
typedef struct 
{
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s){
    s->top = -1;
}

void push(Stack* s, int value){
    if(s->top + 1 >= MAX_SIZE){
        printf("Stack overflow");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack* s){
    if(s->top == -1){
        printf("Stack underflow");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int peek(Stack* s){
    if(s->top == -1){
        printf("Stack is empty");
        return -1;
    }
    return s->data[s->top];
}

/// Implementation of custom static sized Queue
typedef struct{
    int data[QUEUE_MAX_SIZE];
    int front;//index to dequeue at
    int rare;//index to enqueue at
    int size;//counter to see - if we have empty slots in circular array
} Queue;

void initQueue(Queue* q){
    q->front = 0;
    q->rare = 0;
    q->size = 0;
}

int isQueueFull(Queue* q){
    return q->size == QUEUE_MAX_SIZE;
}

int isQueueEmpty(Queue* q){
    return q->size == 0;
}

void enqueue(Queue* q, int value){
    if(isQueueFull(q)){
        printf("Can't Enqueue %d : %d \n", q->rare, value);
        return;
    }
    q->data[q->rare] = value;
    printf("Enqueued %d : %d \n", q->rare, value);
    q->rare = (q->rare + 1) % QUEUE_MAX_SIZE;
    q->size++;
}

int dequeue(Queue* q){
    if(isQueueEmpty(q)){
        printf("Empty queue %d : \n", q->front);
        return -1;
    }
    int value = q->data[q->front];
    printf("Dequeued %d: %d\n", q->front, value);
    q->front = (q->front + 1) % QUEUE_MAX_SIZE;
    q->size--;
    return value;
}




void printArray(int array[], int size){
    for (int i = 0; i < size; i++){
        printf("[%d]", array[i]);
    }
    printf("\n");
}

void testStack(){
     Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Peek : Top of stack is : %d\n", peek(&s));
    printf("Top of stack is : %d\n", pop(&s));
    printf("Top of stack is : %d\n", pop(&s));
}

void testQueue(){
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    dequeue(&q);
    enqueue(&q, 60);
    enqueue(&q, 70);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printArray(q.data, sizeof(q.data)/ sizeof(int));
}


///Implementation of custom static sized dictionary
typedef struct
{
    char *key;
    int value;
} KeyValuePair;

typedef struct{
    KeyValuePair dictArrar[DICTIONARY_MAX_SIZE];
} Dictionary;

unsigned long int hashFunction(const char *str, int maxSize)
{
    unsigned long int hash = 5381;
    int c;

    while((c = *str++)){
        hash = ((hash << 5) + hash) + c;
    }

    //make sure it is within the size range of array
    unsigned long int hashIndex = hash % maxSize;
    return hashIndex;
}

void insert_dict(Dictionary* d,char* key, int value){
    //generate hash from the key
    unsigned long int hashIndex = hashFunction(key, DICTIONARY_MAX_SIZE);
    //set key value pair
    d->dictArrar[hashIndex].key = malloc(strlen(key) + 1);
    strcpy(d->dictArrar[hashIndex].key,key);
    d->dictArrar[hashIndex].value = value;
}

int get_value_dict(Dictionary* d, char* key){
    //generate has
    unsigned long int searchHash = hashFunction(key, DICTIONARY_MAX_SIZE);
    char* foundKey = d->dictArrar[searchHash].key;
    if(strcmp(key, foundKey)){
        printf("KeyNotFound");
        return -1;
    }
    int foundValue = d->dictArrar[searchHash].value;
    return foundValue;
}

int freeDictionery(Dictionary* d){
    for (int i = 0; i < DICTIONARY_MAX_SIZE; i++){
        if (d->dictArrar[i].key != NULL){
            free(d->dictArrar[i].key);
        }
    }
}


void testDictionary(){
    Dictionary d;
    insert_dict(&d, "chetan", 25);
    insert_dict(&d, "pratik", 23);
    insert_dict(&d, "Pragya", 25);
    printf("Age of chetan is %d", get_value_dict(&d, "chetan"));
    freeDictionery(&d);
} 

//Implementaion of custom binary trees
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data){
    Node *n = (Node *)malloc(sizeof(Node));
    if(n == NULL){
        printf("malloc failed \n");
        return NULL;
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void freeTree(Node* root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//root -> left -> right
void preorderTraversal(Node* root){
    if (root == NULL){
        return;
    }
    printf("%d \n",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//left -> root -> right
void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

//left -> right -> root
void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n",root->data);
}

//height of tree
int treeHeight(Node* root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}




void testBinaryTree(){
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);
    printf("_____PREORDER____\n");
    preorderTraversal(root);
    printf("_____INORDER____\n");
    inorderTraversal(root);
    printf("_____POSTORDER____\n");
    postorderTraversal(root);
    printf("Tree height: %d\n", treeHeight(root));
    freeTree(root);
}

Node* insert(Node* root,int data){
    Node *n;
    if(root == NULL){
        //we empty place to insert node
        return createNode(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data >= root -> data){
        //handle duplicates as well
        root->right = insert(root->right, data);
    }

    return root;
}

int search(Node* root, int key){
    int val;
    if(root == NULL){
        return 0;
    }

    if(root->data == key){
        return 1;
    }
    
    if(key < root->data){
        val = search(root->left, key);
    }else if( key >= root->data){
        val = search(root->right, key);
    }

    return val;
}

void testBST(){
    int arr[] = {10, 5, 20, 5, 15, 20, 21, 1, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    for (int i = 1; i < size; i++){
        root = insert(root, arr[i]);
    }
    inorderTraversal(root);
    printf("BST has 3 : %d\n", search(root, 3));
    printf("BST has 99 : %d\n", search(root, 99));
}

//Implementation of custom min heap 
typedef struct 
{
    int data;// lower means higher priority
} Item;

typedef struct{
    Item items[QUEUE_MAX_SIZE + 1]; // index starts from zero
    int size;
} Heap;

int parentIndex(int n){
    if(n <= 1){
        return -1;
    }
    else{
        return (int)n / 2; // child node n -> when n/2 give index of parent
    } 
}

int youngChildIndex(int n){
    return 2 * n;//child is always 2n and 2n+1 in heap\

}

void heapSwap(Heap* pq, int i, int j){
    Item item = pq->items[i];
    pq->items[i] = pq->items[j];
    pq->items[j] = item;
}

void bubbleUp(Heap* pq, int index){
    if (parentIndex(index) == -1) return; // nothing to bubble
    if(pq->items[index].data <  pq->items[parentIndex(index)].data){
        heapSwap(pq, index, parentIndex(index));
        bubbleUp(pq, parentIndex(index));
    }
}

void insertItem(Heap* pq,Item item){
    if(pq->size >= QUEUE_MAX_SIZE){
        printf("Queue is full");
        return;
    }
    //insert element at the end
    pq->size = pq->size + 1;
    pq->items[pq->size] = item;
    bubbleUp(pq, pq->size);
}

void makeHeap(Heap* hp,int* arr,int size){
    for (int i = 0; i < size; i++){
        Item item;
        item.data = arr[i];
        insertItem(hp, item);
    }
}

void printHeap(Heap* hp){
    for (int i = 1; i <= hp->size; i++){
        printf("%d : %d\n", i, hp->items[i].data);
    }
}

void bubbleDown(Heap* pq, int index){
    int c;
    int i;
    int min_index;

    min_index = index;
    c = youngChildIndex(index);// we will get child at 2n
    //iterate through both child
    for (i = 0; i <= 1; i++){
        //two child are at 2n and 2n + 1 -> min_index = parent index
        //if we find child with value smaller than current(parent) 
        if(c + i <= pq->size && pq->items[min_index].data > pq->items[c + i].data){ //in first iteration we compare parent with first child
            //in next we compare first child with second child
            min_index = c + i;
        }
    }

    //we found child to be smaller than parent
    if(index != min_index){
        heapSwap(pq, index, min_index);
        bubbleDown(pq, min_index);
    }
}

int extract_min(Heap* pq){
    int min = -1; //minimum value
    if(pq->size <= 0){
        printf("Empty queue");
    }else{
        min = pq->items[1].data;//item at top is always minimum
        //replace first item with last item
        pq->items[1] = pq->items[pq->size];
        // reduce total size
        pq->size = pq->size - 1;
        bubbleDown(pq, 1);
    }
    return min;
}




void testHeap(){
    int arr[] = {12, 11, 5, 4, 3, 9, 15, 19};
    Heap* hp = (Heap*)malloc(sizeof(Heap));
    hp->size = 0;
    makeHeap(hp, arr, sizeof(arr)/sizeof(arr[0]));
    printHeap(hp);
    printf("----min is----: %d\n", extract_min(hp));
    printHeap(hp);
    printf("----min is----: %d\n", extract_min(hp));
    printHeap(hp);
    printf("----min is----: %d\n", extract_min(hp));
    printHeap(hp);
}

int main(){
    testHeap();
    return 0;
}


