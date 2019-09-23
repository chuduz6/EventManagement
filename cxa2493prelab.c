/* Chudamani Aryal
PreLab Assignment
Date Given: Aug 2010
Date Due: Sept 13 2010
Professor: Dr T
Class: CSE 1320 Section: 001 TH 11-12:20 */

// *********Description of the program**************
/* This program lets the user enter certain set of data with some constraints. 
After the data are entered, this program stores those data and later on acts as a database 
and provides the users to play with some of its menu choices. 
You will know more about the menu choice once you get into the program. */

//*********  pre-processors   *************
#include <stdio.h>
#define EVENTMAX 20
#define EVENTMIN 10

// **************** declaration of functions  *******************
void welcome_msg();
int checknumber(int a);
int check_input_choice(int b);
void input_Individual (int speaker_code1[], int day_of_speech1[], int month1[], int year1[], int hour_time1[], int minute_time1[], int earlybird_dollar1[], int earlybird_cents1[], int regular_dollar1[], int regular_cents1[],int num_of_people1, char series_code1[], char home_state11[], char home_state21[]);
void input_oneLine(int speaker_code2[], int day_of_speech2[], int month2[], int year2[], int hour_time2[], int minute_time2[], int earlybird_dollar2[], int earlybird_cents2[], int regular_dollar2[], int regular_cents2[],int num_of_people2, char series_code2[], char home_state12[], char home_state22[]);
void printArray(int number_of_people_entered, int speaker_code15[], int day_of_speech15[], int month15[], int year15[], int hour_time15[], int minute_time15[], char series_code15[], int earlybird_dollar15[], int earlybird_cents15[], int regular_dollar15[], int regular_cents15[], char home_state115[], char home_state215[]);
void show_menu();
int check_menu_choice(int c);
void main_menu_operation(int e, int d, int speaker_code5[], int day_of_speech5[], int month5[], int year5[], int hour_time5[], int minute_time5[], char series_code5[], int earlybird_dollar5[], int earlybird_cents5[], int regular_dollar5[], int regular_cents5[], char home_state15[], char home_state25[]);
void search_by_speakercode(int f, int speaker_code3[], int day_of_speech3[], int month3[], int year3[], int hour_time3[], int minute_time3[], char series_code3[], int earlybird_dollar3[], int earlybird_cents3[], int regular_dollar3[], int regular_cents3[], char home_state13[], char home_state23[]);
void search_by_dateofspeech(int g, int speaker_code4[], int day_of_speech4[], int month4[], int year4[], int hour_time4[], int minute_time4[], char series_code4[], int earlybird_dollar4[], int earlybird_cents4[], int regular_dollar4[], int regular_cents4[], char home_state14[], char home_state24[]);
void calculate_cost(int h, int speaker_code6[], int earlybird_dollar6[], int earlybird_cents6[], int regular_dollar6[], int regular_cents6[]);
void find_all_same_series(int i, int speaker_code7[], int day_of_speech7[], int month7[], int year7[], int hour_time7[], int minute_time7[], char series_code7[], int earlybird_dollar7[], int earlybird_cents7[], int regular_dollar7[], int regular_cents7[], char home_state17[], char home_state27[]);
void find_all_certain_state(int j, int speaker_code8[], int day_of_speech8[], int month8[], int year8[], int hour_time8[], int minute_time8[], char series_code8[], int earlybird_dollar8[], int earlybird_cents8[], int regular_dollar8[], int regular_cents8[], char home_state18[], char home_state28[]);
void update_array(int k, int speaker_code9[], int day_of_speech9[], int month9[], int year9[], int hour_time9[], int minute_time9[], char series_code9[], int earlybird_dollar9[], int earlybird_cents9[], int regular_dollar9[], int regular_cents9[], char home_state19[], char home_state29[]);
void exit_the_program();
void show_sub_menu();
void change_date_month_year(int index5, int speaker_code10[], int day_of_speech10[], int month10[], int year10[], int hour_time10[], int minute_time10[], char series_code10[], int earlybird_dollar10[], int earlybird_cents10[], int regular_dollar10[], int regular_cents10[], char home_state110[], char home_state210[]);
void change_series_code(int index6, int speaker_code11[], int day_of_speech11[], int month11[], int year11[], int hour_time11[], int minute_time11[], char series_code11[], int earlybird_dollar11[], int earlybird_cents11[], int regular_dollar11[], int regular_cents11[], char home_state111[], char home_state211[]);
void change_two_state_char(int index7, int speaker_code12[], int day_of_speech12[], int month12[], int year12[], int hour_time12[], int minute_time12[], char series_code12[], int earlybird_dollar12[], int earlybird_cents12[], int regular_dollar12[], int regular_cents12[], char home_state112[], char home_state212[]);
void change_one_of_the_tickets(int index8, int speaker_code13[], int day_of_speech13[], int month13[], int year13[], int hour_time13[], int minute_time13[], char series_code13[], int earlybird_dollar13[], int earlybird_cents13[], int regular_dollar13[], int regular_cents13[], char home_state113[], char home_state213[]);
void change_time_array(int index9, int speaker_code14[], int day_of_speech14[], int month14[], int year14[], int hour_time14[], int minute_time14[], char series_code14[], int earlybird_dollar14[], int earlybird_cents14[], int regular_dollar14[], int regular_cents14[], char home_state114[], char home_state214[]);

