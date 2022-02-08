//
//  main.cpp
//
//  Created by Fahreta Hublic on 12/07/21.
//

#include <iostream>
#include <fstream>

using namespace std;

struct linkList
{
    int value;
    linkList *next;
};

linkList* insertOrder (linkList *head, int value);
linkList* deleteItem(linkList *head, int value);

void searching(linkList *head, int value);
void printList(linkList *head);

int main()
{
    ifstream fin;
    linkList *head = NULL;
    int value;
    char selection;

    fin.open("input.txt");
    
    if (!fin.is_open())
    {
        cout << "unable to open file" << endl;
    }

    while (true)
    {

        fin >> selection;
        fin >> value;
        if(fin.eof()) break;

        switch (selection)
        {
            case 'I':
                head = insertOrder(head, value);
                break;
                
            case 'D':
                head = deleteItem(head, value);
                break;
                
            case 'S':
                searching(head, value);
                break;
                
            default:
                cout << "try again, " << selection << " doesn't work" << endl;
                break;
        }
    }

    fin.close();
    
    printList(head);

    return 0;
}

linkList* insertOrder (linkList *head, int value)
{
    linkList *current, *past, *newItem;

    newItem = new linkList;

    newItem->value = value;

    if (head == NULL)
    {
        newItem->next = NULL;
        head = newItem;
        return head;
    }

    if (value < head->value)
    {
        head->next = NULL;
        newItem->next = head;
        head = newItem;
        
        return head;
    }

    current = head->next;
    past = head;

    if (current == NULL)
    {
        head->next = newItem;
        newItem->next = NULL;
        
        return head;
    }
    
    while (current->value < value)
    {
        if (current->next == NULL)
        {
            current->next = newItem;
            newItem->next = NULL;
            
            return head;
        }
        past = current;
        current = current->next;
    }

    past->next = newItem;
    newItem->next = current;

    return head;

}

linkList* deleteItem(linkList *head, int value)
{
    linkList *current, *past, *deleteThis;

    current = head;
    past = head;

    if(head == NULL)
    {
        cout << "nothing to delete present" << endl;
        
        return head;
    }

    while(current != NULL)
    {
        if (current->value != value)
        {
            past = current;
            current = current->next;
        }
        else
        {
            if (current == head)
            {
                deleteThis = head;
                head = head->next;
                
                delete deleteThis;
                return head;
            }
            deleteThis = current;
            past->next = current->next;
            delete deleteThis;
            return head;
        }
    }

    cout << "the value " << value << " could not be deleted because it is not in the list" << endl;
    
    return head;

}

void searching(linkList *head, int value)
{
     linkList *current;

    if(head == NULL)
    {
        cout << "empty list present" << endl;
        
        return;
    }

    current = head;

    while(current != NULL)
    {
        if (current->value != value)
        {
            current = current->next;
        }
        else
        {
            cout << "the value " << value << " was found in the list" << endl;
            
            return;
        }
    }

    cout << "the value " << value << " was not found in the list" << endl;
}

void printList(linkList *head)
{
    linkList *current;

    current = head;

    cout << endl << "linked list complete : | ";

    while (current != NULL)
    {
        cout << current->value << " | ";
        current = current->next;
    }
}
