/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* curr = head;
        while (curr) {
            // Skip `m` nodes
            for (int i = 1; i < m && curr; i++) {
                curr = curr->next;
            }

            if (!curr) break; // If we reach the end, stop

            // Delete `n` nodes
            Node* newGuy = curr->next;
            for (int i = 0; i < n && newGuy; i++) {
                Node* temp = newGuy;
                newGuy = newGuy->next;
                delete temp; // Free memory for the deleted node
            }

            // Connect the `m-th` node to the remaining list
            curr->next = newGuy;

            // Move `curr` to the next segment
            curr = newGuy;
        }

        return head;
    }
};