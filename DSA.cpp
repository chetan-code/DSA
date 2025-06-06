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
    testDictionery();
    return 0;
}
