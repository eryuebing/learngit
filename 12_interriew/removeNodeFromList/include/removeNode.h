#ifndef __REMOVE_NODE__
#define __REMOVE_NODE__

struct Linked_Node{
        int val;
        struct Linked_Node *next;
};

void removeFromList(struct Linked_Node **ppList, int keyVal);

#endif
