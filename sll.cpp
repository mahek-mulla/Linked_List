#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head=NULL;

void reverse_sll()
{
    struct node *temp=NULL, *temp2=NULL;
    while(head!=NULL)
    {
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
}

void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"Linked list is empty";
    }
    while(temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
}

void insert_begin()
{
    struct node *nn;
    nn=new node;
    cout<<"\nEnter data: ";
    cin>>nn->data;
    nn->next=NULL;
    nn->next=head;
    head=nn;
}

void insert_end()
{
    struct node *nn,*temp;
    nn=new node;
    cout<<"\nEnter data: ";
    cin>>nn->data;
    nn->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    { temp=temp->next;
    }
    temp->next=nn;
}

void insert_position()
{
    struct node *nn,*temp;
    temp=head;
    int pos;
    cout<<"\n Enter position : ";
    cin>>pos;
    nn=new node;
    cout<<"\nEnter data: ";
    cin>>nn->data;
    pos--;      //we have to point a position before
    while(pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    nn->next=temp->next;
    temp->next=nn;

}

void delete_begin()
{
    if(head==NULL)
    {
        cout<<"\n List is already empty \n";
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    
}

void delete_end()
{   if(head==NULL)
    {
        cout<<"\n List is already empty \n";
    }
    else if(head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    else{
    struct node *t,*temp;
    temp=head;
    while(temp->next!=NULL)
    {
        t=temp;
        temp=temp->next;
    }
    t->next=NULL;
    delete(temp);
    }
}


void delete_end_single_pointer()
{
    if(head==NULL)
    {
        cout<<"\n List is already empty \n";
    }
    else if(head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    else{
    struct node *temp;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    }
}

void delete_pos()
{
    struct node *t,*temp=head;
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

void delete_sll()
{
    struct node *temp=head;
    while(temp!=NULL)
    {   temp=temp->next;
        delete(head);
        head=temp;
        
    }

}



int main()
{   struct node *nn;
    nn=new node;
    cout<<"\nEnter data: ";
    cin>>nn->data;
    nn->next=NULL;
    head=nn;
    display();
    cout<<"\n Insert begin \n";
    insert_begin();
    display();
    cout<<"\n Insert end \n";
    insert_end();
    insert_end();
    insert_end();
    
    display();
    cout<<"\n Insert at a position \n";
    insert_position();
    display();
    cout<<"\n Delete begin \n";
    delete_begin();
    display();
    cout<<"\n Delete end \n";
    delete_end();
    display();
    cout<<"\n Delete at a position \n";
    delete_pos();
    display();

    cout<<"\n Reverse : \n";
    reverse_sll();
    display();

    cout<<"\n Delete \n";
    delete_sll();
    display();
    return 0;

}
