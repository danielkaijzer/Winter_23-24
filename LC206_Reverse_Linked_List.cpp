#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur){
            ListNode* nxt = cur->next; // keep link to next
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

int main(){
Solution s;

    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    // Reverse the linked list
    ListNode* reversedHead = s.reverseList(head);

    // Print the reversed linked list
    while (reversedHead != nullptr){
        std::cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }

    return 0;
}



/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur != nullptr){ // if not tail
            ListNode* tmp = cur->next; // store link to next so you can break without losing it
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;

    }
};
 */