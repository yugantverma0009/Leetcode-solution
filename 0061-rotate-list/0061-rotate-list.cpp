/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* current=head;
        int count=0;
       
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==0) return NULL;
        if(count==1) return head;
        k=k%count;
        if(k==0) return head;
        count=count-k;
        while(count--){
            prev=current;
            current=current->next;
        }
        prev->next=NULL;
        temp=current;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head=current;
        return head;
    }
};