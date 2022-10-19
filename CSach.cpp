#include"CSach.h"
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>
#include <conio.h>
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
int CSach::Rest_Book()
{
    return Total_Book_Name - Borrowed_Book;
}

void CSach::add_Num_Book() {
    cout << "Enter The Number Of Books Names You Want To Add In Library:";
    cin >> Num_Name_Book;
}
int CSach::getNum_Name_Book()
{
    return Num_Name_Book;
}
// Project Menu
void CSach::menu()
{
menustart:
    char choice;
    char x;
    int k = 1;
    int numBook;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| LIBRARY SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 0. Enter The Number Of Books Data To Add To Library " << endl;
    cout << "\t\t\t 1. Enter New Book Record" << endl;
    cout << "\t\t\t 2. Display All Book Records" << endl;
    cout << "\t\t\t 3. Modify 1 Book Record" << endl;
    cout << "\t\t\t 4. Search 1 Book Record" << endl;
    cout << "\t\t\t 5. Delete 1 Book Record" << endl;
    cout << "\t\t\t 6. Show Available Books" << endl;
    cout << "\t\t\t 7. Input Data from Data.txt" << endl;
    cout << "\t\t\t 8. Exit\n"
        << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case '0':
        add_Num_Book();
       // numBook = getNum_Name_Book();                     
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '1':

        do
        {
            if (Num_Name_Book>0)
            {
                insert();
                cout << "\n\n\t\t\t Add Another Book Record (Y, N) : ";
                cin >> x;
                Num_Name_Book--;
                
            }
            else {
                cout << "Exceed The Number Of Required Books Names! ";
                cout << "Press any key to back to Menu...";
                getch();
                goto menustart;
                break;
            }

        } while (x == 'y' || x == 'Y');
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;


        break;
    case '2':
        display();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '3':
        modify();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '4':
        search();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '5':
        deleted();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '6':
        Book_Existing();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '7':
        input_data_to_file();
        cout << "Press any key to back to Menu...";
        getch();
        goto menustart;
        break;
    case '8':
        cout << "\n\t\t\t Program Is Exit";
        exit(0);

    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}
