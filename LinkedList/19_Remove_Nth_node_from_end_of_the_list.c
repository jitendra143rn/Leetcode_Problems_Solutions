/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *pTemp, *kthNode;
    pTemp = kthNode = head;
    int i = 0;

    for(i = 0; i < n; i++)
    {
      pTemp = pTemp->next;
    }

    if(!pTemp)
    {
        struct ListNode *newNode = head->next;
        free(head);
        return newNode;

    }
    while(pTemp->next)
    {
        pTemp = pTemp->next;
        kthNode = kthNode->next; // Need to delete 
    }
    //struct ListNode *newNode = kthNode->next;
    kthNode->next = kthNode->next->next;
    //free(newNode);
    return head;
}
