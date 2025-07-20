#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

//STL containers 
void explainPairs(){
    pair<int, int> p = {1, 2};
    p.first;
    p.second;
    pair<int, pair<int, int>> nestedP = {1, {2, 3}};//3 pair - we can do nesting
    nestedP.first;
    nestedP.second.first;
    nestedP.second.second;
    //pair array
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
}

void explainVectors(){
    vector<int> v;
    //push values

    v.push_back(10);
    v.push_back(20);
    v.emplace_back(2);//similar to push back - generally faster

    vector<pair<int, int>> pairVec;
    pairVec.push_back({1, 2});
    pairVec.emplace_back(1, 2);//assume it to pair

    vector<int> v3(5, 100); // 100, 100, 100, 100, 100
    vector<int> v2(v); //copy

    v.size();//vector has size

    //iterator
    vector<int>::iterator it = v.begin();//first index memory address
    it++;                                // next memory address;
    cout << *it;                         // derefrencing;
    it = it + 2; // 2 address ahead
    //default values
    it = v.end();//one after end of vector last will be v.end() - 1
    vector<int>::reverse_iterator rit = v.rend();//reverse end
    vector<int>::reverse_iterator rit2 = v.rbegin(); //reverse begin

    //looping is possible in vector
    for (it = v.begin(); it != v.end(); ++it){
        //loopin with iterators
    }

    //use auto for automatic type detection by compiler
    for (auto newIt = v.begin(); newIt != v.end(); newIt++){

    }

    //for each element in v
    for(auto it : v){

    }

    v.erase(v.begin() + 1);//1st index erased - takes address
    v.erase(v.begin() + 2, v.begin() + 4);//range delete start and end (end is exclusive)

    //insert
    v.insert(v.begin(), 200);//200 at 0th index
    v.insert(v.begin() + 3, 400);//400 at 3rd index
    v.insert(v.begin() + 1, 2, 100);//in insert 100 at 1st and 2nd post (10, 100, 100, 20)

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); //add copy at start

    v.pop_back();//remove last element

    v.swap(copy);//swap values
    v.clear();//clear entire vector
    v.empty(); 
}

void explainList(){
    //similar to vector but we can insert at front
    list<int> ls;
    ls.push_back(10);
    ls.emplace_back(20);
    //special to list
    ls.push_front(111);
    ls.emplace_front(111);
    //rest same
    //begin end rbegin rend clear inser size swap
}


void explainDeque(){
    deque<int> dq;
    dq.push_back(10);
    dq.emplace_back(10);
    dq.pop_front();
    dq.emplace_front();
    dq.pop_back();
    dq.front();
    dq.back();
    //all other same as vector
}

void explainStack(){
    //LIFO - last in first out
    stack<int> s;//no index access is allowed
    s.push(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.emplace(40);//push and emplace does the same thing

    s.top();//top element or the last element view

    s.size();
    s.empty();//false
    s.pop();//last element remove first - removed
    stack<int> s2;
    s.swap(s2);
}

void explainQueue(){
    //FIFO - first in first out - same like first cum first serve delivery
    queue<int> q;
    q.push(20);
    q.push(30);
    q.push(10);
    q.emplace(40);
    q.pop();//10 will be removed first
    q.back();//last element
    q.front();//front or first element
    q.size();
    q.back() += 5;//add 5 to last element from back
}

void explainPQ(){
    //priority queue - by default it is a max heap
    //largest value stays at start

    priority_queue<int> pq;//max heap
    pq.push(5);
    pq.push(22);
    pq.push(10);
    pq.emplace(7);

    // cout << pq.top()<< endl;
    // pq.pop();
    // cout << pq.top()<< endl;
    // pq.pop();
    // cout << pq.top()<< endl;

    //min heap
    priority_queue<int, vector<int>, greater<int>> minq;
    minq.push(10);
    minq.push(-1);
    minq.push(100);
    minq.push(11);

    cout << minq.top() << endl;
    minq.pop();
    cout << minq.top() << endl;
}


void explainSet(){
    //sorted and unique - maintain tree for order
    set<int> s;
    s.insert(10);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.emplace(20);
    for(int x : s){
        cout << x << " ";
    }
    //logn complexity 
    cout << endl;
    auto it = s.find(10);
    cout << *it << endl;
    auto fi = s.find(1);
    auto li = s.find(10);
    s.erase(fi, li);

    multiset<int> ms;//sorted but will accept of duplicate
    //erase will erase all the duplicates As well
    //use iterator for specific elememtn removal

    //unordered set - store unique no sorted order - hashing based - O(1)
    //lowerbound and uper bound dont work in unordered set
        //lower bound does a binary search to return first element >= x
        //upper bound does bs to find first element greater than x
        //binary search is only possible in ordered data 
}

void explainMap(){
    map<int, int> table;//key value pair
    //keys are unique - value can be same
    map<int, pair<int, int>> hahhaha;

    //map store keys in sorted ordered
    table[1] = 2; //on key 1 - store 2
    table.insert({3, 4});
    table.emplace(5, 2);

    for(auto it : table){
        cout << it.first << it.second << endl;
    }

    cout << table[1];//value will be printed


    //we can do find
    auto it = table.find(10);//return key location

    //lower and upper bound works

    //same for multimap => allow duplicate keys (log n)

    //unordered = no order but unqiue keys (constant time)
}

// a comprator is a bool return functin which will help your evalute params
bool comp(pair<int, int> p1, pair<int, int> p2){
    //increaing order of second
    if(p1.second < p2.second)return true;
    if(p1.second > p2.second) return false;//swapping
    //if not both are equal and we need them in descending order of first
    if(p1.first > p2.first) return true;
    return false;
}

void algos(){
    vector<int> arr = {1, 5, 6, 9, 2, 10, 3};
    sort(arr.begin(), arr.end());//
    for(int x : arr){
        cout << x << " ";
    }
    vector<pair<int, int>> pairs = {{2, 1}, {3, 5}, {1, 1}, {1,10}};

    cout << endl;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int x : arr){
        cout << x << " ";
    }

    sort(pairs.begin(), pairs.end(), comp);

    int max = *max_element(arr.begin(), arr.end());
}

