#include<iostream>
#include<map>
#include<string>
#include<vector>
#include "huffPriorityQ.h"
#include"huffBinaryTree.h"
using namespace std;

//hash map between the character and its frequency in the file.
//initially all the entries are 0.
void initMap(map<char,int> & alphaMap){
 for(int i=0;i<127;i++)
    {
        alphaMap[char(i)] = 0;
    }
}

 //traversing over the file and filling the map.
void fillMap(map<char,int> & alphaMap, string file){
 for(int i=0;i<file.length();i++)
    {
        char current = file[i];
        alphaMap[current]+=1;
    }
}

//inserting in the min priority queue.
void makeMinPQ(map<char,int> & alphaMap , huffPriorityQ & minQueue){
for(int i=0;i<127;i++)
    {
        object temp;
        temp.key =  char (i);
        temp.freq = alphaMap.at(temp.key);

        if(temp.freq!=0){
          minQueue.insertPQ(temp);
      }
    }
}

int main()
{

string file="abcde";
map<char,int> alphaMap;
initMap(alphaMap);
fillMap(alphaMap,file);
huffPriorityQ minQueue;
makeMinPQ(alphaMap,minQueue);

huffBinaryTree HBT;
huffBinaryTreeNode * root;
while(1){
     object obj1 = minQueue.removeMin();
     object obj2 = minQueue.removeMin();
     root = HBT.insertToHuffBinaryTree(obj1,obj2);
     if(minQueue.heapSize()==0){
         minQueue.insertPQ(root->data);
         break;
     }
     minQueue.insertPQ(root->data);
     /*cout<<root->data.key<<'\t'<<root->data.freq<<'\n';
     cout<<"left:"<<root->left->data.key<<'\n';
     cout<<"right:"<<root->right->data.key<<'\n';*/
}

HBT.printLeafNodes(root);
}
 /*  string file="aasdfgsderaa";

    //hash map between the character and its frequency in the file.
    //initially all the entries are 0.
    map<char,int> alphaMap;
    initMap(alphaMap);

    //traversing over the file and filling the map.
    fillMap(alphaMap, file);

     //inserting in the min priority queue.
    huffPriorityQ minQueue;
    makeMinPQ(alphaMap,minQueue);
//taking out of minQueue.
    huffBinaryTree HBT;
 huffBinaryTreeNode * root;
    while(1){
         object obj1 = minQueue.removeMin();
         object obj2 = minQueue.removeMin();
         root = HBT.insertToHuffBinaryTree(obj1,obj2);
         if(minQueue.heapSize()==0)
         {
             minQueue.insertPQ(root->data);
             cout<<root->data.key<<root->data.freq;
             cout<<HBT.rootVector.size()<<endl;
             break;
         }
         minQueue.insertPQ(root->data);
         cout<<root->data.key<<root->data.freq<<endl;
         cout<<HBT.rootVector.size()<<endl;

         for(int i=0;i<HBT.rootVector.size();i++){
            cout<<"root:"<<HBT.rootVector.at(i)->data.freq<<endl;
            cout<<"left:"<<HBT.rootVector.at(i)->left->data.key<<endl;
            cout<<"right:"<<HBT.rootVector.at(i)->right->data.key<<endl;
         }

       // cout<<temp.key<<endl<<temp.freq;

         }
//cout<<root->data.key<<endl<<root->data.freq;
HBT.printLeafNodes(root);

       /* cout<<root->data.freq<<endl;
    cout<< root->left->data.freq;
    cout<< root->right->data.freq;*/


