/* Chudamani Aryal
Lab1 Assignment
Date Given: Sept 20 2010
Date Due: Oct 5 2010
Professor: Dr T
Class: CSE 1320 Section: 001 TH 11-12:20 */

// *********Description of the program**************
/* This program uses the concpet of mutlidimensional array. 
We will be using this technique to improve whatever we have done from prelab assignment. 
This program lets the user enter certain set of data with some constraints. More about the constraints will be discussed individually later.
After the data are entered, this program stores those data and later on acts as a database 
and provides the users to play with some of its menu choices. 
You will know more about the menu choice once you get into the program. */

//*********  pre-processors   *************


#include <stdio.h>
#include <string.h>
#define EVENTMAX 20
#define EVENTMIN 1
#define MAXNUM 40
#define SPEAKERCODE 0
#define PDAY 1
#define PMONTH 2
#define PYEAR 3
#define PHOUR 4
#define PMINUTE 5
#define EBIRDDOLLAR 6
#define EBIRDCENTS 7
#define REGDOLLAR 8
#define REGCENTS 9
#define BDAY 10
#define BMONTH 11
#define BYEAR 12
#define SCODE 0
#define HOMESTATE1 1
#define HOMESTATE2 2
#define ECODE 3

// **************** declaration of functions  or function prototypes *******************
void welcome_msg();
int checknumber(int a);
int check_input_choice(int b);
int checkSpeakerCode(int a);
int checkDay(int a);
int checkMonth(int a);
int checkYear(int a);
char checkExpertiseCode(char a);
char checkSeriesCode(char a);
int checkHour(int a, int b);
int checkMinute(int a, int b);
int checkBYear(int a, int speakerInt[13][EVENTMAX], int count);
int checkDollar(int a, int b);
int checkCents(int a, int b);
void show_oneLine_enter();
void show_menu();
int check_menu_choice(int c);
int checkSubMenu(int a);
void input_Individual (int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void input_oneLine (int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void printArray(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void main_menu_operation (int menu_choice_number, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void exit_the_program();
void search_by_speakercode(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void search_by_dateofspeech(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void calculate_cost(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void find_all_same_series(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void find_all_certain_state(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void update_array(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void calculate_age(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void find_all_less_than_cost(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void search_by_expertise(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void sort_by_speaker_code(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void sort_by_perfomance_date(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void show_sub_menu();
void change_performance_date(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_series_code(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_two_state_char(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_one_of_the_tickets(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_performance_time(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_birth_date(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_expertise_code(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void change_name_of_speaker(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void bubblesort(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void swap(int j, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);
void bubblesort_performance(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]);

// ****************        main function      ******************
int main (){

	// declarations of variables
	int speakerInt[13][EVENTMAX]={{0}};
	char speakerChar[4][EVENTMAX]; char speakerName[EVENTMAX][MAXNUM];
	int enter_data, num_of_people, input_choice, menu_choice_number;

	// Program begins
	welcome_msg();
	printf ("\nHow many sets of data you want to enter. Remember minimun is 10 and maximum is 20, inclusive.\n");
	scanf ("%d", &enter_data);
	num_of_people = checknumber(enter_data); // check wheather the number entered in within the range from 10 to 20 and returns the right value
	printf ("Now you are going to choose the way to input your data.\nEnter 1 if you want to input your data individually.\nEnter 2 if you want to input your data on one line.\n");
	scanf ("%d", &enter_data);
	input_choice= check_input_choice(enter_data); // checks whether the number entered in valid and returns the value. Asking method of Input (Individual or One Line)

	switch(input_choice) // This switch statement calls the respective input function
	{
	case 1: input_Individual(num_of_people, speakerInt, speakerChar, speakerName);break; // this function calls the individual method
	case 2: input_oneLine(num_of_people, speakerInt, speakerChar, speakerName);break; // this function calls the one line method
	default: printf ("Invalid Input\n");break; // this is a default case. This wont happen here because the number is already checked and verified
	}
	// either of the above functions reads the data entered by the user
	printf ("Congratulations!!!! Congratulations!!! Congratulations!!! You have successfully entered all the required data.\n");
	printf ("Here are your data you have entered: \n");
	printArray(num_of_people, speakerInt, speakerChar, speakerName); // this prints whatever the user had entered

	printf ("Now begins the fun part.\n");
	
	// Once all the data that have been entered are shown, the program next shows the menu
	show_menu();

	// Once all the menu option are shown, the user is asked to enter the option number to work accordingly
	printf ("Now enter the menu option number.\n");
	scanf ("%d", &enter_data);

	// menu choice is verified and main menu operation is called. Also a reminder, one of the options of main menu calls sub menu function
	menu_choice_number = check_menu_choice(enter_data); // the number entered is checked and a value is returned 
	main_menu_operation(menu_choice_number, num_of_people, speakerInt, speakerChar, speakerName); // this calls the main function
	printf ("WORKS FINE");
	
}

void welcome_msg()
{
	printf ("Welcome!!! Welcome!!! Welcome!!!\nWelcome all the users to the interface of UTA event database. \nHope you have fun with this program.\n");
}

//funtion to check whether the user inputs the right number of people or not. i.e. within the range of 10 to 20
int checknumber(int a)
{
	while(a<EVENTMIN || a>EVENTMAX)
	{
		printf ("Invalid Number of People Entered. Please look at the instructions and try again.\n");
		scanf ("%d", &a);
	}
	return a;
}


// this function checks whether the right method of input is chosen or not
int check_input_choice(int b)
{
	while (b!=1 && b!=2)
	{
		printf ("Invalid Input Choice. Please look at the instructions and try again.\n");
		scanf ("%d", &b);
	}
	return b;
}

// this function asks the user to enter all the data individually
void input_Individual (int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int count, input_name, buffer, buffer1; char buffer_char; 
	printf ("You chose to enter your sets of data in Individual data method.\n");
	
	for(count=0; count<num_of_people; count++) // loop to repeat asking the data over and over again
	{		
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("\nPLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		scanf ("%d", &buffer);
		speakerInt[SPEAKERCODE][count]=checkSpeakerCode(buffer); //checks the speaker code and returns valid value

		
		printf ("\nPLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		scanf ("%d", &buffer);
		speakerInt[PDAY][count]=checkDay(buffer); //errror checks the day and returns and valid value
		
		printf ("\nPLEASE ENTER THE month. Remember to make that month valid i.e within the range of 1 to 12. \n");
		scanf ("%d", &buffer);
		speakerInt[PMONTH][count]=checkMonth(buffer); //errror checks the month and returns and valid value
		
		
		printf ("\nPLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		scanf ("%d", &buffer);
		speakerInt[PYEAR][count]=checkYear(buffer); //errror checks the year and returns and valid value
		
		printf ("\nPLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		scanf ("%d.%d", &buffer, &buffer1);

		speakerInt[PHOUR][count]=checkHour(buffer, buffer1); // error check hour and returns value
		speakerInt[PMINUTE][count]=checkMinute(buffer, buffer1);	// error checks minute and return value

			

		printf ("\nPLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		
		scanf ("%c", &buffer_char);
		speakerChar[SCODE][count]=checkSeriesCode(buffer_char); // error checks the series code and returns the valid value

		
		printf ("\nPLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &buffer, &buffer1);
		speakerInt[EBIRDDOLLAR][count]=checkDollar(buffer, buffer1); // error check the dollar and returns value
		speakerInt[EBIRDCENTS][count]=checkCents(buffer, buffer1); // error check the minute and returns value

		
		printf ("\nPLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &buffer, &buffer1);
		speakerInt[REGDOLLAR][count]=checkDollar(buffer, buffer1);
		speakerInt[REGCENTS][count]=checkCents(buffer, buffer1);

		printf ("\nPLEASE ENTER THE HOMESTATE OF THE SPEAKER. For example NY would be for New York. \n");
		scanf (" %c%c", &speakerChar[HOMESTATE1][count], &speakerChar[HOMESTATE2][count]);	
		
		printf ("PLEASE ENTER THE DAY OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		speakerInt[BDAY][count]=checkDay(buffer); // error checks the birth day and returns the valid value

		printf ("PLEASE ENTER THE MONTH OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		speakerInt[BMONTH][count]=checkMonth(buffer); // error checks the birth month and returns the valid value
		
		printf ("PLEASE ENTER THE YEAR OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		speakerInt[BYEAR][count]=checkBYear(buffer, speakerInt, count);
		
		printf ("PLEASE ENTER THE EXPERTISE CODE.");
		printf ("Here is the format. A - Aerospace Engineering, B - Bioengineering, C - Civil Engineering, P - Computer Science and Engineering, E - Electrical Engineering, I - Industrial Engineering, M - Mechanical Engineering, S - Materials Science and Engineering, O - Other Engineering, Z - Science, L - Liberal Arts, D - Education, X - Business, N - Nursing, R - Architecture, W - Social Work, U - Urban and Public Affairs, G - General\n");
		printf ("PLEASE ENTER THE CORRESPONDING ALPHABET.\n");
		scanf ("%c", &buffer_char);
		scanf ("%c", &buffer_char);
		speakerChar[ECODE][count]=checkExpertiseCode(buffer_char);
		
		

		printf ("\nPLESE ENTER THE NAME OF THE SPEAKER. The max length is 40.\n");
		scanf ("%c", &buffer_char);
		fgets(speakerName[count], MAXNUM, stdin);
		speakerName[count][MAXNUM-1]='\0';
		
	}
}

// this function asks the user to enter all the necessary data in one line format
void input_oneLine (int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM]){
	
	int count; //variables declared

	show_oneLine_enter(); // this shows the format for one line method.  Description on how to enter data (Overall)
	
	for(count=0; count<num_of_people; count++) // loop to repeat asking the data over and over again
	{		

		
		
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("PLEASE ENTER.\n");
		scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c",&speakerInt[SPEAKERCODE][count],&speakerInt[PDAY][count],&speakerInt[PMONTH][count],&speakerInt[PYEAR][count],&speakerInt[PHOUR][count],&speakerInt[PMINUTE][count],&speakerChar[SCODE][count],&speakerInt[EBIRDDOLLAR][count],&speakerInt[EBIRDCENTS][count],&speakerInt[REGDOLLAR][count],&speakerInt[REGCENTS][count],&speakerChar[HOMESTATE1][count],&speakerChar[HOMESTATE2][count], &speakerInt[BDAY][count], &speakerInt[BMONTH][count], &speakerInt[BYEAR][count],&speakerChar[ECODE][count]);
		fgets(speakerName[count], MAXNUM, stdin);
		speakerName[count][MAXNUM-1]='\0';
	
		//error checking of everything as a whole
		while ((speakerInt[SPEAKERCODE][count]<100 || speakerInt[SPEAKERCODE][count]>999)||(speakerInt[PDAY][count]<1 || speakerInt[PDAY][count]>32)||(speakerInt[PMONTH][count]<1 || speakerInt[PMONTH][count]>12)||(speakerInt[PYEAR][count]<2000 || speakerInt[PYEAR][count]>2050)||(speakerInt[PHOUR][count]<0 || speakerInt[PHOUR][count]>23 || speakerInt[PMINUTE][count]<0 || speakerInt[PMINUTE][count]>59)||(speakerChar[SCODE][count] != 'M' && speakerChar[SCODE][count] != 'E' && speakerChar[SCODE][count] != 'D'&& speakerChar[SCODE][count] != 'C' && speakerChar[SCODE][count] != 'S' && speakerChar[SCODE][count] != 'U' && speakerChar[SCODE][count] != 'L' && speakerChar[SCODE][count] != 'O')||(speakerInt[EBIRDDOLLAR][count]<0 || speakerInt[EBIRDCENTS][count]<0|| speakerInt[EBIRDCENTS][count]>99)||(speakerInt[REGDOLLAR][count]<0 || speakerInt[REGCENTS][count]<0|| speakerInt[REGCENTS][count]>99))
		{
			printf ("\nInvalid Format. Please go back and look at the instructions and try again.\n");
			scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c",&speakerInt[SPEAKERCODE][count],&speakerInt[PDAY][count],&speakerInt[PMONTH][count],&speakerInt[PYEAR][count],&speakerInt[PHOUR][count],&speakerInt[PMINUTE][count],&speakerChar[SCODE][count],&speakerInt[EBIRDDOLLAR][count],&speakerInt[EBIRDCENTS][count],&speakerInt[REGDOLLAR][count],&speakerInt[REGCENTS][count],&speakerChar[HOMESTATE1][count],&speakerChar[HOMESTATE2][count], &speakerInt[BDAY][count], &speakerInt[BMONTH][count], &speakerInt[BYEAR][count],&speakerChar[ECODE][count]);
			fgets(speakerName[count], MAXNUM, stdin);
			speakerName[count][MAXNUM-1]='\0';
			
			
		}
	
	}
}

// this function prints all the data
void printArray(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int count;
	for(count=0;count<num_of_people;count++)
	{	
		printf ("The data you have entered for Speaker %d is:\n", count+1);
		printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);

	}
}

// this function shows what to enter in one line
void show_oneLine_enter()
{
		printf ("\nYou chose to enter your sets of data in One Line Format.\n");
		printf ("\nRemember the format: 100 24 9 2010 19.00 M 0.00 0.00 NY 2 2 1990 X Chudamani Aryal \nHere 100 is Speaker Code, \n24 is day of the speech, \n9 is the month, \n2010 is the year, \n19.00 is the military timing, \nM is the series code, \n0.00 is early bird ticket and \nsecond 0.00 is regular ticket price and \nfinally NY is the Homestate of the speaker. \n 2 is the birth day \n2 is the birth month \n1990 is the birth year \nX is the expertise code \n Chudamani Aryal is the name of the speaker \n");
	
		printf ("PLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		printf ("PLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		printf ("PLEASE ENTER THE month. Remember to make that month valid i.e within the range of 1 to 12. \n");
		printf ("PLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		printf ("PLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		printf ("PLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		printf ("PLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		printf ("PLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		printf ("PLEASE ENTER THE HOMESTATE OF THE SPEAKER. For example NY would be for New York. \n");
		printf ("PLEASE ENTER THE DAY OF THE BIRTH.\n");
		printf ("PLEASE ENTER THE MONTH OF THE BIRTH.\n");
		printf ("PLEASE ENTER THE YEAR OF THE BIRTH.\n");
		printf ("PLEASE ENTER THE EXPERTISE CODE.");
		printf ("Here is the format. A - Aerospace Engineering, B - Bioengineering, C - Civil Engineering, P - Computer Science and Engineering, E - Electrical Engineering, I - Industrial Engineering, M - Mechanical Engineering, S - Materials Science and Engineering, O - Other Engineering, Z - Science, L - Liberal Arts, D - Education, X - Business, N - Nursing, R - Architecture, W - Social Work, U - Urban and Public Affairs, G - General\n");
		printf ("PLEASE ENTER THE CORRESPONDING ALPHABET.\n");
		printf ("\nPLESE ENTER THE NAME OF THE SPEAKER. The max length is 40.\n");

}

//this function shows user the menu and its options
void show_menu()
{
	printf ("Now you are looking at the menu choices of this program.\nAnd the following are your choices:\n1. Search for speakers/performers by speaker code.\n2. Search for speakers/performers by date of speech/performance.\n 3. Search for speakers by expertise\n 4. Calculate cost for purchase of a given number of tickets of a given type.\n 5. Calculate the age of the speaker while in performance.\n6. Find all the speakers in the same series.\n7. Find all the speakers that are from a certain state.\n8. Find all the speeches/performances that cost less than a given ticket price. \n9. Sort the data by speaker code. \n10.  Sort the data by speech/performance date. \n11. Update the data in the arrays. This will take you to a submenu for doing updates.\n12. End the program.\n");
	printf ("Remember that while chosing your menu choice, you have to choose the corresponding number to the menu option. \nFor example, to calculate the ticket cost you must enter 3.\n");
}

// this function checks whether the right menu choice is entered or not
int check_menu_choice(int c)
{
	while (c<1||c>12)
	{
		printf("Invalid Menu Choice. Please Look at the instructions and try again.\n");
		show_menu();
		scanf ("%d", &c);
	}
	return c;
}

// this function takes the user into the main menu operation and gives the user various choices to enter
void main_menu_operation (int menu_choice_number, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	while (menu_choice_number != 12)
	{
		switch(menu_choice_number)
		{
		// each case here represents the menu options and once that case is entered, this switch statement calls that corresponding function
		case 1: search_by_speakercode(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 2: search_by_dateofspeech(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 3: search_by_expertise(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 4: calculate_cost(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 5: calculate_age(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 6: find_all_same_series(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 7: find_all_certain_state(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 8: find_all_less_than_cost(num_of_people, speakerInt, speakerChar,  speakerName);break;		
		case 9: sort_by_speaker_code(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 10: sort_by_perfomance_date(num_of_people, speakerInt, speakerChar,  speakerName);break;
		case 11: update_array(num_of_people, speakerInt, speakerChar,  speakerName);break;
		default: printf ("Invalid Entry. Please check your choice number.\n");break;
		}
		printf ("Choose Another menu option, which is from the range of 1 to 12.\n");
		scanf ("%d", &menu_choice_number);
		menu_choice_number=check_menu_choice(menu_choice_number); // asks to enter menu choice again and error checks the menu choice and the return value is again compared with while loop
	}
	exit_the_program();
}

// this function is called when the user enter the exit option
void exit_the_program()
{
	// gracefully terminating the program
	printf ("You chose to exit the program. The program exits now. \nThank you for giving your time and using this database. Bye Bye Now!! :)\n");
}

// this function searchs the data by speakercode
void search_by_speakercode(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int enter_data, count, checkpoint=0;
	printf ("\nYou chose menu option 1. This means you want to search a speaker by speaker code.\n");
	printf ("\nNow Enter the speaker code. Remember the range given before.\n"); // Asks to enter the speaker code
	scanf ("%d", &enter_data);
	enter_data=checkSpeakerCode(enter_data); // error checks the speaker code
	for(count=0;count<num_of_people;count++)
	{
		if(enter_data==speakerInt[SPEAKERCODE][count]) // comparing the speaker code entered before with the speaker code entered now
		{
			checkpoint=1;
			printf ("Found Match \n");
			printf ("The set of data found has:\n");
			//if match found result printed
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);

		}
	}
	if(checkpoint==0)
			printf ("No matches found. Sorry!!! :(\n");

}

// this function searchs data by date of speech
void search_by_dateofspeech(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
int enter_data4, enter_data5, enter_data6, count, checkpoint1=0;
	printf ("\nYou chose menu option 2. This means you want to search a speaker by date of speech. \n");
	printf ("\nNow Enter the date of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data4);
	enter_data4=checkDay(enter_data4); // error checks day and returns the value

	printf ("\nNow Enter the month of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data5);
	enter_data5=checkMonth(enter_data5);  //error checking month of speech and returns value
	
	printf ("\nNow Enter the year of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data6);
	enter_data6=checkYear(enter_data6); //error checking year of speech and returns the valid value
	

	for(count=0;count<num_of_people;count++)
	{
		if(enter_data4==speakerInt[PDAY][count]) //comparing the date of speech entered before with the date of speech entered now
			if(enter_data5==speakerInt[PMONTH][count])
				if(enter_data6==speakerInt[PYEAR][count])
				{
					// if match found, result printed
					printf ("Found Match\n");
					printf ("The set of data from the found match is:\n");
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);
					checkpoint1=1;
				}
	}
	if(checkpoint1==0)
	{
		// if match not found
		printf ("No matches found. Sorry!!! :(\n");
	}

}

// this function calculates the cost of the given number of given types of ticket by given speaker
void calculate_cost(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int calculate_choice, checkpoint2, speaker_code_calculate, speaker_code_calculate1, speaker_code_calculate2, count, index, number_of_earlybird, number_of_regular, number_of_earlybird1,number_of_regular1, dollar_price_of_earlybird=0, dollar_price_of_earlybird1=0, cents_price_of_earlybird=0, cents_price_of_earlybird1=0, dollar_price_of_regular=0, dollar_price_of_regular1=0, cents_price_of_regular=0, cents_price_of_regular1=0, dollar_price_of_total=0, cents_price_of_total=0;
	
	//option given to chose how to calculate. 
	printf ("You chose menu option 4, which is to calculate cost for purchase of a given number of tickets of a given type.\n");
	printf ("If you want to calculate both ticket cost then enter 1.\nIf you want to calculate just early bird then enter 2.\nIf you just want to calculate regular ticket cost then enter 3. Please Enter the number.\n");
	scanf ("%d", &calculate_choice);
	while(calculate_choice!=1 && calculate_choice!=2 && calculate_choice!=3) //error checking whether the right option is chosed or not
	{
		printf ("Invalid number entered. Please enter again.\n");
		scanf ("%d", &calculate_choice);
	}
	switch(calculate_choice)
	{
	case 1: // this case calculates the ticket cost of both regular and earlybird
			checkpoint2=0;
			printf ("You chose to calculate both ticket cost as a total sum amount.\n");

			//also option given which speaker's ticket to calculate
			while (checkpoint2!=1)
			{
				printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
				scanf ("%d", &speaker_code_calculate);
				for(count=0;count<num_of_people;count++)
				{
					if(speaker_code_calculate==speakerInt[SPEAKERCODE][count])
					{
						index=count;
						checkpoint2=1;
					}
				}
			}

			if(checkpoint2==0)
			{
				printf ("No matches found.\n"); // when no match is found
			}
			else
			{
				// when match is found, the cost is calculated using the below formula
				printf ("Match Found. Enter the number of earlybird ticket first, then the regular ticket. \nRemember to put a space in between.\n");
				scanf ("%d %d", &number_of_earlybird, &number_of_regular);
				dollar_price_of_earlybird = (number_of_earlybird * speakerInt[EBIRDDOLLAR][index]) + (number_of_earlybird*speakerInt[EBIRDCENTS][index])/100;
				cents_price_of_earlybird = (number_of_earlybird*speakerInt[EBIRDCENTS][index])%100;
				dollar_price_of_regular = (number_of_regular * speakerInt[REGDOLLAR][index]) + (number_of_regular*speakerInt[REGCENTS][index])/100;
				cents_price_of_regular = (number_of_regular*speakerInt[REGCENTS][index])%100;
				dollar_price_of_total = dollar_price_of_earlybird + dollar_price_of_regular + ((cents_price_of_earlybird + cents_price_of_regular)/100);
				cents_price_of_total = ((cents_price_of_earlybird + cents_price_of_regular)% 100);
				printf ("You entered %d for early bird tickets and %d for the regular tickets.\n", number_of_earlybird, number_of_regular);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_total, cents_price_of_total);
			}
			break;
	case 2: //this case calculates the cost of early bird tickets only
			checkpoint2=0;
			printf ("You entered number 2. This means you chose to calculate the total cost of early bird tickets.\n");
			printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
			scanf ("%d", &speaker_code_calculate1);
			for(count=0;count<num_of_people;count++)
			{
				if(speaker_code_calculate1==speakerInt[SPEAKERCODE][count]) //speaker code is compared to find the match
				{
					index=count;
					checkpoint2=1;
				}
			}
			if(checkpoint2==0)
			{
				printf ("No matches found.\n"); //when no match is found
			}
			else
			{
				//when match is found, the cost is calculated along with the below formula
				printf ("Match Found. Enter the number of earlybird ticket.\n");
				scanf ("%d", &number_of_earlybird1);
				dollar_price_of_earlybird1 = (number_of_earlybird1 * speakerInt[EBIRDDOLLAR][index]) + (number_of_earlybird1*speakerInt[EBIRDCENTS][index])/100;
				cents_price_of_earlybird1 = (number_of_earlybird1*speakerInt[EBIRDCENTS][index])%100;
				printf ("You entered %d for early bird tickets.\n", number_of_earlybird1);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_earlybird1, cents_price_of_earlybird1);
			}
			break;
	case 3: // this case calculates the ticket cost of regular tickets only
			checkpoint2=0;
			printf ("You enter 3 and chose to calculate only the cost of regular tickets.\n");
			printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
			scanf ("%d", &speaker_code_calculate2);
			for(count=0;count<num_of_people;count++)
			{
				if(speaker_code_calculate2==speakerInt[SPEAKERCODE][count]) //speaker code compared to find a match
				{
					index=count;
					checkpoint2=1;
				}
			}
			if(checkpoint2==0)
			{
				printf ("No matches found.\n"); //when no match found
			}
			else
			{
				//when match is found, the cost is calculated using the below formula.
				printf ("Match Found. Enter the number of earlybird ticket.\n");
				scanf ("%d", &number_of_regular1);
				dollar_price_of_regular1 = (number_of_regular1 * speakerInt[REGDOLLAR][index]) + (number_of_regular1*speakerInt[REGCENTS][index])/100;
				cents_price_of_regular1 = (number_of_regular1*speakerInt[REGCENTS][index])%100;
				printf ("You entered %d for regular tickets.\n", number_of_regular1);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_regular1, cents_price_of_regular1);
			}
			break;
	default: printf ("Invalid Input. Sorry\n");break;

			
			
	}
}

// this function finds all the speakers with same series code
void find_all_same_series(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char series_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 6, which is to find all the speaker with same series.\n");
	printf ("Now enter the series code of the speaker you want to find. Please Enter the series code.\n");
	scanf ("%c", &series_code_to_find_all);
	series_code_to_find_all=checkSeriesCode(series_code_to_find_all); //error checking for series code and returns the valid value
	
	for (count=0;count<num_of_people;count++)
	{
		if(series_code_to_find_all==speakerChar[SCODE][count]) //series code compared with the one entered before
		{

			//when match found, results displayed
			index2=count;
			printf ("Found Match\n");			
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);
			checkpoint3=1;
		}
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");


}

// this function finds all ths speakers from same state
void find_all_certain_state(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char certain_state_to_find_all, certain_state_to_find_all1, garbage;
	int checkpoint4=0, count, index3;
	printf ("You entered menu option 7, which is to find all the speaker with certain state.\n");
	printf ("Now enter the homestate of the speaker you want to find. Remember both character should be together and C Programming is case-sensitive. \nPlease Enter the two homestate character together.\n");
	scanf ("%c", &certain_state_to_find_all);
	scanf ("%c%c", &certain_state_to_find_all, &certain_state_to_find_all1);

	
	for (count=0;count<num_of_people;count++)
	{
		// howe state with two characters is compared with the previously entered one
		if((certain_state_to_find_all==speakerChar[HOMESTATE1][count]) && (certain_state_to_find_all1==speakerChar[HOMESTATE2][count]))
		{
			// if match found, results printed
			index3=count;
			printf ("Found Match\n");
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);
			checkpoint4=1;
		}
	}
	if(checkpoint4==0) // if no match found
		printf ("No matches found. Sorry!!! :(\n");

}

// this function leads you to the next function, which is a sub menu function of the programming.
void update_array(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int sub_menu_speaker_code, sub_menu_choice_number, count, index4, checkpoint=0;
	printf ("You enter number 11, which is to update array. Now the program will take you to another sub-menu with bunch of options.\n");
	show_sub_menu();
	//the user is asked to enter which array to update
	while (checkpoint==0)
	{
		printf ("Now enter the integer number of speaker code which you want to update. Please Enter the Speaker code. Remember the range.\n");
		scanf ("%d", &sub_menu_speaker_code);
		sub_menu_speaker_code=checkSpeakerCode(sub_menu_speaker_code); // error checks the speaker code and returns valid value
		
		for(count=0;count<num_of_people;count++)
		{
			if(sub_menu_speaker_code==speakerInt[SPEAKERCODE][count]) // comparing the speaker code entered now with the speaker code entered before
			{
				// if equal, then that speaker's data to be updated
				index4=count;
				printf ("So you will be updating the information of Speaker %d.\n", index4 + 1);
				checkpoint=1;
			}
		}
	}
	printf ("Enter the sub-menu choice number. Remember the range. \n");
	scanf ("%d", &sub_menu_choice_number);
	sub_menu_choice_number=checkSubMenu(sub_menu_choice_number); // error check the range of sub menu choice and returns the valid value

	while(sub_menu_choice_number!=9) // this returns to main menu when the user enters 6 which is an option to return to the main menu
	{
		switch(sub_menu_choice_number)
		{
			// according to the number enter, switch statement calls the corresponding function.
			case 1: change_performance_date(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 2: change_series_code(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 3: change_two_state_char(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 4: change_one_of_the_tickets(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 5: change_performance_time(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 6: change_birth_date(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 7: change_expertise_code(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
			case 8: change_name_of_speaker(index4, num_of_people, speakerInt, speakerChar, speakerName);break;
		}
		printf ("Enter the sub-menu choice number. Remember the range. \n"); // this is to compare the sub menu choice number with the top while loop
		scanf ("%d", &sub_menu_choice_number);
		sub_menu_choice_number=checkSubMenu(sub_menu_choice_number);
		
	}
	printf ("You chose to return to the main menu.\n");


}

// this function searchs all the speakers with same expertise
void search_by_expertise(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char expertise_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 3, which is to find all the speaker with same expertise.\n");
	printf ("Now enter the expertise code of the speaker you want to find. Please Enter the expertise code.\n");
	scanf ("%c", &expertise_code_to_find_all);
	scanf ("%c", &expertise_code_to_find_all);
	expertise_code_to_find_all = checkExpertiseCode(expertise_code_to_find_all); //error checking for expertise code 
	
	for (count=0;count<num_of_people;count++)
	{
		if(expertise_code_to_find_all==speakerChar[ECODE][count]) //series code compared with the one entered before
		{

			//when match found, results displayed
			index2=count;
			printf ("Found Match");			
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][count],speakerInt[PDAY][count],speakerInt[PMONTH][count],speakerInt[PYEAR][count],speakerInt[PHOUR][count],speakerInt[PMINUTE][count],speakerChar[SCODE][count],speakerInt[EBIRDDOLLAR][count],speakerInt[EBIRDCENTS][count],speakerInt[REGDOLLAR][count],speakerInt[REGCENTS][count],speakerChar[HOMESTATE1][count],speakerChar[HOMESTATE2][count],speakerInt[BDAY][count], speakerInt[BMONTH][count], speakerInt[BYEAR][count],speakerChar[ECODE][count], speakerName[count]);
			checkpoint3=1;
		}
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");
}

// this function calculates the age of the speaker while performing
void calculate_age(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int calculate_age_speaker_code, count, index, length_age, length_month, length_day, checkpoint=0;
	printf ("You chose menu option 5, which is to calculate the age of the speaker while performing his act.\n");
	while (checkpoint!=1)
	{
		printf ("Enter the speaker code of the speaker.\n");
		scanf ("%d", &calculate_age_speaker_code);
		calculate_age_speaker_code=checkSpeakerCode(calculate_age_speaker_code); // error checks the speaker code and returns value

		for (count=0;count<num_of_people;count++)
		{
			if (calculate_age_speaker_code==speakerInt[SPEAKERCODE][count])
			{
				index=count;
				checkpoint=1;
			}
		}
	}
	
	// this if else calculates the day
	if(speakerInt[PDAY][index]<speakerInt[BDAY][index])
	{
		length_day=30+speakerInt[PDAY][index]-speakerInt[BDAY][index];
		speakerInt[PMONTH][index]--;
	}
	else
		length_day=speakerInt[PDAY][index]-speakerInt[BDAY][index];

	// this if else calculates the month
	if(speakerInt[PMONTH][index]<speakerInt[BMONTH][index])
	{
		length_month=30+speakerInt[PMONTH][index]-speakerInt[BMONTH][index];
		speakerInt[PYEAR][index]--;
	}
	else
		length_month=speakerInt[PMONTH][index]-speakerInt[BMONTH][index];
	// this calculates the year of the speaker
	length_age=speakerInt[PYEAR][index]-speakerInt[BYEAR][index];


	printf ("The age of speaker %d is %d years %d months %d days.\n", index+1, length_age, length_month, length_day);

	
}

// this function finds all the tickets which are less than the given cost
void find_all_less_than_cost(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int input_choice_ticket,ticket_price_dollar=0, ticket_price_cents=0, index4=0, count, checkpoint=0;
	printf ("You chose the menu option 8, which is to find all the tickets with less than the cost entered.\n");
	printf ("Enter 1 if you want to find on early bird ticket. Enter 2 if you want to find on regular ticket.\n");
	scanf ("%d", &input_choice_ticket);
	while (input_choice_ticket!=1 && input_choice_ticket!= 2)
	{
		printf ("Wrong value enter. Please enter again.\n");
		scanf ("%d", &input_choice_ticket);

	}
	switch (input_choice_ticket)
	{
	case 1: // this case finds all the ticket on early bird
			printf ("You chose to find on early bird.\n");
			printf ("Now enter the price of early bird to find the tickets having the cost below the entered price.\n");
			scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			ticket_price_dollar=checkDollar(ticket_price_dollar, ticket_price_cents); // error checks the range of the dollar and returns valid value
			ticket_price_cents=checkCents(ticket_price_dollar, ticket_price_cents); // error checks the range of the cents and returns valid value

			for(count=0;count<num_of_people;count++)
			{
				if(ticket_price_dollar==speakerInt[EBIRDDOLLAR][count])
				{
					if(ticket_price_cents>=speakerInt[EBIRDCENTS][count])
					{
						index4=count; 
						printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
						checkpoint=1;
					}
					
				}
				else if (ticket_price_dollar>speakerInt[EBIRDDOLLAR][count])
				{
					index4=count;
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
					checkpoint=1;
				}
				
			}
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
			break;
	case 2: // this case finds all the ticket on regular 
			
			printf ("You chose to find on regular ticket.\n");
			printf ("Now enter the price of REGULAR TICKET to find the tickets having the cost below the entered price.\n");
			scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			ticket_price_dollar=checkDollar(ticket_price_dollar, ticket_price_cents); // error checks the range of the dollar and returns valid value
			ticket_price_cents=checkCents(ticket_price_dollar, ticket_price_cents); // error checks the range of the cents and returns valid value

			for(count=0;count<num_of_people;count++)
			{
				if(ticket_price_dollar==speakerInt[REGDOLLAR][count])
				{
					if(ticket_price_cents>=speakerInt[REGCENTS][count])
					{
						index4=count; 
						printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
						checkpoint=1;
					}
					
				}
				else if (ticket_price_dollar>speakerInt[REGDOLLAR][count])
				{
					index4=count;
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
					checkpoint=1;
				}
				
			}
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
			break;
			
	default: printf ("Wrong value entered. Please again.\n");break;


	}
}

// this function sorts all data by speaker code
void sort_by_speaker_code(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	printf ("You chose the menu option 9, which is to sort array by speaker code.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(num_of_people, speakerInt, speakerChar, speakerName);
	bubblesort(num_of_people, speakerInt, speakerChar, speakerName);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(num_of_people, speakerInt, speakerChar, speakerName);

}

// this function sorts all the data by performance date
void sort_by_perfomance_date(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	printf ("You chose the menu option 10, which is to sort array by performance date.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(num_of_people, speakerInt, speakerChar, speakerName);
	bubblesort_performance(num_of_people, speakerInt, speakerChar, speakerName);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(num_of_people, speakerInt, speakerChar, speakerName);

}

// this functions shows the sub menu and its option to the user
void show_sub_menu()
{
	printf ("Now you are on sub-menu. The following are the options on sub_menu: \n1. Change speech month, day, or year. \n2. Change the series array. \n3. Change the two state char arrays. \n4. Change one of the ticket arrays. \n5. Change the time array. \n6. Change birth month, day, or year. \n7. Change the expertise code. \n 8. Change the name. \n 9. Return to main menu.\nNow choose the corresponding option to play with the options.\nFor example, enter 2 to change the series array.\n");
}

// this function changes the performance date
void change_performance_date(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int buffer, change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the performance.\n");
	printf ("Beware that you are going to change the data for Speaker %d.\n", index4+1);
	printf ("Please Enter the day of performance. Remember the range.\n");
	scanf ("%d", &buffer);
	change_date=checkDay(buffer); //error checks the range of the day and returns valid value

	speakerInt[PDAY][index4]=change_date; //data updated
	printf ("Please Enter the month of performance. Remember the range.\n");
	scanf ("%d", &buffer);
	change_month=checkMonth(buffer); // error checks the range of the month and returns valid value

	speakerInt[PMONTH][index4]=change_month; //data updated
	printf ("Please Enter the year of performance. Remember the range.\n");
	scanf ("%d", &buffer);
	change_year =checkYear(buffer); // error checks the range of the month and returns valid value

	speakerInt[PYEAR][index4]=change_year; //data updated
	printf ("\nUpdate successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
			

}

// this function changes the series code
void change_series_code(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char change_series_code='a';
	printf ("You chose to change the series code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the series code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_series_code);
	scanf ("%c", &change_series_code);
	change_series_code=checkSeriesCode(change_series_code); // error checks the series code and returns valid value

	speakerChar[SCODE][index4]=change_series_code; //data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
	
}

// this function changes the home state of the speaker
void change_two_state_char(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int change_state1, change_state2;
	char garbage;
	printf ("Beware!!! You are updating the whole array. Please enter a new two character state.\n");
	scanf ("%c", &garbage);
	scanf (" %c%c", &change_state1, &change_state2);
	speakerChar[HOMESTATE1][index4]=change_state1; //data updated
	speakerChar[HOMESTATE2][index4]=change_state2;//data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
	
}

// this function changes the price of the ticket
void change_one_of_the_tickets(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int change_ticket_choice, change_earlybird_dollar=0, change_earlybird_cents=0, change_regular_dollar=0, change_regular_cents=0;
	printf ("Beware!!! You are updating the whole array. Please chose an option. \nENTER 1 to update earlybird price and \nENTER 2 to update regular price.\n");
	scanf ("%d", &change_ticket_choice);
	while(change_ticket_choice!=1 && change_ticket_choice!=2) //error checking the choice
	{
		printf ("Invalid option entered. Please look and try again.\n");
		scanf ("%d", &change_ticket_choice);
	}
	switch(change_ticket_choice) // calling the respective function according to the choice made
	{
	case 1: //this case changes the earlybird price
			printf ("You chose to change earlybird price.\n");
			printf ("Enter a new earlybird price.\n");
			scanf ("%d.%d", &change_earlybird_dollar, &change_earlybird_cents);
			change_earlybird_dollar=checkDollar(change_earlybird_dollar,change_earlybird_cents); // error checks the range of dollar value
			change_earlybird_cents=checkCents(change_earlybird_dollar,change_earlybird_cents); // error checks the range of cents and returns value

			speakerInt[EBIRDDOLLAR][index4]=change_earlybird_dollar; //data updated
			speakerInt[EBIRDCENTS][index4]=change_earlybird_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);break;

	case 2: //this case changes the price of regular tickets
			
			printf ("You chose to change regular price.\n");
			printf ("Enter a new regular price.\n");
			scanf ("%d.%d", &change_regular_dollar, &change_regular_cents);
			change_regular_dollar=checkDollar(change_regular_dollar,change_regular_cents); // error checks the range of dollar and returns valid value
			change_regular_cents=checkCents(change_regular_dollar,change_regular_cents); // error checks the range of cents and returns valid value


			speakerInt[REGDOLLAR][index4]=change_regular_dollar; //data updated
			speakerInt[REGCENTS][index4]=change_regular_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);break;

	default: printf ("Invalid Option Selected.\n");break;

	}

}

// this function changes the performance of the time
void change_performance_time(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int change_hour_time, change_minute_time;
	printf ("You chose to change time array. Beware, updating here changes everything elsewhere. Remember the range.\n");
	printf ("Please enter the new timing. Remember the format!!!\n");
	scanf ("%d.%d", &change_hour_time, &change_minute_time); 
	change_hour_time=checkHour(change_hour_time,change_minute_time); // error checks the range of hour and returns the valid value
	change_minute_time=checkMinute(change_hour_time,change_minute_time); // error checks the range of minute and returns the valid value


	speakerInt[PHOUR][index4]=change_hour_time; //data updated
	speakerInt[PMINUTE][index4]=change_minute_time;//data updated

	//new updated array is printed
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);	
}

// this function changes the birth date of the speaker
void change_birth_date(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the birth.\n");
	printf ("Beware that you are going to change the data for Speaker %d.\n", index4+1);
	printf ("Please Enter the day of birth. Remember the range.\n");
	scanf ("%d", &change_date);
	change_date=checkDay(change_date); // error checks the range of the day and returns the valid value

	speakerInt[BDAY][index4]=change_date; //data updated
	printf ("Please Enter the month of birth. Remember the range.\n");
	scanf ("%d", &change_month);
	change_month=checkMonth(change_month); // error checks the range of the month and returns the valid value

	speakerInt[BMONTH][index4]=change_month; //data updated
	printf ("Please Enter the year of birth. Remember the range.\n");
	scanf ("%d", &change_year);
	change_year=checkBYear(change_year, speakerInt, index4); // error checks the birth year so that the speaker is at least 10 years old

	speakerInt[BYEAR][index4]=change_year; //data updated
	printf ("\nUpdate successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
			
}

// this function changes the expertise code of the speaker
void change_expertise_code(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char change_expertise_code='a';
	printf ("You chose to change the expertise code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the expertise code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_expertise_code);
	scanf ("%c", &change_expertise_code);
	change_expertise_code=checkExpertiseCode(change_expertise_code); // error checks the expertise code and returns the valid value
	
	speakerChar[ECODE][index4]=change_expertise_code; //data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
	
}

// this function changes the name of the speaker
void change_name_of_speaker(int index4, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	char garbage='a';
	char change_name[40]={};
	printf ("You chose to change the name of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	fgets(change_name, MAXNUM, stdin);
	strcpy(speakerName[index4], change_name); //data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c %d %d %d %c %s \n",speakerInt[SPEAKERCODE][index4],speakerInt[PDAY][index4],speakerInt[PMONTH][index4],speakerInt[PYEAR][index4],speakerInt[PHOUR][index4],speakerInt[PMINUTE][index4],speakerChar[SCODE][index4],speakerInt[EBIRDDOLLAR][index4],speakerInt[EBIRDCENTS][index4],speakerInt[REGDOLLAR][index4],speakerInt[REGCENTS][index4],speakerChar[HOMESTATE1][index4],speakerChar[HOMESTATE2][index4],speakerInt[BDAY][index4], speakerInt[BMONTH][index4], speakerInt[BYEAR][index4],speakerChar[ECODE][index4], speakerName[index4]);
	
}

// this function sorts the array using bubble sort technique
void bubblesort(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int i,j;
	for (i=0;i<num_of_people;i++)
	{
		for(j=0; j<num_of_people-1;j++)
		{
			
			if(speakerInt[SPEAKERCODE][j]>speakerInt[SPEAKERCODE][j+1])
			{
				swap(j, num_of_people, speakerInt, speakerChar, speakerName);
			}
		}
	}
	
}

void swap (int j, int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int k=0, l=0, temp_int=0;
	char temp_char;
	char temp_name[40];
	
	for(k=0;k<13;k++)
	{
		temp_int=speakerInt[k][j];
		speakerInt[k][j]=speakerInt[k][j+1];
		speakerInt[k][j+1]=temp_int;
	}
	for (l=0;l<4;l++)
	{
		temp_char=speakerChar[l][j];
		speakerChar[l][j]=speakerChar[l][j+1];
		speakerChar[l][j+1]=temp_char;
	}
	strcpy(temp_name, speakerName[j]);
	strcpy(speakerName[j], speakerName[j+1]);
	strcpy(speakerName[j+1], temp_name);
	
	
	
}

// this function sorts array using bubble sort technique for performance date
void bubblesort_performance(int num_of_people, int speakerInt[13][EVENTMAX], char speakerChar[4][EVENTMAX], char speakerName[EVENTMAX][MAXNUM])
{
	int i,j;
	for (i=0;i<num_of_people;i++)
	{
		for(j=0; j<num_of_people-1;j++)
		{
			if(speakerInt[PYEAR][j]>speakerInt[PYEAR][j+1])
			{
				swap(j, num_of_people, speakerInt, speakerChar, speakerName);
			}
			else if (speakerInt[PYEAR][j]==speakerInt[PYEAR][j+1])
			{
				if (speakerInt[PMONTH][j]>speakerInt[PMONTH][j+1])
					swap(j, num_of_people, speakerInt, speakerChar, speakerName);
				else if (speakerInt[PMONTH][j]==speakerInt[PMONTH][j+1])
				{
					if (speakerInt[PDAY][j]>speakerInt[PDAY][j+1])
						swap(j, num_of_people, speakerInt, speakerChar, speakerName);
				}

			}
		}
	}

}

// this function error checks the speaker code
int checkSpeakerCode (int a)
{
	//error checking speaker code
		while (a < 100 || a > 999) 
		{
			if( a != '\n')
				printf ("\nInvalid Speaker Code. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &a);
		}
		return a;
}	

// this function error checks the day of the speech and birth
int checkDay(int a)
{
	//error checking day of speech
		while (a < 1 || a > 32) 
		{
			printf ("\nInvalid Day of Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &a);
		}
		return a;
}

// this function error checks the month of the speech and birth
int checkMonth(int a)
{
	//error checking month of speech
		while (a<1 || a>12) 
		{
			printf ("\nInvalid month. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &a);
		}
		return a;
}


// this function error checks the year of the speech
int checkYear(int a)
{
	//error checking year of speech
		while (a<2000 || a>2050) 
		{
			printf ("\nInvalid Year. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &a);
		}
		return a;
}

// this function error checks the series code
char checkSeriesCode(char a)
{
	//error checking the series code
		while (a != 'M' && a != 'E' && a != 'D'&& a != 'C' && a != 'S' && a != 'U' && a != 'L' && a != 'O')
		{
			if(a !='\n' )
				printf ("\nInvalid Series Code. Please go back and look at the instructions and try again. :)");
			scanf ("%c", &a);
		}
		return a;
}

// this function error checks the expertise code
char checkExpertiseCode(char a)
{
	char garbage;
	
		while (a!='A' && a!= 'B' && a!= 'C' && a!= 'P' && a!= 'E' && a!= 'I' && a!= 'M' && a!= 'S' && a!= 'O' && a!= 'Z' && a!='L' && a!= 'D' && a!= 'X' && a!='N' && a!='R' && a!='W' && a!='U' && a!= 'G')
		{
			if (a!='\n' || a!='\t' || a!= '\0')
				printf ("Error in input. Try again.\n");
			scanf ("%c", &garbage);
			scanf ("%c", &a);
		}
		return a;
}

// this function error checks the birth year
int checkBYear(int a, int speakerInt[13][EVENTMAX], int count)
{
	
		while (a > (speakerInt[PYEAR][count]-10)) 
		{
			printf ("Wrong BIRTH YEAR format. Should be at least the difference of 10 years. Enter again. \n");
			scanf ("%d",&a);
		}
		return a;
}


// this function error checks the hour of the speech
int checkHour(int a, int b)
{
	//error checking the time of speech
		while (a<0 || a>23 || b<0 || b>59) 
		{
			printf ("\nInvalid Time for Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d.%d", &a, &b);
		}	
		return a;
}

// this function error checks the minute of the speech
int checkMinute(int a, int b)
{
	//error checking the time of speech
		while (a<0 || a>23 || b<0 || b>59) 
		{
			printf ("\nInvalid Time for Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d.%d", &a, &b);
		}	
		return b;
}

// this function error checks the dollar value of the ticket
int checkDollar(int a, int b)
{
	//error checking price of  ticket
		while (a<0 || b<0|| b>99)
		{
			printf ("\nInvalid Price of ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &a, &b);
		}
		return a;
}

// this functions error checks the cent value of the ticket
int checkCents(int a, int b)
{
	//error checking price of  ticket
		while (a<0 || b<0|| b>99)
		{
			printf ("\nInvalid Price of ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &a, &b);
		}
		return b;
}


// this functions whether the valid range fort the sub menu choice is entered or not
int checkSubMenu(int a)
{
	while(a<1 || a>9) //error checking the sub menu option
	{
		printf ("Invalid Entry. Please look at the instructions.\n");
		scanf ("%d", &a);

	}
	return a;
}

