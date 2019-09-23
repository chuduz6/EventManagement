/* Chudamani Aryal
Lab3 Assignment
Date Given: Oct 10 2010
Date Due: Oct 28 2010
Professor: Dr T
Class: CSE 1320 Section: 001 TH 11-12:20 */

// *********Description of the program**************
/* This program uses the concept of linked list. There is no maximum numbers of speaker to enter in this program. 
Every time the user wishes to enter new set of speaker data, the program allocates a dynamic memory to store data and then sorts the data by speaker code and links the data to the linked list. 
After the data are entered, this program stores those data and later on acts as a database 
and provides the users to play with some of its menu choices. 
You will know more about the menu choice once you get into the program. */

//*********  pre-processors   *************

// include files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constants
#define EVENTMIN 3
#define MAXSTATE 3
#define MAXNUM 40
#define MAX 128

// declaration of enum
enum typeofevent
{FREE=0,PAID=1};

// declaration of union
union typeofevent1
{
	int tickets_sold;
	int total_seats;
};
//struct declaration
struct speaker
{
	int speakerCode, pday, pmonth, pyear, bday, bmonth, byear;
	float pTime, ebird, reg;
	union typeofevent1 eventSeats;
	enum typeofevent eventPrice;
	char seriesCode, expertiseCode, state[MAXSTATE], firstName[MAXNUM], lastName[MAXNUM], titleName[MAX];
	struct speaker *next;
};

// **************** declaration of functions  *******************


// display functions
void welcome_msg();
void show_oneLine_enter();
void show_menu();
void show_expertise_format();
void printArray(struct speaker *begin);
void show_sub_menu();
void exit_the_program();
void printSingle(struct speaker *tmpr);


//check functions
int check_input_choice(int b);
int checkSpeakerCode (int a);
int checkDay(int a);
int checkMonth(int a);
int checkYear(int a);
char checkSeriesCode(char a);
char checkExpertiseCode(char a);
float checkTime(float a);
float checkEbirdPrice(float a);
float checkRegPrice(float a);
int checkByear(int a, struct speaker *current);
int check_menu_choice(int c);

// input methods
struct speaker *intputFile(FILE *infile, struct speaker *current);
struct speaker *input_Individual (struct speaker *current);
struct speaker *input_oneLine (struct speaker *current);

// main functions
void main_menu_operation (int menu_choice_number, FILE * infile, struct speaker *begin);

// search functions
struct speaker *search_by_speakercode(struct speaker *begin);
struct speaker *search_by_dateofspeech(struct speaker *begin);
struct speaker *search_by_expertise(struct speaker *begin);
struct speaker *linear_search_lastName(struct speaker *begin, char nameSearch[MAXNUM]);
struct speaker *search_speaker_by_lastname(struct speaker *begin);

// find all functions
struct speaker *find_all_same_series(struct speaker *begin);
struct speaker *find_all_certain_state(struct speaker *begin);
struct speaker *find_all_less_than_cost(struct speaker *begin);

// calculate functions
struct speaker *calculate_cost(struct speaker *begin);
struct speaker *calculate_age(struct speaker *begin);
struct speaker *calculate_length_of_time(struct speaker *begin);
struct speaker *calculate_min_max(struct speaker *begin);

// add and delete functions
struct speaker *del(struct speaker *begin, int code);
struct speaker *addEvent(FILE * infile, struct speaker *begin);
struct speaker *deleteEvent(struct speaker *begin);

// sort functions
struct speaker *sort_by_speaker_code(struct speaker *begin);
struct speaker *sort_by_perfomance_date(struct speaker *begin);
struct speaker *bubblesort(struct speaker *begin);
struct speaker *selectionsort_lastName(struct speaker *begin);
struct speaker *selection(struct speaker *begin);
struct speaker *bubblesort_performance(struct speaker *begin);
struct speaker *selection_sort_by_lastName(struct speaker *begin);

// upadate functions
struct speaker *update_array(struct speaker *begin);
void change_performance_date(struct speaker *tmpr1);
void change_series_code(struct speaker *tmpr1);
void change_two_state_char(struct speaker *tmpr1);
void change_one_of_the_tickets(struct speaker *tmpr1);
void change_performance_time(struct speaker *tmpr1);
void change_birth_date(struct speaker *tmpr1);
void change_firstName(struct speaker *tmpr1);
void change_lastName(struct speaker *tmpr1);
void change_expertise_code(struct speaker *tmpr1);
void change_titleName(struct speaker *tmpr1);
void change_number_tickets_seats(struct speaker *tmpr1);

// ****************        main function      ******************


int main (int argc, char *argv[])
{
	// declarations of variables
	int menu_choice_number;
	static int num_of_people=0;
	struct speaker *current= NULL, *begin= NULL, *travel= NULL, *trailer= NULL;
	FILE *infile=NULL;
	int enter_data, input_choice, answer, i;	
	
	// program starts with the welcome message
	welcome_msg();
	printf ("Now you are going to choose the way to input your data.\nEnter 1 if you want to input your data individually, NOT ONE LINE.\nEnter 2 if you want to input your data using input file method.\n");
	scanf ("%d", &enter_data);
	input_choice= check_input_choice(enter_data); // Asking method of Input (Individual or One Line)

	switch(input_choice)
	{
	case 1: for(i=0;i<EVENTMIN;i++)
			{
				
				current=input_Individual(current);
				if(begin==NULL)
					{	
						begin= current;
					} // if ends
					else if(begin->speakerCode>=current->speakerCode)
					{
						travel=begin;
						begin=current;
						current->next=travel; 
					} // else if ends
					else 
					{	
						travel=begin; 
						trailer=NULL; 
						while((travel->next!=NULL)&&(travel->speakerCode<current->speakerCode))
						{
							trailer=travel;
							travel=travel->next; 
						} // while ends
						if(travel->speakerCode>=current->speakerCode)
						{
							current->next=travel; 
							trailer->next=current; 
						} //  inside else (if ends)
						else 
						{
							travel->next= current; 
						} // inside else (else ends)
					} // else ends
			} // for loop ends
			break;
	case 2: 
		infile = fopen(argv[1],"r");
		if(infile==NULL)
		{
			char filename[20]=" ";
			printf("\nPlease enter the name of the file that you want to read the data from:");
			scanf("%s",&filename);
			infile = fopen(filename, "r"); 
			while(infile==NULL)
			{
				printf("\nInvalid file\n Please Renter the name of the file that you want to read the data from:");
				scanf("%s",&filename);
				infile = fopen(filename, "r");	
				printf("%p",infile);
			}
		}
		while(!feof(infile))
		{	
			
			
			current = intputFile(infile,current);
			if(begin==NULL)
			{	
				begin= current;
			} // if ends
			else if(begin->speakerCode>=current->speakerCode)
			{
				travel=begin;
				begin=current;
				current->next=travel; 
			} // else if ends
			else 
			{	
				travel=begin; 
				trailer=NULL; 
				while((travel->next!=NULL)&&(travel->speakerCode<current->speakerCode))
				{
					trailer=travel;
					travel=travel->next; 
				} // while ends
				if(travel->speakerCode>=current->speakerCode)
				{
					current->next=travel; 
					trailer->next=current; 
				} //  inside else (if ends)
				else 
				{
					travel->next= current; 
				} // inside else (else ends)
			} // else ends

		} // while loop ends
		
		printf("Reading completed.............\n\n");
				
		printf("end\n");
		fclose(infile); break;
		

		}
			
	printf ("Do you wish to enter data for speaker?\n Enter 1 for yes and Enter 0 for no. \n");
	scanf ("%d", &answer);
	input_choice=1;
	printf("Since you want more data, you now have to type them manually, which is individual method.\n");
	while(answer==1)
	{
		
		
		current=input_Individual(current);
		if(begin==NULL)
			{	
				begin= current;
			} // if ends
			else if(begin->speakerCode>=current->speakerCode)
			{
				travel=begin;
				begin=current;
				current->next=travel; 
			} // else if ends
			else 
			{	
				travel=begin; 
				trailer=NULL; 
				while((travel->next!=NULL)&&(travel->speakerCode<current->speakerCode))
				{
					trailer=travel;
					travel=travel->next; 
				} // while ends
				if(travel->speakerCode>=current->speakerCode)
				{
					current->next=travel; 
					trailer->next=current; 
				} //  inside else (if ends)
				else 
				{
					travel->next= current; 
				} // inside else (else ends)
			} // else ends


		
			
			
		

		
		
	
		printf ("Do you wish to enter more data for speaker?\n Enter 1 for yes and Enter 0 for no. \n");
		scanf ("%d", &answer);
	}

	printf ("Congratulations!!!! Congratulations!!! Congratulations!!! You have successfully entered all the required data.\n");
	printf ("Here are your data you have entered: \n");

	printArray(begin );// this prints all the data that the user has entered

	printf ("Now begins the fun part.\n");
	
	
	show_menu(); // Once all the data that have been entered are shown, the program next shows the menu

	// Once all the menu option are shown, the user is asked to enter the option number to work accordingly
	printf ("Now enter the menu option number.\n");
	scanf ("%d", &enter_data);

	// menu choice is verified and main menu operation is called. Also a reminder, one of the options of main menu calls sub menu function
	menu_choice_number = check_menu_choice(enter_data);
	main_menu_operation(menu_choice_number, infile, begin);
	
	printf ("EVERYTHING WORKS FINE :) \n");
	return 0;
	
}
	
