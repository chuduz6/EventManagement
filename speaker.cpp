/*----------------------------------------------------------------------------------------------
PROGRAMMER:				Chudamani Aryal
LANGUAGE:				C or C++
CLASS:                  CSE 1320-001, "Intermediate Programming in C", Summer 2010
PLATFORM:               OMEGA 
OS:                     UNIX 
COMPILER:               gcc
ASSIGNMENT:				Lab #4
ASSIGNED:               November 27,2010
DUE:                    December 9, 2010
DESCRIPTION:            Event management database that inputs, updates, sorts, checks for validity of inputs and displays as desired using C++ concepts as stated in the assignment requirement 
WEIGHT:                 10%
------------------------------------------------------------------------------------------------------*/ 

#include <iostream>
#include <string.h>
#include <iomanip>
#include "speaker.h"

//constants
#define EVENTMAX 40
#define EVENTMIN 12
#define MAXSTATE 3
#define MAXTITLE 128
#define MAXNAME 40
 
using namespace std;

// prototype of fucntions
void show_seriesCode();
void show_expertiseCode();


// defintion of the fucntion declared in the main
// initialization of the event
event::event()
{
	firstName=new char[MAXNAME];
	lastName=new char[MAXNAME];
	titleName=new char[MAXTITLE];
	stateName=new char[MAXSTATE];

	// initializing the variables
	speakerCode=100;
	pday=1;
	pmonth=1;
	pyear=2010;
	pTime=0;
	seriesCode='M';
	ebirdPrice=0;
	regPrice=0;
	strcpy(stateName, "NA");
	expertiseCode='M';
	bday=1;
	bmonth=1;
	byear=1980;
	strcpy(firstName, "FirstName");
	strcpy(lastName, "LastName");
	eventPrice=FREE;
	eventSeats.total_seats=0;
	eventSeats.tickets_sold=0;
	strcpy(titleName, "The Default Title");
	
}

// bool for checking the speaker Code and returning the boolean value
bool event::set_speakerCode(int code)
{
	while (code<100 || code>999)
	{
		cout << "Invalid Speaker Code. The valid range is between 100 to 999 (inclusive).\n";
		cout << "Enter the valid speaker Code." << endl;
		cin >> code;
	}
	speakerCode=code;
	return true;
}

// bool for checking the pday and returning the boolean value
bool event:: set_pday(int day)
{
	while(day<0||day>31)
	{
		cout << "Invalid day of performance. The valid range should be between 0 to 31.\n";
		cout << "Please Enter the valid day of performance.\n";
		cin >> day;
	}
	pday=day;
	return true;
}

//bool for checking the pmonth and returning the boolean value
bool event::set_pmonth(int month)
{
	while(month<0 ||month>12)
	{
		cout << "Invalid month of performance. The valid range should be between 0 to 12.\n";
		cout << "Please enter the valid month of performance.\n";
		cin >> month;
	}
	pmonth=month;
	return true;
}

//bool for checking the pyear and returning the boolean value
bool event::set_pyear(int year)
{
	while(year<2000 ||year>2050)
	{
		cout<< "Invalid year of performance. The valid range should be between 2000 to 2050.\n";
		cout << "Please Enter the valid year of performance.\n";
		cin >> year;
	}
	pyear=year;
	return true;
}

// bool for checking pTIme and returning the boolean value
bool event::set_pTime(float time)
{
	while(time<0 || time>=24 || (time-(int)time)<0 || (time-(int)time)>59 )
	{
		cout<< "Invalid time of performance. The valid range should be between 0.00 to 23.59. Also remember the Military format HH.MM.\n";
		cout << "Please Enter the valid time of performance.\n";
		cin >> time;
	}
	pTime=time;
	return true;
}

// bool for checking seriesCode and returning the boolean value
bool event::set_seriesCode(char sCode)
{
	while (sCode != 'M' && sCode != 'E' && sCode != 'D'&& sCode != 'C' && sCode != 'S' && sCode != 'U' && sCode != 'L' && sCode != 'O')
	{
		cout << "Invalid seriesCode. Look at the instructions. Try again.\n";
		show_seriesCode();
		cout<< "Enter the valid series Code.\n";
		cin>>sCode;
	}
	seriesCode=sCode;
	return true;
}

// bool for cheking ebirdPrice and returning the boolean value
bool event::set_ebirdPrice(float ePrice)
{
	while(ePrice<0.0 || (ePrice-(int)ePrice)<0.0|| (ePrice-(int)ePrice)>0.99)
	{
		cout<< "Invalid ebird Price. Price has to be positive. Also the cents has to positive and less than 100.Try again.\n";
		cout << "Enter the ebird Price.\n";
		cin >> ePrice;
	}
	ebirdPrice=ePrice;
	return true;
}

// bool for checking regPrice and returning the boolean value
bool event:: set_regPrice(float rPrice)
{
	while(rPrice<0.0 || (rPrice-(int)rPrice)<0.0|| (rPrice-(int)rPrice)>0.99)
	{
		cout<< "Invalid reg Price. Price has to be positive. Also the cents has to positive and less than 100.Try again.\n";
		cout << "Enter the reg Price.\n";
		cin >> rPrice;
	}
	regPrice=rPrice;
	return true;
}

