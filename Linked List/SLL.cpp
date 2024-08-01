#include<bits/stdc++.h>
using namespace std;

// Representation of Singly Linked List

class Node{

    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

// Converts array into LL

Node* convertToLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;

    }

    return head;
}

void printList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}

// Length of LL

int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

// Linear Search in LL

int searchInLL(Node* head, int x){
    Node* temp=head;
    while(temp){
        if(temp->data == x) return 1;
        temp=temp->next;
    }
    return 0;
}

// Delete Head from LL

Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

// Delete Tail from LL

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}

// Delete Kth position element from LL (Range: 1 to N)

Node* deleteK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=NULL;
    int cnt=0;
    

    while(temp != NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}

// Delete Element by Value from LL

Node* deleteEl(Node* head, int el){
    if(head==NULL) return head;
    if(head->data == el){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=NULL;

    while(temp != NULL){
        if(temp->data == el){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}

// Insert at head

Node* insertHead(Node* head, int val){
    Node* temp= new Node(val, head);
    return temp;
}

// Insert at Tail

Node* insertTail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;
}

// Insert at Kth position in LL (Range: 1 to N+1)

Node* insertK(Node* head, int k, int el){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }

    if(k==1){
        return new Node(el,head);
    }

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode= new Node(el, temp->next);
            temp->next=newNode;
            break;
        }

        temp=temp->next;
    }

    return head;
}


// Insert before value in LL

Node* insertBeforeValue(Node* head, int val, int el){
    if(head==NULL){
        return NULL;
    }

    if(head->data == val){
        return new Node(el,head);
    }

    Node* temp=head;
    while(temp!=NULL){
        if(temp->next->data == val){
            Node* newNode= new Node(el, temp->next);
            temp->next=newNode;
            break;
        }

        temp=temp->next;
    }

    return head;
}



int main(){
    vector<int> arr={3, 67, 23, 89, 100};
    Node* head= convertToLL(arr);

    // cout<<"Length of LL is " <<lengthOfLL(head)<< endl;
    // cout<< searchInLL(head, 95)<<endl;

    // head=deleteHead(head);
    // head=deleteTail(head);
    // head=deleteK(head, 4);
    // head= deleteEl(head, 100);

    // head=insertHead(head,56);
    // head=insertTail(head,657);
    // head=insertK(head,5,598);
    // head=insertBeforeValue(head,100,498);
    
    printList(head);

    return 0;
}
