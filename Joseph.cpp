#include <iostream>
#include<math.h>
#include <chrono>
 
int decToN(int n, int *intput_arr,int k=2)
{
    // array to store nBase number
    int nBase[32];
 
    // size counter for binary array
    int size = 0;
    while (n > 0) {
 
        // storing remainder in nBase array
        nBase[size] = n % k;
        n = n / k;
        size++;
    }
    // printing binary array in reverse order
    int i=0;
    for (int j = size - 1; j >= 0; j--){
        intput_arr[i] = nBase[j];
        i++;
    }
    return size;
}

int ntoDec(int *input_arr, int k, int size){
    int decimal = 0;
    for(int i = size-1; i>=0;i--){
        decimal = decimal + (input_arr[i] * pow(k,size-i-1));
        //std::cout<<input_arr[i]<<" "<<decimal<<std::endl;
    }
    return decimal;
}

int josephus(int n, int k=2){
    if(k==1 || k==0){
        return 0;
    }
    int nBase[32];
    int size = decToN(n, nBase, k);
    nBase[size]=nBase[0];
    for(int i=0; i<size;i++){
        nBase[i]=nBase[i+1];
    }
    return ntoDec(nBase,k,size);
}
#include <bits/stdc++.h>
using namespace std;
 
// Recursive function to implement the Josephus problem
int josephus_true(int n, int k)
{
    int answer;
    if (n == 1)
        return 1;
    else
        // The position returned by josephus(n - 1, k)
        // is adjusted because the recursive call
        // josephus(n - 1, k) considers the
        // original position k % n + 1 as position 1
        answer = (josephus_true(n - 1, k) + k - 1) % n + 1;
        //std::cout<<n<<" "<<answer<<std::endl;
        return answer;
}
// This code is contributed by shubhamsingh10

int main()
{
    int n = 10000;
    int k=3;
    std::cout<<"n="<<n<<" k="<<k<<std::endl;
    auto s1 = std::chrono::high_resolution_clock::now();
    std::cout << "solution: " << josephus_true(n,k)<<std::endl;
    auto e1 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(e1 - s1);
    std::cout<<"solution took "<<d1.count()<<" microseconds"<<std::endl;
    return 0;
}