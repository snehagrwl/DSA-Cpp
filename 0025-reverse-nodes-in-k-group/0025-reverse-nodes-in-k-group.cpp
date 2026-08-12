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
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail=&dummy;

        while(true){
            ListNode* kThNode=getKthNode(prevGroupTail,k);
            if(!kThNode) break;

            ListNode* nextGroupHead=kThNode->next;
            ListNode* curr=prevGroupTail->next;
            ListNode* prev=kThNode->next;

            while(curr!=nextGroupHead){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* newGroupTail=prevGroupTail->next;
            prevGroupTail->next=kThNode;
            prevGroupTail=newGroupTail;
        }
        return dummy.next;
    }

};