// bool for state name and returning the boolean value
bool event::set_stateName(char state[])
{
	if (strlen(state)>MAXSTATE-1)
	{
		strcpy(stateName, "NA");
		return false;
	}
	strcpy(stateName, state);
	return true;
}

// bool for checking expertiseCode and returning the boolean value
bool event::set_expertiseCode(char eCode)
{
		char garbage;
	
		while (eCode!='A' && eCode!= 'B' && eCode!= 'C' && eCode!= 'P' && eCode!= 'E' && eCode!= 'I' && eCode!= 'M' && eCode!= 'S' && eCode!= 'O' && eCode!= 'Z' && eCode!='L' && eCode!= 'D' && eCode!= 'X' && eCode!='N' && eCode!='R' && eCode!='W' && eCode!='U' && eCode!= 'G')
		{
				cout<<"Error in expertise code. Look at the instructions and Try again.\n";
				show_expertiseCode();
				cin>>garbage>>eCode;
			
		}
		expertiseCode=eCode;
		return true;

}

// bool for checking bday and returning the boolean value
bool event::set_bday(int day1)
{
	while(day1<0 || day1 >31)
	{
		cout << "Invalid day of birth. The valid range should be between 0 and 31 (inclusive).\n";
		cout << "Please enter the valid day of birth.\n";
		cin >> day1;
	}
	bday=day1;
	return true;
}

// bool for checking bmonth and returning the boolean value
bool event::set_bmonth(int month1)
{
	while(month1<0 || month1>12)
	{
		cout<<"Invalid month of birth. The valid range should  be between 0 to 12. \n";
		cout << "Please enter the valid month of birth.\n";
		cin >> month1;
	}
	bmonth=month1;
	return true;
}

// bool for checking byear and returning the boolean value
bool event::set_byear(int year, int year1)
{
	while((year-year1)<10)
	{
		cout << "Invalid year of birth. The difference between performance and birth should be at least 10 years.\n";
		cout << "Please enter the valid year of birth.\n";
		cin >> year1;
	}
	byear=year1;
	return true;
}

// bool for checking firstName and returning the boolean value
bool event::set_firstName(char fName[])
{
	if (strlen(fName)>MAXNAME-1)
	{
		fName[MAXNAME-1]='\0';
		strcpy(firstName, fName);
		return false;
	}
	strcpy(firstName, fName);
	return true;
}

// bool for checking lastName and returning the boolean value
bool event::set_lastName(char lName[])
{
	if (strlen(lName)>MAXNAME-1)
	{
		lName[MAXNAME-1]='\0';		
		strcpy(lastName, lName);
		return false;
	}
	strcpy(lastName, lName);
	return true;
}

// bool for checking eventPrice and returning the boolean value
bool event::set_eventPrice(float ePrice, float rPrice)
{
	if (ePrice==0 && rPrice==0)
		eventPrice=FREE;
	else
		eventPrice=PAID;
	return true;
}

// bool for checking eventSeats and returning the boolean value
bool event::set_tickets_sold(int num)
{
	while(num<0)
	{
		cout << "Invalid number. Should be positive. Please enter again.\n";
		cin >> num;
	}
	eventSeats.tickets_sold=num;
	return true;

}

// bool for checking eventseats and returning the boolean value
bool event::set_total_seats(int num)
{
	while(num<0)
	{
		cout << "Invalid number. Should be positive. Please enter again.\n";
		cin >> num;
	}
	eventSeats.total_seats=num;
	return true;
}

// bool for checking titleName and returning the boolean value
bool event:: set_titleName(char tName[])
{
	if (strlen(tName)>MAXTITLE-1)
	{
		tName[MAXTITLE-1]='\0';
		strcpy(titleName, tName);
		return false;
	}
	strcpy(titleName, tName);
	return true;
}

// format for the series code
void show_seriesCode(void)
{
	cout << "M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, \nC for College for Engineering, S for College of Science, U for University sponsored, \nL for Levitt Pavilion, and O for Others.\nEnter the corresponding character.\n";
}

// format for the expertise code
void show_expertiseCode(void)
{
	cout << "Here is the format. \nA - Aerospace Engineering, B - Bioengineering, C - Civil Engineering, \nP - Computer Science and Engineering, E - Electrical Engineering, I - Industrial Engineering, \nM - Mechanical Engineering, S - Materials Science and Engineering, O - Other Engineering, \nZ - Science, L - Liberal Arts, D - Education, X - Business, \nN - Nursing, R - Architecture, W - Social Work, U - Urban and Public Affairs, G - General\n";
}

// this function prints the date in the array
void event::printSingle()
{
	cout << speakerCode << "\t" << pday << "\t" << pmonth << "\t" << pyear << "\t" << fixed << setprecision(2) << pTime << "\t" << seriesCode << "\t" << fixed << setprecision(2) << ebirdPrice << "\t" << fixed << setprecision(2) << regPrice << "\t" << stateName << "\t" << expertiseCode << "\t" << bday << "\t" << bmonth << "\t" << byear << "\t" << firstName << "\t\t" << lastName << "\t\t";
	if(eventPrice==FREE)
		cout << eventSeats.total_seats;
	else 
		cout << eventSeats.tickets_sold;
	cout << "\t" << titleName << "\n";
}



