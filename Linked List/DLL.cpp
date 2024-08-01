#include<bits/stdc++.h>
using namespace std;

// Representation of Doubly Linked List.

class Node{

    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};

// Convert array into DLL

Node* convertToDLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }

    return head;
}

// Print DLL

void printDLL(Node* head){
    while(head!=NULL){
        cout<< head->data<< " ";
        head=head->next;
    }
}

// Delete Head of DLL

Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;

    return head;
}

// Delete Tail of DLL

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    while(prev->next!=NULL){
        prev=prev->next;
    }

    prev->back->next=nullptr;
    prev->back=nullptr;
    delete prev;

    return head;  
}

// Delete Kth Element from DLL (Range: 1 to K)

Node* deleteKthElement(Node* head, int k){
    if(head==NULL) return NULL;
    Node* temp=head;
    int cnt=0;

    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }

    Node* prev= temp->back;
    Node* front= temp->next;

    if(prev==NULL && front==NULL){
        delete temp;
        return nullptr;
    }
    else if(prev==NULL){
        head=deleteHead(head);
        return head;
    }
    else if(front==NULL){
        head=deleteTail(head);
        return head;
    }

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;

    return head;
}

// Delete Kth Element by Value from DLL

Node* deleteEl(Node* head, int val){
    if(head==NULL) return NULL;
    Node* temp=head;

    while(temp!=NULL){
        if(temp->data == val){
            break;
        }
        
        temp=temp->next;
    }

    Node* prev= temp->back;
    Node* front= temp->next;

    if(prev==NULL && front==NULL){
        delete temp;
        return nullptr;
    }
    else if(prev==NULL){
        head=deleteHead(head);
        return head;
    }
    else if(front==NULL){
        head=deleteTail(head);
        return head;
    }

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;

    return head;
}

// Insert before Head in DLL

Node* insertHead(Node* head, int val){
    Node* newHead= new Node(val, head, nullptr);
    head->back=newHead;

    return newHead;
}

// Insert before Tail in DLL

Node* insertBeforeTail(Node* head, int val){
    if(head->next==NULL){
        return insertHead(head, val);
    }
    Node* tail=head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    Node* prev= tail->back;
    Node* newNode= new Node(val, tail, prev);
    prev->next=newNode;
    tail->back=newNode;

    return head;
}

// Insert before Kth Element in DLL (Range: 1 to K)

Node* insertBeforeKthEle(Node* head, int val, int k){
    if(head->next==NULL || k==1){
        return insertHead(head, val);
    }

    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }

    if(temp->next==NULL){
        return insertBeforeTail(head, val);
    }

    Node* prev= temp->back;
    Node* newNode= new Node(val, temp, prev);
    prev->next=newNode;
    temp->back=newNode;

    return head;
}


int main(){
    vector<int> arr= {23,45,76,19,34,78};
    Node* head= convertToDLL(arr);

    // head= deleteHead(head);
    // head= deleteTail(head);
    // head= deleteKthElement(head, 3);
    // head= deleteEl(head, 19);

    // head= insertHead(head,876);
    // head= insertBeforeTail(head, 97);
    // head= insertBeforeKthEle(head, 243, 5);


    printDLL(head);

    return 0;
}