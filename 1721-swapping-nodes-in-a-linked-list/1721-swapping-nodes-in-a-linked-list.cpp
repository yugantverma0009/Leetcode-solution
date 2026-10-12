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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int n=0;
        while(temp1){
            n++;
            temp1=temp1->next;
        }
        temp1=head;
        int j=k;
        while(--j){
           temp1=temp1->next;
        }
        int l=n-k+1;
        while(--l){
           temp2=temp2->next;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};