/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node* start = head; // keep starting point for returning
        while(head != nullptr){ // until end of linked list
            m[head] = new Node(head->val); // create dict and add new nodes
            head = head -> next;
        }
        for (auto p : m){
            p.second -> next = m[p.first->next]; // translate random and next
            p.second -> random = m[p.first->random];
        }
        return m[start]; // return start of new list
    }
};
