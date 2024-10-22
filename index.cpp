#include <iostream>

#include <fstream>

#include <string>

#include <unistd.h>

#include <cctype>

using namespace std;

void Log_in_panel();

void Bank_page();

void Commands_panel();

void Account_info();

void Deposit();

void Balance();

void Withdrawal();

string choice, username, password, check_username, check_password, lastname;

int bank_card_id, date, month, year, bank_choice, money;

int bank_balance = 0;

int main(){

system("clear");

sleep(1);

Log_in_panel();

return 0;

}

void Log_in_panel() {

cout << "\tWelcome to the Centeral-Bank\n"<<endl;

cout << "Enter «Log>> to log in to ypur account"<<endl;

cout << "Enter «Reg>> For registreation \n"<<endl;

cout << "Enter your choice -> ";

cin >> choice;

if (choice == "Log" || choice == "log") {

cout << "\nPlease enter your username\n>>> ";

cin >> username;

cout << "\nPlease enter your password\n>>> ";

cin >> password;

ifstream read (username + ".txt");

getline(read, check_username);

getline(read, check_password);

if (username == check_username && password == check_password) {

sleep(1);

system("clear");

Bank_page();

}

else {

cout << "\nUser is not found\n"<<endl;

sleep(1);

cout << "Please check your username/password"<<endl;

sleep(2);

system("clear");

Log_in_panel();

}
}

else if (choice == "Reg" || choice = "reg") {

cout << "\nPlease enter username ->"; cin >> username;

cout << "\nPlease enter lastname ->"; cin >> lastname;

cout << "\nPlease enter password ->"; cin >> password;

cout << "\nEnter your date -> "; cin >> date;

cout << "\nEnter your month ->"; cin >> month;

cout << "\nEnter your year -> "; cin >> year;

ofstream personal_users_info;

personal_users_info.open(username + "pr.txt", ofstream::out | ofstream::app);

personal_users_info << "Name: "<< username << ""<<lastname<<endl << "Password: "<< password

<<endl << "Data: "<< date<<"/"<<month<<"/"<< year <<endl;

personal_users_info.close();

ofstream user_file;

user_file.open(username + ".txt", ofstream:: out | ofstream:: app);

user_file << username << endl << password;

user_file.close();

cout << "\nYou finished your registration"<<endl;

sleep(1);

system("clear");

Bank_page();
}
else {

cout << "\nCommand is not found\n"<<endl;

sleep(1);

cout << "Please try again!\n"<<endl;

sleep(2);

system("clear");

Log_in_panel();

}
}

void Bank_page() {

cout <<"\tWelcome to the Bank page "<< username <<endl<<endl;

cout << "========================================="<<endl;

cout << "|" <<" [1] --> Account info"<< "                   |"<<endl;
cout << "|" <<" [2] --> Deposit"<< "                        |"<<endl;
cout << "|" <<" [3] --> Check balance"<< "                  |"<<endl;
cout << "|" <<" [4] --> Withdrawal"<< "                     |"<<endl;
cout << "| "<<" [5] --> exit"<< "                           | "<<endl;
cout << "========================================="<<endl;
cout <<endl;

while (bank_choice != 5) {

cout << "Enter the command ->"; cin >>bank_choice;

Commands_panel();
}
}

void Commands_panel() {
    switch(bank_choice)

{

case 0: system("clear"); Bank_page(); break;

case 1: system("clear"); Account_info(); break;

case 2: system("clear"); Deposit();

break;

case 3: system("clear"); Balance();

break;

case 4: system("clear"); Withdrawal();

break;

case 5: cout << "\nYou left the Bank app\n"<<endl; sleep (1); break;

break;



default: cout <<"\nCommand is not found"<<endl; system("clear"); Bank_page();
}
}

void Account_info(){

cout << "Your personal information\n"<<endl; sleep(1);

ifstream tiop(username + "pr.txt");

char ch;

while (tiop)

{

tiop.get(ch);
cout << ch;

}

sleep(1);

cout <<"Enter [0] to go back\n"<<endl;

sleep(1);

}

void Deposit(){

cout << "\tDeposit page\n"<<endl;

cout << "Enter the amount of money "; cin >> money;

if (money > 1000) {

sleep(1);

cout << "\nLoading...\n"<<endl;

sleep (2);

cout << "\nToo big number, please try again!\n"<<endl;

sleep (2);

system("clear");

Deposit();
}
else {

sleep(1);

cout << "\nLoading...\n"<<endl;

sleep (2);

cout << "Deposit added succesfully\n"<<endl;

sleep (2);

system("clear");

Bank_page();

}

}

void Balance() {

cout << "Your balance information\n"<<endl;

cout << "Name: "<< username << ""<< lastname<<endl;
sleep(2);

cout << "\nYour current balance is "<< bank_balance<<"f"<< endl;

char yn;

sleep (2);

cout << "\nDo you want to put money on your card (y/n) -> "; cin >> yn;

if (yn == 'y'){ 

cout << "\nEnter the amount of monet -> "; cin >> money; bank_balance += money;

cout << "\nYou got +"<< money <<"\n"<<endl;

cout << "Now your balance is "<< bank_balance << "£\n"<<endl;

sleep(3);

system("clear");

Bank_page();

}

else if (yn == 'n') {

cout << "\nYour balance is still the same\n"<<endl;

sleep (2);

system("clear");

Bank_page();

}

else{

cout << "\nCommand is not found, please try again\n"<<endl;

sleep (2);

system("clear");

Balance();
}

}

void Withdrawal() {

cout << "\tWithdrawal page\n"<<endl;

cout << "Enter the amout of money -> "; cin >> money;

if (bank_balance < money) {

sleep(1);

cout << "\nLoading...\n"<<endl;

sleep (2);

cout << "\nYou do not have enough money on your card!\n"<<endl;

sleep (2);

system("clear");

Bank_page();

}

else {

sleep(1);

cout << "\nLoading...\n"<<endl;

sleep (2);

cout << "Withdrawal added succesfully\n"<<endl;

bank_balance -= money;

sleep (2);

system("clear");

Bank_page();
}
}