// this function prints single set of data
void printSingle(struct speaker *tmpr)
{
	printf ("CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tBDAY\tBMONTH\tBYEAR\tECODE\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n");

	printf ("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("%d\t%d\t%d\t%d\t%.2f\t%c\t%.2f\t%.2f\t%s\t%d\t%d\t%d\t%c\t%s\t\t%s\t\t%d\t%s \n",tmpr->speakerCode, tmpr->pday, tmpr->pmonth, tmpr->pyear, tmpr->pTime, tmpr->seriesCode, tmpr->ebird, tmpr->reg, tmpr->state, tmpr->bday, tmpr->bmonth, tmpr->byear, tmpr->expertiseCode, tmpr->firstName, tmpr->lastName, tmpr->eventSeats.total_seats, tmpr->titleName );
	printf ("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//this function shows user the menu and its options
void show_menu()
{
	printf ("Now you are looking at the menu choices of this program.\nAnd the following are your choices:\n1. Search for speakers/performers by speaker code.\n2. Search for speakers/performers by date of speech/performance.\n3. Search for speakers by expertise. \n4. Calculate cost for purchase of a given number of tickets of a given type.\n5. Calculate the age of the speaker while in performance.\n6. Find all the speakers in the same series.\n7. Find all the speakers that are from a certain state.\n8. Find all the speeches/performances that cost less than a given ticket price. \n9. Calculate length of time from current date to the date of the speech/performance. \n10.  Calculate max and minimum tickets function. \n11. Add events. Takes to the sub function. \n12.  Search the speaker by last name using linear SEARCH.\n13.  Update the data in the arrays. This will take you to a submenu for doing updates.\n14. Sort the data by speaker code. \n15. Sort the data by speech/performance date. \n16. Sort the data by last name. \n17. Delete Events. \n18. End the program.\n");
	printf ("Remember that while chosing your menu choice, you have to choose the corresponding number to the menu option. \nFor example, to calculate the ticket cost you must enter 4.\n");
}

// this function checks whether the right menu choice is entered or not
int check_menu_choice(int c)
{
	while (c<1||c>18)
	{
		printf("Invalid Menu Choice. Please Look at the instructions and try again.\n");
		show_menu();
		scanf ("%d", &c);
	}
	return c;
}

// this function takes the user into the main menu operation and gives the user various choices to enter
void main_menu_operation (int menu_choice_number, FILE *infile, struct speaker *begin)
{
	while (menu_choice_number != 18)
	{
		switch(menu_choice_number)
		{
		// each case here represents the menu options and once that case is entered, this switch statement calls that corresponding function
		case 1: begin=search_by_speakercode(begin);break;
		case 2: begin=search_by_dateofspeech(begin);break;
		case 3: begin=search_by_expertise(begin);break;
		case 4: begin=calculate_cost(begin);break;
		case 5: begin=calculate_age(begin);break;
		case 6: begin=find_all_same_series(begin);break;
		case 7: begin=find_all_certain_state(begin);break;
		case 8: begin=find_all_less_than_cost(begin);break;			
		case 9: begin=calculate_length_of_time(begin);break;
		case 10: begin=calculate_min_max(begin);break;
		case 11: begin=addEvent(infile, begin);
			printf ("The list the data after adding all events is as follows:\n");
			printArray(begin);break;

		case 12: begin=search_speaker_by_lastname(begin);break;
		case 13: begin= update_array(begin);break;
		case 14: begin=sort_by_speaker_code(begin);break;
		case 15: begin=sort_by_perfomance_date(begin);break;
		case 16: begin=selection_sort_by_lastName(begin);break;	
		case 17: begin=deleteEvent(begin);
			printf ("The list the data after deleting all events is as follows:\n");
			printArray(begin);break;
		
		default: printf ("Invalid Entry. Please check your choice number.\n");break;
		}
		printf ("Choose Another menu option, which is from the range of 1 to 18.\n");
		scanf ("%d", &menu_choice_number);
		menu_choice_number=check_menu_choice(menu_choice_number);
	}
	exit_the_program();
}
//this function calcultes the maximum and minimu tickets
struct speaker *calculate_min_max(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	int speakerCodeMinMax, checkpoint=0, minReceipts, maxReceipts;
	printf ("You chose to calculate the minimum and maximum numbers of tickets sold.\n");
	
			printf ("Enter the speaker code you wish to calculate the maximum and minimum ticket receipts.\n");
			scanf ("%d", &speakerCodeMinMax);
			speakerCodeMinMax=checkSpeakerCode(speakerCodeMinMax);
			tmpr=begin;
			while(tmpr!=NULL)
			{
				if (speakerCodeMinMax==tmpr->speakerCode)
				{
					checkpoint=1;
					if(tmpr->eventPrice==FREE)
					{
						printf ("Since this is a free Event. There is no ticket amount to calculate.\n");
					}
					else
					{
						minReceipts=(tmpr->ebird)*(tmpr->eventSeats.tickets_sold);
						maxReceipts=(tmpr->reg)*(tmpr->eventSeats.tickets_sold);
						printf ("The minimum Receipts is %d and the maximum receipts is %d.\n", minReceipts, maxReceipts);

					}

				}
				tmpr=tmpr->next;
			}
			
	
	if (checkpoint==0)
			printf ("Speaker Code Not Found. Returned to the main menu\n");

return begin;


}

//this function adds event to the data while taking into sub menu
struct speaker *addEvent(FILE * infile, struct speaker *begin)
{
	struct speaker *current=NULL, *travel=NULL, *trailer=NULL;
	
	int enter_data, input_choice=1, answer=1;
	printf ("You chose to add event.\n");
	
	
	printf ("Since you wanted to add event you will have you enter the data manually, ie. using individual method.\n");
	while(answer==1)
	{
		
		
		switch(input_choice) // This switch statement calls the respective input function
		{
			case 1: current=input_Individual(current);break;
			
			default: printf ("Invalid Input\n");break;
		}
			if(begin==NULL)
			{	
				begin= current;
			} // if ends
			else if(begin->speakerCode>=current->speakerCode)
			{
				travel=begin;
				begin=current;
				current->next=travel; 
			} // else if ends
			else 
			{	
				travel=begin; 
				trailer=NULL; 
				while((travel->next!=NULL)&&(travel->speakerCode<current->speakerCode))
				{
					trailer=travel;
					travel=travel->next; 
				} // while ends
				if(travel->speakerCode>=current->speakerCode)
				{
					current->next=travel; 
					trailer->next=current; 
				} //  inside else (if ends)
				else 
				{
					travel->next= current; 
				} // inside else (else ends)
			} // else ends
		
     

		printf ("Do you wish to add more events to the data for speaker?\n Enter 1 for yes and Enter 0 for no. \n");
		scanf ("%d", &answer);
	}
			
		
		

	return begin;

}

//this function deletes the event from the data

// function to delete the node
struct speaker *deleteEvent(struct speaker *begin)
{
     int count,answer=0;
	struct speaker *index=begin;	
	struct speaker *trailer=NULL;
	struct speaker *travel=NULL;
	int speakerCode;
	if( index!=NULL)
	{
		printf("Are you sure you want to DELETE the data displayed below\n");
		printf("Press 1 to continue, 0 to exit\n");
		scanf("%d",&answer);
		printf ("Enter the speaker Code you wish to delete? Make sure it is the right one.\n");
		scanf ("%d", &speakerCode);
		speakerCode=checkSpeakerCode(speakerCode);
		
	}

	if(answer==1)	
	{
		
		if(begin->next==NULL)
		{
			if(speakerCode==begin->speakerCode)
			{
				begin=NULL;
			}
		}
		else
		{
			trailer=begin;
			travel=begin->next;
			if(speakerCode==begin->speakerCode)
			{
				begin=travel;
			}
			else
			{
				while((travel!=NULL)&&(speakerCode!=travel->speakerCode))
				{
					trailer=travel;
					travel=travel->next;
				}
				if(speakerCode==travel->speakerCode)
				{
					if(travel->next!=NULL)
						trailer->next=(trailer->next)->next;
					else
						trailer->next=NULL;
				}
			}
		}
	}
	else
		printf ("You chose not to delete any event. So, returning to the main menu.\n");
	
	return begin;
	
}

//delete function not used right now
struct speaker *del(struct speaker *begin, int code)
{
       struct speaker *current=NULL,*follow;
       current=begin;
       follow= NULL;

	   while (current !=NULL)
	   {
 	    if(current->speakerCode == code)
 	    {
		//if desired element is found
		if (follow==NULL)
		{
		//fix beginning pointeer
		begin = current->next;
		free(current);
		}
		else
		{
		follow->next = current->next;
		free(current);
		}
		follow=current;
     	    }   
  		
  		current=current->next;
       }
  return (begin);
}


// this functions shows the sub menu and its option to the user
void show_sub_menu()
{
	printf ("Now you are on sub-menu. The following are the options on sub_menu: \n1. Change speech month, day, or year. \n2. Change the series array. \n3. Change the two state char arrays. \n4. Change one of the ticket arrays. \n5. Change the time array. \n6. Change birth month, day, or year. \n7. Change the expertise code. \n 8. Change the title name. \n 9. Change the first name. \n10. Change the last name. \n11. Change the number of tickets or seat. \n 12. Return to main menu.\nNow choose the corresponding option to play with the options.\nFor example, enter 2 to change the series array.\n");
}

// this function is called when the user enter the exit option
void exit_the_program()
{
	// gracefully terminating the program
	printf ("You chose to exit the program. The program exits now. \nThank you for giving your time and using this database. Bye Bye Now!! :)\n");
}


// this function prints welcome message
void welcome_msg()
{
	printf ("Welcome!!! Welcome!!! Welcome!!!\nWelcome all the users to the interface of UTA event database. \nHope you have fun with this program.\n");
}

// this function checks whether the right method of input is chosen or not
int check_input_choice(int b)
{
	while (b!=1 && b!=2)
	{
		printf ("Invalid Input choice entered. Please look at the instructions and try again.\n");
		scanf ("%d", &b);
	}
	return b;
}

// this function asks the user to enter all the data individually
struct speaker *input_Individual(struct speaker *current)
{
	current = (struct speaker *)malloc(sizeof(struct speaker));
	int input_name, buffer, buffer1; 
	char buffer_char, garbage, buffer_char1[MAXNUM]; 
	float buffer_float;	
			
		printf ("\nPLEASE ENTER THE SPEAKER CODE. This is a single integer value of less that four digits. Use the hundreds place digit to represent the series. \n100 for Maverick Speaker Series. 200 for Engineering Speaker Series. 300 for Engineering departmental sponsored event. 400 for College of Engineering event including Engineers Week. 500 for College of Science Event. 600 for University sponsored event including EXCEL activities, Homecoming,etc. 700 for Levitt Pavilion concert or event. 800 for Others. \n");
		scanf ("%d", &buffer); 
		current->speakerCode = checkSpeakerCode(buffer); //error checks and returns valid value
		
		
		printf ("\nPLEASE ENTER THE DAY OF SPEECH. Remember to make that day valid i.e within the range of 1 to 32. \n");
		scanf ("%d", &buffer);
		current->pday = checkDay(buffer); //error checks and returns valid value


		
		printf ("\nPLEASE ENTER THE month. Remember to make that month valid i.e within the range of 1 to 12. \n");
		scanf ("%d", &buffer);
		current->pmonth = checkMonth(buffer); //error checks and returns valid value


		
		printf ("\nPLEASE ENTER THE YEAR. Remember to make that year valid i.e within the range of 2000 to 2050. \n");
		scanf ("%d", &buffer);
		current->pyear = checkYear(buffer); //error checks and returns valid value

		
		
		printf ("\nPLEASE ENTER THE TIME FOR SPEECH. For example HH.MM This hour should be in military time i.e within the range of the hour should 0 to 23. Also, the minute should be the range of 0 to 59. \n");
		scanf ("%f", &buffer_float);
		current->pTime=checkTime(buffer_float); // error checks the entered value and returns valid value
		

		printf ("\nPLEASE ENTER THE SERIES CODE. Remember that this is a single UPPERCASE character. It is generally the first letter of the event. M for Maverick, E for Engineering Speaker, D for Engineering departmental sponsored, C for College for Engineering, S for College of Science, U for University sponsored, L for Levitt Pavilion, and O for Others.\n");
		scanf ("%c", &buffer_char);
		current->seriesCode=checkSeriesCode(buffer_char); // error checks and returns valid value


		
		printf ("\nPLEASE ENTER THE PRICE OF EARLY BIRD TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%f", &buffer_float);
		current->ebird=checkEbirdPrice(buffer_float); //error checks and returns valid value
		
		printf ("\nPLEASE ENTER THE PRICE OF REGULAR TICKET. Remember the format \"dollar.cents\" \n");
		scanf ("%f", &buffer_float);
		current->reg=checkRegPrice(buffer_float); //error check and returns valid value

		if((current->ebird==0)&&(current->reg==0)) // checks and assigns event price
			current->eventPrice=FREE;
		else
			current->eventPrice=PAID;

		printf ("\nPLEASE ENTER THE HOMESTATE OF THE SPEAKER. Remember C programming is case sensitive. \nFor example NY would be for New York. \n");
		scanf (" %s", &current->state);	

		show_expertise_format(); //shows the format to enter expertise code and also shows the list of expertise code
		printf ("\nPLEASE ENTER THE EXPERTISE CODE.\n");
		scanf ("%c", &garbage);
		scanf ("%c", &buffer_char);
		current->expertiseCode=checkExpertiseCode(buffer_char); //error checks and returns valid value

		
		printf ("\nPLEASE ENTER THE DAY OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		current->bday=checkDay(buffer); //error checks and returns valid value

		printf ("\nPLEASE ENTER THE MONTH OF THE BIRTH.\n");
		scanf ("%d",&buffer);
		current->bmonth=checkMonth(buffer); //error checks and returns valid value

		printf ("\nPLEASE ENTER THE YEAR OF THE BIRTH.\n");
		scanf ("%d",&buffer);		
		current->byear = checkByear(buffer, current); //error checks and returns valid value

		printf ("\nPLEASE ENTER THE FIRST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		scanf ("%c", &garbage);
		scanf ("%s", &buffer_char1);
		buffer_char1[MAXNUM-1]='\0';
		strcpy(current->firstName, buffer_char1);
		
		printf ("\nPLEASE ENTER THE LAST NAME OF THE SPEAKER. THE MAX LENGTH IS 40.\n");
		scanf ("%c", &garbage);
		scanf ("%s", &buffer_char1);		
		buffer_char1[MAXNUM-1]='\0';
		strcpy(current->lastName, buffer_char1);
		
		//based on the event price, either total seats or tickets sold is assigned
		if(current->eventPrice==FREE)
		{
			printf ("The Event is free. Enter the number of seats.\n");
			scanf ("%d", &current->eventSeats.total_seats);
		}
		else
		{
			printf ("The event is Paid. Enter the number of total tickets.\n");
			scanf ("%d", &current->eventSeats.tickets_sold);
		}
				

		printf ("\nPLESE ENTER THE TITLE OF THE SPEAKER'S PERORMANCE OR SPEECH. THE MAX LENGTH IS 128.\n");
		scanf ("%c", &garbage);
		fgets(current->titleName, MAX, stdin);
		current->titleName[MAX-1]='\0';
		
	return current;
}

//this function is for input file
struct speaker *intputFile(FILE *infile, struct speaker *current)
{
	current = (struct speaker *)malloc(sizeof(struct speaker));
	int row_count=128;
	float buffer_float;
	char buffer_char;
	char buffer_char1[MAXSTATE];
	char buffer_char2[MAXNUM];
	char *buffer_char3;
	buffer_char3=(char *)malloc(sizeof(row_count+1));

	// checks and stores speaker code
	
	fscanf (infile,"%d", &current->speakerCode);
	current->speakerCode=checkSpeakerCode(current->speakerCode);


	

	// checks and stores day of speech
	fscanf(infile,"%d",&current->pday);
    current->pday=checkDay(current->pday);
	


	// checks and stores month of the speech
	fscanf(infile,"%d",&current->pmonth);
    current->pmonth=checkMonth(current->pmonth);


	// checks and stores year of the speech
	fscanf(infile,"%d",&current->pyear);
    current->pyear=checkYear(current->pyear);

	// checks and stores time of speech
	fscanf(infile,"%f",&current->pTime);
    current->pTime=checkTime(current->pTime);

	// checks and stores series code
	fscanf(infile," %c",&current->seriesCode);
    current->seriesCode=checkSeriesCode(current->seriesCode);

	// checks and stores ebird price
	fscanf(infile,"%f",&current->ebird);
    current->ebird=checkEbirdPrice(current->ebird);

	// checks and stores regular price
	fscanf(infile,"%f",&current->reg);
    current->reg=checkRegPrice(current->reg);

	// checks and assigns event price
	if((current->ebird==0)&&(current->reg==0)) 
			current->eventPrice=FREE;
		else
			current->eventPrice=PAID;

	// stores state
	fscanf(infile,"%s",&buffer_char1);
	strcpy(current->state,buffer_char1);

	// checks and stores expertise code
	
	fscanf(infile," %c",&current->expertiseCode);
    current->expertiseCode=checkExpertiseCode( current->expertiseCode);

	// checks and stores DAY of the birth
	fscanf(infile,"%d",&current->bday);
    current->bday=checkDay(current->bday);

	// checks and stores month of the birth
	fscanf(infile,"%d",&current->bmonth);
    current->bmonth=checkMonth(current->bmonth);

	// checks and stores year of the birth
	fscanf(infile,"%d",&current->byear);
    current->byear=checkByear(current->byear, current);
	
	// stores first name
	fscanf(infile,"%s",&buffer_char2);
    strcpy(current->firstName,buffer_char2);
	current->firstName[MAXNUM-1]='\0';
	

	// stores last name
	fscanf(infile,"%s",&buffer_char2);
    strcpy(current->lastName,buffer_char2);
	current->lastName[MAXNUM-1]='\0';

	//based on the event price, either total seats or tickets sold is assigned
		if(current->eventPrice==FREE)
		{
			fscanf(infile, "%d", &current->eventSeats.total_seats);
			
		}
		else
		{
			fscanf(infile, "%d", &current->eventSeats.tickets_sold);
			
			
		}
		

	// stores title
	fgets(buffer_char3, row_count, infile);
	buffer_char3[MAX-1]='\0';
    strcpy(current->titleName,buffer_char3); 
	
	

	return current;
}


float checkTime(float a)
{
	//error checking the time of speech
		while (a<0 || a>23 || (a-(int)a)<0 || (a-(int)a)>59) 
		{
			printf ("\nInvalid Time for Speech. Please go back and look at the instructions and try again.\n");
			scanf ("%d.%d", &a);
		}	
		return a;
}

//error checking price of early bird ticket
float checkEbirdPrice(float a)
{
	
		while (a<0.0 || (a-(int)a)<0.0|| (a-(int)a)>0.99)
		{
			printf ("\nInvalid Price of earlybird ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d", &a);
		}
		return a;
}

//error checking price of regular ticket
float checkRegPrice(float a)
{
	
		while (a <0.0 || (a-(int)a)<0.0 || (a-(int)a)>0.99)
		{
			printf ("\nInvalid Price of regular ticket. Look at the instruction above and try again. :)\n");
			scanf ("%d", &a);
		}
		return a;
}

// error checking for the birth year of the speaker
int checkByear(int a, struct speaker *current)
{
	while ((current->pyear-a)<=10)
		{
			printf ("Invalid Birth year. Try again.\n");
			scanf ("%d",&a);

		}
	return a;
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


//error checking expertise code
char checkExpertiseCode(char a)
{
	char garbage;
	
		while (a!='A' && a!= 'B' && a!= 'C' && a!= 'P' && a!= 'E' && a!= 'I' && a!= 'M' && a!= 'S' && a!= 'O' && a!= 'Z' && a!='L' && a!= 'D' && a!= 'X' && a!='N' && a!='R' && a!='W' && a!='U' && a!= 'G')
		{
			if (a!='\n' || a!='\t' || a!= '\0')
				printf ("Error in expertise code. Try again.\n");
			scanf ("%c", &garbage);
			scanf ("%c", &a);
		}
		return a;
}

// this function prints all the data
void printArray(struct speaker *begin)
{
	
	struct speaker *tmpr=begin;
	printf ("CODE\tPDAY\tPMONTH\tPYEAR\tPTIME\tSCODE\tEBIRD\tREG\tSTATE\tBDAY\tBMONTH\tBYEAR\tECODE\tFIRST\t\tLAST\t\tNUMBER\tTITLE\n");
	while(tmpr!=NULL)
	{
		
		printf ("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%d\t%d\t%d\t%d\t%.2f\t%c\t%.2f\t%.2f\t%s\t%d\t%d\t%d\t%c\t%s\t%s\t\t%d\t%s \n",tmpr->speakerCode, tmpr->pday, tmpr->pmonth, tmpr->pyear, tmpr->pTime, tmpr->seriesCode, tmpr->ebird, tmpr->reg, tmpr->state, tmpr->bday, tmpr->bmonth, tmpr->byear, tmpr->expertiseCode, tmpr->firstName, tmpr->lastName, tmpr->eventSeats.total_seats, tmpr->titleName );
		printf ("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		tmpr=tmpr->next;
		
	}
}
// this function shows the format of expertise code
void show_expertise_format()
{
	printf ("Here is the format. A - Aerospace Engineering, B - Bioengineering, C - Civil Engineering, P - Computer Science and Engineering, E - Electrical Engineering, I - Industrial Engineering, M - Mechanical Engineering, S - Materials Science and Engineering, O - Other Engineering, Z - Science, L - Liberal Arts, D - Education, X - Business, N - Nursing, R - Architecture, W - Social Work, U - Urban and Public Affairs, G - General\n");
		printf ("PLEASE ENTER THE CORRESPONDING ALPHABET.\n");
}

// this function searchs the data by speakercode
struct speaker *search_by_speakercode(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	int enter_data, count, checkpoint=0;
	printf ("\nYou chose to search a speaker by speaker code.\n");
	printf ("\nNow Enter the speaker code. Remember the range given before.\n");
	scanf ("%d", &enter_data);
	enter_data = checkSpeakerCode(enter_data);
	while(tmpr!=NULL)
	{
		if(enter_data==tmpr->speakerCode) // comparing the speaker code entered before with the speaker code entered now
		{
			checkpoint=1;
			printf ("Found Match \n");
			printf ("The set of data found has:\n");
			//if match found result printed
			printSingle(tmpr);
		}
		tmpr=tmpr->next;
	}
	if(checkpoint==0)
			printf ("No matches found. Sorry!!! :(\n");
return begin;
}

// this function searchs data by date of speech
struct speaker *search_by_dateofspeech(struct speaker *begin)
{
	struct speaker *tmpr=begin;
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

	while(tmpr!=NULL)
	{
		if(enter_data4==tmpr->pday) //comparing the date of speech entered before with the date of speech entered now
			if(enter_data5==tmpr->pmonth)
				if(enter_data6==tmpr->pyear)
				{
					// if match found, result printed
					printf ("Found Match\n");
					printf ("The set of data from the found match is:\n");
					printSingle(tmpr);
					checkpoint1=1;
				}
		tmpr=tmpr->next;
	}
	if(checkpoint1==0)
	{
		// if match not found
		printf ("No matches found. Sorry!!! :(\n");
	}
return begin;
}

// this function calculates the cost of the given number of given types of ticket by given speaker
struct speaker *calculate_cost(struct speaker *begin)
{
	struct speaker *tmpr1=NULL, *tmpr=begin;
	int calculate_choice, count, checkpoint2=0, index, speaker_code_calculate,number_of_earlybird, number_of_regular; 
	float dollar_price_of_earlybird, dollar_price_of_regular, dollar_price_of_total;
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
				speaker_code_calculate=checkSpeakerCode(speaker_code_calculate);
				tmpr=begin;
				while (tmpr!=NULL)
				{
					if(speaker_code_calculate==tmpr->speakerCode)
					{
						tmpr1=tmpr;
						checkpoint2=1;
					}
					tmpr=tmpr->next;
				}
				if (checkpoint2==0)
					printf ("No match found. Try again to enter speaker code.\n");
			}

			
				// when match is found, the cost is calculated using the below formula
				printf ("Match Found. \nEnter the number of earlybird ticket first, then the regular ticket. \nRemember to put a space in between.\n");
				scanf ("%d %d", &number_of_earlybird, &number_of_regular);
				dollar_price_of_earlybird = (number_of_earlybird * tmpr1->ebird);
				dollar_price_of_regular = (number_of_regular * tmpr1->reg);
				dollar_price_of_total = dollar_price_of_earlybird + dollar_price_of_regular ;
				printf ("You entered %d for early bird tickets and %d for the regular tickets.\n", number_of_earlybird, number_of_regular);
				printf ("Hence your total price is %.2f. \n", dollar_price_of_total);
			
			break;
	case 2: //this case calculates the cost of early bird tickets only
			checkpoint2=0;
			printf ("You entered number 2. This means you chose to calculate the total cost of early bird tickets.\n");
			while (checkpoint2!=1)
			{
				printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
				scanf ("%d", &speaker_code_calculate);
				speaker_code_calculate=checkSpeakerCode(speaker_code_calculate);
				tmpr=begin;
				while(tmpr!=NULL)
				{
					if(speaker_code_calculate==tmpr->speakerCode)
					{
						tmpr1=tmpr;
						checkpoint2=1;
					}
					tmpr=tmpr->next;
				}

				if(checkpoint2==0)
				{
					printf ("No matches found.\n"); //when no match is found
				}

			}

			
			
				//when match is found, the cost is calculated along with the below formula
				printf ("Match Found. Enter the number of earlybird ticket.\n");
				scanf ("%d", &number_of_earlybird);
				dollar_price_of_earlybird = (number_of_earlybird * tmpr1->ebird);
				printf ("You entered %d for early bird tickets.\n", number_of_earlybird);
				printf ("Hence your total price is %.2f \n", dollar_price_of_earlybird);
			
			break;
	case 3: // this case calculates the ticket cost of regular tickets only
			checkpoint2=0;
			printf ("You enter 3 and chose to calculate only the cost of regular tickets.\n");
			while (checkpoint2!=1)
			{
				printf ("Enter the speaker code whose ticket cost you want to calculate. Make sure its the right speaker code. Please Enter.\n");
				scanf ("%d", &speaker_code_calculate);
				speaker_code_calculate=checkSpeakerCode(speaker_code_calculate);
				tmpr=begin;
				while(tmpr!=NULL)
				{
					if(speaker_code_calculate==tmpr->speakerCode)
					{
						tmpr1=tmpr;
						checkpoint2=1;
					}
					tmpr=tmpr->next;
				}
				if(checkpoint2==0)
				{
					printf ("No matches found.\n"); //when no match found
				}
			}

			
			
				//when match is found, the cost is calculated using the below formula.
				printf ("Match Found. Enter the number of regular ticket.\n");
				scanf ("%d", &number_of_regular);
				dollar_price_of_regular = (number_of_regular * tmpr1->reg);
				printf ("You entered %d for regular tickets.\n", number_of_regular);
				printf ("Hence your total price is %.2f \n", dollar_price_of_regular);
			
			break;
	default: printf ("Invalid Input. Sorry\n");break;

			
			
	}
	return begin;
}

// this function finds all the speakers with same series code
struct speaker *find_all_same_series(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	char series_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 6, which is to find all the speaker with same series.\n");
	printf ("Now enter the series code of the speaker you want to find. Please Enter the series code.\n");
	scanf ("%c", &series_code_to_find_all);
	series_code_to_find_all = checkSeriesCode(series_code_to_find_all);

	while(tmpr!=NULL)
	{
		if(series_code_to_find_all==tmpr->seriesCode) //series code compared with the one entered before
		{

			//when match found, results displayed
			
			printf ("Found Match\n");			
			printf ("The set of data from the found match is:\n");
			printSingle(tmpr);
			checkpoint3=1;
		}
		tmpr=tmpr->next;
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");

return begin;
}

// this function finds all ths speakers from same state
struct speaker *find_all_certain_state(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	char certain_state_to_find_all[3], garbage;
	int checkpoint4=0, count, index3;
	printf ("You entered menu option 7, which is to find all the speaker with certain state.\n");
	printf ("Now enter the homestate of the speaker you want to find. Remember both character should be together and C Programming is case-sensitive. \nPlease Enter the two homestate character together.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &certain_state_to_find_all);

	
	while(tmpr!=NULL)
	{
		// howe state with two characters is compared with the previously entered one
		if((certain_state_to_find_all[0]==tmpr->state[0]) &&(certain_state_to_find_all[1]==tmpr->state[1] ))
		{
			// if match found, results printed
			printf ("Found Match\n");
			printf ("The set of data from the found match is:\n");
			printSingle(tmpr);
			checkpoint4=1;
		}
		tmpr=tmpr->next;
	}
	if(checkpoint4==0) // if no match found
		printf ("No matches found. Sorry!!! :(\n");
return begin;
}

// this function leads you to the next function, which is a sub menu function of the programming.
struct speaker *update_array(struct speaker *begin)
{
	struct speaker *tmpr1=begin;
	struct speaker *tmpr=begin;
	
	int sub_menu_speaker_code, sub_menu_choice_number, count, index4, checkpoint=0;
	printf ("You enter number 11, which is to update array. Now the program will take you to another sub-menu with bunch of options.\n");
	show_sub_menu();
	//the user is asked to enter which array to update
	while (checkpoint==0)
	{
		printf ("Now enter the integer number of speaker code which you want to update. Please Enter the Speaker code. Remember the range.\n");
		scanf ("%d", &sub_menu_speaker_code);
		sub_menu_speaker_code=checkSpeakerCode(sub_menu_speaker_code);
		tmpr=begin;
		while(tmpr!=NULL)
		{
			if(sub_menu_speaker_code==tmpr->speakerCode) // comparing the speaker code entered now with the speaker code entered before
			{
				// if equal, then that speaker's data to be updated
				tmpr1=tmpr;
				printf ("So you will be updating the information of Speaker\n");
				checkpoint=1;
			}
			tmpr=tmpr->next;
		}
	}
	printf ("Enter the sub-menu choice number. Remember the range. \n");
	scanf ("%d", &sub_menu_choice_number);
	while(sub_menu_choice_number<1 || sub_menu_choice_number>12) //error checking the sub menu option
	{
		printf ("Invalid Entry. Please look at the instructions.\n");
		scanf ("%d", &sub_menu_choice_number);

	}
	while(sub_menu_choice_number!=12) // this returns to main menu when the user enters 6 which is an option to return to the main menu
	{
		switch(sub_menu_choice_number)
		{
			// according to the number enter, switch statement calls the corresponding function.
			case 1: change_performance_date(tmpr1);break;
			case 2: change_series_code(tmpr1);break;
			case 3: change_two_state_char(tmpr1);break;
			case 4: change_one_of_the_tickets(tmpr1);break;
			case 5: change_performance_time(tmpr1);break;
			case 6: change_birth_date(tmpr1);break;
			case 7: change_expertise_code(tmpr1);break;
			case 8: change_titleName(tmpr1);break;
			case 9: change_firstName(tmpr1);break;
			case 10: change_number_tickets_seats(tmpr1);break;
			case 11: change_lastName(tmpr1);break; 
		}
		printf ("Enter the sub-menu choice number. Remember the range. \n"); // this is to compare the sub menu choice number with the top while loop
		scanf ("%d", &sub_menu_choice_number);
		while(sub_menu_choice_number<1 || sub_menu_choice_number>12)
		{
			printf ("Invalid Entry. Please look at the instructions.\n");
			scanf ("%d", &sub_menu_choice_number);

		}
		
	}
	printf ("You chose to return to the main menu.\n");

	return begin;
}

// this function searchs all the speakers with same expertise
struct speaker *search_by_expertise(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	char expertise_code_to_find_all;
	int checkpoint3=0, count, index2;
	printf ("You entered menu option 3, which is to find all the speaker with same expertise.\n");
	printf ("Now enter the expertise code of the speaker you want to find. Please Enter the expertise code.\n");
	scanf ("%c", &expertise_code_to_find_all);
	scanf ("%c", &expertise_code_to_find_all);
	expertise_code_to_find_all=checkExpertiseCode(expertise_code_to_find_all);

	while(tmpr!=NULL)
	{
		if(expertise_code_to_find_all==tmpr->expertiseCode) //series code compared with the one entered before
		{

			//when match found, results displayed
			
			printf ("Found Match");			
			printf ("The set of data from the found match is:\n");
			printSingle(tmpr);
			checkpoint3=1;
		}
		tmpr=tmpr->next;
	}
	if(checkpoint3==0) // when no match is found
		printf ("No matches found. Sorry!!! :(\n");
	return begin;
}

// this function calculates the age of the speaker while performing
struct speaker *calculate_age(struct speaker *begin)
{
	struct speaker *tmpr1, *tmpr=begin;
	int calculate_age_speaker_code, count, index, length_day, length_month, length_year, checkpoint=0;
	printf ("You chose menu option 5, which is to calculate the age of the speaker while performing his act.\n");
	while (checkpoint!=1)
	{
		printf ("Enter the speaker code of the speaker.\n");
		scanf ("%d", &calculate_age_speaker_code);
		calculate_age_speaker_code=checkSpeakerCode(calculate_age_speaker_code);
		tmpr=begin;
		while(tmpr!=NULL)
		{
			if (calculate_age_speaker_code==tmpr->speakerCode)
			{
				tmpr1=tmpr;
				checkpoint=1;
			}
			tmpr=tmpr->next;
		}
		
		if (checkpoint==0)
		printf ("Speaker Not Found. Enter again.\n");
	}
	if (checkpoint==1)
	{	
		if(tmpr1->pday<tmpr1->bday)
		{
			length_day=30+tmpr1->pday-tmpr1->bday;
			tmpr1->pmonth--;
		}
		else
		{
			length_day=tmpr1->pday-tmpr1->bday;
		}
		
		if(tmpr1->pmonth<tmpr1->bmonth)
		{
			length_month=12+tmpr1->pmonth-tmpr1->bmonth;
			tmpr1->pyear--;
		}
		else
		{
			length_month=tmpr1->pmonth-tmpr1->bmonth;
		}
		length_year=tmpr1->pyear-tmpr1->byear;
	}
		printf ("The age of the speaker is %d years, %d months and %d days.\n", length_year, length_month, length_day);
	return begin;
}

// this function finds all the tickets which are less than the given cost
struct speaker *find_all_less_than_cost(struct speaker *begin)
{
	struct speaker *tmpr=begin;
	int input_choice_ticket,index4=0, count, checkpoint=0;
	float ticket_price_dollar;
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
			scanf ("%f", &ticket_price_dollar);
			ticket_price_dollar = checkEbirdPrice(ticket_price_dollar);
			tmpr=begin;
			while(tmpr!=NULL)
			{
				if(ticket_price_dollar>=tmpr->ebird)
				{
					
						
						printf ("Match Found.\n");
						printSingle(tmpr);
						checkpoint=1;			
					
				}
				tmpr=tmpr->next;
				
			}
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
			break;
	case 2: printf ("You chose to find on regular ticket.\n");
			printf ("Now enter the price of regular to find the tickets having the cost below the entered price.\n");
			scanf ("%f", &ticket_price_dollar);
			ticket_price_dollar=checkRegPrice(ticket_price_dollar);
			tmpr=begin;
			while(tmpr!=NULL)
			{
				if(ticket_price_dollar>=tmpr->reg)
				{
					
						
						printf ("Match Found.\n");
						printSingle(tmpr);
						checkpoint=1;		
				}
				tmpr=tmpr->next;
				
			}
			break;
			if (checkpoint==0)
				printf ("NO MATCH FOUND.\n");
	default: printf ("Wrong value entered. Please again.\n");break;


	}
	return begin;
}


//this function Calculates length of time from current date to the date of the speech/performance
struct speaker *calculate_length_of_time(struct speaker *begin)
{
	struct speaker *tmpr1=begin, *tmpr=begin;
	int length_speaker, count, index, checkpoint=0, checkpoint1=0, cday, cmonth, cyear, check_day_value, check_month_value, check_year_value, length_day=0, length_month=0, length_year=0;
	printf ("You entered to calculate the length of the time from current date to the date of the speech.\n");
	while (checkpoint!=1)
	{
		printf ("Enter the speaker code to know which speaker's length of time you wish to calculate.\n");
		scanf ("%d", &length_speaker);
		length_speaker = checkSpeakerCode(length_speaker);
		tmpr1=begin;
		while(tmpr1!=NULL)
		{
			if(length_speaker==tmpr1->speakerCode)
			{
				
				tmpr=tmpr1;
				checkpoint=1;
				
			}
			tmpr1=tmpr1->next;
			
		}
		
	if (checkpoint==0)
		printf ("No speaker found. Sorry. Try again.\n");
	}
	printf ("Enter the current date in format DD MM YYYY.\n");
	scanf ("%d %d %d", &cday, &cmonth, &cyear);

	if ((tmpr->pyear-cyear)<0)
		printf ("The event is already past. Sorry.\n");
	else if (tmpr->pyear==cyear)
	{
		if((tmpr->pmonth-cmonth)<0)
			printf ("The event is already past. Sorry.\n");
		else if (tmpr->pmonth==cmonth)
		{
			if ((tmpr->pday-cday)<0)
				printf ("The event is already past. Sorry.\n");
			else if(tmpr->pday==cday)
				printf ("The event is today. Hurry up!!!\n");
			else
			{
				length_day=tmpr->pday-cday;
				length_month=0;
				length_year=0;
				checkpoint1=1;
			}
		}
		else
		{
			checkpoint1=1;
			length_year=0;
			check_day_value = tmpr->pday - cday;
			if (check_day_value < 0)
			{
			length_day=tmpr->pday - cday + 30;
			cmonth=cmonth+1;
			}
			else
				length_day=tmpr->pday - cday;

			length_month=tmpr->pmonth - cmonth;
			
		}
	}
	else
	{
		checkpoint1=1;
		check_day_value = tmpr->pday - cday;
		if (check_day_value < 0)
		{
			length_day=tmpr->pday - cday + 30;
			cmonth=cmonth+1;
		}
		else
			length_day=tmpr->pday - cday;

		check_month_value = tmpr->pmonth - cmonth;
		if (check_month_value < 0)
		{
			length_month=tmpr->pmonth - cmonth+12;
			cyear=cyear+1;
		}
		else
			length_month=tmpr->pmonth - cmonth;

		length_year=tmpr->pyear - cyear;

	}

	
	if(checkpoint1==1)
		printf ("The length of from current date to the date of the speech/performance is %d days, %d months, %d years.\n", length_day, length_month, length_year); 
return begin;
}










// this function changes the performance date
void change_performance_date(struct speaker *tmpr1)
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the performance.\n");
	printf ("Beware that you are going to change the data for Speaker.\n");
	printf ("Please Enter the day of performance. Remember the range.\n");
	scanf ("%d", &change_date);
	tmpr1->pday=checkDay(change_date); //data updated

	printf ("Please Enter the month of performance. Remember the range.\n");
	scanf ("%d", &change_month);
	tmpr1->pmonth=checkMonth(change_month);//data updated

	printf ("Please Enter the year of performance. Remember the range.\n");
	scanf ("%d", &change_year);
	tmpr1->pyear=checkYear(change_year);//data updated

	printf ("\nUpdate successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);					
					

}

// this function changes the series code
void change_series_code(struct speaker *tmpr1)
{
	char change_series_code='a';
	printf ("You chose to change the series code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the series code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_series_code);
	scanf ("%c", &change_series_code);
	tmpr1->seriesCode=checkSeriesCode(change_series_code);//data updated

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);							
}

// this function changes the home state of the speaker
void change_two_state_char(struct speaker *tmpr1)
{
	int change_state;
	char garbage;
	printf ("Beware!!! You are updating the whole array. Please enter a new two character state.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &tmpr1->state); //data updated

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);							
}

// this function changes the price of the ticket
void change_one_of_the_tickets(struct speaker *tmpr1)
{
	int change_ticket_choice;
	float change_earlybird_dollar, change_regular_dollar;
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
			scanf ("%f", &change_earlybird_dollar);
			tmpr1->ebird =checkEbirdPrice(change_earlybird_dollar); //data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker is as follows:\n");
			printSingle(tmpr1);
			break;

	case 2: //this case changes the price of regular tickets
			printf ("You chose to change regular price.\n");
			printf ("Enter a new regular price.\n");
			scanf ("%f", &change_regular_dollar);

			tmpr1->reg=checkRegPrice(change_regular_dollar); //data updated

			//new updated array printed
			printf ("Update Successful. The new set of data of the speaker is as follows:\n");
			printSingle(tmpr1);
			break;

	default: printf ("Invalid Option Selected.\n");break;

	}

}

// this function changes the performance of the time
void change_performance_time(struct speaker *tmpr1)
{
	float change_hour_time;
	printf ("You chose to change time array. Beware, updating here changes everything elsewhere. Remember the range.\n");
	printf ("Please enter the new timing. Remember the format!!!\n");
	scanf ("%f", &change_hour_time);
	tmpr1->pTime=checkTime(change_hour_time); //data updated

	//new updated array is printed
	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);						
}

// this function changes the birth date of the speaker
void change_birth_date(struct speaker *tmpr1)
{
	int change_date, change_month, change_year;
	printf ("You chose to change date, month and year of the birth.\n");

	printf ("Beware that you are going to change the data for Speaker .\n");

	printf ("Please Enter the day of birth. Remember the range.\n");
	scanf ("%d", &change_date);	
	tmpr1->bday=checkDay(change_date); //data updated

	printf ("Please Enter the month of birth. Remember the range.\n");
	scanf ("%d", &change_month);
	tmpr1->bmonth=checkMonth(change_month); //data updated

	printf ("Please Enter the year of birth. Remember the range.\n");
	scanf ("%d", &change_year);
	
	tmpr1->byear=checkByear(change_year, tmpr1); //data updated

	printf ("\nUpdate successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);								
}

// this function changes the expertise code of the speaker
void change_expertise_code(struct speaker *tmpr1)
{
	char change_expertise_code='a';
	printf ("You chose to change the expertise code. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the expertise code. Remember the instructions.Please Enter.\n");
	scanf ("%c", &change_expertise_code);
	scanf ("%c", &change_expertise_code);
	tmpr1->expertiseCode=checkExpertiseCode(change_expertise_code); //data updated

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);					
}

// this function changes the first name of the speaker
void change_firstName(struct speaker *tmpr1)
{
	char garbage='a';
	char change_firstname[MAXNUM]={};
	printf ("You chose to change the first name of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the first name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &change_firstname); 
	
	strcpy(tmpr1->firstName,change_firstname); //data updated
	tmpr1->firstName[MAXNUM-1]='\0';

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);					
}

// this function changes the last name of the speaker
void change_lastName(struct speaker *tmpr1)
{
	char garbage='a';
	char change_lastname[MAXNUM]={};
	printf ("You chose to change the last name of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the last name of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	scanf ("%s", &change_lastname); 
	
	strcpy(tmpr1->lastName, change_lastname); //data updated
	tmpr1->lastName[MAXNUM-1]='\0';

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);
}


// this function changes the title of the speech or the performance of the speaker
void change_titleName(struct speaker *tmpr1)
{
	char garbage='a';
	char change_name[MAX]={};
	printf ("You chose to change the title of the speech or performance of the speaker. Beware!!! Updating here, changes everywhere else.\n");
	printf ("Please Enter the title of the speech of the speaker. Remember the instructions.Please Enter.\n");
	scanf ("%c", &garbage);
	fgets(change_name, MAX, stdin);
	strcpy(tmpr1->titleName, change_name); //data updated
	tmpr1->titleName[MAX-1]='\0';

	printf ("Update Successful. The new set of data of the speaker is as follows:\n");
	printSingle(tmpr1);					
}

// this function changes the number of tickets or seats 
void change_number_tickets_seats(struct speaker *tmpr1)
{
	printf ("You chose to change the number of ticket or seats sold.\n");

	if(tmpr1->eventPrice==FREE)
	{
		printf ("You are going to change the number of seats. Please enter the right number of seats.\n");
		scanf ("%d", &tmpr1->eventSeats.total_seats);
		printf ("You changed the data. The new data looks like this:\n");
		printSingle(tmpr1);
	}
	else
	{
		printf ("You are going to change the number of tickets sold. Please enter the right number of tickets.\n");
		scanf ("%d", &tmpr1->eventSeats.tickets_sold);
		printf ("You changed the data. The new data looks like this:\n");
		printSingle(tmpr1);
	}
}
// this function sorts all data by speaker code
struct speaker *sort_by_speaker_code(struct speaker *begin)
{
	printf ("You chose the menu option to sort array by speaker code.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(begin);
	begin= bubblesort(begin);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(begin);
return begin;
}

// this function sorts all data by speaker code
struct speaker *selection_sort_by_lastName(struct speaker *begin)
{
	printf ("You chose to sort array by last name of the speaker using selection SORT.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(begin);
	begin= selectionsort_lastName(begin);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(begin);
	return begin;

}

// this function sorts all the data by performance date
struct speaker *sort_by_perfomance_date(struct speaker *begin)
{
	printf ("You chose the menu option to sort array by performance date.\n");
	printf ("The arrays BEFORE SORTING are:\n");
	printArray(begin);
	begin = bubblesort_performance(begin);
	printf ("The arrays AFTER SORTING are:\n");
	printArray(begin);
	return begin;

}

// this function search the speakers by last name
struct speaker *search_speaker_by_lastname(struct speaker *begin)
{
	int found=0,choice=1;
	char garbage;
	char keyword[40];
	struct speaker *travel=NULL;
	struct speaker *trailer=NULL;
	printf ("You entered to search the speaker by their last name using linear SEARCH.\n");
	//begin=selectionsort_lastName(begin);// first sorts the list of lastname before searching lastname
	printf ("The list has been already sort by lastName using selection sort for the linear search.\n");	

	printf ("Enter the last name you wish to search.\n");
	scanf ("%c", &garbage);	
	scanf ("%s", &keyword);

	
	travel=begin;
	while( (travel!=NULL))
	{
		if(strcmp(travel->lastName,keyword)==0)
		{
			found=1;
			printf("..................................................................\n");
			printf("Match found!! The result is displayed below:\n");
			printSingle(travel);
			printf("..................................................................\n");
			
			
		}
		travel=travel->next;
	}
	if(found==0)
	{
		printf("No match found..Sorry. Returned to main menu.\n");
	}
return begin;
}

// this function sorts the array using bubble sort technique
struct speaker *bubblesort(struct speaker *begin)
{
	struct speaker *forward=NULL;
	struct speaker *first=NULL;
	struct speaker *trailer=NULL;
	struct speaker *travel=NULL;
    int still_changing;

    do
    {
        still_changing = 0;
		trailer=begin;
		travel=begin->next;
	
		if(travel!=NULL)
		{
			if(travel->speakerCode<trailer->speakerCode)	
			{
				begin=travel;
				first=begin;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				still_changing=1;
				
			}
			else
			{
				first=begin;
				trailer=travel;
				travel=travel->next;
			}
		}

		while(travel!=NULL)
		{
			if(travel->speakerCode<trailer->speakerCode)
			{
				first->next=travel;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				first=first->next;
				still_changing=1;
			}
			else
			{
				first=first->next;
				trailer=travel;
				travel=travel->next;
			}
		}
		
    } while (still_changing);
return begin;	


	
}



// this function sorts array using bubble sort technique for performance date
struct speaker *bubblesort_performance(struct speaker *begin)
{
	
struct speaker *forward;
	struct speaker *first;
	struct speaker *travel;
	struct speaker *trailer;
    int still_changing;

    do
    {
        still_changing = 0;
		trailer=begin;
		travel=begin->next;
		
		if(travel!=NULL)
		{
			if( (	(travel->pyear==trailer->pyear)	&&	(travel->pmonth==trailer->pmonth)	&&	(travel->pday<trailer->pday)	) ||	(	(	travel->pyear==trailer->pyear	)	&&	(travel->pmonth<trailer->pmonth)	)	||	(travel->pyear<trailer->pyear)	)
			{
				begin=travel;
				first=begin;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				still_changing=1;
			}
			else
			{
				first=begin;
				trailer=travel;
				travel=travel->next;
			}
		}

		while(travel!=NULL)
		{
			if( (	(travel->pyear==trailer->pyear)	&&	(travel->pmonth==trailer->pmonth)	&&	(travel->pday<trailer->pday)	) ||	(	(	travel->pyear==trailer->pyear	)	&&	(travel->pmonth<trailer->pmonth)	)	||	(travel->pyear<trailer->pyear)	)
			{
				first->next=travel;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				first=first->next;
				still_changing=1;
			
			}
			else
			{
				first=first->next;
				trailer=travel;
				travel=travel->next;
			}
		}
		
    } while (still_changing);
	
		
return begin;	


}
// this function sorts the data by last name
struct speaker *selectionsort_lastName(struct speaker *begin)
{
	
struct speaker *forward=NULL;
	struct speaker *first=NULL;
	struct speaker *trailer=NULL;
	struct speaker *travel=NULL;
    int still_changing;

    do
    {
        still_changing = 0;
		trailer=begin;
		travel=begin->next;
		

		if(travel!=NULL)
		{
			if(	strcmp(	trailer->lastName,travel->lastName)>0)	
			{
				begin=travel;
				first=begin;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				still_changing=1;
				
			}
			else
			{
				first=begin;
				trailer=travel;
				travel=travel->next;
			}
		}

		while(travel!=NULL)
		{
			if(	strcmp(	trailer->lastName,travel->lastName)>0)	
			{
				first->next=travel;
				forward=travel->next;
				travel->next=trailer;
				trailer->next=forward;
				travel=forward;
				first=first->next;
				still_changing=1;
			
			}
			else
			{
				first=first->next;
				trailer=travel;
				travel=travel->next;
			}
		}
		
    } while (still_changing);
return begin;	

}



// linear search
struct speaker *linear_search_lastName(struct speaker *begin, char nameSearch[MAXNUM])
{
	struct speaker *tmpr=begin;
	while(tmpr!=NULL)
	{
		if((strcmp(nameSearch, tmpr->lastName))==0)
		{
			printf ("Match Found.\n");

			printSingle(tmpr);
		}
		tmpr=tmpr->next;
	}
	return begin;
}