void CSach::upper_Name(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] = s[i] - ((int)('a') - (int)('A'));
        }
    }
}
void CSach::insert() // Add books details
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Book Details ---------------------------------------------" << endl;
   bookdetail:
    cout << "\t\t\tEnter Name: ";
    cin.ignore();
    getline(cin,Book_Name);
    upper_Name(Book_Name);
    
    cout << "\t\t\tEnter Total Books: ";
    cin >> Total_Book_Name;
    cout << "\t\t\tEnter Books are being borrowed: ";
    cin >> Borrowed_Book;
    file.open("LibraryRecord.txt", ios::app | ios::out);   
    
    file << " " << Book_Name << " " << Total_Book_Name << " " << Borrowed_Book << "\n";
    file.close();
}
void CSach::display() // Display data of library
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Book Record Table --------------------------------------------" << endl;
    file.open("LibraryRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tBook No.: " << total++ << endl;
            cout << "\t\t\tName: " << Book_Name << "\n";
            cout << "\t\t\tTotal Books: " << Total_Book_Name << "\n";
            cout << "\t\t\tBooks are being borrowed: " << Borrowed_Book << "\n";

            file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void CSach::modify() // Modify details of library
{
    system("cls");
    fstream file, file1;
    string Modified_Book;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Book Modify Details ------------------------------------------" << endl;
    file.open("LibraryRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Name Of A Book You Want To Modify: ";
        cin.ignore();
        getline(cin, Modified_Book);
        upper_Name(Modified_Book);
        file1.open("record.txt", ios::app | ios::out);
        file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        while (!file.eof())
        {
            if (Modified_Book != Book_Name)
                file1 << " " << Book_Name << " " << Total_Book_Name << " " << Borrowed_Book << "\n";
            else
            {
                cout << "\n\t\t\tMODIFY THE BOOK: " << Book_Name << endl;
                cout << "\t\t\tUpdate Total: ";
                cin >> Total_Book_Name;
                cout << "\t\t\tUpdate Number of Books are being Borrowed: ";
                cin >> Borrowed_Book;

                file1 << " " << Book_Name << " " << Total_Book_Name << " " << Borrowed_Book << "\n";
                found++;
            }
            file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Your Wanted Book Not Found....";
        }
        file1.close();
        file.close();
        remove("LibraryRecord.txt");
        rename("record.txt", "LibraryRecord.txt");
    }
}

void CSach::search() // search data of library
// chua xong phan tim kiem nang cao
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("LibraryRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Book Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string Find_Book;
        int check_Find_Book;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Book Search Table --------------------------------------------" << endl;
        cout << "\nEnter Book's Name which you want to search: ";
        cin.ignore();
        getline(cin, Find_Book);
        
        upper_Name(Find_Book);
        file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        while (!file.eof())
        {

            if (Find_Book== Book_Name)
            {
                cout << "\n\n\t\t\t Information of " << Book_Name << "\n";
                cout << "\t\t\tTotal Books.: " << Total_Book_Name << "\n";
                cout << "\t\t\tNumber of Books are being Borrowed: " << Borrowed_Book << "\n";
                found++;
                
            }
            
                file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
                if (found == 0)
                {
                    cout << "\n\t\t\t Your Wanted Book Not Found....";
                }
        }
        
        file.close();
    }
      
}
void CSach::deleted() // deleted data of library
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string Deleted_Book;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Book Details ------------------------------------------" << endl;
    file.open("LibraryRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Name of a Book which you want Delete Data: ";
        cin.ignore();
        getline(cin, Deleted_Book);
        file1.open("record.txt", ios::app | ios::out);
        file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        while (!file.eof())
        {
            if (Deleted_Book != Book_Name)
            {
                file1 << " " << Book_Name << " " << Total_Book_Name << " " << Borrowed_Book << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data\n";
            }
            file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Your Wanted Book Not Found....";
        }
        file1.close();
        file.close();
        remove("LibraryRecord.txt");
        rename("record.txt", "LibraryRecord.txt");
    }
}
void CSach::Book_Existing()
{
    system("cls");
    cout << "\n\t\t\t THE AVAILABLE BOOKS IN THE LIBRARY\n\n";
    fstream file;
    int check_available = 0;
    file.open("LibraryRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else {
        file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        while (!file.eof())
        {
            if (Rest_Book() > 0)
            {
                cout << "\t\t\tName of Book:" << Book_Name << endl;
                cout << "\t\t\tTotal Book:" << Total_Book_Name << endl;
                cout << "\t\t\tBooks are being Borrowed:" << Borrowed_Book << endl;
                cout << "\t\t\tNumbers of " << Book_Name << " are available:" << Rest_Book() << "\n\n";
                check_available++;
                file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
            }
            else {
                file >> Book_Name >> Total_Book_Name >> Borrowed_Book;
            }
        }
        if (check_available == 0)
        {
            cout << "\nThere is no book available!" << endl;
        }
    }
    file.close();
}
void CSach::input_data_to_file()
{
    system("cls");
    fstream filein, fileout;
    filein.open("Data.txt", ios::in);
    if (!filein)
    {
        cout << "\t\t\t There's no data in the file...\n";
        filein.close();
    }
    else {
        filein >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        fileout.open("LibraryRecord.txt", ios::app | ios::out);
        while (!filein.eof())
        {
            upper_Name(Book_Name);
            fileout << Book_Name << " " << Total_Book_Name << " " << Borrowed_Book << "\n";
            filein >> Book_Name >> Total_Book_Name >> Borrowed_Book;
        }
        cout << "\t\t\t Data inputed successfully...\n";

    }
    filein.close();
    fileout.close();
}
