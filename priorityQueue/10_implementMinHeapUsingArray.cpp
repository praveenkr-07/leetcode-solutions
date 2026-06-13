#include<iostream>
using namespace std;
class MinHeap{
    public :
    int arr[50];
    int idx ;

    MinHeap(){
        idx = 1;
    }
    int top(){
        if(idx==1) {
            cout<<"Heap is empty !!"<<endl;
            return -1;
        }
        return arr[1];
    }

    void push(int x){
        arr[idx] = x;
        int i = idx;
        idx++;
        while(i != 1){
            int parent = i/2;
            if(arr[i] < arr[parent]) {
                swap(arr[i],arr[parent]); 
                i = parent;
            }
            else break;
        }
    }
    int size() {
        return idx-1;
    }

    void pop(){
        if(idx==1) {
            cout<<"Heap is empty !!"<<endl;
            return ;
        }
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while(true){
            int left = 2*i , right = 2*i +1;
            if(left > idx-1) break;
            if(right > idx-1){
                if(arr[i]>arr[left])
                { swap(arr[left],arr[i]);
                    i = left;
                }
                break;
            }
            if(arr[left] < arr[right]){
                if(arr[i]>arr[left])
                { swap(arr[left],arr[i]);
                    i = left;
                }
                else break;
            }
            else{
                if(arr[i]>arr[right])
                { swap(arr[right],arr[i]);
                    i = right;
                }
                else break;
            }
        }
        
    }
    void display(){
        for(int i = 1 ; i<=idx-1;i++){
            cout<< arr[i] <<" ";
        }
        
        cout<<endl;
    }

};
int main(){
    MinHeap pq ;
    pq.push(10);
    pq.push(20);
    pq.push(11);
    pq.push(1);
    pq.push(22);
    pq.push(0);
    pq.push(-1);
    pq.push(14);
    pq.push(2);
    cout<<pq.size()<<" "<<pq.top()<<" "<<endl;
    pq.display();
    pq.pop();
    cout<<pq.size()<<" "<<pq.top()<<" "<<endl;
    pq.display();
    pq.pop();
    cout<<pq.size()<<" "<<pq.top()<<" "<<endl;
    pq.display();
}