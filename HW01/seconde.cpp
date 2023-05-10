#include <iostream>
using namespace std;

struct node {
    int value;
     node* next;
};

typedef node* nodeptr;

void insert(nodeptr* head, int number)
{
    nodeptr newone = new node;
    nodeptr cur=*head,prev=nullptr;
    newone->next = nullptr;
    newone->value = number;

    if (!(*head)) {
        *head=newone;
        return;
    }
    while (cur != nullptr && cur->value <= number) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == nullptr) {// 1pre 3new 5cur
        newone->next = cur;
        *head = newone; 
    }
    else { 
        prev->next = newone;//step1// 1  3       insert 2
        newone->next = cur;
    }
    /*nodeptr new_node = new node;
    new_node->value = number;
    new_node->next = NULL;

    nodeptr prev = NULL;
    nodeptr cur = *head;

    for (; cur != NULL; prev = cur, cur = cur->next)
    {
        if (number <= cur->value)
        {
            break;
        }
    }

    if (cur == *head)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        new_node->next = cur;
        prev->next = new_node;
    }*/
}

void delete_node(nodeptr* head, int number)
{
    nodeptr prev=nullptr;
    nodeptr cur = *head;
    
    while (cur) {//1 2 3 4 5 delete 1 pre null  cur=1
        if (cur->value==number) {
            if (prev == nullptr) {
                *head = cur->next;
                delete cur;
                cur = *head;
            }
            else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void display(nodeptr head)
{
    for (; head != NULL; head = head->next)
    {
        cout << head->value << " ";
    }
    cout << endl;
}

int main()
{
    char n;
    int number;
    nodeptr head = NULL;

    while (1)
    {
        cout << "Input or Delete?";
        cin >> n;

        switch (n)
        {
        case 'i':
            cout << "Input an integer?";
            cin >> number;
            insert(&head, number);
            display(head);
            break;
        case 'd':
            cout << "Delete a integer?";
            cin >> number;
            delete_node(&head, number);
            display(head);
            break;
        }
    }

    return 0;
}
