/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    
    struct ListNode* slowPtr, *fastPtr;

    slowPtr = head;
    fastPtr = head;

    while(fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    
    // reverse 2nd half list

    struct ListNode *previousPtr, *currentPtr, *nextPtr;
    previousPtr = NULL;
    while(slowPtr){
        currentPtr = slowPtr->next;
        slowPtr->next = previousPtr;
        previousPtr = slowPtr;
        slowPtr = currentPtr;

    }

    struct ListNode* first = head;
    struct ListNode* second = previousPtr;
  // compare list 
    while(second)
    {
        if(first->val != second->val)
        {
            return false;
        }
        first = first->next;
        second = second->next;
 
    }

    return true;
}
