#include"bst.h"



int main()
{
 binary_search_tree obj;
 char choice;
 int no;
 do
   {
     cout<<"enter no. to insert in tree:";
     cin>>no;
     obj.push(no,&obj.root);
     cout<<"want to enter more(y/n):";
     cin>>choice;
   }while(choice=='y'); 

 obj.display(obj.root);

 int item;
 cout<<"\nenter no. to search:-";
 cin>>item;

 obj.search(item,obj.root);

 obj.mirror_image(&obj.root);
 cout<<"\n mirror image of the tree is:-";
 obj.display(obj.root);
 return 0;
}