// ****************        main function      ******************
int main ()
{
	
	// declarations of variables
	int enter_data, enter_data1, enter_data2,num_of_people, input_choice, menu_choice_number;
	int speaker_code[EVENTMAX]={0},day_of_speech[EVENTMAX]={0},month[EVENTMAX]={0},year[EVENTMAX]={0},hour_time[EVENTMAX]={0},minute_time[EVENTMAX]={0}, earlybird_dollar[EVENTMAX]={0}, earlybird_cents[EVENTMAX]={0},regular_dollar[EVENTMAX]={0},regular_cents[EVENTMAX]={0};
	char series_code[EVENTMAX],home_state1[EVENTMAX],home_state2[EVENTMAX]; 

	
	// Program begins
	welcome_msg();
	printf ("\nHow many sets of data you want to enter. Remember minimun is 10 and maximum is 20, inclusive.\n");
	scanf ("%d", &enter_data);
	num_of_people = checknumber(enter_data); // check wheather the number entered in within the range from 10 to 20
	printf ("Now you are going to choose the way to input your data.\nEnter 1 if you want to input your data individually.\nEnter 2 if you want to input your data on one line.\n");
	scanf ("%d", &enter_data1);
	input_choice= check_input_choice(enter_data1); // Asking method of Input (Individual or One Line)
	switch(input_choice) // This switch statement calls the respective input function
	{
	case 1: input_Individual(speaker_code, day_of_speech, month, year, hour_time, minute_time, earlybird_dollar, earlybird_cents, regular_dollar, regular_cents,num_of_people, series_code, home_state1, home_state2);break;
	case 2: input_oneLine(speaker_code, day_of_speech, month, year, hour_time, minute_time, earlybird_dollar, earlybird_cents, regular_dollar, regular_cents,num_of_people, series_code, home_state1, home_state2);break;
	default: printf ("Invalid Input\n");break;
	}
	printf ("\nCongratulations!!! You have successfully entered all the required data.\n");

	// prints the whole array which was entered by the user
	printArray(num_of_people, speaker_code, day_of_speech, month, year, hour_time, minute_time, series_code, earlybird_dollar, earlybird_cents, regular_dollar, regular_cents,  home_state1, home_state2);
	printf ("Now begins the fun part.\n");
	
	// Once all the data that have been entered are shown, the program next shows the menu
	show_menu();

	// Once all the menu option are shown, the user is asked to enter the option number to work accordingly
	printf ("Now enter the menu option number.\n");
	scanf ("%d", &enter_data2);

	// menu choice is verified and main menu operation is called. Also a reminder, one of the options of main menu calls sub menu function
	menu_choice_number = check_menu_choice(enter_data2);
	main_menu_operation(num_of_people, menu_choice_number, speaker_code, day_of_speech, month, year, hour_time, minute_time, series_code, earlybird_dollar, earlybird_cents, regular_dollar, regular_cents, home_state1, home_state2);

}

// definitions of the functions 

// function to greet users
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


