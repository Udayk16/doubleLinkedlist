#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* prev;
    node* next;
    node(int val){
        prev=nullptr;
        next=nullptr;
        this->val=val;
    }
};
class linkedlist{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=nullptr;
        tail=nullptr;
    }
    void insert(int val){
        if (head==nullptr){
            node* new_=new node(val);
            head=new_;
            tail=new_;
            return;
        }
        node* current= head;
        node* temp=head;
        node* before=nullptr;
        while(temp->next!=NULL){
            temp=current->next;
            temp->prev=current;
            current->prev=before;
            before=current;
            current=temp;
        }
        tail=new node(val);
        temp->next=tail;
        tail->prev=temp;
        return;
    }
    
    void display(){
        node* temp= head;
        if(head==nullptr){
            return;
        }
        while(temp!=nullptr){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
        cout<<"null\n";
        return;
    }
    void revDisplay(){
        cout<<"displaying list in reverse: \n";
        node* temp=tail;
        if(tail==nullptr){
            return;
        }
        while(temp!=nullptr){
            cout<<temp->val<<"->";
            temp=temp->prev;
        }
        cout<<"null\n";
        return;
        
    }
    int  len(){
         node* temp=head;
         int c=0;
         while(temp){
            temp=temp->next;
            c++;
         }
         return c;
    }
    void insertAt(int k,int val){
         cout<<"inserting a element at "<<k<<" position"<<endl;
        int l=len();
       if(k>l){
        return;
        }
        if(head==nullptr){
            return;
        }
        if (k==1){
            node* temp2=new node(val);
            temp2->next=head;
            head=temp2;
            return;
        }
        node* temp=head;
        int c=0;
        while(c<k-1){
            temp=temp->next;
            c++;
        }
       
        node* prev=temp->prev;
        node* new_node=new node(val);
        new_node->next=temp;
        new_node->prev=prev;
        prev->next=new_node;
        temp->prev=new_node;
        return;
    }
    void deleteHead(){ 
        if(head==nullptr){
            return; 
          }
        if(head->next==nullptr){
            delete head;
            head=NULL;
            tail=NULL;
        }
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        cout<<"delteing head\n";
        return;
        
    }
    void deleteTail()
    {
        if (tail==nullptr){
            return;
            }
        if (tail->prev==nullptr){

            return;
        }
        node* temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        return;
    }
    void deleteAt(int k){
        if (head==NULL && tail==nullptr){
            return;
        }
        if(k>len ()&& k==0){
            return;
        }
        if(k==1){
            deleteHead();
            return;
        }
        if(k==len()){
            deleteTail();
            return;
        }
        node* temp=head;
        int c=1;
        while(c<k){
            temp=temp->next;
            c++;
        }
        node* before=temp->prev;
        node* after=temp->next;
        before->next=after;
        after->prev=before;
        delete temp;
        return;
    }

};
int main(){
    linkedlist ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4);
    ll1.insert(5);
    ll1.insert(6);
    ll1.insert(7);
    ll1.insert(8);
    ll1.insert(9);
    ll1.display();
    ll1.insertAt(1,10);
    ll1.display();
    ll1.deleteHead();
    ll1.display();
    ll1.deleteTail();
    ll1.display();
    ll1.deleteAt(3);
    ll1.display();

    return 0;
    while(ll1.head){
        node* temp=ll1.head;
        ll1.head=ll1.head->next;
        delete temp;
    }
}