//#include "huffObject.h"
class huffBinaryTreeNode{
public:
   object data;
   huffBinaryTreeNode * left;
   huffBinaryTreeNode * right;
   char lbit='0';
   char rbit='1';

   huffBinaryTreeNode(object obj){
   data.freq = obj.freq;
   data.key = obj.key;
   left=NULL;
   right=NULL;
   }

   huffBinaryTreeNode(object obj, huffBinaryTreeNode* l, huffBinaryTreeNode* r){
   data.freq = obj.freq;
   data.key = obj.key;
   left = l;
   right = r;
   }
};