//basic math
//digit extraction 
int countDigit(int n){
    int given = n;
    int count = 0;
    while(given != 0){
        given /= 10;
        count++;
    }
    return count;
}

int reverseNumber(int n){
    int given = n;
    int reverse = 0;
    while(given != 0){
        int lastDigit = given % 10;
        reverse = (reverse * 10) + lastDigit;
        given /= 10;
    }
    return reverse;
}

bool isPalindrome(int n){
    int given = n;
    int reverse = 0;
    while(given != 0){
        int lastDigit = given % 10;
        reverse = (reverse * 10) + lastDigit;
        given /= 10;
    }

    return (reverse == n);
}

int sumOfDigits(int n){
    int given = n;
    int sum = 0;
    while(given != 0){
        int lastDigit = given % 10;
        sum += lastDigit;
        given /= 10;
    }
    return sum;
}
//a number is called armstrong no - when the sum of cube of all the digits of the number is equal to number
bool isArmstrongNumber(int n){
    int given = n;
    int sum = 0;
    while(given != 0){
        int lastDigit = given % 10;
        sum += pow(lastDigit, 3);
        given /= 10;
    }
    return (n == sum);
}

void printAllDivisors_A(int x){
    for (int i = 1; i <= x; i++){
        if(x % i == 0){
            //perfect division
            cout << i << " ";
        }
    }
}

//uses square root of number as after the root the divisor just repeat example 2 x 5 <==> 5 x 2
void printAllDivisors_B(int x){
    //use a list or vector if you want them in order
    vector<int> ls;
    //O (sqrt(n))
    for (int i = 1; i < sqrt(x); i++){
        if(x % i == 0){ // 6 % 2 == 0
            cout << i << " ";// 2
            ls.push_back(i);
            if((x/i) != i){ // 6 / 2 = 3 also a divisor 
                cout << x / i << " "; //print will be not in order
                ls.push_back(x / i);
            }
        }
    }
    cout << endl;
    //sorting O(n*log(n))
    sort(ls.begin(), ls.end());
    cout << "Sorted list : ";
    // O(n);
    for(int x : ls){
        cout << x << " ";
    }
}

//a prime number has two divisor 1 and itself. Note 1 is not prime
bool checkIfPrime(int n){
    int divisorCount = 0;
    //i < sqrt(n) is same as i * i < n
    for (int i = 1; (i * i) < n; i ++){
        if(n % i == 0){
            divisorCount++;
            if((n / i) != i){//check for like 36 = 6 * 6 ===> so 36/6 == 6 ==> we dont want again to add 6
                divisorCount++;
            }
        }
    }

    if(divisorCount == 2) {return true;}
    return false;
}

//gcd == hcf
//using euclidean algorithm - gcd(a, b) == gcd(a % b, b) --> till a or b == 0 ==> other is gcd
int calculateGCD(int a, int b){
    //can also be implemented using recursion where a==0 or b == 0 can act as break
    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    //time complexity --> O(logX(min(a, b)))
}

//Recursion - O(N)
void recursionCount(int n, int count){
    if(count == n){
        return;
    }
    count++;
    cout << count << endl;
    recursionCount(n, count);
}

//O(n)
void recursionReverseCount(int i){
    if(i == 0){
        return;
    }
    cout << i << endl;
    i--;
    recursionReverseCount(i);//we can also directly plug --i
}

// writing code after the recursion call - it will be called in reverse after the base returns;
void backtrackingCount(int i){ //f(5)
    if(i == 0){
        return;
    }
    backtrackingCount(i - 1);
    cout << i << endl;
}

//=> time O(n) and space O(n)
void backtrackingReverseCount(int n,int i){
    if(i > n){
        return;
    }
    backtrackingReverseCount(n, i + 1);
    cout << i << " ";
}

