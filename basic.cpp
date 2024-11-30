#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printNums(int n){
    if(n == 0) return;
    cout<<n<<" ";
    printNums(n-1);
}
// n!
int factorial(int n){ //TC=> O(n) || SC=> O(n)
    if(n == 0) return 1;
    return n * factorial(n-1);
}
// sum of N numbers
int sumOfN(int n){ //TC=> O(n) || SC=> O(n)
    if(n == 0) return 0;
    return n + sumOfN(n-1);
}
// fibonacci
int fibonacci(int n){ //TC=> O(2^n) || SC=>O(n)
    if(n == 0 || n == 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
// sorted array
bool isSorted(vector<int>& A, int n){ //TC=> O(n) || SC=> O(n)
    if(n == 1 || n == 0) return true;
    return A[n-1] >= A[n-2] && isSorted(A, n-1);
}
// reverse array
void reverseArray(int arr[], int n){ //TC =>O(n) || SC=> O(n)
    if(n == 0 || n == 1){
        return;
    }
    swap(arr[0], arr[n-1]);
    reverseArray(arr+1, n-2);
}
// reverse vector
void reverseVector(vector<int>& v, int st, int end){ //TC=> O(n) || SC=> O(n)
    if(st >= end){ //st = starting || end = ending pointer
        return;
    }
    swap(v[st], v[end]);
    reverseVector(v, st+1, end-1);
}
// remove char from string
string removeChar(string& s, int st){
   int n = s.length();
   if(st >= n) return s;
   if(s[st] == 'x'){
        for(int i = st; i < n-1; i++){
            s[i] = s[i+1];
        }
        s.pop_back(); 
        return removeChar(s, st);
   }
   else{
        return removeChar(s, st+1);
   }
}
//binarySearch 
int binarySearch(vector<int>& A, int target, int st, int end){ //TC=>O(logn) || SC=> O(logn)
    if(st <= end){
        int mid = st + (end - st)/2;
        if(target == A[mid]) return mid;

        else if(target > A[mid]){
        return binarySearch(A, target, mid+1, end);
        }
        else{ //target < A[mid]
            return binarySearch(A, target, st, mid-1);
        }
    }
    return -1; //not found
}
int main(){
    // printNums(10);
    // cout<<factorial(6);
    // cout<<sumOfN(5); //5+4+3+2+1=>15
    // cout<<fibonacci(6); //8
    vector<int>v = {1, 2, 3, 4};
    // cout<<isSorted(v, 4); // 4 is size of array
    int st = 0, end = v.size() - 1;
    // cout<<binarySearch(v, 40, st, end);
    // int arr[] = {10, 2, 3, 4, 5, 7}, n = 6;
    // reverseArray(arr, n);
    // for(int i = 0 ;i < n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // reverseVector(v, st, end);
    // for(auto i : v){
    //     cout<<i<<" ";
    // }
    // cout<<removeChar(s, st);
    string s = "abcxbdx";
    replace(s.begin(), s.end(), 'x', 'a');
    cout<<s;
    return 0;
}