#include"CSach.h"
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include<algorithm>
#include <conio.h>
#include<iostream>
#include<vector>
#include<winbgim.h>
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
        if (Num_Name_Book<=0)
        {
            cout << "Please choose Option 0 in Menu to initialize Number of Books Data To Add!\n";
            goto backmenu;
        }
        
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
                cout << "Exceed The Number Of Required Books Data! ";
                cout << "Press any key to back to Menu...";
                getch();
                goto menustart;
                break;
            }

        } while (x == 'y' || x == 'Y');
        backmenu:
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
        cin.ignore();
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
    goto menustart;;
}
string CSach::getCorrect_Book_Name(string& transfer_Book_Name)
{
    int n = transfer_Book_Name.size();
    int left = 0, right = n - 1;
    while (left < n && transfer_Book_Name[left] == ' ')left++;
    while (right >= 0 && transfer_Book_Name[right] == ' ')right--;
    string res = "";
    for (int i = left; i <= right; i++)
    {
        if (transfer_Book_Name[i] == ' ') {
            if (res[res.size() - 1] == ' ')continue;
            else res += ' ';
        }
        else {
            res += (char)(transfer_Book_Name[i]);
        }
    }
    return res;

}
void CSach::insert() // Add books details
// nhớ lên xem video bữa trước để làm cái tên sách có dấu cách
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Book Details ---------------------------------------------" << endl;
    //check sach ton tai chua

    vector<string> checkName;
    vector<int>checkTotal;
    vector<int>checkBorrowed;
    fstream file1;
    file1.open("LibraryRecord.txt", ios::in);
    string checkName1;
    int checkTotal1;
    int checkBorrowed1;
    getline(file1, checkName1, ':');
    checkName.push_back(checkName1);
    file1 >> checkTotal1 >> checkBorrowed1;
    string temp;
    getline(file1, temp);
    
        while (!file1.eof())
        {
            getline(file1, checkName1, ':');
            checkName.push_back(checkName1);
            file1 >> checkTotal1 >> checkBorrowed1;
            string temp;
            getline(file1, temp);
        }
        file1.close();
        //checkName.push_back("\n");
       

        
    
    
        cin.ignore();
    bookname:
    cout << "\t\t\tEnter Name: ";
    string tranfer_Book_Name;
    getline(cin, tranfer_Book_Name);
    Book_Name = getCorrect_Book_Name(tranfer_Book_Name);
    //upper_Name(Book_Name);
    transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
    //cout << Book_Name;
    int found = 0;
    for (int i = 0; i < checkName.size(); i++)
    {
        //cout << checkName[i] << endl;
        if (Book_Name == checkName[i])
        {
            found++;
            
        }
    }
    if (found != 0)
    {
        cout << "This Book Name '"<<Book_Name<<"' is Already Exist!!Please press Enter to try another name" << endl;
    hitenter:
        string tempspace;
        getline(cin, tempspace);
        goto bookname;
    }
                        

    info1:
    cout << "\t\t\tEnter Total Books: ";
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9')
        {
            cout << "\t\t\t\tOnly number please... Try again!\n";
            goto info1;
        }
    }
     Total_Book_Name=stoi(s);
    
    info2:
    cout << "\t\t\tEnter Books are being borrowed: ";
    string s2;

    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] != '0' && s2[i] != '1' && s2[i] != '2' && s2[i] != '3' && s2[i] != '4' && s2[i] != '5' && s2[i] != '6' && s2[i] != '7' && s2[i] != '8' && s2[i] != '9')
        {
            cout << "\t\t\t\tOnly number please... Try again!\n";
            goto info2;
        }
    }
    Borrowed_Book=stoi(s2);
    if (Borrowed_Book > Total_Book_Name)
    {
        cout << "It has to be equal or smaller than Total Books...Try again\n";
        goto info2;
    }
        
    file.open("LibraryRecord.txt", ios::app | ios::out);
    
    file << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
