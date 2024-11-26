#include<iostream>
#include<string.h>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }
};

class node {
public:
    Book book;
    node *next;

    node(string title, string author) : book(title, author) {
        next = NULL;
    }
};

class Library {
public:
    node* head;

    Library() {
        head = NULL;
    }

    void addBooks(string title, string author) {
        node* newnode = new node(title, author);
        if (head == NULL) {
            head = newnode;
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "BOOK ADDED SUCCESSFULLY" << endl;
    }

    void displayBooks() {
        if (head == NULL) {
            cout << "BOOK is not Available" << endl;
        } else {
            node* temp = head;
            while (temp != NULL) {
                cout << "Title: " << temp->book.title
                     << ", Author: " << temp->book.author
                     << ", Available: " << (temp->book.isAvailable ? "Yes" : "No") << endl;
                temp = temp->next;
            }
        }
    }
    void borrowBooks(string title)
    {
        if(head==NULL)
        {
            cout<<"No BOOk is Availaible !!!!!!!"<<endl;
        }else
        {
            node* temp = head;
            while (temp != NULL)
            {

                    if(temp->book.title == title){
                        cout<<"Book is Borrowed"<<endl;
                        temp->book.isAvailable = false;
                        return;
                    }else{
                        temp=temp->next;
                    }

            }
        }
    }
    void returnBooks(string title)
    {
        if(head==NULL)
        {
            cout<<"No BOOK is Available"<<endl;
        }else
        {
            node* temp = head;
            while (temp != NULL)
            {
                if(temp->book.title == title)
                {
                    cout<<"Book is Returned"<<endl;
                    temp->book.isAvailable = true;
                    return;
                }
            }
        }
    }
 void searchBooks(string title)
    {
        if(head==NULL)
        {
            cout<<"No BOOK is Available"<<endl;
        }
        else
        {
            node* temp = head;
            while (temp != NULL)
            {
                if(temp->book.title == title)
                {
                    cout<<"Book is Available"<<endl;
                    cout<<"Use (2) to Borrow the Book"<<endl;
                    return;
                }else
                {
                    cout<<"Book is Not Available"<<endl;
                }
            }
        }
    }
};

int main(){
    Library library;
    string title, author;
    int choice;

    cout << "Welcome to Our Library" << endl;

    do {
        cout << "\nLibrary Management System\n" << endl;
        cout << "(1) Add Books" << endl;
        cout << "(2) Display Books" << endl;
        cout<<"(3) Borrow Book"<<endl;
        cout<<"(4) Return Book"<<endl;
        cout<<"(5) Search Book"<<endl;
        cout<<"(6) Exit"<<endl;
        cout<<"\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Title: ";
                cin >> title;
                cout << "Enter the Author: ";
                cin >> author;
                library.addBooks(title, author);
                break;

            case 2:
                cout << "Available Books in Library:" << endl;
                library.displayBooks();
                break;
            case 3:
                cout<<"Enter the Title of the book which you want to Borrow:-"<<endl;
                cout << "Enter the Title: ";
                cin >> title;
                library.borrowBooks(title);
                break;
            case 4:
                cout<<"Enter the Tile of the book which you want to Return:-";
                cin>>title;
                library.returnBooks(title);
                break;
        case 5:
            cout<<"Enter the Title of the Book which You want to search:-";
            cin>>title;
            library.searchBooks(title);
            break;
            case 6:
                cout<<"Thanks for using Our Library"<<endl;
            cout<<"Have a good day!"<<endl;
            break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
