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
#include <fstream>
#include "speaker.cpp"

//constants
#define EVENTMAX 40
#define EVENTMIN 12
#define MAXSTATE 3
#define MAXTITLE 128
#define MAXNAME 40
#define MAXIMUM 40
 
using namespace std;

// prototype functions

// display functions
void printArray(event utaSpeaker[MAXIMUM], int count);
void welcome_msg();
void show_menu();
void show_sub_menu();


// error checking functions
int check_menu_choice(int a);
int checkSubMenu(int a);

// main functions
void main_menu_operation(int menu_choice, event utaSpeaker[MAXIMUM], int count);
void exit_the_program();


// search functions
void search_by_speakerCode(event utaSpeaker[MAXIMUM], int count);
void search_by_lastName(event utaSpeaker[MAXIMUM], int count);
int binary_search_lastName(int low, int high, event utaSpeaker[MAXIMUM], char value[MAXNAME]);


// sort functions
void sort_by_performance_date(event utaSpeaker[MAXIMUM], int count);
void sort_by_speakerCode(event utaSpeaker[MAXIMUM], int count);
void merge(int low,int mid,int high, event utaSpeaker[MAXIMUM]);
void mergesort_lastName(int low, int high, event utaSpeaker[MAXIMUM]);
void bubblesort(event utaSpeaker[MAXIMUM], int count);
void swap (int j, int count, event utaSpeaker[MAXIMUM]);
void bubblesort_performance(event utaSpeaker[MAXIMUM], int count);

// calculate functions
void calculate_length_of_time(event utaSpeaker[MAXIMUM], int count);
void calculate_max_min(event utaSpeaker[MAXIMUM], int count);


// update array
void updateArray(event utaSpeaker[MAXIMUM], int count);
void change_performance_date(int index4, int count, event utaSpeaker[MAXIMUM]);
void change_series_code(int index4, int count, event utaSpeaker[MAXIMUM]);
void change_two_state_char(int index4, int count, event utaSpeaker[MAXIMUM]);
void change_one_of_the_tickets(int index4, int count, event utaSpeaker[MAXIMUM]);
void change_performance_time (int index4, int count, event utaSpeaker[MAXIMUM]);
void change_birth_date (int index4, int count, event utaSpeaker[MAXIMUM]);
void change_expertise_code(int index4, int count, event utaSpeaker[MAXIMUM]);
void change_firstName (int index4, int count, event utaSpeaker[MAXIMUM]);
void change_lastName (int index4, int count, event utaSpeaker[MAXIMUM]);
void change_number_tickets_or_seats (int index4, int count, event utaSpeaker[MAXIMUM]);
void change_titleName(int index4, int count, event utaSpeaker[MAXIMUM]);




