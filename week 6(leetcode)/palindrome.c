
#include <stdbool.h>
#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* Temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Temp;
    }
    return prev;
}


bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    
    int length = 0;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }

    
    int half = length / 2;
    ptr = head;
    for (int i = 1; i < half; ++i) {
        ptr = ptr->next;
    }

    struct ListNode* second = NULL;
    if (length % 2 == 0) {
        second = ptr->next;
        ptr->next = NULL; 
    } else {
        
        second = ptr->next->next;
        ptr->next->next = NULL; 
    }

    
    second = reverseList(second);

    
    struct ListNode* p1 = head;
    struct ListNode* p2 = second;
    bool result = true;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }



    return result;
}
