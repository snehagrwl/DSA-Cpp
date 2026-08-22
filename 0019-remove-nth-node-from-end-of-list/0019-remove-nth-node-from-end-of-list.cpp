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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //counting the number of elements in the string
        ListNode* temp;
        temp=head;
        int count=0;
        while(temp){
          //  temp=temp->next;
            count++;
            temp=temp->next;
        }
        int m=count-n;
        if (m == 0) {
            return head->next;
        }
        temp=head;
        for (int i = 0; i < m - 1; i++) {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};