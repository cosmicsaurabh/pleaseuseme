// two ways iterative and recursive
//  iterative way
#include<iostream>
using namespace std;
class node{
public:
int data;
node* next;
// constructor

node(int val){
    data=val;
    next=NULL;
}
};
void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
// here we are taking by refrence bcs we want to modify our linked list
void insertAtTail(node * &head,int val){

    node* n=new node(val);
    if (head==NULL){
        head=n;
        return;
    }

    node * temp=head;
    while (temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
}

void display(node * head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool search(node* head, int x)
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}
void deletion(node* &head,int val){

    node* temp=head;
    if (head->data==val)
        head=head->next;
    if(head==NULL)
        return;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
//#########################################################################
//reverse by iterrative
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
//##############################################################################
//  reverse by recursion
node* reverseRecur(node* &head){
    if(head==NULL || head->next==NULL){
        return head;

    }

    node* newhead=reverseRecur(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,44);
    display(head);
    // deletion(head,3);
    // display(head);
    // cout<<search(head,5)<<endl;
    node* newhead=reverse(head);
    display(newhead);
    // node* newhead=reverseRecur(head);
    // display(newhead);

    // reverse(head);
    // head.reverse()
    // display(head);
    return 0;
};
