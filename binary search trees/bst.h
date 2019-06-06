#include<iostream>

using namespace std;

struct node 
{
  int info;
  struct node *left;
  struct node *right;
};

typedef struct node node;

class binary_search_tree
{
  public:
          node *root,*ptr;
  public:
         binary_search_tree();
         void push(int,node**);
         node* create_new_node(int);
         //node* pop();
         void search(int,node*);
         void mirror_image(node**);
         int smallest(node *);
         int largest(node *);
         void display(node *);

};

binary_search_tree::binary_search_tree()
{
  root=NULL;
}


void binary_search_tree::push(int I,node* *temp)
{
  if(root==NULL)
     {
       root=create_new_node(I);
     }
  else
     {
       if((*temp)->info>I)
         {
           if((*temp)->left==NULL)
              (*temp)->left=create_new_node(I);
           else
              push(I,&(*temp)->left);
         }

       else if((*temp)->info<I)
        {
           if((*temp)->right==NULL)
              (*temp)->right=create_new_node(I);
           else
              push(I,&(*temp)->right);
        }
     }
 
}



node* binary_search_tree::create_new_node(int I)
{
    node *temp=new node();
    temp->info=I;
    temp->left=temp->right=NULL;
    return temp;
}


void binary_search_tree::display(node *temp)
{
   if(temp!=NULL)
      {
         display(temp->left);
         cout<<temp->info<<" ";
         display(temp->right);         
      } 

}


void binary_search_tree::search(int item,node *temp)
{
 if(temp!=NULL) 
   if(temp->info==item)
        cout<<"item found";
   else if(temp->info>item)
          search(item,temp->left);
        else
          search(item,temp->right);
}


int binary_search_tree::largest(node *temp)
{
  if(temp->right!=NULL)
     largest(temp->right);
  return temp->info;
}


int binary_search_tree::smallest(node *temp)
{
  if(temp->left!=NULL)
     largest(temp->left);
  return temp->info;
}


void binary_search_tree::mirror_image(node* *temp)
{
  if (*(temp)!=NULL)
    {
      mirror_image(&(*temp)->left);
      mirror_image(&(*temp)->right);
      node *temp_addr;
      temp_addr=(*temp)->left;
      (*temp)->left=(*temp)->right;
      (*temp)->right=temp_addr;
       
    }
}

