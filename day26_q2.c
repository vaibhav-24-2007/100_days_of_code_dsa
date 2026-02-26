#include <stdio.h>
#include <stdlib.h>

char your_name[] = "vaibhav maheshwari";
char your_sapid[] = "590022236";

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;

Node* makeNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (!obj || index < 0 || index >= obj->size) return -1;

    Node *temp = obj->head;
    int i;
    for (i = 0; i < index; i++) temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (!obj) return;

    Node *n = makeNode(val);
    n->next = obj->head;
    obj->head = n;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (!obj) return;

    Node *n = makeNode(val);

    if (obj->head == NULL) {
        obj->head = n;
    } else {
        Node *temp = obj->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (!obj) return;

    if (index < 0) index = 0;
    if (index > obj->size) return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node *temp = obj->head;
    int i;
    for (i = 0; i < index - 1; i++) temp = temp->next;

    Node *n = makeNode(val);
    n->next = temp->next;
    temp->next = n;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (!obj || index < 0 || index >= obj->size) return;

    if (index == 0) {
        Node *del = obj->head;
        obj->head = obj->head->next;
        free(del);
        obj->size--;
        return;
    }

    Node *temp = obj->head;
    int i;
    for (i = 0; i < index - 1; i++) temp = temp->next;

    Node *del = temp->next;
    temp->next = del->next;
    free(del);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (!obj) return;

    Node *temp = obj->head;
    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}

/* optional demo main
Input:
q
then q operations:
1 val            addAtHead
2 val            addAtTail
3 index val      addAtIndex
4 index          deleteAtIndex
5 index          get (prints answer)
*/
int main() {
    printf("Name %s SAP-ID %s\n", your_name, your_sapid);

    MyLinkedList *list = myLinkedListCreate();
    int q;
    if (scanf("%d", &q) != 1) return 0;

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int val; scanf("%d", &val);
            myLinkedListAddAtHead(list, val);
        } else if (type == 2) {
            int val; scanf("%d", &val);
            myLinkedListAddAtTail(list, val);
        } else if (type == 3) {
            int index, val; scanf("%d %d", &index, &val);
            myLinkedListAddAtIndex(list, index, val);
        } else if (type == 4) {
            int index; scanf("%d", &index);
            myLinkedListDeleteAtIndex(list, index);
        } else if (type == 5) {
            int index; scanf("%d", &index);
            printf("%d\n", myLinkedListGet(list, index));
        }
    }

    myLinkedListFree(list);
    return 0;
}
