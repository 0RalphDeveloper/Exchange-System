#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[36m"
#define YELLOW "\033[33m"
#define GREEN "\033[31m"
#define SUPER "\033[1m"
void homeDisplay();
void displayPage();
void choiceDisplay();
void signUp();
void signIn();
void choiceOptions(double balance);
void generateCurrency(double balance);
double addBalance(double balance);
void displayBalance(double balance);
void displayCurrent( double usd, double yen, double euro, double pound, double canadian);
void sellingCurrencies(double balance, double usd1, double  yen1, double euro1, double pound1, double canadian1);


using namespace std;

int main()
{
	char already;
	
	displayPage();
	cout<<SUPER<<"-------------------------------------------------------------------"<<RESET<<"\n\n";
	cout<<"Already have an account? (Y/N): ";
	cin>>already;
	
	 
	
	if(already == 'Y' || already == 'y'){
		signIn();
		}
	else if(already == 'N' || already == 'n'){
		signUp();
		}
	else{
		cout<<"Can't identify your choice.\n\n";
		system("pause");
		system("cls");
		main();
		
		}
	
	
}

void signIn()
{
		Sleep(350);
		system("cls");
			cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"["<<RESET << YELLOW << "\t\t  SIGN IN" << RESET << "\t\t"<<SUPER<<" ]"<<RESET << endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t==========================================\n\n";
		string userId, password, id, pass;
        int count;
        double balance =0;
        double usd =0;
        double yen =0;
        double euro = 0;
        double pound = 0;
        double canadian = 0;
        back:
        cout << "\tUSERNAME: ";
        cin >> userId;
        cout << "\tPASSWORD ";
        cin >> password;

        ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();
int display;
    if (count == 1) {
		int age = 0;
		int pick;
        homeDisplay();
        
        cout <<"Account Name: "<< userId <<endl << endl;
        cout<<"Wallet Balance: P"<<setprecision(2)<<fixed<<balance;
        	cout<<SUPER<<"\n\n-------------------------------------------------------------------"<<RESET;
        cout<<"\n\n\t1.Verify Account\n\t2.Log Out\n";
        returnPick:
        cout<<"\tEnter your choice: ";
        cin>>pick;
        if(pick == 1){
        	system("pause");
        	system("cls");
        		cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t   VERIFYING ACCOUNT\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
        ages:
 		cout<<"\n\nVerify Account Age: ";
        cin>>age;
        	cin.clear( );
    fflush(stdin);
        if(age >=18 && age <=150){
        system("pause");
        system("cls");
        choiceDisplay();
  	   cout<<"Wallet Balance: P"<<setprecision(2)<<fixed<<balance;
        displayCurrent(usd, yen, euro, pound, canadian);
        choiceOptions(balance);  
        }
        else{
        	cout<<"Can't verified your account. Your age is below 18.\n";
        	goto ages;
        	}
        }
        else if(pick == 2){
        	cout<<"\nLOGGING OUT...\n.";
        	system("pause");
        	system("cls");
        	main();
        }
        else{
        	cout<<"\t\nYour choice can't be identified.\n";
        	goto returnPick;
        	}
        
     
    }
    else {
        cout << "\n\nLOGIN ERROR \n Please check your username or password\n";
        goto back;
    }
}


void signUp()
{
	string already;
	int pin;
	Sleep(350);
	system("cls");
cout<<"\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"["<<RESET << GREEN << "\t\t  SIGN UP" << RESET << "\t\t"<<SUPER<<" ]"<<RESET << endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t==========================================\n\n";
	
	string ruserid, rpassword;
    cout << "\tEnter username: ";
    cin >> ruserid;
    cout << "\tEnter password: ";
    cin >> rpassword;
    cout<<"\tEnter numeric pin: ";
	cin>>pin;
	
	ofstream f2("pin.txt", ios::app);
	f2 << pin << endl;

    ofstream f1("records.txt", ios::app);

    f1 << ruserid << ' ' << rpassword << endl;
    cout << "\n\tDIRECTING TO SIGN IN PAGE... \n\n";
    Sleep(1000);
	system("cls");
	signIn();
    

}

void homeDisplay()
{
	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"["<<RESET << RED << "\tBLOCK CHAIN CLOUD WALLET" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
}



void displayPage(){
	 	cout<<endl;
	 		cout << "\t"<<RED<<"=================================================="<<RESET<<"\n ";
	cout << "\t"<<RED<<"[\t\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<RED<<"["<<RESET << SUPER << "     WELCOME TO THE BLOCK CHAIN CLOUD WALLET" << RESET << "\t"<<RED<<" ]"<<RESET << endl;
	cout << "\t"<<RED<<"[\t\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<RED<<"=================================================="<<RESET<<"\n\n";
}

