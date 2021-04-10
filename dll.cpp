#include<iostream>
using namespace std;

struct node
{
    struct node *prev, *next;
    int data;
}*head=NULL;

void create()
{
    struct node *nn;
    nn=new node;
    cout<<"\n Enter data \n";
    cin>>nn->data;
    nn->next=NULL;
    nn->prev=NULL;
    if(head==NULL)
    {
        head=nn;
    }
    else
    {   struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
    
}

void insert_begin()
{
    struct node *nn;
    nn= new node;
    cout<<"\n Enter data \n";
    cin>>nn->data;
    nn->next=NULL;
    nn->prev=NULL;
    head->prev=nn;
    nn->next=head;
    head=nn;  
}

void insert_pos()
{   int pos;
    cout<<"\n Enter position : ";
    cin>>pos;

    struct node *nn,*temp=head;
    nn=new node;
    cout<<"\n Enter data \n";
    cin>>nn->data;
    nn->next=NULL;
    nn->prev=NULL;
    
    pos--;
    while(pos-1)
    {
        temp=temp->next;
        pos--;
    }
    nn->next=temp->next;
    nn->prev=temp;
    temp->next->prev=nn;
    temp->next=nn;


}

void insert_end()
{
    struct node *nn,*temp=head;
    nn=new node;
    cout<<"\n Enter data \n";
    cin>>nn->data;
    nn->next=NULL;
    nn->prev=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
    nn->prev=temp;
}

void delete_begin()
{
    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete(temp);
    
}

void delete_pos()
{
    int pos;
    cout<<"\n Enter position : ";
    cin>>pos;
    pos--;
    struct node *t,*temp=head; 
    while(pos)
    {
        t=temp;
        temp=temp->next;
        pos--;
    }
    temp->next->prev=t;
    t->next=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
    delete(temp);
}

void delete_end()
{
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    delete(temp);
}

void reverse_dll()
{
    struct node *temp=head,*val;
    
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        val=temp->next;
        temp->next=temp->prev;
        temp->prev=val;
        

    }
    head=temp;
}
    

int main()
{
    create();
    display();
    insert_begin();
    display();
    insert_pos();
    display();
    insert_end();
    insert_end();
    insert_end();
    display();
    delete_begin();
    display();
    delete_pos();
    display();
    delete_end();
    display();
    reverse_dll();
    display();

}