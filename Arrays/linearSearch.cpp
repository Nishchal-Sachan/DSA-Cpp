#include <iostream>
using namespace std;

int linearSearch(int arr[],int size, int key){
    for (int i=0;i<size;i++){
        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]= {4,2,7,8,1,2,5};
    int key = 8;
    
    int s= linearSearch(arr,7,key);
    if (s==-1){
        cout << "key not found!"<<endl;
    }else{
        cout << "key found at index: "<<s; 
    }
    return 0;
}