void choiceOptions(double balance){
	int choice;
	
			
	cout<<"\n\n\tOPTIONS\n\t1.Add Wallet Balance\n\t2.Exchange Currency\n\t3.Send Wallet Balance\n\t4.Log Out\n\n";
	
	do{
	cout<<"Enter option choice: ";
	cin>>choice;
	cin.clear( );
    fflush(stdin);
    if(choice == 1){
    	system("pause");
    	system("cls");
			int registered, attempt, inputed;
			int count;
			
	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t    ADD WALLET BALANCE\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
			
			back:
			cout<<"Enter registered pin: ";
			cin>>registered;
				
			ifstream registeredpin("pin.txt");
				while(registeredpin >> inputed){
				if(inputed == registered )
				{
					count = 1;
					break;
					system("cls");
				}
			}
		registeredpin.close();
		if(count ==1)
	{
		
		balance = balance + addBalance(balance);
		system("pause");
		system("cls");
		choiceDisplay();
		displayBalance(balance);
		choiceOptions(balance);
		
	}	 
	else
	{
		cout<<"INVALID PIN, PLEASE BE SURE IT'S VALID\n";
		goto back;
		}
    }
    else if(choice == 2)
    {
    	system("pause");
    	system("cls");
    		cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t      EXCHANGE PESO\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
			
   	generateCurrency(balance);
   	
    }
    else if(choice == 3)
    {
    		 system("cls");
    		 
    	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\tSENDING ACCOUNT BALANCE\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
    		 ifstream input("records.txt");
	string id, userId;
	cout<<"Enter receiver username: ";
	cin>>userId;
	
	int count =0;
        while (input >> id) {
        if (id == userId) {
            count = 1;
            
            break;
        }
    }
    input.close();
            	double total1 =0;
    if (count == 1) {
    		double send = 0;
    		    		 system("cls");
    		 
    	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\tSENDING ACCOUNT BALANCE\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
	cout<<"Account found username: "<<userId<<endl<<endl;
    	cout<<"CURRENT BALANCE: "<<balance<<endl;
		cout<<"Enter balance to be sent: ";
    	cin>>send;
    				cin.clear( );
    fflush(stdin);
    	
    		if (send > balance){
		cout<<"Your balance is insufficient."<<endl;
		system("pause");
		system("cls");
		choiceDisplay();
		displayBalance(balance);
		choiceOptions(balance);
    		}else if(send < 0){
    			cout<<"invalid amount\n";
    			system("pause");
    			 system("cls");
    			 choiceDisplay();
   	displayBalance(balance);
		choiceOptions(balance);
    			}
    		else{
    			balance = balance - send;
    			system("pause");
    			system("cls");
    		 
    	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t TRANSACTION RECEIPT\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
           	cout<<SUPER<<"\n-------------------------------------------------------------------"<<RESET<<endl<<endl;
           	cout<<"\t    AMOUNT OF MONEY SENT: P"<<send<<endl;
    			cout<<"\t    SUCCESSFULLY SENT TO: "<<userId<<endl;
    			cout<<"\t    YOUR NEW BALANCE IS: P"<<balance<<endl<<endl;
    			    	   // Get current time
    std::time_t currentTime = std::time(nullptr);
    char timeString[100];
    std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
    std::cout << "\t    TRANSACTION TIME: " << timeString << std::endl<<endl;
           	cout<<SUPER<<"-------------------------------------------------------------------"<<RESET<<endl;
    			system("pause");
    			system("cls");
    			choiceDisplay();
    			displayBalance(balance);
    			choiceOptions(balance);
    			
    			}
   				
   	}				    
    else{
    	system("cls");
    		 
    	cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\tSENDING ACCOUNT BALANCE\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
    	
    	cout<<"USERNAME CAN'T BE FOUND. OR IT IS NOT VALID. PLEASE MAKE SURE IT IS CORRECT.\n";
    	system("pause");
    	system("cls");
    	choiceDisplay();
		displayBalance(balance);
		choiceOptions(balance);
       	}
    }
    else if(choice == 4){
    	cout<<"\nLOGGING OUT YOUR ACCOUNT.";
    	cout<<"\nPLEASE WAIT PATIENTLY.\n";
    	Sleep(5000);
    	system("cls");
    	main();
    	}
    
  
	}while(choice !=4);
	
}
	
void displayBalance(double balance)
{
	cout<<"Wallet Balance: P"<<setprecision(2)<<fixed<<balance;
	
}

