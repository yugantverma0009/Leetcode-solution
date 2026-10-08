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
    ListNode* Find_Middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge2list(ListNode* list1,ListNode* list2){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next=merge2list(list1->next,list2);
            return list1;
        }
        else{
            list2->next=merge2list(list1,list2->next);
            return list2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=Find_Middle(head);
        ListNode* left_head=head;
        ListNode* right_head=middle->next;
        middle->next=NULL;
        left_head=sortList(left_head);
        right_head=sortList(right_head);
        return merge2list(left_head,right_head);
    }
};