// main function
int main (void)
{
	// variable declaration and initialization
	int count=0, conti, menu_choice, tempcode, tempday, tempmonth, tempyear, tempbday, tempbmonth, tempbyear, tempnumber;
	float temptime, tempebird, tempreg;
	char tempstatename[MAXSTATE], tempscode, tempecode, tempfname[MAXNAME], templname[MAXNAME], temptname[MAXTITLE];
	event utaSpeaker[MAXIMUM];

	// program starts with the welcome message
	welcome_msg();
	cout << "Press 0 to continue.\n";
	cin >> conti;
	while(conti!=0)
	{
		cout << "Wrong number entered. Please enter 0 to continue.\n";
		cin >> conti;
	}
	
	cout << "You chose to continue. Now the program will be reading data from the file that this program has allocated to. which is cxa2493lab3.txt.\n";

	ifstream infile("cxa2493lab3.txt"); // file from where the data is gathered
	do
	{
		cout << "The Line " << count+1 << "is begin processed.\n";
		infile >> tempcode >> tempday >> tempmonth >> tempyear >> temptime >> tempscode >> tempebird >> tempreg >> tempstatename >> tempecode >> tempbday >> tempbmonth >> tempbyear >> tempfname >> templname;
		utaSpeaker[count].set_eventPrice(tempebird, tempreg);
		if(utaSpeaker[count].eventPrice_is()==FREE)
		{
			infile >> tempnumber;
			utaSpeaker[count].set_total_seats(tempnumber); // saving the input
		}
		else
		{
			infile >> tempnumber;
			utaSpeaker[count].set_tickets_sold(tempnumber); // saving the input
		}

		infile.getline(temptname, MAXTITLE);

		//saving the inputs
		utaSpeaker[count].set_speakerCode(tempcode);
		utaSpeaker[count].set_pday(tempday);
		utaSpeaker[count].set_pmonth(tempmonth);
		utaSpeaker[count].set_pyear(tempyear);
		utaSpeaker[count].set_pTime(temptime);
		utaSpeaker[count].set_seriesCode(tempscode);
		utaSpeaker[count].set_ebirdPrice(tempebird);
		utaSpeaker[count].set_regPrice(tempreg);
		utaSpeaker[count].set_stateName(tempstatename);
		utaSpeaker[count].set_expertiseCode(tempecode);
		utaSpeaker[count].set_bday(tempbday);
		utaSpeaker[count].set_bmonth(tempbmonth);
		utaSpeaker[count].set_byear(tempyear,tempbyear);
		utaSpeaker[count].set_firstName(tempfname);
		utaSpeaker[count].set_lastName(templname);
		utaSpeaker[count].set_titleName(temptname);
		count++;

	}
	while(!infile.eof());

	cout << "The file reading from the cxa2493lab3.txt is complete.\n";
	cout << "The data that has been stored till now by reading the file is as follows:\n";
	printArray(utaSpeaker,count);
	cout << "Now enter 0 to continue.\n";
	cin >> conti;
	while(conti!=0)
	{
		cout << "Wrong number entered. Please enter 0 to continue.\n";
		cin >> conti;
	}

	count=count-1;

	cout << "Now begins the fun part. The menu choice is shown as follows:\n";

	show_menu();
	cout << "Now enter the menu choice number.\n";
	cin >> menu_choice;
	menu_choice=check_menu_choice(menu_choice);

	main_menu_operation(menu_choice, utaSpeaker, count);

	cout << "Everything Works!! Isnt is weird???\n";
	return 0;
}

// this function deals with the main menu operation 
void main_menu_operation(int menu_choice, event utaSpeaker[MAXIMUM], int count)
{
while (menu_choice != 9)
	{
		switch(menu_choice)
		{
		// each case here represents the menu options and once that case is entered, this switch statement calls that corresponding function
		case 1: search_by_speakerCode(utaSpeaker, count);break;
		case 2: search_by_lastName(utaSpeaker,count);break;
		case 3: calculate_length_of_time(utaSpeaker,count);break;
		case 4: calculate_max_min(utaSpeaker,count);break;
		case 5: sort_by_speakerCode(utaSpeaker,count);break;
		case 6: sort_by_performance_date(utaSpeaker,count);break;
		case 7: updateArray(utaSpeaker,count);break;
		case 8: cout << "You chose to print the arrays of data. \n";
				printArray(utaSpeaker,count);break;
		default: cout << "Invalid Entry. Please check your choice number.\n";break;
		}
		cout << "Choose Another menu option, which is from the range of 1 to 9.\n";
		cin >> menu_choice;
		menu_choice=check_menu_choice(menu_choice);
	}
	exit_the_program();
}

// this function displays the exit the program function
void exit_the_program()
{
	cout << "You chose to exit the program. The program exits now. \nThank you for giving your time and using this database. Bye Bye Now!! :)\n";
}