void displayCurrent(double usd, double yen, double euro, double pound, double canadian)
{
cout<<"\t$"<<setprecision(2)<<fixed<<usd;
cout<<"\t¥"<<setprecision(2)<<fixed<<yen;
cout<<"\t€"<<setprecision(2)<<fixed<<euro;
cout<<"\t£"<<setprecision(2)<<fixed<<pound;
cout<<"\tCA$"<<setprecision(2)<<fixed<<canadian;
}		
	
	
void generateCurrency(double balance){
	srand(time(0));
	int choice;
	double amounted =0;
	double usd =0;
	double yen =0;
	double euro =0;
	double  pound =0;
	double  canadian =0;
	double usd1 =0;
	double yen1 =0;
	double euro1 =0;
	double pound1 =0; 
	double canadian1 =0;
	
	
	displayBalance(balance);
	
	cout<<"\n\nPESO INTO CURRENCY OF EACH COUNTRY:\n";
	usd = .018+ rand() % 1;
	yen = .060 + rand() % 1;
	euro = .016+ rand() % 2;
	pound = .014 + rand() %1;
	canadian = .024 + rand() % 1;
	cout<<"$"<<usd<<"\t¥"<<yen<<"\t£"<<euro<<"\t€"<<pound<<"\tCA$"<<canadian<<endl<<endl;

	cout<<endl;
	cout<<"\n\nEXCHANGING PESO INTO: \n1.USD\n2.YEN\n3.EURO\n4.POUND\n5.CANADIAN DOLLAR\n6.Retrun\n\n";
	char exchange;
	returning:
	cout<<"Enter choice number: ";
	cin>>choice;
	
		cin.clear( );
    fflush(stdin);

	
	switch(choice)
	{
	case 1 :
	  cout<<"Enter value to be converted into USD: ";
	cin>>amounted;
		cin.clear( );
    fflush(stdin);
	if(balance >=  amounted ){
	usd1 = usd1+ (amounted * usd);
	balance =  balance - amounted;
	cout<<"\nCurrent Balance "<<balance<<endl;
	cout<<"USD VALUE "<<usd1<<endl;
	n:
	cout<<"Do you want to exchange again(Y/N): ";
	cin>>exchange;
		cin.clear( );
    fflush(stdin);
	
	if(exchange == 'Y' || exchange == 'y'){
			cout<<endl;
		goto returning;
		}
	else if (exchange == 'N' || exchange == 'n'){
			system("pause");
 	       system("cls");
			sellingCurrencies(balance, usd1, yen1,  euro1,  pound1,  canadian1);	
		}
	}
	else{
		cout<<"Invalid, balance insufficient\n\n";
		cout<<"\nCurrent Balance "<<balance<<endl;
		goto n;
		}
		break;
	case 2 : cout<<"Enter value to be converted into YEN: ";
	cin>>amounted;
		cin.clear( );
    fflush(stdin);
	if(balance >= amounted){
	yen1 = yen1+ (amounted * yen);
	balance = balance - amounted;
	cout<<"\nCurrent Balance "<<balance<<endl;
	cout<<"YEN VALUE "<<yen1<<endl;
	cout<<"Do you want to exchange again: ";
	cin>>exchange;
		cin.clear( );
    fflush(stdin);
	if(exchange == 'Y' ||exchange == 'y'){
			cout<<endl;
		goto returning;
		}
	else if (exchange == 'N' || exchange == 'n'){
			system("pause");
			system("cls");
		    sellingCurrencies(balance, usd1, yen1,  euro1,  pound1,  canadian1);
		}
	}
	else{
		cout<<"Invalid, balance insufficient\n\n";
		cout<<"\nCurrent Balance "<<balance<<endl;
		goto n;
		}
		break;
	case 3 : cout<<"Enter value to be converted into EURO: ";
	cin>>amounted;
		cin.clear( );
    fflush(stdin);
	if(balance >= amounted){
	euro1 = euro1+ (amounted * euro);
	balance = balance - amounted;
	cout<<"\nCurrent Balance "<<balance<<endl;
	cout<<"EURO VALUE "<<euro1<<endl;
	cout<<"Do you want to exchange again: ";
	cin>>exchange;
	if(exchange == 'Y' || exchange == 'y'){
			cout<<endl;
		goto returning;
		}
	else if (exchange == 'N' || exchange == 'n'){
		system("pause");
		system("cls");
		sellingCurrencies(balance, usd1, yen1,  euro1,  pound1,  canadian1);
		}
	}
	else{
		cout<<"Invalid, balance insufficient\n\n";
		cout<<"\nCurrent Balance "<<balance<<endl;
		goto n;
		}
		break;
	case 4 : cout<<"Enter value to be converted into POUND: ";
	cin>>amounted;
		cin.clear( );
    fflush(stdin);
	if(balance >= amounted){
	pound1 = pound1+ (amounted * pound);
	balance = balance - amounted;
	cout<<"\nCurrent Balance "<<balance<<endl;
	cout<<"POUND VALUE "<<pound1<<endl;
	cout<<"Do you want to exchange again: ";
	cin>>exchange;
	if(exchange == 'Y' || exchange == 'y'){
			cout<<endl;
		goto returning;
		}
	else if (exchange == 'N' || exchange == 'n'){
			system("pause");
        	system("cls");
        	sellingCurrencies(balance, usd1, yen1,  euro1,  pound1,  canadian1);
		}
	}
	else{
		cout<<"Invalid, balance insufficient\n\n";
		cout<<"\nCurrent Balance "<<balance<<endl;
		goto n;
		}	
		break;
	case 5 : cout<<"Enter value to be converted into CANADIAN DOLLAR: ";
	cin>>amounted;
		cin.clear( );
    fflush(stdin);
	if(balance >= amounted){
	canadian1 = canadian1+ (amounted * canadian);
	balance  = balance - amounted;
	cout<<"\nCurrent Balance "<<balance<<endl;
	cout<<"CANADIAN DOLLAR VALUE "<<canadian1<<endl;
	cout<<"Do you want to exchange again: ";
	cin>>exchange; 
	if(exchange == 'Y' || exchange == 'y'){
			cout<<endl;
		goto returning; 
		}
	else if (exchange == 'N' || exchange == 'n'){
			system("pause");
 	       system("cls");
        	sellingCurrencies(balance, usd1, yen1,  euro1,  pound1,  canadian1);
		}
	}
	else{
		cout<<"Invalid, balance insufficient\n\n";
		cout<<"\nCurrent Balance "<<balance<<endl;
		goto n;
		}
	break;
	case 6 :
	 cout<<"\nReturning home.\n\n";
	 system("pause");
	 system("cls");
	 choiceDisplay();
	 displayBalance(balance);
	 choiceOptions(balance);
	 break;
	default : cout<<"\nIncorrect choice.\n\n";
						cout<<endl;
					goto returning;
	
    }
}

