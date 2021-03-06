#include"huffBinaryTreeNode.h"
//Binary Tree nodes are also of the type huffObject. For the nodes with no valid characters.
//i.e all the intermediary nodes will have their characters as the null characters.

//algorithm: first, select top two from the minPriorityQ, add them to the binary tree with the root being a node whose freq member has the value
//equal to the sum of the two child nodes; now again when we select two min nodes we also consider the new parent node formed in the first step
//and so on till our minPriorityQ is not empty.

class huffBinaryTree
{
    public:
    vector <huffBinaryTreeNode *> rootVector;
    bool case3(object obj1, object obj2)
    {
        bool ans1=false,ans2=false;
        for(int i=0; i<rootVector.size(); i++)
        {
            if(rootVector.at(i)->data.freq==obj1.freq && rootVector.at(i)->data.key=='\0')
            {
                ans1=true;
            }
            if(rootVector.at(i)->data.freq==obj2.freq && rootVector.at(i)->data.key=='\0')
            {
                ans2=true;
            }
        }
        return ans1&&ans2;
    }

    bool case1OR2(object obj)
    {
        for(int i=0; i<rootVector.size(); i++)
        {

            if(rootVector.at(i)->data.freq==obj.freq && rootVector.at(i)->data.key=='\0')
            {
                return false;
            }
        }
        return true;
    }

    int returnIndexPosition(object obj)
    {

        for(int i=0; i<rootVector.size(); i++)
        {
            if(rootVector.at(i)->data.freq==obj.freq && rootVector.at(i)->data.key=='\0')
            {
                return i;
            }
        }
    }


        huffBinaryTreeNode * insertToHuffBinaryTree(object obj1, object obj2 )
        {

            //check k jo do objects insert hone aaye hain kya unme se koi bhi already tree mein  hai?
            //case 1: dono hi nahi hain: then make two binary tree nodes, unse ek naya root aayega and push it into the root vector.
            //hence, we are maintaing multiple roots for a single binary tree at a particular instance.
            //case 2: ek ho ek na ho: then create one binary tree node and rempve the existing root from the vector and insert the new one.
            //case 3: dono hon: to simply create the new rootnode and push it while removing the previous two roots from the vector.

            //case1 and empty case
            if(rootVector.size()==0 || (case1OR2(obj1) && case1OR2(obj2)))
            {
                cout<<"CASE-ONE"<<endl;
                huffBinaryTreeNode * newNode1 = new huffBinaryTreeNode(obj1);
                huffBinaryTreeNode  * newNode2 = new huffBinaryTreeNode (obj2);

                object rootObj;
                rootObj.freq = obj1.freq + obj2.freq;
                rootObj.key = '\0';

                huffBinaryTreeNode  * rootNode = new huffBinaryTreeNode (rootObj,newNode1,newNode2);
                rootVector.push_back(rootNode);
                return rootNode;
            }
            //case3
            else if(case3(obj1,obj2))
            {
cout<<"CASE-THREE"<<endl;
                object rootObj;
                rootObj.freq = obj1.freq + obj2.freq;
                rootObj.key = '\0';
                huffBinaryTreeNode  * rootNode = new huffBinaryTreeNode (rootObj);

                int pos1 =  returnIndexPosition(obj1);
                int pos2 =  returnIndexPosition(obj2);

                huffBinaryTreeNode  * leftobj = rootVector.at(pos1);
                huffBinaryTreeNode  * rightobj = rootVector.at(pos2);
                rootNode->left=leftobj;
                rootNode->right = rightobj;


                rootVector.push_back(rootNode);
                rootVector.erase(rootVector.begin()+pos1);
                //cout<<"imfine!!";
                rootVector.erase(rootVector.begin()+pos2);

                return rootNode;

            }

            //case2
            else if(case1OR2(obj1) || case1OR2(obj2))
            {
                //check kaunsa present hai already
                cout<<"CASE-TWO"<<endl;
                bool ans1 = !case1OR2(obj1);
                bool ans2 = !case1OR2(obj2);

                if(ans1==true)
                {
                    huffBinaryTreeNode  * newNode2 = new huffBinaryTreeNode (obj2);
                    object rootObj;
                    rootObj.freq = obj1.freq + obj2.freq;
                    rootObj.key = '\0';
                    huffBinaryTreeNode  * rootNode = new huffBinaryTreeNode (rootObj);
                    int pos1 = returnIndexPosition(obj1);
                    huffBinaryTreeNode  * left = rootVector.at(pos1);
                    rootNode->left=left;
                    rootNode->right = newNode2;
                    rootVector.push_back(rootNode);
                    rootVector.erase(rootVector.begin()+pos1);
                     return rootNode;
                }
               else if(ans2==true){
                    huffBinaryTreeNode  * newNode1 = new huffBinaryTreeNode (obj1);
                    object rootObj;
                    rootObj.freq = obj1.freq + obj2.freq;
                    rootObj.key = '\0';
                    huffBinaryTreeNode  * rootNode = new huffBinaryTreeNode (rootObj);
                    int pos1 = returnIndexPosition(obj2);
                    huffBinaryTreeNode  * left = rootVector.at(pos1);
                    rootNode->left=left;
                    rootNode->right = newNode1;
                     rootVector.push_back(rootNode);
                      rootVector.erase(rootVector.begin()+pos1);
                     return rootNode;


               }
            }
        }

