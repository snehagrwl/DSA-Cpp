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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        vector<int>result;
        ListNode* temp=head->next;
        ListNode* prev=head;
        int i=2;
        while(temp->next!=nullptr){
             if((temp->val>temp->next->val && temp->val>prev->val)||(temp->val<temp->next->val && temp->val<prev->val)){
                criticalPoints.push_back(i);
             }
             temp=temp->next;
             prev=prev->next;
             i++;
        }
        if (criticalPoints.size() < 2) {
        return {-1, -1};
        }
        int maxDist = criticalPoints.back() - criticalPoints.front();
        int minDist = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
        // Compare the current adjacent difference with our running minimum
        minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
         }
        return {minDist, maxDist};
    }
};