void sellingCurrencies(double balance, double usd1, double  yen1, double euro1, double pound1, double canadian1){
	double usd2 = 0;
	double yen2 =0;
	double euro2 =0;
	double pound2 =0;
	double canadian2 =0;
			double exchanges;
	
	char check;
		cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t    EXCHANGE CURRENCIES\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
			here:
			cout<<"Do you want to sell your currencies(Y/N): ";
			cin>>check;
			if(check == 'Y' || check == 'y'){
				system("pause");
				system("cls");
					cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t    EXCHANGE CURRENCIES\t" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
			
		srand(time(0));
		cin.clear( );
    fflush(stdin);

		int currencies;
		cout<<"\nEXCHANGING CURRENCY INTO: \n1.USD INTO PESO\n2.YEN INTO PESO\n3.EURO INTO PESO\n4.POUND INTO PESO\n5.CANADIAN DOLLAR INTO PESO\n6.Return\n\n\n";
	cout<<"\nCURRENCY OF EACH COUNTRY INTO PESO\n";
	usd2 = .06+ rand() % 80;
	yen2 = .37+ rand() % 10;
	euro2 = .47+ rand() % 85;
	pound2 = .61 + rand() %81;
	canadian2 = .74 + rand() % 51;
char exc;

	cout<<"$"<<usd2<<"\t¥"<<yen2<<"\t£"<<euro2<<"\t€"<<pound2<<"\tCA$"<<canadian2<<endl<<endl;
		displayBalance(balance);
	displayCurrent(usd1, yen1, euro1, pound1, canadian1);
	cout<<endl<<endl;
	ret:
	cout<<"Enter currency number: ";
	cin>>currencies;
		cin.clear( );
    fflush(stdin);
 
	switch(currencies){
		case 1 : cout<<"Enter usd value to be exchanged: ";
					cin>>exchanges;
						cin.clear( );
    fflush(stdin);
					if(usd1 >  exchanges){
						balance = balance +(exchanges * usd2);
						usd1 -= exchanges;
						thiss:
							cout<<"Do you want to exchange again (Y/N): ";
					cin>>exc;
					if(exc == 'Y' || exc == 'y'){
						cout<<endl;
					goto ret;
								}
					else if(exc == 'N' || exc == 'n'){
						system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
						}
						}
					else{
						cout<<"Invalid, balance insufficient\n\n";
						goto thiss;
						}
				break;
				
		case 2 : cout<<"Enter yen value to be exchanged: ";
					cin>>exchanges;
						cin.clear( );
    fflush(stdin);
					if(yen1 >= exchanges){
						balance =   balance +  (exchanges * yen2);
						yen1 -= exchanges;
							cout<<"Do you want to exchange again (Y/N): ";
					cin>>exc;
					if(exc == 'Y' || exc == 'y'){
						cout<<endl;
					goto ret;
								}
					else if(exc == 'N' || exc == 'n'){
						system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
						}
						}
					else{
						cout<<"Invalid, balance insufficient\n\n";
						displayBalance(balance);
						goto thiss;
						}
				break;
			case 3 : cout<<"Enter euro value to be exchanged: ";
					cin>>exchanges;
						cin.clear( );
    fflush(stdin);
					if(euro1 >= exchanges){
						balance =   balance +  (exchanges * euro2);
						euro1 -=  exchanges;
							cout<<"Do you want to exchange again (Y/N):";
					cin>>exc;
					if(exc == 'Y' || exc == 'y'){
						cout<<endl;
					goto ret;
								}
					else if(exc == 'N' || exc == 'n'){
						system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
						}
						}
					else{
						cout<<"Invalid, balance insufficient\n\n";
						goto thiss;
						}
				break;
			case 4 : cout<<"Enter pound value to be exchanged: ";
					cin>>exchanges;
						cin.clear( );
    fflush(stdin);
					if(pound1 >= exchanges){
						balance =   balance +  (exchanges * pound2);
						pound1 -= exchanges;
							cout<<"Do you want to exchange again (Y/N): ";
					cin>>exc;
					if(exc == 'Y' || exc == 'y'){
						cout<<endl;
					goto ret;
								}
					else if(exc == 'N' || exc == 'n'){
						system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
						}
						}
					else{
						cout<<"Invalid, balance \n";
						goto thiss;
						}
				break;
			case 5 : cout<<"Enter canadian dollar value to be exchanged: ";
					cin>>exchanges;
						cin.clear( );
    fflush(stdin);
					if(canadian1 >=  exchanges){
						balance =   balance +  (exchanges * canadian2);
						canadian1 -= exchanges;
							cout<<"Do you want to exchange again (Y/N): ";
					cin>>exc;
					if(exc == 'Y' || exc == 'y'){
						cout<<endl;
					goto ret;
								}
					else if(exc == 'N' || exc == 'n'){
						system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
						}
						}
					else{
						cout<<"Invalid, balance insufficient\n\n";
						goto thiss;
						}
				break;
			case 6 : system("pause");
						system("cls");
						choiceDisplay();
						displayBalance(balance);
						displayCurrent(usd1, yen1, euro1, pound1, canadian1);
						choiceOptions(balance);
					break;
						
			default : cout<<"Invalid Choice: ";
							system("pause");
							system("cls");
							goto ret;
		}
			}
			else if(check == 'N' || check == 'n'){
					system("pause");
					system("cls");
					choiceDisplay();
					displayBalance(balance);
					displayCurrent(usd1, yen1, euro1, pound1, canadian1);
					choiceOptions(balance);
				}
			else{
				cout<<"\nInvalid Input.\n";
				
				goto ret;
				}
}


double addBalance(double balance){
	
		double amount;
		cout<<"Enter amount to deposited: ";
		cin>>amount;

	
		if(amount > 0)
		{	
			return amount;
		}
		else if(amount < 0)
		{
			cout<<"\n\nAMOUNT CAN'T BE DEPOSITED.\n";
			system("pause");
			system("cls");
			choiceDisplay();
			displayBalance(balance);
			choiceOptions(balance);
		}
		else
		{
		cout<<"\n";
		cout<<"That's invalid amount."<<endl<<endl;
		system("pause");
		system("cls");
		choiceDisplay();
		displayBalance(balance);
		choiceOptions(balance);
		}
}

void choiceDisplay(){
		cout << "\n\t"<<SUPER<<"=========================================="<<RESET<<"\n ";
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"[ "<<RESET << RED << "\t VERIFIED ACCOUNT SECTION" << RESET << "\t"<<SUPER<<" ]" <<RESET<< endl;
	cout << "\t"<<SUPER<<"[\t\t\t\t\t ]"<<RESET<<"\n";
	cout << "\t"<<SUPER<<"=========================================="<<RESET<<"\n\n";
	
	}

