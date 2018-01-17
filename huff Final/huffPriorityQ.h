#include<vector>
#include<stdlib.h>
#include"huffObject.h"
using namespace std;



class huffPriorityQ
{
public:
    vector <object> heap;


    int heapSize()
    {
        return heap.size();
    }
    bool isEmpty()
    {
        return heap.size() == 0;
    }

    object minObject()
    {
        if(heap.size() == 0)
        {
            object nullobj;
            nullobj.freq = -1;
            nullobj.key = '\0';
            return nullobj;
        }
        return heap[0];
    }

    void insertPQ(object elem)
    {
        heap.push_back(elem);
        int childIndex = heap.size()-1;
        int parentIndex = (childIndex-1)/2;

        while(parentIndex>=0){
            if(heap[childIndex].freq < heap[parentIndex].freq){
                object temp;
                temp.freq =heap[childIndex].freq;
                temp.key =heap[childIndex].key;
                heap[childIndex].freq = heap[parentIndex].freq;
                heap[childIndex].key = heap[parentIndex].key;
                heap[parentIndex].freq = temp.freq;
                heap[parentIndex].key = temp.key;
                childIndex =   (int)  parentIndex;
                parentIndex = (childIndex - 1) / 2;
            }
            else{
                break;
            }
        }
    }

    object removeMin(){

    object temp = heap.at(0);
    heap[0].freq= heap.at(heap.size()-1).freq;
    heap[0].key=heap.at(heap.size()-1).key;
    heap.pop_back();

    if(heap.size()>1){
        downHeapify(0);
    }
    return temp;

    }

    void showHeap(){
        cout<<"heap:"<<'\t';
    for(int i=0;i<heap.size();i++){
        cout<<heap[i].key<<heap[i].freq<<'\t';
    }
    cout<<endl;
    }

private:

     void downHeapify(int index){

     int leftChildIndex = 2*index + 1;
     int rightChildIndex = leftChildIndex +1;

     if(leftChildIndex >= heap.size()){
        return;
     }
     int minIndex = leftChildIndex;
     if(rightChildIndex < heap.size() &&
                heap[rightChildIndex].freq < heap[minIndex].freq){

              minIndex = rightChildIndex;
     }
   /* if(rightChildIndex < heap.size() && heap[leftChildIndex].freq < heap[rightChildIndex].freq){
        minIndex = leftChildIndex;
     }*/

     if(minIndex != index){
        object temp;
        temp.freq = heap[minIndex].freq;
        temp.key = heap[minIndex].key;
        heap[minIndex].freq = heap[index].freq;
        heap[minIndex].key = heap[index].key;
        heap[index].freq = temp.freq;
        heap[index].key = temp.key;
        downHeapify(minIndex);

     }

     }


};

