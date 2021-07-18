#include <bits/stdc++.h>

using namespace std;
typedef struct node *nodePtr;
typedef struct node
{
    int data;
    nodePtr next;
} node;

void printList(node *head) //This function prints the list
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data;
    cout << endl;
    return;
}

void atLast(int n, nodePtr *head) //this function adds the list from last
{
    nodePtr temp = *head;
    nodePtr newPtr = (nodePtr)malloc(sizeof(node));
    newPtr->data = n;
    newPtr->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPtr;
    return;
}

nodePtr pushAtFirst(int n, nodePtr head) //this function adds the list from the begining this is not a void function it returns the adress of the newly created link list
{
    nodePtr newptr = (nodePtr)malloc(sizeof(node));
    newptr->data = n;
    newptr->next = head;
    return newptr;
}

void insertAtPos(int n, int pos, nodePtr *head) //this function inserts at the given position as per '0' indexing
{
    nodePtr temp = *head;
    nodePtr newnode = (nodePtr)malloc(sizeof(node));
    newnode->data = n;
    int po = 0;
    while (po < pos - 1)
    {
        temp = temp->next;
        po++;
    }
    nodePtr temp2 = temp->next;
    temp = *head;
    po = 0;
    while (po < pos - 1)
    {
        temp = temp->next;
        po++;
    }
    temp->next = newnode;
    newnode->next = temp2;
    return;
}

void insertAfter(int n, int m, nodePtr *head) //this function adds the new list after the targeted data
{
    nodePtr temp = *head;
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    newNode->data = m;
    int datas;
    while (temp->data != n)
    {
        datas = temp->data;
        temp = temp->next;
        if (temp == NULL)
            return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void del(int n, nodePtr *head) //this function deletes the list with the value if there are multiple values then it deletes the first occurance of it
{
    nodePtr temp = *head;
    int data1;
    while (temp->data != n)
    {
        data1 = temp->data;
        temp = temp->next;
    }
    nodePtr temp2 = temp->next;
    temp = *head;
    while (temp->data != data1)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    return;
}

nodePtr findList(int n, nodePtr head) //find list find the data and returns it's adress if present;
{
    while (head->data != n)
    {
        head = head->next;
        if (head == NULL)
            return NULL;
    }
    return head;
}

int length(nodePtr head) //finds the length of the list
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

int minimum(nodePtr head) //returns the minimum of the list
{
    int min = INT_MAX;
    while (head != NULL)
    {
        int dat = head->data;
        min = min < dat ? min : dat;
        head = head->next;
    }
    return min;
}

int maximum(nodePtr head) //returns the maximum of the list
{
    int min = INT_MAX;
    while (head != NULL)
    {
        int dat = head->data;
        min = min > dat ? min : dat;
        head = head->next;
    }
    return min;
}

void sortAcc(nodePtr *head)
{
    nodePtr temp = *head;
    nodePtr curr = temp;
    nodePtr next = temp->next;
    while(curr && next)
    {
        while(next)
        {
            if(curr->data > next->data)
            {
                swap(curr->data,next->data);
            }
            next = next->next;
        }
        curr = curr->next;
    }
}

int main()
{
    nodePtr head = (nodePtr)malloc(sizeof(node));
    nodePtr first = (nodePtr)malloc(sizeof(node));
    head->data = 1;
    head->next = first;
    first->data = 2;
    first->next = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        atLast(t, &head);
    }
    sortAcc(&head);
    printList(head);
    return 0;
}