       void printLeafNodes(huffBinaryTreeNode * rootNode){
       if(rootNode->left==NULL && rootNode->right==NULL){
        cout<<rootNode->data.key<<endl;
        return;
       }
       printLeafNodes(rootNode->left);
       printLeafNodes(rootNode->right);

        }


        bool returnCodes(huffBinaryTreeNode * root){
           if(root->left==NULL && root->right==NULL)
           {
               if(root->data.key=='c')
               {
                   return true;
               }
               else{
                return false;
               }
           }


           static string codes="";
          // cout<<"callstack";
           bool lans = returnCodes(root->left);
           bool rans = returnCodes(root->right);

           if(lans==true){
            codes="1"+codes;
            cout<<codes<<"\n";
            return true;
           }
           if(rans==true){
            codes="0"+codes;
            cout<<codes<<"\n";
            return true;
           }

           else{
            return false;
           }

        }





    };













    /*

    class BST{

    	BinaryTreeNode<int>* root;

    	public:
    	BST(){
    		root = NULL;
    	}

    	void insert(int elem){
    		root = insert(root, elem);
    	}

    	BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int elem){

    		if(root == NULL){
    			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(elem);
    			return newNode;
    		}else if(root->data > elem){
    			root->left = insert(root->left, elem);
    		}else{
    			root->right = insert(root->right, elem);
    		}
    		return root;
    	}

    	void deleteData(int elem){
    		root = deleteData(elem);
    	}

    	BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* root, int elem){
    		if(root == NULL){
    			return root;
    		}
    		if(root->data == elem){
    			if(root->left == NULL && root->right == NULL){
    				delete root;
    				return NULL;
    			}else if(root->left == NULL){
    				BinaryTreeNode<int>* temp = root;
    				root = root->right;
    				delete temp;
    				return root;
    			}else if(root->right == NULL){
    				BinaryTreeNode<int>* temp = root;
    				root = root->left;
    				delete temp;
    				return root;
    			}else{
    					BinaryTreeNode<int>* successor = root->right;
    					while(successor->left != NULL){
    						successor = successor->left;
    					}
    					root->data = successor->data;
    					root->right = deleteData(root->right, successor->data);
    					return root;
    			}

    		}else if(root->data < elem){
    			root->right =  deleteData(root->right, elem);
    		}else{
    			root->left = deleteData(root->left, elem);
    		}
    	}

    	bool hasData(int elem){
    		return hasData(root, elem);
    	}

    	private:

    	bool hasData(BinaryTreeNode<int>* root, int elem){

    		if(root == null){
    			return false;
    		}
    		if(root->data == elem){
    			return true;
    		}else if(root->data > elem){
    			return hasData(root->left, elem);
    		}else{
    			return hasData(root->right, elem);
    		}


    	}



    };
    */
