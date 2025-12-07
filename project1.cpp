#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = tail = NULL;
    }

    void printLL() {
        if(head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_front(int val) {
        Node* newnode = new Node(val);
        if(head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void push_back(int val) {
        Node* newnode = new Node(val);
        if(head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void push_at(int pos, int val) {
        if(pos == 1) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Position out of bound." << endl;
            return;
        }

        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if(temp == tail)
            tail = newnode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Nothing to delete." << endl;
            return;
        }
        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "Nothing to delete." << endl;
            return;
        }
        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void pop_at(int pos) {
        if(head == NULL) {
            cout << "Nothing to delete." << endl;
            return;
        }
        if(pos == 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL || temp->next == NULL) {
            cout << "Position out of bound." << endl;
            return;
        }

        Node* ptr = temp->next;
        temp->next = ptr->next;

        if(ptr == tail)
            tail = temp;

        delete ptr;
    }

    bool search(int key) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int countNodes() {
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void reverse() {
        Node *prev = NULL, *curr = head, *nxt = NULL;
        tail = head;

        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    void insertSorted(int val) {
        Node* newnode = new Node(val);

        if(head == NULL || val < head->data) {
            push_front(val);
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data < val)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;

        if(newnode->next == NULL)
            tail = newnode;
    }

    void deleteValue(int key) {
        if(head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if(head->data == key) {
            pop_front();
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if(temp->next == NULL) {
            cout << "Value not found." << endl;
            return;
        }

        Node* ptr = temp->next;
        temp->next = ptr->next;

        if(ptr == tail)
            tail = temp;

        delete ptr;
    }

    int middle() {
        if(head == NULL)
            return -1;

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }

    void clear() {
        Node* temp;
        while(head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }

    ~LinkedList() {
        clear();
    }
};


int main() {
    LinkedList li;
    int choice, val, pos;

    while(true) {

        cout << "\nCurrent Linked List: ";
        li.printLL();

        cout << "\n================ LINKED LIST MENU ================" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete from Front" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from Position" << endl;
        cout << "7. Search an Element" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Reverse Linked List" << endl;
        cout << "10. Insert in Sorted Order" << endl;
        cout << "11. Delete by Value" << endl;
        cout << "12. Show Middle Element" << endl;
        cout << "13. Detect Cycle" << endl;
        cout << "14. Clear Linked List" << endl;
        cout << "0. Exit" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                li.push_front(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                li.push_back(val);
                break;

            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                li.push_at(pos, val);
                break;

            case 4:
                li.pop_front();
                break;

            case 5:
                li.pop_back();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                li.pop_at(pos);
                break;

            case 7:
                cout << "Enter key: ";
                cin >> val;
                if(li.search(val))
                    cout << "Element found." << endl;
                else
                    cout << "Element not found." << endl;
                break;

            case 8:
                cout << "Total nodes: " << li.countNodes() << endl;
                break;

            case 9:
                li.reverse();
                cout << "Linked list reversed." << endl;
                break;

            case 10:
                cout << "Enter value: ";
                cin >> val;
                li.insertSorted(val);
                break;

            case 11:
                cout << "Enter value to delete: ";
                cin >> val;
                li.deleteValue(val);
                break;

            case 12:
                cout << "Middle element: " << li.middle() << endl;
                break;

            case 13:
                if(li.detectLoop())
                    cout << "Cycle detected!" << endl;
                else
                    cout << "No cycle." << endl;
                break;

            case 14:
                li.clear();
                cout << "Linked list cleared." << endl;
                break;

            case 0:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
