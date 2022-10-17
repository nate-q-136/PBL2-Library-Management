#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class CSach
{
private:
    string Book_Name;
    int Total_Book_Name;
    int Borrowed_Book;
    int Num_Name_Book;

public:
    CSach() {};
    CSach(string, int, int, int) {};
    int getNum_Name_Book();
    int Rest_Book();
    void Book_Existing();
    void add_Num_Book();
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void input_data_to_file();
};