close:
    file1.close();
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
        
        getline(file, Book_Name, ':');
        file >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(file, temp);
        while (!file.eof())
        {
            cout << "\n\n\t\t\tBook No.: " << total++ << endl;
            cout << "\t\t\tName: " << Book_Name << "\n";
            cout << "\t\t\tTotal Books: " << Total_Book_Name << "\n";
            cout << "\t\t\tBooks are being borrowed: " << Borrowed_Book << "\n";
            
            
            getline(file, Book_Name, ':');
            file >> Total_Book_Name >> Borrowed_Book;
            string temp2;
            getline(file, temp2);
           //đọc kí tự '\n' dòng trên
           
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
        string transfer_Modified_Book;
        getline(cin, transfer_Modified_Book);
        Modified_Book = getCorrect_Book_Name(transfer_Modified_Book);
        transform(Modified_Book.begin(),Modified_Book.end(),Modified_Book.begin(),::toupper);
        file1.open("record.txt", ios::app | ios::out);
        getline(file, Book_Name, ':');
        file >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(file, temp);
        while (!file.eof())
        {
            if (Modified_Book != Book_Name)
            {
                file1  << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
            }
            else
            {
            
                cout << "\n\t\t\tMODIFY THE BOOK: " << Book_Name << endl;
                updateinfo1:
                cout << "\t\t\tUpdate Total: ";
                string s;

                getline(cin, s);
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9')
                    {
                        cout << "\t\t\t\tOnly number please... Try again!\n";
                        goto updateinfo1;
                    }
                }
                Total_Book_Name = stoi(s);
                updateinfo2:
                cout << "\t\t\tUpdate Number of Books are being Borrowed: ";
                string s2;

                getline(cin, s2);
                for (int i = 0; i < s.length(); i++)
                {
                    if (s2[i] != '0' && s2[i] != '1' && s2[i] != '2' && s2[i] != '3' && s2[i] != '4' && s2[i] != '5' && s2[i] != '6' && s2[i] != '7' && s2[i] != '8' && s2[i] != '9')
                    {
                        cout << "\t\t\t\tOnly number please... Try again!\n";
                        goto updateinfo2;
                    }
                }
                Borrowed_Book = stoi(s2);
                

                file1  << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
                found++;
            }
            getline(file, Book_Name, ':');
            file >> Total_Book_Name >> Borrowed_Book;
            string temp2;
            getline(file, temp2);
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
        string transfer_Find_Book;
        getline(cin, transfer_Find_Book);
        Find_Book = getCorrect_Book_Name(transfer_Find_Book);
        transform(Find_Book.begin(),Find_Book.end(),Find_Book.begin(),::toupper);
        getline(file, Book_Name, ':');
        file >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(file, temp);
        while (!file.eof())
        {

            if (Find_Book== Book_Name)
            {
                cout << "\n\n\t\t\tInformation Of " << Book_Name << "\n";
                cout << "\t\t\tTotal Books.: " << Total_Book_Name << "\n";
                cout << "\t\t\tNumber of Books are being Borrowed: " << Borrowed_Book << "\n";
                found++;
                
            }
            
            getline(file, Book_Name, ':');
            file >> Total_Book_Name >> Borrowed_Book;
            string temp2;
            getline(file, temp2);
                
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Your Wanted Book Not Found....";
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
        string transfer_Deleted_Book;
        getline(cin, transfer_Deleted_Book);
        Deleted_Book = getCorrect_Book_Name(transfer_Deleted_Book);
        transform(Deleted_Book.begin(), Deleted_Book.end(), Deleted_Book.begin(), ::toupper);
        file1.open("record.txt", ios::app | ios::out);
        getline(file, Book_Name, ':');
        file >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(file, temp);
        while (!file.eof())
        {
            if (Deleted_Book != Book_Name)
            {
                file1 << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data\n";
            }
            getline(file, Book_Name, ':');
            file >> Total_Book_Name >> Borrowed_Book;
            string temp2;
            getline(file, temp2);
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
        getline(file, Book_Name, ':');
        file >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(file, temp);
        while (!file.eof())
        {
            if (Rest_Book() > 0)
            {
                cout << "\t\t\tName of Book:" << Book_Name << endl;
                cout << "\t\t\tTotal Book:" << Total_Book_Name << endl;
                cout << "\t\t\tBooks are being Borrowed:" << Borrowed_Book << endl;
                cout << "\t\t\tNumbers of " << Book_Name << " are available:" << Rest_Book() << "\n\n";
                check_available++;
                

            }
            
                getline(file, Book_Name, ':');
                file >> Total_Book_Name >> Borrowed_Book;
                string temp2;
                getline(file, temp2);
            
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
    fstream filein,filein2, fileout;
    filein.open("LibraryRecord.txt", ios::in);
    if (!filein)
    {
        cout << "\t\t\t There's no data in the file...\n";
        filein.close();
    }
    else {
        
        getline(filein, Book_Name, ':');
        filein >> Total_Book_Name >> Borrowed_Book;
        string temp;
        getline(filein, temp);
        transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
        vector<string> check_name;
        while (!filein.eof())
        {
            check_name.push_back(Book_Name);
            getline(filein, Book_Name, ':');
            transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
            filein >> Total_Book_Name >> Borrowed_Book;
            string temp3;
            getline(filein, temp3);

        }
        filein.close();
        for (int i = 0; i < check_name.size(); i++)
        {
            cout << check_name[i] << endl;
        }

        filein2.open("Data.txt", ios::in);
        getline(filein2, Book_Name, ':');
        filein2 >> Total_Book_Name >> Borrowed_Book;
        string temp2;
        getline(filein2, temp2);
        transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
        vector<string>existed_name;
        int found = 0;
        int add = 0;
        fileout.open("LibraryRecord.txt", ios::app | ios::out);
        while (!filein2.eof())
        {
           
                for (int j = 0; j < check_name.size(); j++)
                {
                    if (Book_Name == check_name[j])
                    {
                        found++;
                        existed_name.push_back(check_name[j]);
                    }
                }
                //if (Book_Name == check_name[i])
                //{
                   // found++;
                    //existed_name.push_back(check_name[i]);
                if (found == 1)
                {
                    getline(filein2, Book_Name, ':');
                    transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
                    filein2 >> Total_Book_Name >> Borrowed_Book;
                    string temp3;
                    getline(filein2, temp3);
                }
                
                
                if(found==0)
                {
                 adddata:
                    fileout << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
                
                    getline(filein2, Book_Name, ':');
                    transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
                    filein2 >> Total_Book_Name >> Borrowed_Book;
                    string temp4;
                    getline(filein2, temp4);
                    
                }
                found = 0;
            
        }
        cout << "Data inputed successfully!" << endl;
        if (existed_name.size()!=0)
        {
            cout << "Except for the books are already existing:\n";
            for (int i = 0; i < existed_name.size(); i++)
            {
                cout << existed_name[i] << endl;
            }
        }

            

        //fileout.open("LibraryRecord.txt", ios::app | ios::out);
       // while (!filein2.eof())
        //{
           // transform(Book_Name.begin(), Book_Name.end(), Book_Name.begin(), ::toupper);
            
           // fileout << Book_Name << ":" << Total_Book_Name << " " << Borrowed_Book << "\n";
           //fileinnext:
           // getline(filein2, Book_Name, ':');
           // filein2 >> Total_Book_Name >> Borrowed_Book;
           // string temp2;
          //  getline(filein2, temp2);
        //}
       // cout << "\t\t\t Data inputed successfully...\n";

    }
    //filein.close();
    filein2.close();
    fileout.close();
    
}
