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
    ListNode* merge2sortedLists(ListNode* list1,ListNode* list2){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next=merge2sortedLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=merge2sortedLists(list1,list2->next);
            return list2;
        }
    }
    ListNode* partition_and_merge(int start,int end,vector<ListNode*>& lists){
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode* l1=partition_and_merge(start,mid,lists);
        ListNode* l2=partition_and_merge(mid+1,end,lists);
        return merge2sortedLists(l1,l2);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int k=lists.size();
       if(k==0) return NULL;
       return partition_and_merge(0,k-1,lists);
    }
};