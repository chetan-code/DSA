#include <iostream>
#include <cstring>
#define MAXSIZE 100
#define QUEUE_MAXSIZE 4
#define DICTIONERY_MAX_SIZE 20
/// @brief Implementation of a custom static sized stack 
class Stack{
private:
    int data[MAXSIZE];
    int top;
public :
    Stack() : top(-1) {}
    void push(int value){
        if(top + 1 >= MAXSIZE){
            std::cout << "Stack overflow";
            return;
        }
        top++;
        data[top] = value;
    }

    int pop(){
        if(top == -1){
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        int value = data[top];
        top--;
        return value;
    }

    int peek(){
        if(top == -1){
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        return data[top];
    }

    void print(){
        for (int i = top; i >= 0; i--)
        {
            std::cout << data[i] << std::endl;
        }
    }
};

/// @brief Implementation of a custom static sized queue
class Queue{
};

struct KeyValuePair{
    char *key;
    int value;
};

unsigned long int hashFunction(const char* str, int max_size){
    unsigned long int hash = 5321;
    int c;
    while((c = *str++)){
        hash = ((hash << 5) + hash) + c;
    }
    //we need to limit it within max size
    return hash % max_size;
};

/// @brief Implementation of a custom static sized dictionery
class Dictionery{
    private:
        KeyValuePair arr[DICTIONERY_MAX_SIZE];

    public :
        Dictionery() {}
        ~Dictionery(){
            for (int i = 0; i < DICTIONERY_MAX_SIZE; i++){
                if(arr[i].key != NULL){
                    delete[] arr[i].key;
                }
            }
        }
        void add(const char* key, int value){
            //generate hash
            unsigned long int hashIndex = hashFunction(key, DICTIONERY_MAX_SIZE);
            arr[hashIndex].key = new char[strlen(key) + 1];
            strcpy(arr[hashIndex].key, key);
            arr[hashIndex].value = value;
        }

        int getValue(const char* key){
            //search hash
            unsigned long int searchHashIndex = hashFunction(key, DICTIONERY_MAX_SIZE);
            char* foundKey = arr[searchHashIndex].key;
            if(strcmp(key, foundKey) != 0){
                std::cerr << "KeyNotFound" << std::endl;
                return -1;
            }
            return arr[searchHashIndex].value;
        }
};

//Implementation of a linked list
struct LinkNode{
    int data;
    LinkNode* next;
    
    LinkNode(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    LinkNode* head;
   
public :
    LinkedList(){
        head = nullptr;
    }    

    //insert at end
    void push_back(int value){
        LinkNode* newNode = new LinkNode(value);
        //head is not set yet
        if(head == nullptr){
            head = newNode;
            return;
        }

        //iterate to find the next null node
        LinkNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //insert at front
    void push_front(int value){
        LinkNode* newNode = new LinkNode(value);
        newNode->next = head;
        head = newNode;
    }

    void reverse(){
        LinkNode *prev = nullptr;
        LinkNode *current = head;
        LinkNode *next = nullptr;
        //iterate through and swap pointers
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //new head
        head = prev;
    }

    void print(){
        LinkNode *temp = head;
        while(temp->next != nullptr){
            std::cout << "["<< temp->data << "]" << "->";
            temp = temp->next;
        }
        std::cout << "NULL \n";
    }
};

//Implementation of BST
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int newVal){
        val = newVal;
        left = right = nullptr;
    }
};

class BST{
    Node *root;

    Node* insert(Node* root, int val){
        if(root == nullptr){
            return new Node(val);
        }

        if(val < root->val){
            root->left = insert(root->left, val);
        }else if(val >= root->val){
            //duplicate go to the right
            root->right = insert(root->right, val);
        }
        return root;
    }

    bool search(Node* root, int val){
        if(root == nullptr){
            return false;
        }

        if(root->val == val){
            return true;
        }

        if(val < root->val){
            return search(root->left, val);
        }else {
            return search(root->right, val);
        }
    }

    //in order traversal => left -> root ->right
    void inorder(Node* node){
        if(node == nullptr){
            return;
        }
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }

    Node* findMin(Node* node){
        while(node && node->left != nullptr){
            node = node->left;
        }
        return node;
    }

    void mirror(Node* node){
        if(node == nullptr){
            return;
        }

        //swap left and right
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        //recurse for children
        mirror(node->left);
        mirror(node->right);
    }
};

void testLinkedList(){
    LinkedList list;
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.print();
    list.reverse();
    list.print();
}

void testStack(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.pop();
    s.print();
    std::cout << s.peek() << std::endl;
};

void testDictionery() {
    Dictionery d;
    d.add("chetan", 24);
    d.add("pragya", 22);
    d.add("pratik", 20);
    std::cout << "age of chetan is : " << d.getValue("chetan") << std::endl;
    std::cout << "age of suraj is : " << d.getValue("suraj") << std::endl;
    std::cout << "age of pragya is : " << d.getValue("pragya") << std::endl;
}

int main(int argc, char const *argv[])
{
    testLinkedList();
    return 0;
}
