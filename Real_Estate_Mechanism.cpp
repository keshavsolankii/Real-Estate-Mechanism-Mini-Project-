#include<bits/stdc++.h>
using namespace std;

// Number of houses in the city are represented by Linked list

class Node // Node represent a house
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

// Inserting the houses, in case of new houses, in the database

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail ,int data)
{
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertInBetween(Node* &head, Node* &tail, int d, int position)
{
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;

    int count = 1;
    while(count != position-1)
    {
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

// If a house is being sold then that node would be deleted and the remaining houses would bhi displayed!

void deleteNode(Node* &head, int position)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

// This function will display the current houses in the city
void displayHouses(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// To find the vacant sector, searching would be done. If the sector is vacant then true will be returned otherwise false will be returned.

bool isSectorVacant(Node* &head)
{
    Node* temp = head;
    if(temp == NULL)
    return false;
    else
    return true;
}

// Searching for the required house in that sector

bool isHouseVacant(Node* &head, int HouseNumber)
{
    Node* temp = head;
    if(temp == NULL)
        return false;

    while(temp != NULL)
    {
        if(temp->data == HouseNumber)
        return true;

        temp = temp->next;
    }
    return false;
}

// Asking for users choice and searching if that house is vacant or occupied

pair<int, int> usersChoiceForSector(Node* &head)
{
    pair<int, int> secAndHouse;
    int sector;
    cout<<"Please tell us in which sector you want to purchase a house : "<<endl;
    cin>>sector;

    if(isSectorVacant(head))
    {
        cout<<"Yes, in this sector your required house is present!"<<endl;
        secAndHouse.first = sector;

        cout<<"In this sector, following houses are vacant -->"<<" ";
        displayHouses(head);
        cout<<endl;

        int house;
        cout<<"Please choose a house from the above list"<<endl;
        cin>>house;

        cout<<"Are you sure to book this house? (Y/N)"<<endl;
        char response;
        cin>>response;

        if(response == 'Y' or response == 'y')
        {
            secAndHouse.second = house;
            return secAndHouse;
        }
        else if(response == 'N' or response == 'n')
        {
            cout<<"";
        }

    }
    else{
        cout<<"We are really sorry :( , All houses in this sector are already booked!"<<endl;
        cout<<"You can choose another sector :) "<<endl;
        cout<<"Do you want to choose another sector? (Y/N)"<<endl;
        char response;
        cin>>response;

        if(response == 'Y' or response == 'y')
        {
            cin>>sector;
        }
        else if(response == 'N' or response == 'n')
        {
            cout<<"We are sad to see you go!"<<endl;
            cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"We hope we will be able to provide you your dream house next time! \n Have a Good Day!";
        }

    }
}


int main()
{
    
    return 0;
}
