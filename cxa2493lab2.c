/* Chudamani Aryal
Lab2 Assignment
Date Given: Oct 10 2010
Date Due: Oct 28 2010
Professor: Dr T
Class: CSE 1320 Section: 001 TH 11-12:20 */

// *********Description of the program**************
/* This program lets the user enter certain set of data with some constraints. 
After the data are entered, this program stores those data and later on acts as a database 
and provides the users to play with some of its menu choices. 
You will know more about the menu choice once you get into the program. */

//*********  pre-processors   *************
#include <stdio.h>
#include <string.h>
#define EVENTMAX 25
#define EVENTMIN 1
#define MAXSTATE 3
#define MAXNUM 40
#define MAX 128

// declaration of definition of structure datatype
struct speaker
{
	int speakerCode, pday, pmonth, pyear, phour, pminute, ebird_dollar, ebird_cents, reg_dollar, reg_cents, bday, bmonth, byear;
	char seriesCode, expertiseCode, state[MAXSTATE], firstName[MAXNUM], lastName[MAXNUM], titleName[MAX];
};


// **************** declaration of functions  *******************
void welcome_msg();
int checknumber(int a);
int check_input_choice(int b);
int checkSpeakerCode (int a);
int checkDay(int a);
int checkMonth(int a);
int checkYear(int a);
char checkSeriesCode(char a);
char checkExpertiseCode(char a);
void show_oneLine_enter();
void show_menu();
void show_expertise_format();
int check_menu_choice(int c);
void input_Individual (int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void input_oneLine (int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void printArray(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void main_menu_operation (int menu_choice_number, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void exit_the_program();
void search_by_speakercode(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void search_by_dateofspeech(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void calculate_cost(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void find_all_same_series(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void find_all_certain_state(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void update_array(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void calculate_age(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void find_all_less_than_cost(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void search_by_expertise(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void sort_by_speaker_code(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void sort_by_perfomance_date(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void show_sub_menu();
void change_performance_date(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_series_code(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_two_state_char(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_one_of_the_tickets(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_performance_time(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_birth_date(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_firstName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_lastName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_expertise_code(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void change_titleName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void bubblesort(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void bubblesort_lastName(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void swap(int j, int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void bubblesort_performance(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void sort_by_lastName(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void calculate_length_of_time(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);
void search_speaker_by_lastname(int num_of_people, struct speaker utaSpeaker[EVENTMAX]);

// ****************        main function      ******************
int main (){

	// declarations of variables
	struct speaker utaSpeaker[EVENTMAX];
	int enter_data, num_of_people, input_choice, menu_choice_number;

	// Program begins
	welcome_msg();
	printf ("\nHow many sets of data you want to enter. Remember minimun is 12 and maximum is 25, inclusive.\n");
	scanf ("%d", &enter_data);
	num_of_people = checknumber(enter_data); // check wheather the number entered in within the range from 10 to 20
	printf ("Now you are going to choose the way to input your data.\nEnter 1 if you want to input your data individually.\nEnter 2 if you want to input your data on one line.\n");
	scanf ("%d", &enter_data);
	input_choice= check_input_choice(enter_data); // Asking method of Input (Individual or One Line)

	switch(input_choice) // This switch statement calls the respective input function
	{
	case 1: input_Individual(num_of_people, utaSpeaker);break;
	case 2: input_oneLine(num_of_people, utaSpeaker);break;
	default: printf ("Invalid Input\n");break;
	}
	
	printf ("Congratulations!!!! Congratulations!!! Congratulations!!! You have successfully entered all the required data.\n");
	printf ("Here are your data you have entered: \n");
	printArray(num_of_people, utaSpeaker);

	printf ("Now begins the fun part.\n");
	
	// Once all the data that have been entered are shown, the program next shows the menu
	show_menu();

	// Once all the menu option are shown, the user is asked to enter the option number to work accordingly
	printf ("Now enter the menu option number.\n");
	scanf ("%d", &enter_data);

	// menu choice is verified and main menu operation is called. Also a reminder, one of the options of main menu calls sub menu function
	menu_choice_number = check_menu_choice(enter_data);
	main_menu_operation(menu_choice_number, num_of_people, utaSpeaker);
	printf ("EVERYTHING WORKS FINE :) \n");
	return 0;
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
		printf ("Invalid Number. Please look at the instructions and try again.\n");
		scanf ("%d", &a);
	}
	return a;
}


// this function checks whether the right method of input is chosen or not
int check_input_choice(int b)
{
	while (b!=1 && b!=2)
	{
		printf ("Invalid Number entered. Please look at the instructions and try again.\n");
		scanf ("%d", &b);
	}
	return b;
}

// this function asks the user to enter all the data individually
void input_Individual (int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int count, input_name, buffer, buffer1; char buffer_char, garbage, buffer_char1[MAXNUM];
	printf ("You chose to enter your sets of data in Individual data method.\n");
	
	for(count=0; count<num_of_people; count++) // loop to repeat asking the data over and over again
	{		
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("\nPLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		scanf ("%d", &buffer); 
		utaSpeaker[count].speakerCode = checkSpeakerCode(buffer); 
		
		
		printf ("\nPLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		scanf ("%d", &buffer);
		utaSpeaker[count].pday = checkDay(buffer);


		
		printf ("\nPLEASE ENTER THE month. Remember to make that month valid i.e within the range of 1 to 12. \n");
		scanf ("%d", &buffer);
		utaSpeaker[count].pmonth = checkMonth(buffer);


		
		printf ("\nPLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		scanf ("%d", &buffer);
		utaSpeaker[count].pyear = checkYear(buffer);

		
		
		printf ("\nPLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		scanf ("%d.%d", &utaSpeaker[count].phour, &utaSpeaker[count].pminute);
		


		//error checking the time of speech
		while (utaSpeaker[count].phour<0 || utaSpeaker[count].phour>23 || utaSpeaker[count].pminute<0 || utaSpeaker[count].pminute>59) 
		{
			printf ("\nInvalid Time for Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d.%d", &utaSpeaker[count].phour, &utaSpeaker[count].pminute);
		}		

		printf ("\nPLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		
		scanf ("%c", &buffer_char);
		utaSpeaker[count].expertiseCode=checkSeriesCode(buffer_char);


		
		printf ("\nPLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &utaSpeaker[count].ebird_dollar, &utaSpeaker[count].ebird_cents);

		//error checking price of early bird ticket
		while (utaSpeaker[count].ebird_dollar<0 || utaSpeaker[count].ebird_cents<0|| utaSpeaker[count].ebird_cents>99)
		{
			printf ("\nInvalid Price of earlybird ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &utaSpeaker[count].ebird_dollar, &utaSpeaker[count].ebird_cents);
		}
		printf ("\nPLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &utaSpeaker[count].reg_dollar, &utaSpeaker[count].reg_cents);

		//error checking the price of regular tickets
		while (utaSpeaker[count].reg_dollar <0 || utaSpeaker[count].reg_cents<0|| utaSpeaker[count].reg_cents >99)
		{
			printf ("\nInvalid Price of regular ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &utaSpeaker[count].reg_dollar, &utaSpeaker[count].reg_cents);
		}
		printf ("\nPLEASE ENTER THE HOMESTATE OF THE SPEAKER. For example NY would be for New York. \n");
		scanf (" %s", &utaSpeaker[count].state);	
		
		printf ("PLEASE ENTER THE DAY OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		utaSpeaker[count].bday=checkDay(buffer);

		printf ("PLEASE ENTER THE MONTH OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		utaSpeaker[count].bmonth=checkMonth(buffer);

		printf ("PLEASE ENTER THE YEAR OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		while ((buffer-utaSpeaker[count].pyear)<10)
		{
			printf ("Invalid Birth year. Try again.\n");
			scanf ("%d",&buffer);

		}
		utaSpeaker[count].byear = buffer;

		
		show_expertise_format();
		printf ("PLEASE ENTER THE EXPERTISE CODE.");
		scanf ("%c", &garbage);
		scanf ("%c", &buffer_char);
		utaSpeaker[count].expertiseCode=checkExpertiseCode(buffer_char);
		
		printf ("\nPLEASE ENTER THE FIRST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		scanf ("%c", &garbage);
		scanf ("%s", &buffer_char1);
		
		if(strlen(buffer_char1)>MAXNUM)
		{
			printf ("Crossed the max length.Truncated to fit.\n");
			buffer_char1[MAXNUM]='\0';
		}
		strcpy(utaSpeaker[count].firstName, buffer_char1);
		
		printf ("\nPLEASE ENTER THE LAST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		scanf ("%c", &garbage);
		scanf ("%s", &buffer_char1);
		
		if(strlen(buffer_char1)>MAXNUM)
		{
			printf ("Crossed the max length.Truncated to fit.\n");
			buffer_char1[MAXNUM]='\0';
		}
		strcpy(utaSpeaker[count].lastName, buffer_char1);
		

				

		printf ("\nPLESE ENTER THE TITLE OF THE SPEAKER'S PERORMANCE OR SPEECH. THE MAX LENGTH IS 512.\n");
		scanf ("%c", &garbage);
		fgets(utaSpeaker[count].titleName, MAX, stdin);
		utaSpeaker[count].titleName[MAX-1]='\0';
		
	}
}

// this function asks the user to enter all the necessary data in one line format
void input_oneLine (int num_of_people, struct speaker utaSpeaker[EVENTMAX]){
	int count;
	show_oneLine_enter();
	// loop to repeat asking the data over and over again
	for(count=0; count<num_of_people; count++) 
	{		

		// Description on how to enter data (Overall)
		
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("PLEASE ENTER.\n");
		scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s",&utaSpeaker[count].speakerCode, &utaSpeaker[count].pday, &utaSpeaker[count].pmonth, &utaSpeaker[count].pyear, &utaSpeaker[count].phour, &utaSpeaker[count].pminute, &utaSpeaker[count].seriesCode, &utaSpeaker[count].ebird_dollar, &utaSpeaker[count].ebird_cents, &utaSpeaker[count].reg_dollar, &utaSpeaker[count].reg_cents, &utaSpeaker[count].state, &utaSpeaker[count].bday, &utaSpeaker[count].bmonth, &utaSpeaker[count].byear, &utaSpeaker[count].expertiseCode, &utaSpeaker[count].firstName, &utaSpeaker[count].lastName );
		fgets(utaSpeaker[count].titleName, MAX, stdin);
		utaSpeaker[count].titleName[MAX-1]='\0';
	
		//error checking of everything as a whole
		while ((utaSpeaker[count].speakerCode<100 || utaSpeaker[count].speakerCode >999)||(utaSpeaker[count].pday<1 || utaSpeaker[count].pday>32)||(utaSpeaker[count].pmonth<1 || utaSpeaker[count].pmonth>12)||(utaSpeaker[count].pyear<2000 || utaSpeaker[count].pyear>2050)||(utaSpeaker[count].phour<0 || utaSpeaker[count].phour>23 || utaSpeaker[count].pminute<0 || utaSpeaker[count].pminute>59)||(utaSpeaker[count].seriesCode != 'M' && utaSpeaker[count].seriesCode != 'E' && utaSpeaker[count].seriesCode != 'D'&& utaSpeaker[count].seriesCode != 'C' && utaSpeaker[count].seriesCode != 'S' && utaSpeaker[count].seriesCode != 'U' && utaSpeaker[count].seriesCode != 'L' && utaSpeaker[count].seriesCode != 'O')||(utaSpeaker[count].ebird_dollar<0 || utaSpeaker[count].ebird_cents<0|| utaSpeaker[count].ebird_cents>99)||(utaSpeaker[count].reg_dollar<0 || utaSpeaker[count].reg_cents<0|| utaSpeaker[count].reg_cents>99)|| (utaSpeaker[count].expertiseCode != 'A' && utaSpeaker[count].expertiseCode != 'B' && utaSpeaker[count].expertiseCode != 'C' && utaSpeaker[count].expertiseCode != 'P' && utaSpeaker[count].expertiseCode != 'E' && utaSpeaker[count].expertiseCode != 'I' && utaSpeaker[count].expertiseCode != 'M' && utaSpeaker[count].expertiseCode != 'S' && utaSpeaker[count].expertiseCode != 'O' && utaSpeaker[count].expertiseCode != 'Z' && utaSpeaker[count].expertiseCode != 'L' && utaSpeaker[count].expertiseCode != 'D' && utaSpeaker[count].expertiseCode != 'X' && utaSpeaker[count].expertiseCode != 'N' && utaSpeaker[count].expertiseCode != 'R' && utaSpeaker[count].expertiseCode != 'W' && utaSpeaker[count].expertiseCode != 'U' && utaSpeaker[count].expertiseCode != 'G'))
		{
			printf ("\nInvalid Format. Please go back and look at the instructions and try again.\n");
			scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s",&utaSpeaker[count].speakerCode, &utaSpeaker[count].pday, &utaSpeaker[count].pmonth, &utaSpeaker[count].pyear, &utaSpeaker[count].phour, &utaSpeaker[count].pminute, &utaSpeaker[count].seriesCode, &utaSpeaker[count].ebird_dollar, &utaSpeaker[count].ebird_cents, &utaSpeaker[count].reg_dollar, &utaSpeaker[count].reg_cents, &utaSpeaker[count].state, &utaSpeaker[count].bday, &utaSpeaker[count].bmonth, &utaSpeaker[count].byear, &utaSpeaker[count].expertiseCode, &utaSpeaker[count].firstName, &utaSpeaker[count].lastName );
			fgets(utaSpeaker[count].titleName, MAX, stdin);
			utaSpeaker[count].titleName[MAX-1]='\0';
			
			
		}
		if(strlen(utaSpeaker[count].firstName)>MAXNUM)
			utaSpeaker[count].firstName[MAXNUM]='\0';
		if(strlen(utaSpeaker[count].lastName)>MAXNUM)
			utaSpeaker[count].firstName[MAXNUM]='\0';
	
	}
}

// this function prints all the data
void printArray(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int count;
	for(count=0;count<num_of_people;count++)
	{	
		printf ("The data you have entered for Speaker %d is:\n", count+1);
		printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
			
	}
}

// this function shows what to enter in one line
void show_oneLine_enter()
{
		printf ("\nYou chose to enter your sets of data in One Line Format.\n");
		printf ("\nRemember the format: 100 24 9 2010 19.00 M 0.00 0.00 NY \nHere 100 is Speaker Code, \n24 is day of the speech, \n9 is the month, \n2010 is the year, \n19.00 is the military timing, \nM is the series code, \n0.00 is early bird ticket and \nsecond 0.00 is regular ticket price and \nfinally NY is the Homestate of the speaker. \n");
	
		printf ("PLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		printf ("PLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		printf ("PLEASE ENTER THE MONTH. Remember to make that month valid i.e within the range of 1 to 12. \n");
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
		printf ("PLEASE ENTER THE FIRST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		printf ("PLEASE ENTER THE LAST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		printf ("\nPLESE ENTER THE TITLE NAME OF THE PERFORMANCE OR SPEECH OF THE SPEAKER. THE MAX LENGTH IS 512.\n");

}

//this function shows user the menu and its options
void show_menu()
{
	printf ("Now you are looking at the menu choices of this program.\nAnd the following are your choices:\n1. Search for speakers/performers by speaker code.\n2. Search for speakers/performers by date of speech/performance.\n 3. Search for speakers by expertise\n 4. Calculate cost for purchase of a given number of tickets of a given type.\n 5. Calculate the age of the speaker while in performance.\n6. Find all the speakers in the same series.\n7. Find all the speakers that are from a certain state.\n8. Find all the speeches/performances that cost less than a given ticket price. \n9. Sort the data by speaker code. \n10.  Sort the data by speech/performance date. \n11. Update the data in the arrays. This will take you to a submenu for doing updates.\n12. Search the speaker by last name.\n13. Calculate length of time from current date to the date of the speech/performance.\n14. Sort the data by last name.\n 15. End the program.\n");
	printf ("Remember that while chosing your menu choice, you have to choose the corresponding number to the menu option. \nFor example, to calculate the ticket cost you must enter 4.\n");
}

// this function checks whether the right menu choice is entered or not
int check_menu_choice(int c)
{
	while (c<1||c>15)
	{
		printf("Invalid Menu Choice. Please Look at the instructions and try again.\n");
		show_menu();
		scanf ("%d", &c);
	}
	return c;
}

// this function takes the user into the main menu operation and gives the user various choices to enter
void main_menu_operation (int menu_choice_number, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	while (menu_choice_number != 15)
	{
		switch(menu_choice_number)
		{
		// each case here represents the menu options and once that case is entered, this switch statement calls that corresponding function
		case 1: search_by_speakercode(num_of_people, utaSpeaker);break;
		case 2: search_by_dateofspeech(num_of_people, utaSpeaker);break;
		case 3: search_by_expertise(num_of_people, utaSpeaker);break;
		case 4: calculate_cost(num_of_people, utaSpeaker);break;
		case 5: calculate_age(num_of_people, utaSpeaker);break;
		case 6: find_all_same_series(num_of_people, utaSpeaker);break;
		case 7: find_all_certain_state(num_of_people, utaSpeaker);break;
		case 8: find_all_less_than_cost(num_of_people, utaSpeaker);break;		
		case 9: sort_by_speaker_code(num_of_people, utaSpeaker);break;
		case 10: sort_by_perfomance_date(num_of_people, utaSpeaker);break;
		case 11: update_array(num_of_people, utaSpeaker);break;
		case 12: search_speaker_by_lastname(num_of_people, utaSpeaker);break;
		case 13: calculate_length_of_time(num_of_people, utaSpeaker);break;
		case 14: sort_by_lastName(num_of_people, utaSpeaker);break;
		default: printf ("Invalid Entry. Please check your choice number.\n");break;
		}
		printf ("Choose Another menu option, which is from the range of 1 to 15.\n");
		scanf ("%d", &menu_choice_number);
		while(menu_choice_number<1||menu_choice_number>15)  //error checking the menu option
		{
			printf ("Invalid entry. Please enter again.\n");
			scanf ("%d", &menu_choice_number);
		}
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
void search_by_speakercode(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int enter_data, count, checkpoint=0;
	printf ("\nYou chose menu option 1. This means you want to search a speaker by speaker code.\n");
	printf ("\nNow Enter the speaker code. Remember the range given before.\n");
	scanf ("%d", &enter_data);
	enter_data = checkSpeakerCode(enter_data);
	for(count=0;count<num_of_people;count++)
	{
		if(enter_data==utaSpeaker[count].speakerCode) // comparing the speaker code entered before with the speaker code entered now
		{
			checkpoint=1;
			printf ("Found Match \n");
			printf ("The set of data found has:\n");
			//if match found result printed
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
		
		}
	}
	if(checkpoint==0)
			printf ("No matches found. Sorry!!! :(\n");

}

// this function searchs data by date of speech
void search_by_dateofspeech(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
int enter_data4, enter_data5, enter_data6, count, checkpoint1=0;
	printf ("\nYou chose menu option 2. This means you want to search a speaker by date of speech. \n");
	printf ("\nNow Enter the date of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data4);
	enter_data4=checkDay(enter_data4);

	printf ("\nNow Enter the month of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data5);
	enter_data5=checkMonth(enter_data5);

	printf ("\nNow Enter the year of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data6);
	enter_data6=checkYear(enter_data6);

	for(count=0;count<num_of_people;count++)
	{
		if(enter_data4==utaSpeaker[count].pday) //comparing the date of speech entered before with the date of speech entered now
			if(enter_data5==utaSpeaker[count].pmonth)
				if(enter_data6==utaSpeaker[count].pyear)
				{
					// if match found, result printed
					printf ("Found Match\n");
					printf ("The set of data from the found match is:\n");
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
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
void calculate_cost(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int calculate_choice, checkpoint2, speaker_code_calculate, speaker_code_calculate1, speaker_code_calculate2, count, index, number_of_earlybird, number_of_regular, number_of_earlybird1,number_of_regular1, dollar_price_of_earlybird, dollar_price_of_earlybird1, cents_price_of_earlybird, cents_price_of_earlybird1, dollar_price_of_regular, dollar_price_of_regular1, cents_price_of_regular, cents_price_of_regular1, dollar_price_of_total, cents_price_of_total;
	
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
					if(speaker_code_calculate==utaSpeaker[count].speakerCode)
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
				dollar_price_of_earlybird = (number_of_earlybird * utaSpeaker[index].ebird_dollar) + (number_of_earlybird*utaSpeaker[index].ebird_cents)/100;
				cents_price_of_earlybird = (number_of_earlybird*utaSpeaker[index].ebird_cents)%100;
				dollar_price_of_regular = (number_of_regular * utaSpeaker[index].reg_dollar) + (number_of_regular*utaSpeaker[index].reg_cents)/100;
				cents_price_of_regular = (number_of_regular*utaSpeaker[index].reg_cents)%100;
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
				if(speaker_code_calculate1==utaSpeaker[count].speakerCode) //speaker code is compared to find the match
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
				dollar_price_of_earlybird1 = (number_of_earlybird1 * utaSpeaker[index].ebird_dollar) + (number_of_earlybird1*utaSpeaker[index].ebird_cents)/100;
				cents_price_of_earlybird1 = (number_of_earlybird1*utaSpeaker[index].ebird_cents)%100;
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
				if(speaker_code_calculate2==utaSpeaker[count].speakerCode) //speaker code compared to find a match
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
				dollar_price_of_regular1 = (number_of_regular1 * utaSpeaker[index].reg_dollar) + (number_of_regular1*utaSpeaker[index].reg_cents)/100;
				cents_price_of_regular1 = (number_of_regular1*utaSpeaker[index].reg_cents)%100;
				printf ("You entered %d for regular tickets.\n", number_of_regular1);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_regular1, cents_price_of_regular1);
			}
			break;
	default: printf ("Invalid Input. Sorry\n");break;

			
			
	}
}

// this function finds all the speakers with same series code
void find_all_same_series(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char series_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 6, which is to find all the speaker with same series.\n");
	printf ("Now enter the series code of the speaker you want to find. Please Enter the series code.\n");
	scanf ("%c", &series_code_to_find_all);
	series_code_to_find_all = checkSeriesCode(series_code_to_find_all);

	for (count=0;count<num_of_people;count++)
	{
		if(series_code_to_find_all==utaSpeaker[count].seriesCode) //series code compared with the one entered before
		{

			//when match found, results displayed
			index2=count;
			printf ("Found Match\n");			
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
			checkpoint3=1;
		}
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");


}

// this function finds all ths speakers from same state
void find_all_certain_state(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char certain_state_to_find_all[3], garbage;
	int checkpoint4=0, count, index3;
	printf ("You entered menu option 7, which is to find all the speaker with certain state.\n");
	printf ("Now enter the homestate of the speaker you want to find. Remember both character should be together and C Programming is case-sensitive. \nPlease Enter the two homestate character together.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &certain_state_to_find_all);

	
	for (count=0;count<num_of_people;count++)
	{
		// howe state with two characters is compared with the previously entered one
		if((certain_state_to_find_all[0]==utaSpeaker[count].state[0]) &&(certain_state_to_find_all[1]==utaSpeaker[count].state[1] ))
		{
			// if match found, results printed
			index3=count;
			printf ("Found Match\n");
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
			checkpoint4=1;
		}
	}
	if(checkpoint4==0) // if no match found
		printf ("No matches found. Sorry!!! :(\n");

}

// this function leads you to the next function, which is a sub menu function of the programming.
void update_array(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int sub_menu_speaker_code, sub_menu_choice_number, count, index4, checkpoint=0;
	printf ("You enter number 11, which is to update array. Now the program will take you to another sub-menu with bunch of options.\n");
	show_sub_menu();
	//the user is asked to enter which array to update
	while (checkpoint==0)
	{
		printf ("Now enter the integer number of speaker code which you want to update. Please Enter the Speaker code. Remember the range.\n");
		scanf ("%d", &sub_menu_speaker_code);
		sub_menu_speaker_code=checkSpeakerCode(sub_menu_speaker_code);

		for(count=0;count<num_of_people;count++)
		{
			if(sub_menu_speaker_code==utaSpeaker[count].speakerCode) // comparing the speaker code entered now with the speaker code entered before
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
	while(sub_menu_choice_number<1 || sub_menu_choice_number>11) //error checking the sub menu option
	{
		printf ("Invalid Entry. Please look at the instructions.\n");
		scanf ("%d", &sub_menu_choice_number);

	}
	while(sub_menu_choice_number!=11) // this returns to main menu when the user enters 6 which is an option to return to the main menu
	{
		switch(sub_menu_choice_number)
		{
			// according to the number enter, switch statement calls the corresponding function.
			case 1: change_performance_date(index4, num_of_people, utaSpeaker);break;
			case 2: change_series_code(index4, num_of_people, utaSpeaker);break;
			case 3: change_two_state_char(index4, num_of_people, utaSpeaker);break;
			case 4: change_one_of_the_tickets(index4, num_of_people, utaSpeaker);break;
			case 5: change_performance_time(index4, num_of_people, utaSpeaker);break;
			case 6: change_birth_date(index4, num_of_people, utaSpeaker);break;
			case 7: change_expertise_code(index4, num_of_people, utaSpeaker);break;
			case 8: change_titleName(index4, num_of_people, utaSpeaker);break;
			case 9: change_firstName(index4, num_of_people, utaSpeaker);break;
			case 10: change_lastName(index4, num_of_people, utaSpeaker);break;
		}
		printf ("Enter the sub-menu choice number. Remember the range. \n"); // this is to compare the sub menu choice number with the top while loop
		scanf ("%d", &sub_menu_choice_number);
		while(sub_menu_choice_number<1 || sub_menu_choice_number>11)
		{
			printf ("Invalid Entry. Please look at the instructions.\n");
			scanf ("%d", &sub_menu_choice_number);

		}
		
	}
	printf ("You chose to return to the main menu.\n");


}

// this function searchs all the speakers with same expertise
void search_by_expertise(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char expertise_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 3, which is to find all the speaker with same expertise.\n");
	printf ("Now enter the expertise code of the speaker you want to find. Please Enter the expertise code.\n");
	scanf ("%c", &expertise_code_to_find_all);
	scanf ("%c", &expertise_code_to_find_all);
	expertise_code_to_find_all=checkExpertiseCode(expertise_code_to_find_all);

	for (count=0;count<num_of_people;count++)
	{
		if(expertise_code_to_find_all==utaSpeaker[count].expertiseCode) //series code compared with the one entered before
		{

			//when match found, results displayed
			index2=count;
			printf ("Found Match");			
			printf ("The set of data from the found match is:\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
				checkpoint3=1;
		}
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");
}

// this function calculates the age of the speaker while performing
void calculate_age(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int calculate_age_speaker_code, count, index, length_day, length_month, length_year, checkpoint=0;
	printf ("You chose menu option 5, which is to calculate the age of the speaker while performing his act.\n");
	while (checkpoint!=1)
	{
		printf ("Enter the speaker code of the speaker.\n");
		scanf ("%d", &calculate_age_speaker_code);
		calculate_age_speaker_code=checkSpeakerCode(calculate_age_speaker_code);

		for (count=0;count<num_of_people;count++)
		{
			if (calculate_age_speaker_code==utaSpeaker[count].speakerCode)
			{
				index=count;
				checkpoint=1;
			}
		}
		
		if (checkpoint==0)
		printf ("Speaker Not Found. Enter again.\n");
	}
	if (checkpoint==1)
	{	
		if(utaSpeaker[index].pday<utaSpeaker[index].bday)
		{
			length_day=30+utaSpeaker[index].pday-utaSpeaker[index].bday;
			utaSpeaker[index].pmonth--;
		}
		else
		{
			length_day=utaSpeaker[index].pday-utaSpeaker[index].bday;
		}
		
		if(utaSpeaker[index].pmonth<utaSpeaker[index].bmonth)
		{
			length_month=12+utaSpeaker[index].pmonth-utaSpeaker[index].bmonth;
			utaSpeaker[index].pyear--;
		}
		else
		{
			length_month=utaSpeaker[index].pmonth-utaSpeaker[index].bmonth;
		}
		length_year=utaSpeaker[index].pyear-utaSpeaker[index].byear;
	}
		printf ("The age of speaker %d is %d years, %d months and %d days.\n", index+1, length_year, length_month, length_day);
	
}

// this function finds all the tickets which are less than the given cost
void find_all_less_than_cost(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int input_choice_ticket,ticket_price_dollar, ticket_price_cents, index4=0, count, checkpoint=0;
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
	case 1: printf ("You chose to find on early bird.\n");
			printf ("Now enter the price of early bird to find the tickets having the cost below the entered price.\n");
			scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			while(ticket_price_dollar<0 || ticket_price_cents<0 || ticket_price_cents>99)
			{
				printf ("Wrong price entered. Please enter again.\n");
				scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			}
			for(count=0;count<num_of_people;count++)
			{
				if(ticket_price_dollar==utaSpeaker[count].ebird_dollar)
				{
					if(ticket_price_cents>=utaSpeaker[count].ebird_cents)
					{
						index4=count; 
						printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
						checkpoint=1;
					}
					
				}
				else if (ticket_price_dollar>utaSpeaker[count].ebird_dollar)
				{
					index4=count;
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
					checkpoint=1;
				}
				
			}
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
			break;
	case 2: printf ("You chose to find on regular ticket.\n");
			printf ("Now enter the price of regular to find the tickets having the cost below the entered price.\n");
			scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			while(ticket_price_dollar<0 || ticket_price_cents<0 || ticket_price_cents>99)
			{
				printf ("Wrong price entered. Please enter again.\n");
				scanf ("%d.%d", &ticket_price_dollar, &ticket_price_cents);
			}
			for(count=0;count<num_of_people;count++)
			{
				if(ticket_price_dollar==utaSpeaker[count].reg_dollar)
				{
					if(ticket_price_cents>=utaSpeaker[count].reg_cents)
					{
						index4=count; 
						printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
							checkpoint=1;
					}
					
				}
				else if (ticket_price_dollar>utaSpeaker[count].reg_dollar)
				{
					index4=count;
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
					checkpoint=1;
				}
				
			}
			break;
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
	default: printf ("Wrong value entered. Please again.\n");break;


	}
}

// this function sorts all data by speaker code
void sort_by_speaker_code(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	printf ("You chose the menu option 9, which is to sort array by speaker code.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(num_of_people, utaSpeaker);
	bubblesort(num_of_people, utaSpeaker);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(num_of_people, utaSpeaker);

}

// this function sorts all data by speaker code
void sort_by_lastName(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	printf ("You chose to sort array by last name of the speaker.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(num_of_people, utaSpeaker);
	bubblesort_lastName(num_of_people, utaSpeaker);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(num_of_people, utaSpeaker);

}

// this function sorts all the data by performance date
void sort_by_perfomance_date(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	printf ("You chose the menu option 10, which is to sort array by performance date.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(num_of_people, utaSpeaker);
	bubblesort_performance(num_of_people, utaSpeaker);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(num_of_people, utaSpeaker);

}

// this functions shows the sub menu and its option to the user
void show_sub_menu()
{
	printf ("Now you are on sub-menu. The following are the options on sub_menu: \n1. Change speech month, day, or year. \n2. Change the series array. \n3. Change the two state char arrays. \n4. Change one of the ticket arrays. \n5. Change the time array. \n6. Change birth month, day, or year. \n7. Change the expertise code. \n 8. Change the title name. \n 9. Change the first name. 10. Change the last name. \n11. Return to main menu.\nNow choose the corresponding option to play with the options.\nFor example, enter 2 to change the series array.\n");
}

// this function changes the performance date
void change_performance_date(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the performance.\n");
	printf ("Beware that you are going to change the data for Speaker %d.\n", index4+1);
	printf ("Please Enter the day of performance. Remember the range.\n");
	scanf ("%d", &change_date);
	utaSpeaker[index4].pday=checkDay(change_date); //data updated

	printf ("Please Enter the month of performance. Remember the range.\n");
	scanf ("%d", &change_month);
	utaSpeaker[index4].pmonth=checkMonth(change_month);//data updated

	printf ("Please Enter the year of performance. Remember the range.\n");
	scanf ("%d", &change_year);
	utaSpeaker[index4].pyear=checkYear(change_year);//data updated

	printf ("\nUpdate successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
					

}

// this function changes the series code
void change_series_code(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char change_series_code='a';
	printf ("You chose to change the series code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the series code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_series_code);
	scanf ("%c", &change_series_code);
	utaSpeaker[index4].seriesCode=checkSeriesCode(change_series_code);//data updated

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
			
}

// this function changes the home state of the speaker
void change_two_state_char(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int change_state;
	char garbage;
	printf ("Beware!!! You are updating the whole array. Please enter a new two character state.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &utaSpeaker[index4].state); //data updated

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
			
}

// this function changes the price of the ticket
void change_one_of_the_tickets(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int change_ticket_choice, change_earlybird_dollar, change_earlybird_cents, change_regular_dollar, change_regular_cents;
	printf ("Beware!!! You are updating the whole array. Please chose an option. Enter 1 to update earlybird price and enter 2 to update regular price.\n");
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
			while(change_earlybird_dollar<0 || change_earlybird_cents<0 || change_earlybird_cents>99) //error checking earlybird price range
			{
				printf ("Invalid price of earlybird. Try again.\n");
				scanf ("%d.%d", &change_earlybird_dollar, &change_earlybird_cents);
			}
			utaSpeaker[index4].ebird_dollar=change_earlybird_dollar; //data updated
			utaSpeaker[index4].ebird_cents=change_earlybird_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	break;

	case 2: //this case changes the price of regular tickets
			printf ("You chose to change regular price.\n");
			printf ("Enter a new regular price.\n");
			scanf ("%d.%d", &change_regular_dollar, &change_regular_cents);
			while(change_regular_dollar<0 || change_regular_cents<0 || change_regular_cents>99)//error checking for the price of regular ticket range
			{
				printf ("Invalid price of earlybird. Try again.\n");
				scanf ("%d.%d", &change_regular_dollar, &change_regular_cents);
			}
			utaSpeaker[index4].reg_dollar=change_regular_dollar; //data updated
			utaSpeaker[index4].reg_cents=change_regular_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
		break;

	default: printf ("Invalid Option Selected.\n");break;

	}

}

// this function changes the performance of the time
void change_performance_time(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int change_hour_time, change_minute_time;
	printf ("You chose to change time array. Beware, updating here changes everything elsewhere. Remember the range.\n");
	printf ("Please enter the new timing. Remember the format!!!\n");
	scanf ("%d.%d", &change_hour_time, &change_minute_time); 
	while(change_hour_time<0 || change_hour_time>23 || change_minute_time<0 || change_minute_time>59)//error checking for time
	{
		printf ("Invalid Time Enter. Please recall the time format. ie. military format HH.MM.\n");
		scanf ("%d.%d", &change_hour_time, &change_minute_time);
	}
	utaSpeaker[index4].phour=change_hour_time; //data updated
	utaSpeaker[index4].pminute=change_minute_time;//data updated

	//new updated array is printed
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	
}

// this function changes the birth date of the speaker
void change_birth_date(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the birth.\n");

	printf ("Beware that you are going to change the data for Speaker %d.\n", index4+1);

	printf ("Please Enter the day of birth. Remember the range.\n");
	scanf ("%d", &change_date);	
	utaSpeaker[index4].bday=checkDay(change_date); //data updated

	printf ("Please Enter the month of birth. Remember the range.\n");
	scanf ("%d", &change_month);
	utaSpeaker[index4].bmonth=checkMonth(change_month); //data updated

	printf ("Please Enter the year of birth. Remember the range.\n");
	scanf ("%d", &change_year);
	while(change_year>utaSpeaker[index4].pyear-10) // error checking the year
	{
		printf ("Invalid year. Please look at the instructions and try again. Please Enter again.\n");
		scanf ("%d", &change_year);
	}
	utaSpeaker[index4].byear=change_year; //data updated

	printf ("\nUpdate successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
			
}

// this function changes the expertise code of the speaker
void change_expertise_code(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char change_expertise_code='a';
	printf ("You chose to change the expertise code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the expertise code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_expertise_code);
	scanf ("%c", &change_expertise_code);
	utaSpeaker[index4].expertiseCode=checkExpertiseCode(change_expertise_code); //data updated

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	
}

// this function changes the first name of the speaker
void change_firstName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char garbage='a';
	char change_firstname[MAXNUM]={};
	printf ("You chose to change the first name of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &change_firstname); 
	
	strcpy(utaSpeaker[index4].firstName,change_firstname); //data updated
	utaSpeaker[index4].firstName[MAXNUM-1]='\0';

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	
}

// this function changes the last name of the speaker
void change_lastName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char garbage='a';
	char change_lastname[MAXNUM]={};
	printf ("You chose to change the last name of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &change_lastname); 
	
	strcpy(utaSpeaker[index4].lastName, change_lastname); //data updated
	utaSpeaker[index4].lastName[MAXNUM-1]='\0';

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	
}


// this function changes the title of the speech or the performance of the speaker
void change_titleName(int index4, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char garbage='a';
	char change_name[MAX]={};
	printf ("You chose to change the title of the speech or performance of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	fgets(change_name, MAX, stdin);
	strcpy(utaSpeaker[index4].titleName, change_name); //data updated
	utaSpeaker[index4].titleName[MAX-1]='\0';

	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index4+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[index4].speakerCode, utaSpeaker[index4].pday, utaSpeaker[index4].pmonth, utaSpeaker[index4].pyear, utaSpeaker[index4].phour, utaSpeaker[index4].pminute, utaSpeaker[index4].seriesCode, utaSpeaker[index4].ebird_dollar, utaSpeaker[index4].ebird_cents, utaSpeaker[index4].reg_dollar, utaSpeaker[index4].reg_cents, utaSpeaker[index4].state, utaSpeaker[index4].bday, utaSpeaker[index4].bmonth, utaSpeaker[index4].byear, utaSpeaker[index4].expertiseCode, utaSpeaker[index4].firstName, utaSpeaker[index4].lastName, utaSpeaker[index4].titleName );
	
}



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

void show_expertise_format()
{
	printf ("Here is the format. A - Aerospace Engineering, B - Bioengineering, C - Civil Engineering, P - Computer Science and Engineering, E - Electrical Engineering, I - Industrial Engineering, M - Mechanical Engineering, S - Materials Science and Engineering, O - Other Engineering, Z - Science, L - Liberal Arts, D - Education, X - Business, N - Nursing, R - Architecture, W - Social Work, U - Urban and Public Affairs, G - General\n");
		printf ("PLEASE ENTER THE CORRESPONDING ALPHABET.\n");
}

// this function search the speakers by last name
void search_speaker_by_lastname(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	char garbage, search_lastname[MAXNUM];
	int count, value, checkpoint=0;
	printf ("You entered to search the speaker by their last name.\n");
	printf ("Enter the last name you wish to search.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &search_lastname);
	for (count=0;count<num_of_people;count++)
	{
			
			value = strcmp(search_lastname, utaSpeaker[count].lastName);
			if (value==0)
			{
				printf ("Found Match\n");
				printf ("The set of data from the found match is:\n");
				printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %s %d %d %d %c %s %s %s \n",utaSpeaker[count].speakerCode, utaSpeaker[count].pday, utaSpeaker[count].pmonth, utaSpeaker[count].pyear, utaSpeaker[count].phour, utaSpeaker[count].pminute, utaSpeaker[count].seriesCode, utaSpeaker[count].ebird_dollar, utaSpeaker[count].ebird_cents, utaSpeaker[count].reg_dollar, utaSpeaker[count].reg_cents, utaSpeaker[count].state, utaSpeaker[count].bday, utaSpeaker[count].bmonth, utaSpeaker[count].byear, utaSpeaker[count].expertiseCode, utaSpeaker[count].firstName, utaSpeaker[count].lastName, utaSpeaker[count].titleName );
				checkpoint=1;
			}
	}
	
	if(checkpoint==0) // if no match found
		printf ("No matches found. Sorry!!! :(\n");

}

//this function Calculates length of time from current date to the date of the speech/performance
void calculate_length_of_time(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int length_speaker, count, index, checkpoint=0, checkpoint1=0, cday, cmonth, cyear, check_day_value, check_month_value, check_year_value, length_day=0, length_month=0, length_year=0;
	printf ("You entered to calculate the length of the time from current date to the date of the speech.\n");
	while (checkpoint!=1)
	{
		printf ("Enter the speaker code to know which speaker's length of time you wish to calculate.\n");
		scanf ("%d", &length_speaker);
		length_speaker = checkSpeakerCode(length_speaker);
		for(count=0;count<num_of_people;count++)
		{
			if(length_speaker==utaSpeaker[count].speakerCode)
			{
				index=count;
				checkpoint=1;
			}
		}
	if (checkpoint==0)
		printf ("No speaker found. Sorry. Try again.\n");
	}
	printf ("Enter the current date in format DD MM YYYY.\n");
	scanf ("%d %d %d", &cday, &cmonth, &cyear);

	if ((utaSpeaker[index].pyear-cyear)<0)
		printf ("The event is already past. Sorry.\n");
	else if (utaSpeaker[index].pyear==cyear)
	{
		if((utaSpeaker[index].pmonth-cmonth)<0)
			printf ("The event is already past. Sorry.\n");
		else if (utaSpeaker[index].pmonth==cmonth)
		{
			if ((utaSpeaker[index].pday-cday)<0)
				printf ("The event is already past. Sorry.\n");
			else if(utaSpeaker[index].pday==cday)
				printf ("The event is today. Hurry up!!!\n");
			else
			{
				length_day=utaSpeaker[index].pday-cday;
				length_month=0;
				length_year=0;
				checkpoint1=1;
			}
		}
		else
		{
			checkpoint1=1;
			length_year=0;
			check_day_value = utaSpeaker[index].pday - cday;
			if (check_day_value < 0)
			{
			length_day=utaSpeaker[index].pday - cday + 30;
			cmonth=cmonth+1;
			}
			else
				length_day=utaSpeaker[index].pday - cday;

			length_month=utaSpeaker[index].pmonth - cmonth;
			
		}
	}
	else
	{
		checkpoint1=1;
		check_day_value = utaSpeaker[index].pday - cday;
		if (check_day_value < 0)
		{
			length_day=utaSpeaker[index].pday - cday + 30;
			cmonth=cmonth+1;
		}
		else
			length_day=utaSpeaker[index].pday - cday;

		check_month_value = utaSpeaker[index].pmonth - cmonth;
		if (check_month_value < 0)
		{
			length_month=utaSpeaker[index].pmonth - cmonth+12;
			cyear=cyear+1;
		}
		else
			length_month=utaSpeaker[index].pmonth - cmonth;

		length_year=utaSpeaker[index].pyear - cyear;

	}

	if(checkpoint1==1)
		printf ("The length of from current date to the date of the speech/performance is %d days, %d months, %d years.\n", length_day, length_month, length_year); 
}

// this function sorts the data by last name
void bubblesort_lastName(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int i, j, result;
	
		for (i=0; i<num_of_people; i++)
		{
	
		for(j=0; j<num_of_people-1;j++)
		{
			result=strcmp(utaSpeaker[j].lastName, utaSpeaker[j+1].lastName);
			if(result>0)
			{
				swap(j, num_of_people, utaSpeaker);
			}
		}
		}

}





// this function sorts the array using bubble sort technique
void bubblesort(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int i, j;
	
		for (i=0; i<num_of_people; i++)
		{
			for(j=0; j<num_of_people-1;j++)
			{
			
				if(utaSpeaker[j].speakerCode>utaSpeaker[j+1].speakerCode)
				{
					swap(j, num_of_people, utaSpeaker);
				}
			}
		}

	
}

void swap (int j, int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	struct speaker temp;
	temp = utaSpeaker[j];
	utaSpeaker[j]=utaSpeaker[j+1];
	utaSpeaker[j+1]=temp;
	
}

// this function sorts array using bubble sort technique for performance date
void bubblesort_performance(int num_of_people, struct speaker utaSpeaker[EVENTMAX])
{
	int i, j;
	
		for (i=0; i<num_of_people; i++)
		{
		for(j=0; j<num_of_people-1;j++)
		{
			if(utaSpeaker[j].pyear>utaSpeaker[j+1].pyear)
			{
				swap(j, num_of_people, utaSpeaker);
			}
			else if (utaSpeaker[j].pyear==utaSpeaker[j+1].pyear)
			{
				if (utaSpeaker[j].pmonth>utaSpeaker[j+1].pmonth)
					swap(j, num_of_people, utaSpeaker);
				else if (utaSpeaker[j].pmonth==utaSpeaker[j+1].pmonth)
				{
					if (utaSpeaker[j].pday>utaSpeaker[j+1].pday)
						swap(j, num_of_people, utaSpeaker);
				}

		}
		}
	}

}

