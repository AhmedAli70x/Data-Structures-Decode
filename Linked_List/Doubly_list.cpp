// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class linkedListNode
{
public:
    int data;
    linkedListNode *next;
    linkedListNode *back;

    linkedListNode(int _data)
    {
        this->data = _data;
        this->next = NULL;
        this->back = NULL;
    }
};

class linkedListIterator
{

private:
    linkedListNode *currentNode;

public:
    linkedListIterator() { currentNode = NULL; }
    linkedListIterator(linkedListNode *node) { currentNode = node; }

    int data()
    {
        return this->currentNode->data;
    }
    linkedListIterator next()
    {
        this->currentNode = this->currentNode->next;
        return *this;
    }

    linkedListNode *current()
    {
        return this->currentNode;
    }
    void reset()
    {
        this->currentNode = NULL;
    }
};
class linkedList
{

private:
    int count = 0;

public:
    linkedListNode *head = NULL;
    linkedListNode *tail = NULL;

    linkedListIterator begin()
    {
        linkedListIterator itr(this->head);
        return itr;
    }

    void printList()
    {
        for (linkedListIterator itr = this->begin(); itr.current() != NULL; itr.next())
        {
            cout << itr.data() << " - > ";
        }
        cout << "\n";
    }

    void insertAfter(linkedListNode *node, int _data)
    {
        linkedListNode *newNode = new linkedListNode(_data);

        newNode->next = node->next;
        newNode->back = node;
        node->next = newNode;
        // newNode in the last
        if (newNode->next == NULL)
        {
            this->tail = newNode;
        }
        // newNode in the middle
        else
        {
            newNode->next->back = newNode;
        }
        this->count++;
    }

    int length()
    {
        return this->count;
    }

    void insertLast(int _data)
    {
        linkedListNode *newNode = new linkedListNode(_data);
        if (this->tail == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        newNode->back = tail;
        this->tail->next = newNode;
        this->tail = newNode;
        this->count++;
    };

    linkedListNode *find(int _data)
    {
        for (linkedListIterator itr = this->begin(); itr.current() != NULL;
             itr.next())
        {
            if (_data == itr.data())
            {
                return itr.current();
            }
        }
        return NULL;
    }

    void insertBefore(linkedListNode *node, int _data)
    {
        linkedListNode *newNode = new linkedListNode(_data);

        newNode->next = node;

        if (node == this->head)
        {
            this->head = newNode;
        }
        else
        {
            node->back->next = newNode;
        }
        node->back = newNode;
        this->count++;
    };

    void deleteNode(linkedListNode *node)
    {

        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (node->back == NULL)
        {
            node->next->back = NULL;
            this->head = node->next;
        }
        // node is tail only
        else if (node->next == NULL)
        {
            this->tail = node->back;
            node->back->next = NULL;
        }
        else
        {
            node->back->next = node->next;
            node->next->back = node->back;
        }
        delete node;
        this->count--;
    }
};

int main()
{
    linkedList *list = new linkedList();
    cout << "list length is  " << list->length() << "\n";
    list->insertLast(1);
    list->insertLast(2);
    list->insertLast(3);
    list->printList();
    cout << "list length is  " << list->length() << "\n";

    list->insertAfter(list->find(2), 98);
    list->printList();
    cout << "list length is  " << list->length() << "\n";

    list->insertBefore(list->find(3), 55);
    list->printList();
    cout << "list length is  " << list->length() << "\n";

    list->deleteNode(list->find(98));
    list->printList();

    //  cout << "head is " << list->head->data<<"\n";
    cout << "list length is  " << list->length() << "\n";
    list->printList();
}