// this function defines the search by speaker code function
void search_by_speakerCode(event utaSpeaker[MAXIMUM], int count)
{
	int enter_data, i, checkpoint=0;
	event temp;
	cout << "\nYou chose to search a speaker by speaker code.\n";
	cout << "\nNow Enter the speaker code. The valid range for speaker code is between 100 and 999.\n";
	cin >> enter_data;
	temp.set_speakerCode(enter_data);

	for(i=0;i<count;i++)
	{
		if(temp.speakerCode_is()==utaSpeaker[i].speakerCode_is()) // comparing the speaker code entered before with the speaker code entered now
		{
			checkpoint=1;
			cout << "Found Match \n";
			cout << "The set of data found has:\n";
			//if match found result printed
			cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			utaSpeaker[i].printSingle();
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		}
	}
	if(checkpoint==0)
			cout << "No matches found. Sorry!!! :(\n";

}

//this function defines the search by last name function
void search_by_lastName(event utaSpeaker[MAXIMUM], int count)
{
	char garbage, search_lastname[MAXNAME];
	int i;
	cout << "You entered to search the speaker by their last name using BINARY SEARCH.\n";
	mergesort_lastName(0, count-1, utaSpeaker);// first sorts the list of lastname before searching lastname
	cout << "The list has been already sort by lastName using merge sort for the binary search.\n";	
	cout << "Enter the last name you wish to search.\n";
	cin >> search_lastname;

	i=binary_search_lastName(0, count-1, utaSpeaker, search_lastname); //binary search and returns the value. The value returned is either the position value. if not found then returns -1


	
	if(i==-1) // if no match found
		cout << "No matches found. Sorry!!! :(\n";
	else
	{
		cout << "Found Match\n";
		cout << "The set of data from the found match is:\n";
		//if match found result printed
			cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			utaSpeaker[i].printSingle();
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	}


}

// this function sorts the data by last name merge sort by last name
void mergesort_lastName(int low, int high, event utaSpeaker[MAXIMUM])
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  mergesort_lastName(low, mid, utaSpeaker);
  mergesort_lastName(mid+1,high, utaSpeaker);
  merge(low,mid,high, utaSpeaker);
 }
}

