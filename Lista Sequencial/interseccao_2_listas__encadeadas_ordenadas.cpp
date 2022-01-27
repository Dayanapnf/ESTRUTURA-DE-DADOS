#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

 

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;

}
bool busca(ListNode *head, int value)
{
  if (head == nullptr)
    return false;
  else if (head->val == value)
    return true;
  else
    return busca(head->next, value);
}

ListNode *intersectionList(ListNode *head1, ListNode *head2){
  ListNode *aux = nullptr, *node;
  
    for(ListNode *p = head1; p != nullptr; p = p->next){
        for (ListNode *q = head2; q != nullptr; q = q->next){
            if(busca(head2, p->val)){
                if(aux == nullptr){
                    aux = new ListNode(p->val);
                    node= aux;
                }else{ 
                    if(!busca(aux,p->val)){
                        node->next = new ListNode(p->val,nullptr);
                        node= node->next;
                    }
                }
            }
        }

    }
    return aux;
}

void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}



int main(){
    
    ListNode * head1 = readList();
    ListNode * head2 = readList();
     
    ListNode * res = intersectionList(head1, head2);


    printList(res);

    return 0;    
}