//functional way of recursion : n = 3 summation = 3+2+1 => time O(n) and space O(n)
int summation(int n){
     if(n == 1){
         return 1;
     }
     return n + summation(n - 1);
}
//factorial of n = n * (n - 1) * (n - 2) * .....1  ==> time O(n) and space O(n)
int factorial(int n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

//two pointer approach l = 0 and r = arr size - 1
void reverseArray(int l, int r, int arr[])
{
    if(l >= r){
        //we reached mid - no more swap
        return;
    }
    swap(arr[l], arr[r]);
    reverseArray(l + 1, r - 1, arr); //left move to right and right move to left
}

//using just index - becuase last index is count - currentIndex - 1 
void reverseArraySingleIndex(int i, int size, int arr[]){
    if(i >= size/2){
        //we reached mid of arr
        return;
    }
    swap(arr[i], arr[size - i - 1]);//last index is alway size - i - 1 ex. (5 - 0 - 1) => 4
    reverseArraySingleIndex(i + 1, size, arr);
}

bool isStringPalindrome(int i, string& s){
    if(i >= s.size()/2){
        return true;//we are at end and found no mismatch
    }
    if(s[i] != s[s.size() - i - 1]){
        //mismatch found
        return false;
    }
    //check next
    isStringPalindrome(i + 1, s);
}

//Multiple recursion calls - fabinacci sequence - find the nth fibnanci number
int fabinacciSeq(int n){
    if(n <= 1){
        return n;//0th febanacci is zero and 1st is one - here we are considering zero as zeroth 
    }
    int last = fabinacciSeq(n - 1); //will call and wait till return
    int secondLast = fabinacciSeq(n - 2);//will call and then wait till return
    return last + secondLast;            //complexity O(2^n) - each call will have 2 more calls
}

//HASHING
//here we assume that maximum possible element in an array can be 12
int hasharr[12] = {0};//
//hashing - frequency count - copy the code in main to make it work for multiple queries
void precomputeWithHashing(int arr[], int n){
    //we use index for the number - and it value as its frequency
    for (int i = 0; i < n; i++){
        hasharr[arr[i]]++; //increase count we find number in arr
    }
}
int findNumberCount(int x){
    return hasharr[x];//O(1) constant time access
}

int charHashArr[26] = {0}; // assumption only small case letter from a-z (total 26)
void precomputeCharHashArr(string s){
    for (int i = 0; i < s.size(); i++){
        charHashArr[s[i] - 'a']++;// ascii magic - value of a is 65 it is considered as zero b - a = 1 and c - a = 2 ..so on 
    }
}

int findAlphabetFrequency(char c){
    return charHashArr[c - 'a'];//again ascii value based - auto convert to int
}

int allcharHash[256] = {0};//when string can contain any alphabet or symbol etc they need to be ascii
void precomputeAllChar(string s){
    for (int i = 0; i < s.size(); i++){
        allcharHash[s[i]]++;//here we just use ascci value directly because array has that size
    }
}

int findAnyCharFrequency(char x){
    return allcharHash[x];//arr support all ascii values
}

//hashing using map => max array size possible is about 10^6 so we use inbuilt map which can handle larger data set
map<int, int> numberMap; //use unordered_map for O(1) add and find 
void precomputeNumberMap(int arr[], int n){
    for (int i = 0; i < n; i++){
        numberMap[arr[i]]++;//int is key - and value is increase => map will manage order of keys
    }
}

int findNumberMap(int x){
    return numberMap[x];//since map are ordered time complexity is nlog(n)
}

//Fastest = hasing using unordered_map -> time complexity O(1) [average and best case]
//rarely in worst case - we have O(n) -> in case of collisions [when same hash index is occupied by many entries]
unordered_map<int, int> fastNumberMap; //use <char, int> for character map
void precomputeFastMap(int arr[], int n){
    for (int i = 0; i < n; i++){
        fastNumberMap[arr[i]]++;//key is number - freqency value
    }
}

int findFastMap(int x){
    return fastNumberMap[x];//O(1) is most cases
}
//to find element with highest or lowest freq - do either linear search or reverse map to make frequency to element map

//SORTING
//selection sort - find the minumum index at each index - swap it - and move from 0 to n - 2 
//3 4 2 1 7 => 1 4 2 3 7 => 1 2 4 3 7 => 1 2 3 4 7 => 1 2 3 4 7
//^     ^        ^ ^            ^ ^            ^ ^     RESULT
void selection_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){ //we dont need last element
        int min = i;
        //find min from remaining next element
        for (int j = i; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    //complexity => O(n^2) for all cases
}

//Bubble Sort - best case (already sorted arr) => O(n)
// average and work case => O(n^2)
void bubble_sort(int arr[], int n){
    int didSwap = 0;
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
    }
    //if we have already sorted array we can check it in one loop => no swap will happen
}

//Find right position for each element 
// 3 2 4 1 
// 2 3 4 1 // [0, 1] comp
// 2 3 4 1 //[0,1], [1,2] comp => no swap
// 2 3 4 1 //[0,1],[1,2] [2,3] comp=> swap till 1 reaches front (arr[2] > arr[3]) -> arr[1] > arr[2] -> arr[1] > arr[0]
// 1 2 3 4
void insertion_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int j = i;
        while(arr[j - 1] > arr[j] && j > 0){
            swap(arr[j - 1], arr[j]);//move to right
            j--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