// this function defines the merge function 
void merge(int low,int mid,int high, event utaSpeaker[MAXIMUM])
{
 int h,i,j,k,result;
event temp[MAXIMUM];
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
	result=strcmp(utaSpeaker[h].lastName_is(),utaSpeaker[j].lastName_is());
  if(result<0)
  {
   temp[i]=utaSpeaker[h];
   h++;
  }
  else
  {
   temp[i]=utaSpeaker[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   temp[i]=utaSpeaker[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   temp[i]=utaSpeaker[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) utaSpeaker[k]=temp[k];
}

// this functions searches the last name using the technique of binary search
int binary_search_lastName(int low, int high, event utaSpeaker[MAXIMUM], char value[MAXNAME])
{

	int result, mid=0;
	
	if (high < low)
           return -1; // not found
       mid = low + ((high - low) / 2);
	result=strcmp(utaSpeaker[mid].lastName_is(), value);
       if (result >0)
           return binary_search_lastName(low, mid-1, utaSpeaker, value);
	   else if (result < 0)
           return binary_search_lastName(mid+1, high, utaSpeaker, value);
       else
           return mid; // found
}


// this fuction defines the calculate the length of time function
void calculate_length_of_time(event utaSpeaker[MAXIMUM], int count)
{
	int length_speaker, i, index, checkpoint=0, checkpoint1=0, cday, cmonth, cyear, check_day_value, check_month_value, check_year_value, length_day=0, length_month=0, length_year=0;
	event temp;
	cout << "You entered to calculate the length of the time from current date to the date of the speech.\n";
	while (checkpoint!=1)
	{
		cout << "Enter the speaker code to know which speaker's length of time you wish to calculate.\n";
		cin >> length_speaker;
		temp.set_speakerCode(length_speaker);
		for(i=0;i<count;i++)
		{
			if(temp.speakerCode_is()==utaSpeaker[i].speakerCode_is())
			{
				index=i;
				checkpoint=1;
			}
		}
	if (checkpoint==0)
		cout << "No speaker found. Sorry. Try again.\n";
	}
	cout << "Enter the current date in format DD MM YYYY.\n";
	cin >> cday >> cmonth >> cyear;

	if ((utaSpeaker[index].pyear_is()-cyear)<0)
		cout << "The event is already past. Sorry.\n";
	else if (utaSpeaker[index].pyear_is()==cyear)
	{
		if((utaSpeaker[index].pmonth_is()-cmonth)<0)
			cout << "The event is already past. Sorry.\n";
		else if (utaSpeaker[index].pmonth_is()==cmonth)
		{
			if ((utaSpeaker[index].pday_is()-cday)<0)
				cout << "The event is already past. Sorry.\n";
			else if(utaSpeaker[index].pday_is()==cday)
				cout << "The event is today. Hurry up!!!\n";
			else
			{
				length_day=utaSpeaker[index].pday_is()-cday;
				length_month=0;
				length_year=0;
				checkpoint1=1;
			}
		}
		else
		{
			checkpoint1=1;
			length_year=0;
			check_day_value = utaSpeaker[index].pday_is() - cday;
			if (check_day_value < 0)
			{
			length_day=utaSpeaker[index].pday_is() - cday + 30;
			cmonth=cmonth+1;
			}
			else
				length_day=utaSpeaker[index].pday_is() - cday;

			length_month=utaSpeaker[index].pmonth_is() - cmonth;
			
		}
	}
	else
	{
		checkpoint1=1;
		check_day_value = utaSpeaker[index].pday_is() - cday;
		if (check_day_value < 0)
		{
			length_day=utaSpeaker[index].pday_is() - cday + 30;
			cmonth=cmonth+1;
		}
		else
			length_day=utaSpeaker[index].pday_is() - cday;

		check_month_value = utaSpeaker[index].pmonth_is() - cmonth;
		if (check_month_value < 0)
		{
			length_month=utaSpeaker[index].pmonth_is() - cmonth+12;
			cyear=cyear+1;
		}
		else
			length_month=utaSpeaker[index].pmonth_is() - cmonth;

		length_year=utaSpeaker[index].pyear_is() - cyear;

	}

	if(checkpoint1==1)
		cout << "The length of time from current date to the date of the speech/performance is " << length_day << " days, " << length_month << " months, and " << length_year << " years.\n";

}

// this function defines the calculate the min max function
void calculate_max_min(event utaSpeaker[MAXIMUM], int count)
{

	int speakerCodeMinMax, checkpoint=0, i;
	float minReceipts, maxReceipts;
	event temp;
	cout << "You chose to calculate the minimum and maximum numbers of tickets sold.\n";
	cout << "Enter the speaker code you wish to calculate the maximum and minimum ticket receipts.\n";
	cin >> speakerCodeMinMax;
	temp.set_speakerCode(speakerCodeMinMax);
	
	for(i=0; i<count; i++)
	{
		if (temp.speakerCode_is()==utaSpeaker[i].speakerCode_is())
			{
				checkpoint=1;
				if(utaSpeaker[i].eventPrice_is()==FREE)
				{
					cout << "Since this is a free Event. There is no ticket amount to calculate.\n";
				}
				else
				{
					minReceipts=(utaSpeaker[i].ebirdPrice_is())*(utaSpeaker[i].tickets_sold_is());
					maxReceipts=(utaSpeaker[i].regPrice_is())*(utaSpeaker[i].tickets_sold_is());
					cout << "The minimum Receipts is " << fixed << setprecision(2) << minReceipts << " and the maximum receipts is "<< fixed << setprecision(2) << maxReceipts << ".\n";

				}

			}
				
	}
			
	
	if (checkpoint==0)
			cout << "Speaker Code Not Found. Returned to the main menu\n";
}

// this function defines the sort by speakerCode function
void sort_by_speakerCode(event utaSpeaker[MAXIMUM], int count)
{
	cout << "You entered to sort the date by speaker code using bubblesort.\n";
	cout << "The array BEFORE sorting was:\n";
	printArray(utaSpeaker,count);
	bubblesort(utaSpeaker, count);
	cout << "The array AFTER sorting is:\n";
	printArray(utaSpeaker,count);

}

// this function defines bubblesort by speakercode function
void bubblesort(event utaSpeaker[MAXIMUM], int count)
{
	int i, j;
	
		for (i=0; i<count; i++)
		{
			for(j=0; j<count-1;j++)
			{
			
				if(utaSpeaker[j].speakerCode_is() > utaSpeaker[j+1].speakerCode_is())
				{
					swap(j, count, utaSpeaker);
				}
			}
		}
}

// this function defines the swap function
void swap (int j, int count, event utaSpeaker[MAXIMUM])
{
	event temp;
	temp = utaSpeaker[j];
	utaSpeaker[j]=utaSpeaker[j+1];
	utaSpeaker[j+1]=temp;
	
}
// this function defines the sort by performance date function
void sort_by_performance_date(event utaSpeaker[MAXIMUM], int count)
{
	cout << "You entered to sort the data by performance date code using bubblesort.\n";
	cout << "The array BEFORE sorting was:\n";
	printArray(utaSpeaker,count);
	bubblesort_performance(utaSpeaker, count);
	cout << "The array AFTER sorting is:\n";
	printArray(utaSpeaker,count);

	
}

// this function defines the bubblesort performance function
void bubblesort_performance(event utaSpeaker[MAXIMUM], int count)
{
		int i, j;
	
		for (i=0; i<count; i++)
		{
			for(j=0; j<count-1;j++)
			{
				if(utaSpeaker[j].pyear_is() > utaSpeaker[j+1].pyear_is())
				{
					swap(j, count, utaSpeaker);
				}
				else if (utaSpeaker[j].pyear_is()==utaSpeaker[j+1].pyear_is())
				{
					if (utaSpeaker[j].pmonth_is() > utaSpeaker[j+1].pmonth_is())
						swap(j, count, utaSpeaker);
					else if (utaSpeaker[j].pmonth_is()==utaSpeaker[j+1].pmonth_is())
					{
						if (utaSpeaker[j].pday_is() > utaSpeaker[j+1].pday_is())
							swap(j, count, utaSpeaker);
					}
                
				}
			}
		}
}

// this function defines the update array function
void updateArray(event utaSpeaker[MAXIMUM], int count)
{
	
	int sub_menu_speaker_code, sub_menu_choice_number, i, index4, checkpoint=0;
	event temp;
	cout << "You chose to update data or array of data. Now the program will take you to another sub-menu with bunch of options.\n";
	while (checkpoint==0)
	{
		cout << "Now enter the integer number of speaker code which you want to update. The valid range is 100 to 999 (inclusive).\n";
		cin >> sub_menu_speaker_code;
		temp.set_speakerCode(sub_menu_speaker_code);

		for(i=0;i<count;i++)
		{
			if(temp.speakerCode_is()==utaSpeaker[i].speakerCode_is()) // comparing the speaker code entered now with the speaker code entered before
			{
				// if equal, then that speaker's data to be updated
				index4=i;
				cout << "So you will be updating the information of Speaker " << index4 + 1 << ".\n";
				checkpoint=1;
			}
		}
		if (checkpoint==0)
			cout << "Speaker not found. Try again.\n";
	}
	show_sub_menu();
	cout << "Enter the sub menu choice number. Remember the range from above.\n";
	cin >> sub_menu_choice_number;
	sub_menu_choice_number=checkSubMenu(sub_menu_choice_number);

	while(sub_menu_choice_number!=12) // this returns to main menu when the user enters 12 which is an option to return to the main menu
	{
		switch(sub_menu_choice_number)
		{
			// according to the number enter, switch statement calls the corresponding function.
			case 1: change_performance_date(index4, count, utaSpeaker);break;
			case 2: change_series_code(index4, count, utaSpeaker);break;
			case 3: change_two_state_char(index4, count, utaSpeaker);break;
			case 4: change_one_of_the_tickets(index4, count, utaSpeaker);break;
			case 5: change_performance_time(index4, count, utaSpeaker);break;
			case 6: change_birth_date(index4, count, utaSpeaker);break;
			case 7: change_expertise_code(index4, count, utaSpeaker);break;			
			case 8: change_firstName(index4, count, utaSpeaker);break;			
			case 9: change_lastName(index4, count, utaSpeaker);break;
			case 10: change_number_tickets_or_seats(index4, count, utaSpeaker);break;
			case 11: change_titleName(index4, count, utaSpeaker);break;
		}
		cout << "Enter the sub-menu choice number. Remember the range. \n"; // this is to compare the sub menu choice number with the top while loop
		cin >> sub_menu_choice_number;
		sub_menu_choice_number=checkSubMenu(sub_menu_choice_number);
		
	}
	cout << "You chose to return to the main menu.\n";


}

// this function changes the performance date of the speaker
void change_performance_date(int index4, int count, event utaSpeaker[MAXIMUM])
{
	int change_date, change_month, change_year;
	cout << "You chose to change date, month and year of the performance.\n";
	cout << "Beware that you are going to change the data for Speaker " << index4+1 << ".\n";
	cout << "Please Enter the day of performance. Remember the range.\n";
	cin >> change_date;
	utaSpeaker[index4].set_pday(change_date); //data updated

	cout << "Please Enter the month of performance. Remember the range.\n";
	cin >> change_month;
	utaSpeaker[index4].set_pmonth(change_month);//data updated

	cout << "Please Enter the year of performance. Remember the range.\n";
	cin >> change_year;
	utaSpeaker[index4].set_pyear(change_year);//data updated

	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
}

// this function changes the series code of the speaker
void change_series_code(int index4, int count, event utaSpeaker[MAXIMUM])
{
	char change_series_code='a';
	cout << "You chose to change the series code. Beware!!! Updating here, changes everywhere else.\n";
	cout << "Please Enter the series code. Remember the instructions.Please Enter.\n";
	cin >> change_series_code;
	utaSpeaker[index4].set_seriesCode(change_series_code);//data updated

	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
} 

// this function changes the state of the speaker
void change_two_state_char(int index4, int count, event utaSpeaker[MAXIMUM])
{
	char change_state[MAXSTATE];
	char garbage, change;
	cout << "You chose to change two state characters.\n";
	cout << "Beware!!! You are updating the whole array. Please enter a new two character state.\n";
	cin >> change_state; 
	utaSpeaker[index4].set_stateName(change_state); //data updated

	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";


}

// this function changes one of the tickets either ebird or reg ticket
void change_one_of_the_tickets(int index4, int count, event utaSpeaker[MAXIMUM])
{
	int change_ticket_choice;
	float change_earlybird_dollar, change_regular_dollar;
	cout << "You chose to change either one of the ticket price.\n";
	cout << "Beware!!! You are updating the whole array.";
	cout << "Please chose an option. \nEnter 1 to update earlybird price and enter 2 to update regular price.\n";
	cin >> change_ticket_choice;
	while(change_ticket_choice!=1 && change_ticket_choice!=2) //error checking the choice
	{
		cout << "Invalid option entered. Please look and try again.\n";
		cin >> change_ticket_choice;
	}
	switch(change_ticket_choice) // calling the respective function according to the choice made
	{
	case 1: //this case changes the earlybird price
			cout << "You chose to change earlybird price.\n";
			cout << "Enter a new earlybird price.\n";
			cin >> change_earlybird_dollar;
			utaSpeaker[index4].set_ebirdPrice(change_earlybird_dollar); //data updated

			//new updated array printed
			cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
			cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			utaSpeaker[index4].printSingle();
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			break;

	case 2: //this case changes the price of regular tickets
			cout << "You chose to change regular price.\n";
			cout << "Enter a new regular price.\n";
			cin >> change_regular_dollar;
			utaSpeaker[index4].set_regPrice(change_regular_dollar); //data updated

			//new updated array printed
			cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
			cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			utaSpeaker[index4].printSingle();
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			break;

	default: cout << "Invalid Option Selected.\n";break;

	}
}

// this function changes the performance time
void change_performance_time(int index4, int count, event utaSpeaker[MAXIMUM])
{
	float change_hour_time;
	cout << "You chose to change time array. Beware, updating here changes everything elsewhere. Remember the range and format.\n";
	cout << "Please enter the new timing. Remember the format!!!\n";
	cin >> change_hour_time;
	utaSpeaker[index4].set_pTime(change_hour_time); //data updated

	//new updated array is printed
	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			

}

// this function changes the birth date
void change_birth_date(int index4, int count, event utaSpeaker[MAXIMUM])
{
	int change_date, change_month, change_year;
	cout << "You chose to change date, month and year of the birth.\n";

	cout << "Beware that you are going to change the data for Speaker " << index4+1 << ".\n";

	cout << "Please Enter the day of birth. Remember the range.\n";
	cin >> change_date;	
	utaSpeaker[index4].set_bday(change_date); //data updated

	cout << "Please Enter the month of birth. Remember the range.\n";
	cin >> change_month;
	utaSpeaker[index4].set_bmonth(change_month); //data updated

	cout << "Please Enter the year of birth. Remember the range.\n";
	cin >> change_year;
	
	utaSpeaker[index4].set_byear(utaSpeaker[index4].pyear_is(), change_year); //data updated
	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			
}

// this function changes the expertise code of the speaker
void change_expertise_code(int index4, int count, event utaSpeaker[MAXIMUM])
{
	char change_expertise_code='a';
	cout << "You chose to change the expertise code. Beware!!! Updating here, changes everywhere else.\n";
	cout << "Please Enter the expertise code. Remember the instructions.Please Enter.\n";
	cin >> change_expertise_code;
	utaSpeaker[index4].set_expertiseCode(change_expertise_code); //data updated		
	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			
}

// this function changes the first Name of the speaker
void change_firstName(int index4, int count, event utaSpeaker[MAXIMUM])
{
	char garbage='a';
	char change_firstname[MAXNAME];
	cout << "You chose to change the first name of the speaker. Beware!!! Updating here, changes everywhere else.\n";
	cout << "Please Enter the first name of the speaker you wish to change. Remember the instructions.Please Enter.\n";
	cin >> change_firstname; 	
	utaSpeaker[index4].set_firstName(change_firstname); //data updated
	
	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
}

// this function changes the last Name of the speaker
void change_lastName(int index4, int count, event utaSpeaker[MAXIMUM])
{
	
	char change_lastname[MAXNAME];
	cout << "You chose to change the last name of the speaker. Beware!!! Updating here, changes everywhere else.\n";
	cout << "Please Enter the last name of the speaker. Remember the instructions.Please Enter.\n";
	cin >> change_lastname; 	
	utaSpeaker[index4].set_lastName(change_lastname); //data updated

	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
}

// this function changes either the number of tickets or the number of seats whichever is necessary
void change_number_tickets_or_seats(int index4, int count, event utaSpeaker[MAXIMUM])
{
	int seats, tickets;
	cout << "You chose to change the number of ticket or seats sold.\n";

	if(utaSpeaker[index4].eventPrice_is()==FREE)
	{
		cout << "You are going to change the number of seats. Please enter the right number of seats.\n";
		cin >> seats;
		utaSpeaker[index4].set_total_seats(seats);
		cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
		cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		utaSpeaker[index4].printSingle();
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		
	}
	else
	{
		cout << "You are going to change the number of tickets. Please enter the right number of seats.\n";
		cin >> tickets;
		utaSpeaker[index4].set_tickets_sold(tickets);
		cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
		cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		utaSpeaker[index4].printSingle();
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		
	}

}

// this function changes the title of the speaker
void change_titleName(int index4, int count, event utaSpeaker[MAXIMUM])
{
	char garbage[MAXTITLE];
	char change_name[MAXTITLE];
	cout << "You chose to change the title of the speech or performance of the speaker. \n";
	cout << "Beware!!! Updating here, changes everywhere else.\n";
	cout << "Please Enter the title of the speech of the speaker. Remember the instructions.Please Enter.\n";
	cin >> garbage;
	fgets(change_name, MAXTITLE, stdin);
	strcat(garbage, change_name);
	utaSpeaker[index4].set_titleName(garbage);  //data updated
	

	cout << "\nUpdate successful. The new set of data of the speaker " << index4+1 << " is as follows:\n";
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	utaSpeaker[index4].printSingle();
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
}

// this function checks the sub menu choice number and returns the valid value
int checkSubMenu(int a)
{
	while(a<1 || a>12)
	{
		cout << "Invalid Sub Menu Choice Number. Please Look at the instructions and Try again.\n";
		show_sub_menu();
		cout << "Enter the sub menu choice number. Remember the range from above.\n";
		cin >> a;

	}
	return a;
}

// this function displays the sub menu format
void show_sub_menu()
{
	cout << "Now you are on sub-menu. The following are the options on sub_menu: \n";
	cout << "1. Change speech month, day, or year. \n";
	cout << "2. Change the series array. \n";
	cout << "3. Change the two state char arrays. \n";
	cout << "4. Change one of the ticket arrays. \n";
	cout << "5. Change the time array. \n";
	cout << "6. Change birth month, day, or year. \n";
	cout << "7. Change the expertise code. \n";	
	cout << "8. Change the first name. \n";
	cout << "9. Change the last name. \n";
	cout << "10. Change the number of tickets or seats (make sure to update the enumerated value if needed.)\n";
	cout << "11. Change the title name. \n";
	cout << "12. Return to main menu.\n";
	cout << "Now choose the corresponding option to play with the options.\nFor example, enter 2 to change the series array.\n";
}


// this functions checks the menu choice option
int check_menu_choice(int a)
{
	while(a<1 || a>9)
	{
		cout << "Invalid Menu choice Number entered. Please look at the instructions and try again.\n";
		cin >> a;
	}
	return a;
}

// this function shows the menu options
void show_menu()
{
	cout << "Now you are looking at the menu choices of this program.\nAnd the following are your choices:\n";
	cout << "1. Search for speakers/performers by speaker code.\n";
	cout << "2. Search for speakers by last name.\n";
	cout << "3. Calculate length of time from current date to the date of the speech/performance.\n";
	cout << "4. Calculate minimum and maximum ticket receipts for a speaker.\n";
	cout << "5. Sort the data by speaker code.\n";
	cout << "6. Sort the data by speech/performance date.\n";
	cout << "7. Update the data in the array of objects this will take the user to a submenu for doing updates.\n";
	cout << "8. Print all the data in the array.\n";
	cout << "9. End the Program.\n";
	cout << "Please Enter the corresponding integer number to do your task. For example, Enter 1 to search for speaker by speaker code.\n";
}

// this function prints the whole data
void printArray(event utaSpeaker[MAXIMUM], int count)
{
	int i;
	cout << "CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tECODE\tBDAY\tBMONTH\tBYEAR\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n";
	for (i=0; i<count;i++)
	{
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		utaSpeaker[i].printSingle();
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}


}

// this function is for the welcome message
void welcome_msg()
{
	cout << "Welcome!!! Welcome!!! Welcome!!!\nWelcome to the Speaker Management Database. This program reads the data from the infile and stores it accordingly. \nHence the users dont have to worry about entering their data. This is already done for you by this program.\nAfter the data has be automatically read and stored, the program will show a menu box and from that menu box you can perform certain tasks as described in the menu box. \nDetail be given to you later as the program progresses. Dont worry just follow the on-screen instructions.\n";
}




