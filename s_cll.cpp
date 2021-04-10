#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*tail=NULL;

void create()
{
    struct node *nn;
    nn=new node;
    cout<<"\n Enter data : ";
    cin>>nn->data;
    nn->next=NULL;
    
    tail=nn;
    nn->next=tail;
    
    
}

void display()
{
    struct node *temp=tail->next;
    
    do
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    } while (temp!=tail->next);
    cout<<"\n";
    
}

void insert_begin()
{
    struct node *nn;
    nn=new node;
    cout<<"\n Enter data : ";
    cin>>nn->data;
    nn->next=NULL;
    nn->next=tail->next;
    tail->next=nn;
    

}

void insert_end()
{
    struct node *nn;
    nn=new node;
    cout<<"\n Enter data : ";
    cin>>nn->data;
    nn->next=NULL;
    nn->next=tail->next;
    tail->next=nn;
    tail=nn;
}


void insert_pos()
{
    struct node *nn,*temp=tail;
    int pos;
    cout<<"\n Enter position : ";
    cin>>pos;
    nn=new node;
    cout<<"\n Enter data : ";
    cin>>nn->data;
    nn->next=NULL;  
    pos--;
    while(pos--)
    {
        temp=temp->next;
    } 
    if(temp==tail)
    {
        insert_end();
    }
    else{
        nn->next=temp->next;
        temp->next=nn;
    }
    
}

void delete_begin()
{
    struct node *temp=tail->next;

    tail->next=temp->next;
    temp->next=NULL;
    delete(temp);
    
}

void delete_end()
{
   struct node *temp=tail->next;
   while(temp->next!=tail) 
   {
       temp=temp->next;
   }
   temp->next=tail->next;
   tail->next=NULL;
   delete(tail);
   tail=temp;
}

void delete_pos()
{
    struct node *t,*temp=tail->next;
    int pos;
    cout<<"\n Enter position : ";
    cin>>pos;
    while(pos!=1)
    {   t=temp;
        temp=temp->next;
        pos--;
    }
    t->next=temp->next;
    temp->next=NULL;
    delete(temp);
}




int main()
{
    create();
    insert_begin();
    insert_end();
    insert_end();
    insert_end();
    insert_end();
    display();
    insert_pos();
    display();
    delete_begin();
    display();
    delete_end();
    display();
    delete_pos();
    display();
}