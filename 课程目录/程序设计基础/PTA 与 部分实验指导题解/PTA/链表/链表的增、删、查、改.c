#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;  
    struct Node* next;
} Node;

// 增：创建新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 头插法：在链表头部插入新的节点
void prepend(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 尾插法：在链表尾部插入新的节点
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删：删除指定值的节点
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // 如果头节点就是目标节点
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // 查找要删除的节点
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // 如果未找到该节点
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // 删除节点
    prev->next = temp->next;
    free(temp);
}

// 查：查找节点，返回节点的指针（如果找到的话）
Node* findNode(Node* head, int data) {
    Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // 没有找到
}

// 改：修改指定节点的数据
void modifyNode(Node* head, int oldData, int newData) {
    Node* target = findNode(head, oldData);
    if (target) {
        target->data = newData;
    }
    else {
        printf("Node with data %d not found.\n", oldData);
    }
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;

    // 使用头插法插入节点
    prepend(&head, 10);
    prepend(&head, 20);
    prepend(&head, 30);
    printf("List after using prepend (head insertion): ");
    printList(head);

    // 使用尾插法插入节点
    append(&head, 40);
    append(&head, 50);
    printf("List after using append (tail insertion): ");
    printList(head);

    // 删除节点
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    // 查找节点
    Node* foundNode = findNode(head, 30);
    if (foundNode) {
        printf("Found node with data: %d\n", foundNode->data);
    }
    else {
        printf("Node with data 30 not found.\n");
    }

    // 修改节点
    modifyNode(head, 30, 35);
    printf("After modifying 30 to 35: ");
    printList(head);

    return 0;
}