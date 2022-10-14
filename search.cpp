#include<iostream>
#include <chrono>
#include <stdlib.h>
#include<time.h>


int search(int arr[],int find, int step){
    int iter=0;
    while (true){
        if(arr[iter*step]>find)
            iter = (iter-1)*step;
            break;
        iter++;
    }
    for(iter;arr[iter]!=find;iter++){}
    return iter;
}

void insortion(int *arr,int size){
    int hold;
    for(int i=1; i<size;i++){
        if(arr[i]>=arr[i-1]){
            continue;
        }
        hold = arr[i];
        for(int j=i-1;j>=0;j--){
            if(hold<arr[j]){
                arr[j+1]=arr[j];
                if(j==0){
                    arr[0]=hold;
                }
            }
            else{
                arr[j+1]=hold;
                break;
            }

        }
    }
}



int main(){
    //get parameters
    int arr_size=10;
    int max_int_size=10;
    int step_size=10;/*
    std::cout<<"Input Array Size"<<std::endl;
    std::cin>>arr_size;
    std::cout<<"Input Maximum Integer Size"<<std::endl;
    std::cin>>max_int_size;
    std::cout<<"Input Search Step Size"<<std::endl;
    std::cin>>step_size;
*/
//generate list
    srand (time(NULL));
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
        arr[i]=rand() % max_int_size;
    }
    int find = arr[0];
    if(arr_size<=20){
        for(int i=0;i<arr_size;i++){
            std::cout<<arr[i]<< " ";
        }
    }
//print out results
    std::cout<<std::endl;
    auto s1 = std::chrono::high_resolution_clock::now();
    insortion(arr,arr_size);
    auto e1 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(e1 - s1);
    std::cout << std::endl << "Sorting took " << d1.count() << " microseconds"<<std::endl <<std::endl;
    if(arr_size<=20){
        for(int i=0;i<arr_size;i++){
            std::cout<<arr[i]<< " ";
        }
    }

    
    std::cout<<"Find: "<<find<<"..."<<std::endl;
    s1 = std::chrono::high_resolution_clock::now();
    int index= search(arr,find,step_size);
    e1 = std::chrono::high_resolution_clock::now();
    d1 = std::chrono::duration_cast<std::chrono::microseconds>(e1 - s1);
    std::cout << "Finding took " << d1.count() << " microseconds with step size " << step_size << std::endl;
    std::cout<<"Found: "<<arr[index]<<" found at index: "<<index<<std::endl;
    return 0;
}