//this function is called when user selects the Individual method of input
void input_Individual (int speaker_code1[], int day_of_speech1[], int month1[], int year1[], int hour_time1[], int minute_time1[], int earlybird_dollar1[], int earlybird_cents1[], int regular_dollar1[], int regular_cents1[],int num_of_people1, char series_code1[], char home_state11[], char home_state21[])
{
	int count;
	printf ("You chose to enter your sets of data in Individual data method.\n");
	for(count=0; count<num_of_people1; count++) // loop to repeat asking the data over and over again
	{		
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("\nPLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		scanf ("%d", &speaker_code1[count]); 

		//error checking speaker code
		while (speaker_code1[count]<100 || speaker_code1[count]>999) 
		{
			if(speaker_code1[count] != '\n')
				printf ("\nInvalid Speaker Code. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &speaker_code1[count]);
		}
		
		printf ("\nPLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		scanf ("%d", &day_of_speech1[count]);

		//error checking day of speech
		while (day_of_speech1[count]<1 || day_of_speech1[count]>32) 
		{
			printf ("\nInvalid Day of Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &day_of_speech1[count]);
		}
		printf ("\nPLEASE ENTER THE MONTH. Remember to make that month valid i.e within the range of 1 to 12. \n");
		scanf ("%d", &month1[count]);

		//error checking month of speech
		while (month1[count]<1 || month1[count]>12) 
		{
			printf ("\nInvalid Month. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &month1[count]);
		}
		printf ("\nPLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		scanf ("%d", &year1[count]);

		//error checking year of speech
		while (year1[count]<2000 || year1[count]>2050) 
		{
			printf ("\nInvalid Year. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &year1[count]);
		}
		
		
		printf ("\nPLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		scanf ("%d.%d", &hour_time1[count], &minute_time1[count]);

		//error checking the time of speech
		while (hour_time1[count]<0 || hour_time1[count]>23 || minute_time1[count]<0 || minute_time1[count]>59) 
		{
			printf ("\nInvalid Time for Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d.%d", &hour_time1[count], &minute_time1[count]);
		}		

		printf ("\nPLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		
		scanf ("%c", &series_code1[count]);

		//error checking the series code
		while (series_code1[count] != 'M' && series_code1[count] != 'E' && series_code1[count] != 'D'&& series_code1[count] != 'C' && series_code1[count] != 'S' && series_code1[count] != 'U' && series_code1[count] != 'L' && series_code1[count] != 'O')
		{
			if(series_code1[count] !='\n' )
				printf ("\nInvalid Series Code. Please go back and look at the instructions and try again. :)");
			scanf ("%c", &series_code1[count]);
		}
		printf ("\nPLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &earlybird_dollar1[count], &earlybird_cents1[count]);

		//error checking price of early bird ticket
		while (earlybird_dollar1[count]<0 || earlybird_cents1[count]<0|| earlybird_cents1[count]>99)
		{
			printf ("\nInvalid Price of earlybird ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &earlybird_dollar1[count], &earlybird_cents1[count]);
		}
		printf ("\nPLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%d.%d", &regular_dollar1[count], &regular_cents1[count]);

		//error checking the price of regular tickets
		while (regular_dollar1[count]<0 || regular_cents1[count]<0|| regular_cents1[count]>99)
		{
			printf ("\nInvalid Price of regular ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d.%d", &regular_dollar1[count], &regular_cents1[count]);
		}
		printf ("\nPLEASE ENTER THE HOMESTATE OF THE SPEAKER. For example NY would be for New York. \n");
		scanf (" %c%c", &home_state11[count], &home_state21[count]);		
		


	}
}

void input_oneLine(int speaker_code2[], int day_of_speech2[], int month2[], int year2[], int hour_time2[], int minute_time2[], int earlybird_dollar2[], int earlybird_cents2[], int regular_dollar2[], int regular_cents2[],int num_of_people2, char series_code2[], char home_state12[], char home_state22[])
{
	int count;
	printf ("\nYou chose to enter your sets of data in One Line Format.\n");
	printf ("\nRemember the format: 100 24 9 2010 19.00 M 0.00 0.00 NY \nHere 100 is Speaker Code, \n24 is day of the speech, \n9 is the month, \n2010 is the year, \n19.00 is the military timing, \nM is the series code, \n0.00 is early bird ticket and \nsecond 0.00 is regular ticket price and \nfinally NY is the Homestate of the speaker. \n");
	
	// loop to repeat asking the data over and over again
	for(count=0; count<num_of_people2; count++) 
	{		

		// Description on how to enter data (Overall)
		printf ("\nNow you are entering the data for person %d.\n", count+1);
		printf ("\nPLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		printf ("\nPLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		printf ("\nPLEASE ENTER THE MONTH. Remember to make that month valid i.e within the range of 1 to 12. \n");
		printf ("\nPLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		printf ("\nPLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		printf ("\nPLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		printf ("\nPLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		printf ("\nPLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		printf ("\nPLEASE ENTER THE HOMESTATE OF THE SPEAKER. For example NY would be for New York. \n");
		scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c", &speaker_code2[count],&day_of_speech2[count],&month2[count],&year2[count],&hour_time2[count],&minute_time2[count],&series_code2[count],&earlybird_dollar2[count], &earlybird_cents2[count],&regular_dollar2[count], &regular_cents2[count],&home_state12[count], &home_state22[count]); 
		
		//error checking of everything as a whole
		while ((speaker_code2[count]<100 || speaker_code2[count]>999)||(day_of_speech2[count]<1 || day_of_speech2[count]>32)||(month2[count]<1 || month2[count]>12)||(year2[count]<2000 || year2[count]>2050)||(hour_time2[count]<0 || hour_time2[count]>23 || minute_time2[count]<0 || minute_time2[count]>59)||(series_code2[count] != 'M' && series_code2[count] != 'E' && series_code2[count] != 'D'&& series_code2[count] != 'C' && series_code2[count] != 'S' && series_code2[count] != 'U' && series_code2[count] != 'L' && series_code2[count] != 'O')||(earlybird_dollar2[count]<0 || earlybird_cents2[count]<0|| earlybird_cents2[count]>99)||(regular_dollar2[count]<0 || regular_cents2[count]<0|| regular_cents2[count]>99))
		{
			printf ("\nInvalid Format. Please go back and look at the instructions and try again.\n");
			scanf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c", &speaker_code2[count],&day_of_speech2[count],&month2[count],&year2[count],&hour_time2[count],&minute_time2[count],&series_code2[count],&earlybird_dollar2[count], &earlybird_cents2[count],&regular_dollar2[count], &regular_cents2[count],&home_state12[count], &home_state22[count]); 
		
		}
		
		
		


	}
}

//this function shows user the menu and its options
void show_menu()
{
	printf ("Now you are looking at the menu choices of this program.\nAnd the following are your choices:\n1. Search for speakers/performers by speaker code.\n2. Search for speakers/performers by date of speech/performance.\n3. Calculate cost for purchase of a given number of tickets of a given type.\n4. Find all the speakers in the same series.\n5. Find all the speakers that are from a certain state.\n6. Update the data in the arrays. This will take you to a submenu for doing updates.\n7. End the program.\n");
	printf ("Remember that while chosing your menu choice, you have to choose the corresponding number to the menu option. \nFor example, to calculate the ticket cost you must enter 3.\n");
}

// this function checks whether the right menu choice is entered or not
int check_menu_choice(int c)
{
	while (c<1||c>7)
	{
		printf("Invalid Menu Choice. Please Look at the instructions and try again.\n");
		show_menu();
		scanf ("%d", &c);
	}
	return c;
}

// this function is the main menu operation function. It is called from main function. this function calls several other functions.
void main_menu_operation(int e, int d, int speaker_code5[], int day_of_speech5[], int month5[], int year5[], int hour_time5[], int minute_time5[], char series_code5[], int earlybird_dollar5[], int earlybird_cents5[], int regular_dollar5[], int regular_cents5[], char home_state15[], char home_state25[])
{
	while(d!=7) // this is to make sure that the user stays in main menu unless the user decide to exit the program
	{
			switch(d)
		{
		// each case here represents the menu options and once that case is entered, this switch statement calls that corresponding function
		case 1: search_by_speakercode(e, speaker_code5, day_of_speech5, month5, year5, hour_time5, minute_time5, series_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5, home_state15, home_state25);break;
		case 2: search_by_dateofspeech(e, speaker_code5, day_of_speech5, month5, year5, hour_time5, minute_time5, series_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5, home_state15, home_state25);break;
		case 3: calculate_cost(e, speaker_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5);break;
		case 4: find_all_same_series(e, speaker_code5, day_of_speech5, month5, year5, hour_time5, minute_time5, series_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5, home_state15, home_state25);break;
		case 5: find_all_certain_state(e, speaker_code5, day_of_speech5, month5, year5, hour_time5, minute_time5, series_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5, home_state15, home_state25);break;
		case 6: update_array(e, speaker_code5, day_of_speech5, month5, year5, hour_time5, minute_time5, series_code5, earlybird_dollar5, earlybird_cents5, regular_dollar5, regular_cents5, home_state15, home_state25);break;
		default: printf ("Invalid Entry. Please check your choice number.\n");break;
		}
		printf ("Choose Another menu option, which is from the range of 1 to 7.\n");
		scanf ("%d", &d);
		while(d<1||d>7)  //error checking the menu option
		{
			printf ("Invalid entry. Please enter again.\n");
			scanf ("%d", &d);
		}
		

	}
	if (d==7)
			exit_the_program();
	 
}

// this function is called when the user enters one of the menu option to search the speaker by speaker code
void search_by_speakercode(int f, int speaker_code3[], int day_of_speech3[], int month3[], int year3[], int hour_time3[], int minute_time3[], char series_code3[], int earlybird_dollar3[], int earlybird_cents3[], int regular_dollar3[], int regular_cents3[], char home_state13[], char home_state23[])
{
	int enter_data3, count2, count3=1, checkpoint=0;
	printf ("\nYou chose menu option 1. This means you want to search a speaker by speaker code.\n");
	printf ("\nNow Enter the speaker code. Remember the range given before.\n");
	scanf ("%d", &enter_data3);
	while(enter_data3<100||enter_data3>999) //error checking speaker code
	{
		printf ("\nInvalid Entry. Please try again.\n");
		scanf ("%d", &enter_data3);
	}
	for(count2=0;count2<f;count2++)
	{
		if(enter_data3==speaker_code3[count2]) // comparing the speaker code entered before with the speaker code entered now
		{
			printf ("Found Match %d \n", count3++);
			printf ("The set of data from the matched speaker code on this format: (100 24 9 2010 19.00 M 0.00 0.00 NY)\n");

			//if match found result printed
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code3[count2], day_of_speech3[count2], month3[count2], year3[count2], hour_time3[count2], minute_time3[count2], series_code3[count2], earlybird_dollar3[count2], earlybird_cents3[count2], regular_dollar3[count2], regular_cents3[count2], home_state13[count2], home_state23[count2]);
			checkpoint=1;
		}
	}
	if(checkpoint==0)
	{
		// if match no found
		printf ("No matches found. Sorry!!! :(\n");
	}


}

// this function is called when the user enters one of the menu option to search the speaker by date of speech
void search_by_dateofspeech(int g, int speaker_code4[], int day_of_speech4[], int month4[], int year4[], int hour_time4[], int minute_time4[], char series_code4[], int earlybird_dollar4[], int earlybird_cents4[], int regular_dollar4[], int regular_cents4[], char home_state14[], char home_state24[])
{
	int enter_data4, enter_data5, enter_data6, count4, count5=1, checkpoint1=0;
	printf ("\nYou chose menu option 2. This means you want to search a speaker by date of speech. \n");
	printf ("\nNow Enter the date of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data4);
	while(enter_data4<1||enter_data4>32) //error checking date of speech
	{
		printf ("\nInvalid Entry. Please try again.\n");
		scanf ("%d", &enter_data4);
	}
	printf ("\nNow Enter the month of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data5);
	while(enter_data5<1||enter_data5>12) //error checking month of speech
	{
		printf ("\nInvalid Entry. Please try again.\n");
		scanf ("%d", &enter_data5);
	}
	printf ("\nNow Enter the year of speech. Remember the range given before.\n");
	scanf ("%d", &enter_data6);
	while(enter_data6<2000||enter_data6>2050) //error checking year of speech 
	{
		printf ("\nInvalid Entry. Please try again.\n");
		scanf ("%d", &enter_data6);
	}

	for(count4=0;count4<g;count4++)
	{
		if(enter_data4==day_of_speech4[count4]) //comparing the date of speech entered before with the date of speech entered now
			if(enter_data5==month4[count4])
				if(enter_data6==year4[count4])
				{
					// if match found, result printed
					printf ("Found Match %d \n", count5++);
					printf ("The set of data from the found match of date of speech on this format: (100 24 9 2010 19.00 M 0.00 0.00 NY)\n");
					printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code4[count4], day_of_speech4[count4], month4[count4], year4[count4], hour_time4[count4], minute_time4[count4], series_code4[count4], earlybird_dollar4[count4], earlybird_cents4[count4], regular_dollar4[count4], regular_cents4[count4], home_state14[count4], home_state24[count4]);
					checkpoint1=1;
				}
	}
	if(checkpoint1==0)
	{
		// if match not found
		printf ("No matches found. Sorry!!! :(\n");
	}


}

// this function is called when the user enters one of the menu option to calculate the ticket cost

void calculate_cost(int h, int speaker_code6[], int earlybird_dollar6[], int earlybird_cents6[], int regular_dollar6[], int regular_cents6[])
{
	int calculate_choice, checkpoint2, speaker_code_calculate, speaker_code_calculate1, speaker_code_calculate2, count7, index, number_of_earlybird, number_of_regular, number_of_earlybird1,number_of_regular1, dollar_price_of_earlybird, dollar_price_of_earlybird1, cents_price_of_earlybird, cents_price_of_earlybird1, dollar_price_of_regular, dollar_price_of_regular1, cents_price_of_regular, cents_price_of_regular1, dollar_price_of_total, cents_price_of_total;
	
	//option given to chose how to calculate. 
	printf ("You chose menu option 3, which is to calculate cost for purchase of a given number of tickets of a given type.\n");
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
			printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
			scanf ("%d", &speaker_code_calculate);
			for(count7=0;count7<h;count7++)
			{
				if(speaker_code_calculate==speaker_code6[count7])
				{
					index=count7;
					checkpoint2=1;
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
				dollar_price_of_earlybird = (number_of_earlybird * earlybird_dollar6[index]) + (number_of_earlybird*earlybird_cents6[index])/100;
				cents_price_of_earlybird = (number_of_earlybird*earlybird_cents6[index])%100;
				dollar_price_of_regular = (number_of_regular * regular_dollar6[index]) + (number_of_regular*regular_cents6[index])/100;
				cents_price_of_regular = (number_of_regular*regular_cents6[index])%100;
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
			for(count7=0;count7<h;count7++)
			{
				if(speaker_code_calculate1==speaker_code6[count7]) //speaker code is compared to find the match
				{
					index=count7;
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
				dollar_price_of_earlybird1 = (number_of_earlybird1 * earlybird_dollar6[index]) + (number_of_earlybird1*earlybird_cents6[index])/100;
				cents_price_of_earlybird1 = (number_of_earlybird1*earlybird_cents6[index])%100;
				printf ("You entered %d for early bird tickets.\n", number_of_earlybird1);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_earlybird1, cents_price_of_earlybird1);
			}
			break;
	case 3: // this case calculates the ticket cost of regular tickets only
			checkpoint2=0;
			printf ("You enter 3 and chose to calculate only the cost of regular tickets.\n");
			printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
			scanf ("%d", &speaker_code_calculate2);
			for(count7=0;count7<h;count7++)
			{
				if(speaker_code_calculate2==speaker_code6[count7]) //speaker code compared to find a match
				{
					index=count7;
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
				scanf ("%d %d", &number_of_regular1);
				dollar_price_of_regular1 = (number_of_regular1 * regular_dollar6[index]) + (number_of_regular1*regular_cents6[index])/100;
				cents_price_of_regular1 = (number_of_regular1*regular_cents6[index])%100;
				printf ("You entered %d for regular tickets.\n", number_of_regular1);
				printf ("Hence your total price is %d.%d \n", dollar_price_of_regular1, cents_price_of_regular1);
			}
			break;
	default: printf ("Invalid Input. Sorry\n");break;

			
			
	}
}

// this function is called when the user enters one of the menu option to find all speakers with same series
void find_all_same_series(int i, int speaker_code7[], int day_of_speech7[], int month7[], int year7[], int hour_time7[], int minute_time7[], char series_code7[], int earlybird_dollar7[], int earlybird_cents7[], int regular_dollar7[], int regular_cents7[], char home_state17[], char home_state27[])
{
	char series_code_to_find_all;
	int checkpoint3=0, count8, count9=1, index2;
	printf ("You entered menu option 4, which is to find all the speaker with same series.\n");
	printf ("Now enter the series code of the speaker you want to find. Please Enter the series code.\n");
	scanf ("%c", &series_code_to_find_all);
	
	//error checking for series code 
	while (series_code_to_find_all != 'M' && series_code_to_find_all != 'E' && series_code_to_find_all != 'D'&& series_code_to_find_all != 'C' && series_code_to_find_all != 'S' && series_code_to_find_all != 'U' && series_code_to_find_all != 'L' && series_code_to_find_all != 'O')
	{
		if(series_code_to_find_all !='\n' )
			printf ("\nInvalid Series Code. Please go back and look at the instructions and try again. :)");
		scanf ("%c", &series_code_to_find_all);
	}
	for (count8=0;count8<i;count8++)
	{
		if(series_code_to_find_all==series_code7[count8]) //series code compared with the one entered before
		{

			//when match found, results displayed
			index2=count8;
			printf ("Found Match %d \n", count9++);
			
			printf ("The set of data from the found match of same series on this format: (100 24 9 2010 19.00 M 0.00 0.00 NY)\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code7[index2], day_of_speech7[index2], month7[index2], year7[index2], hour_time7[index2], minute_time7[index2], series_code7[index2], earlybird_dollar7[index2], earlybird_cents7[index2], regular_dollar7[index2], regular_cents7[index2], home_state17[index2], home_state27[index2]);
			checkpoint3=1;
		}
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");


}


// this function is called when the user enters one of the menu option to search speakers with certain state
void find_all_certain_state(int j, int speaker_code8[], int day_of_speech8[], int month8[], int year8[], int hour_time8[], int minute_time8[], char series_code8[], int earlybird_dollar8[], int earlybird_cents8[], int regular_dollar8[], int regular_cents8[], char home_state18[], char home_state28[])
{
	char certain_state_to_find_all, certain_state_to_find_all1;
	int checkpoint4=0, count10, count11=0, index3;
	printf ("You entered menu option 5, which is to find all the speaker with certain state.\n");
	printf ("Now enter the homestate of the speaker you want to find. Remember both character should be together and C Programming is case-sensitive. \nPlease Enter the two homestate character together.\n");
	scanf ("%c%c", &certain_state_to_find_all, &certain_state_to_find_all1);

	
	for (count10=0;count10<j;count10++)
	{
		// howe state with two characters is compared with the previously entered one
		if((certain_state_to_find_all==home_state18[count10]) && (certain_state_to_find_all1==home_state18[count10]))
		{
			// if match found, results printed
			index3=count10;
			printf ("Found Match %d \n", count11++);
			printf ("The set of data from the found match of certain state on this format: (100 24 9 2010 19.00 M 0.00 0.00 NY)\n");
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code8[index3], day_of_speech8[index3], month8[index3], year8[index3], hour_time8[index3], minute_time8[index3], series_code8[index3], earlybird_dollar8[index3], earlybird_cents8[index3], regular_dollar8[index3], regular_cents8[index3], home_state18[index3], home_state28[index3]);
			checkpoint4=1;
		}
	}
	if(checkpoint4==0) // if no match found
		printf ("No matches found. Sorry!!! :(\n");

}


// this function is called when the user enters one of the menu option to update array
void update_array(int k, int speaker_code9[], int day_of_speech9[], int month9[], int year9[], int hour_time9[], int minute_time9[], char series_code9[], int earlybird_dollar9[], int earlybird_cents9[], int regular_dollar9[], int regular_cents9[], char home_state19[], char home_state29[])
{
	int sub_menu_speaker_code, sub_menu_choice_number, count12, index4;
	printf ("You enter number 6, which is to update array. Now the program will take you to another sub-menu with bunch of options.\n");
	show_sub_menu();
	//the user is asked to enter which array to update
	printf ("Now enter the integer number of speaker code which you want to update. Please Enter the Speaker code. Remember the range.\n");
	scanf ("%d", &sub_menu_speaker_code);
	while (sub_menu_speaker_code<100 || sub_menu_speaker_code>999) //error checking for speaker code
		{
			if(sub_menu_speaker_code !='\n' )
			printf ("Invalid Speaker Code. Please go back and look at the instructions and try again.\n");
			scanf ("%d", &sub_menu_speaker_code);
		}
	for(count12=0;count12<k;count12++)
	{
		if(sub_menu_speaker_code==speaker_code9[count12]) // comparing the speaker code entered now with the speaker code entered before
		{
			// if equal, then that speaker's data to be updated
			index4=count12;
			printf ("So you will be updating the information of Speaker %d.\n", index4 + 1);
		}
	}
	printf ("Enter the sub-menu choice number. Remember the range. \n");
	scanf ("%d", &sub_menu_choice_number);
	while(sub_menu_choice_number<1 || sub_menu_choice_number>6) //error checking the sub menu option
	{
		printf ("Invalid Entry. Please look at the instructions.\n");
		show_sub_menu();
		scanf ("%d", &sub_menu_choice_number);

	}
	while(sub_menu_choice_number!=6) // this returns to main menu when the user enters 6 which is an option to return to the main menu
	{
		switch(sub_menu_choice_number)
		{
			// according to the number enter, switch statement calls the corresponding function.
			case 1: change_date_month_year(index4,  speaker_code9, day_of_speech9, month9, year9, hour_time9, minute_time9, series_code9, earlybird_dollar9, earlybird_cents9, regular_dollar9, regular_cents9, home_state19, home_state29);break;
			case 2: change_series_code(index4,  speaker_code9, day_of_speech9, month9, year9, hour_time9, minute_time9, series_code9, earlybird_dollar9, earlybird_cents9, regular_dollar9, regular_cents9, home_state19, home_state29);break;
			case 3: change_two_state_char(index4,  speaker_code9, day_of_speech9, month9, year9, hour_time9, minute_time9, series_code9, earlybird_dollar9, earlybird_cents9, regular_dollar9, regular_cents9, home_state19, home_state29);break;
			case 4: change_one_of_the_tickets(index4,  speaker_code9, day_of_speech9, month9, year9, hour_time9, minute_time9, series_code9, earlybird_dollar9, earlybird_cents9, regular_dollar9, regular_cents9, home_state19, home_state29);break;
			case 5: change_time_array(index4,  speaker_code9, day_of_speech9, month9, year9, hour_time9, minute_time9, series_code9, earlybird_dollar9, earlybird_cents9, regular_dollar9, regular_cents9, home_state19, home_state29);break;
		}
		printf ("Enter the sub-menu choice number. Remember the range. \n"); // this is to compare the sub menu choice number with the top while loop
		scanf ("%d", &sub_menu_choice_number);
		while(sub_menu_choice_number<1 || sub_menu_choice_number>6)
		{
			printf ("Invalid Entry. Please look at the instructions.\n");
			show_sub_menu();
			scanf ("%d", &sub_menu_choice_number);

		}
		
	}
	printf ("You chose to return to the main menu.\n");


}

// this function is called when the user enter the exit option
void exit_the_program()
{
	// gracefully terminating the program
	printf ("You chose to exit the program. The program exits now. \nThank you for giving your time and using this database. Bye Bye Now!! :)\n");
}

// this functions shows the sub menu and its option to the user
void show_sub_menu()
{
	printf ("Now you are on sub-menu. The following are the options on sub_menu: \n1. Change speech month, day, or year. \n2. Change the series array. \n3. Change the two state char arrays. \n4. Change one of the ticket arrays. \n5. Change the time array. \n6. Return to main menu.\nNow choose the corresponding option to play with the options.\nFor example, enter 2 to change the series array.\n");
}

// this function is called when the user decide to change date, month and year
void change_date_month_year(int index5, int speaker_code10[], int day_of_speech10[], int month10[], int year10[], int hour_time10[], int minute_time10[], char series_code10[], int earlybird_dollar10[], int earlybird_cents10[], int regular_dollar10[], int regular_cents10[], char home_state110[], char home_state210[])
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year.\n");
	printf ("Beware that you are going to change the data for Speaker %d.\n", index5+1);
	printf ("Please Enter the date of performance. Remember the range.\n");
	scanf ("%d", &change_date);
	while(change_date<1 || change_date>32) // error checking the date
	{
		printf ("Invalid Date. Please look at the instructions and try again. Please Enter again.\n");
		scanf ("%d", &change_date);
	}
	day_of_speech10[index5]=change_date; //data updated
	printf ("Please Enter the month of performance. Remember the range.\n");
	scanf ("%d", &change_month);
	while(change_month<1 || change_month>12) // error checking the month
	{
		printf ("Invalid Month. Please look at the instructions and try again. Please Enter again.\n");
		scanf ("%d", &change_month);
	}
	month10[index5]=change_month; //data updated
	printf ("Please Enter the year of performance. Remember the range.\n");
	scanf ("%d", &change_year);
	while(change_year<2000 || change_year>2050) // error checking the year
	{
		printf ("Invalid Month. Please look at the instructions and try again. Please Enter again.\n");
		scanf ("%d", &change_year);
	}
	year10[index5]=change_year; //data updated
	printf ("\nUpdate successful. The new set of data of the speaker %d is as follows:\n", index5+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code10[index5], day_of_speech10[index5], month10[index5], year10[index5], hour_time10[index5], minute_time10[index5], series_code10[index5], earlybird_dollar10[index5], earlybird_cents10[index5], regular_dollar10[index5], regular_cents10[index5], home_state110[index5], home_state210[index5]);


}


// this is function is called when the user decides to change series code
void change_series_code(int index6, int speaker_code11[], int day_of_speech11[], int month11[], int year11[], int hour_time11[], int minute_time11[], char series_code11[], int earlybird_dollar11[], int earlybird_cents11[], int regular_dollar11[], int regular_cents11[], char home_state111[], char home_state211[])
{
	int change_series_code;
	printf ("You chose to change the series code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the series code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_series_code);

	// error checking the series code
	while (change_series_code != 'M' && change_series_code != 'E' && change_series_code != 'D'&& change_series_code != 'C' && change_series_code != 'S' && change_series_code != 'U' && change_series_code != 'L' && change_series_code != 'O')
	{
		if(change_series_code !='\n' )
			printf ("\nInvalid Series Code. Please go back and look at the instructions and try again. :)");
		scanf ("%c", &change_series_code);
	}
	series_code11[index6]=change_series_code; //data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index6+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code11[index6], day_of_speech11[index6], month11[index6], year11[index6], hour_time11[index6], minute_time11[index6], series_code11[index6], earlybird_dollar11[index6], earlybird_cents11[index6], regular_dollar11[index6], regular_cents11[index6], home_state111[index6], home_state211[index6]);


}


//this function is called when the user decides to change state
void change_two_state_char(int index7, int speaker_code12[], int day_of_speech12[], int month12[], int year12[], int hour_time12[], int minute_time12[], char series_code12[], int earlybird_dollar12[], int earlybird_cents12[], int regular_dollar12[], int regular_cents12[], char home_state112[], char home_state212[])
{
	int change_state1, change_state2;
	printf ("Beware!!! You are updating the whole array. Please enter a new two character state.\n");
	scanf (" %c%c", &change_state1, &change_state2);
	home_state112[index7]=change_state1; //data updated
	home_state212[index7]=change_state2;//data updated
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index7+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code12[index7], day_of_speech12[index7], month12[index7], year12[index7], hour_time12[index7], minute_time12[index7], series_code12[index7], earlybird_dollar12[index7], earlybird_cents12[index7], regular_dollar12[index7], regular_cents12[index7], home_state112[index7], home_state212[index7]);


}

//this function is called when the user decides to change the price of the ticket
void change_one_of_the_tickets(int index8, int speaker_code13[], int day_of_speech13[], int month13[], int year13[], int hour_time13[], int minute_time13[], char series_code13[], int earlybird_dollar13[], int earlybird_cents13[], int regular_dollar13[], int regular_cents13[], char home_state113[], char home_state213[])
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
			earlybird_dollar13[index8]=change_earlybird_dollar; //data updated
			earlybird_cents13[index8]=change_earlybird_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index8+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code13[index8], day_of_speech13[index8], month13[index8], year13[index8], hour_time13[index8], minute_time13[index8], series_code13[index8], earlybird_dollar13[index8], earlybird_cents13[index8], regular_dollar13[index8], regular_cents13[index8], home_state113[index8], home_state213[index8]);break;
	case 2: //this case changes the price of regular tickets
			printf ("You chose to change regular price.\n");
			printf ("Enter a new regular price.\n");
			scanf ("%d.%d", &change_regular_dollar, &change_regular_cents);
			while(change_regular_dollar<0 || change_regular_cents<0 || change_regular_cents>99)//error checking for the price of regular ticket range
			{
				printf ("Invalid price of earlybird. Try again.\n");
				scanf ("%d.%d", &change_regular_dollar, &change_regular_cents);
			}
			regular_dollar13[index8]=change_regular_dollar; //data updated
			regular_cents13[index8]=change_regular_cents;//data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index8+1);
			printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code13[index8], day_of_speech13[index8], month13[index8], year13[index8], hour_time13[index8], minute_time13[index8], series_code13[index8], earlybird_dollar13[index8], earlybird_cents13[index8], regular_dollar13[index8], regular_cents13[index8], home_state113[index8], home_state213[index8]);break;
			break;
	default: printf ("Invalid Option Selected.\n");break;

	}

}


//this functions is called when the user decides to change time array
void change_time_array(int index9, int speaker_code14[], int day_of_speech14[], int month14[], int year14[], int hour_time14[], int minute_time14[], char series_code14[], int earlybird_dollar14[], int earlybird_cents14[], int regular_dollar14[], int regular_cents14[], char home_state114[], char home_state214[])
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
	hour_time14[index9]=change_hour_time; //data updated
	minute_time14[index9]=change_minute_time;//data updated

	//new updated array is printed
	printf ("Update Successful. The new set of data of the speaker %d is as follows:\n", index9+1);
	printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code14[index9], day_of_speech14[index9], month14[index9], year14[index9], hour_time14[index9], minute_time14[index9], series_code14[index9], earlybird_dollar14[index9], earlybird_cents14[index9], regular_dollar14[index9], regular_cents14[index9], home_state114[index9], home_state214[index9]);
			
}

// this function simply prints the data that are in the array
void printArray(int number_of_people_entered, int speaker_code15[], int day_of_speech15[], int month15[], int year15[], int hour_time15[], int minute_time15[], char series_code15[], int earlybird_dollar15[], int earlybird_cents15[], int regular_dollar15[], int regular_cents15[], char home_state115[], char home_state215[])
{
	int count15;
	for(count15=0;count15<number_of_people_entered;count15++)
	{	
		printf ("The data you have entered for Speaker %d is:\n", count15+1);
		printf ("%d %d %d %d %d.%d %c %d.%d %d.%d %c%c\n", speaker_code15[count15], day_of_speech15[count15], month15[count15], year15[count15], hour_time15[count15], minute_time15[count15], series_code15[count15], earlybird_dollar15[count15], earlybird_cents15[count15], regular_dollar15[count15], regular_cents15[count15], home_state115[count15], home_state215[count15]);
	
	}

}
