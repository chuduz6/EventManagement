

#include<iostream>
#include<string.h>
#include<iomanip>
#include "event.h"

#define NAMEMAX 75
#define ROOMMAX 20
#define BUILDINGMAX 5
using namespace std;
//prototype of function-------------------------
void menuEventpurpose(void);
bool chktime_min(float time);
bool chkdate_2(int month, int date);
void menuEventtype(void);
//-----------------------------------------------
// definition of the function declared in the main----------------------------------

// initialization of the of the event
event :: event()
	{
	eventName = new char[NAMEMAX];
	eventRoom = new char[ROOMMAX];
	eventBuilding = new char[BUILDINGMAX];
	
	// initialing the variables
	
	eventNum = 0;
	strcpy(eventName, "aa");
	eventType = 'C';
	eventPurpose = 'C';
	eventTime= 0;
	eventDay= 0;
	eventMonth = 0;
	eventSize = 0;
	eventCost = 0;
	strcpy(eventBuilding, "aa");
	strcpy(eventRoom, "aa");
	eventLength = 0;
	goal = networking;
	attended = 0;
	predict= 0;
}
/*
event :: ~event()
{	
	delete[] eventName;
	delete[] eventBuilding;
	delete[] eventRoom;
}
*/
// bool for the checking and the event number and returning the bollen value

bool event :: set_Num( int event)
{
    while (!(event==842 || event==110 || event==120 || event==130 || event==140 || event==500 || event==803 || event==810 || event==874 || event==990 || event==318 || event==337 || event==301 || event==554 || event==868 || event==935 || event==4 || event==8 || event==10))
      {
       //menuEventcode();
       cout<<"Enter the valid Event number from the above list"<<endl;
       cin>>event;
      }
    eventNum=event;
	return true;
}

// bool for the checking and the event Name and returning the bollen value

bool event :: set_Name ( char name [])
{
	//char *temp = new char [strlen(name)+1];
	if (strlen(name)>(NAMEMAX-1))
	{
		
		strcpy(eventName, "The default");
		return false;
	}
//strcpy(temp, name);
//delete[] eventName;
strcpy(eventName, name);
//eventName = temp;
return true;
}


// bool for the checking and the event type and returning the bollen value


bool event :: set_Type ( char type)
{
      while (!(type=='C' || type=='S' || type=='P' || type=='N' || type=='D' || type=='L' || type=='B' || type=='O'))
      {
       menuEventtype();
       cout<<"Enter the valid Event type from the above list"<<endl;
       cin>>type;
      }
	  eventType = type;
	  predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
      return true;
}

// bool for the checking and the event purpose and returning the bollen value

bool event :: set_Purpose (char event)
{
     while (!(event=='F' || event=='M' || event=='C' || event=='S' || event=='V' || event=='L' || event=='E' || event=='A' || event=='P' || event=='O'))
      {
	  menuEventpurpose();
       cout<<"Enter the valid Event purpose from the above list"<<endl;
       cin>>event;
      }
	  eventPurpose = event;
	  predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
     return true;
}

// bool for the checking and the event time and returning the bollen value

bool event :: set_time( float time)
{
    int first_half;
    float second_half;
    first_half=(int) time;
    second_half=(time - first_half);
    if ((first_half >= 0 && first_half<24) && (second_half>= 0 && second_half<.60))
    {
	eventTime = time;
     return true;
    }
    else
    {
     while(chktime_min(time))
     {
     cout<<"Please enter the valid time as a 24 hours format";
     cin>>time;
     }
	 eventTime = time;
     return true;
     }
}

// bool for the checking and the event day and returning the bollen value

bool event:: set_Day( int month, int date)
{
    int buffer;
    if (month==2 && (date>0 && date<=28))
    {
	  eventDay = date;
      return true;

    }
    else if ((month==9 || month==4 || month==6 || month==11) && (date>0 && date<=30))
    {
     eventDay = date;
      return true;

    }
    else if ((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (date>0 && date<=31))
    {
     eventDay = date;
      return true;

    }
    else
    {
     while (chkdate_2(month, date))
     {
     cout<<"Please enter the valid date aa"<<endl;
     cin>>date;
     }
     eventDay = date;
      return true;
     }
}

// bool for the checking and the event month and returning the bollen value

bool event:: set_Month(int month)
{
     while (month<1 || month>12)
     {
     cout<<"Please enter the valid month";
     cin>>month;
     }
     eventMonth= month;
     return true;
     
}


// bool for the checking and the event size and returning the bollen value

bool event:: set_Size (int size)
{
    while (size < 0)
    {
        cout<<"It is an invalid event size. Enter a valid size of the event"<<endl;
        cin>>size;
    }
	eventSize = size;
	predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
    return true;
}

// bool for the checking and the event cost and returning the bollen value

bool event :: set_Cost (float cost)
{
    while (cost < 0)
    {
          cout<<"It is an invalid event cost. Enter a valid size of the event"<<endl;
          cin>>cost;
    }
	eventCost = cost;
    return true;
}

// bool for the checking and the event building and returning the bollen value

bool event :: set_Building( char building [])
{
	//char *temp = new char [strlen(building)+1];
	if (strlen(building)>(BUILDINGMAX-1))
	{
		
		strcpy(eventBuilding, "AAA");
		return false;
	}
//strcpy(temp, building);
//delete[] eventBuilding;
strcpy(eventBuilding, building);
//eventBuilding = temp;
return true;
}

// bool for the checking and the event length and returning the bollen value

bool event :: set_Length(int buffer)
{
     while (buffer<1)
     {
     cout<<"Enter the length of the event in minute.";
     cin>>buffer;
     }
	 eventLength = buffer;
     return true;
}

// bool for the checking and the event goal and returning the bollen value

bool event :: set_Goal(int check)
{
    while (check<0 && check >6)
    {
    cout<<"Enter the value for the event goal."<<endl;
    cin>>check;
    }
	switch(check)
	{
	case 0: goal=networking; break;
	case 1: goal=recruiting; break;
	case 2: goal=charitable; break;
	case 3: goal=general; break;
	case 4: goal=talent; break;
	case 5: goal=service; break;
	}
	predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
    return true;
}

// bool for the checking and the event room and returning the bollen value

bool event :: set_Room( char room[])
{
	//char *temp = new char [strlen(room)+1];
	if (strlen(room)>(ROOMMAX-1))
	{
		
		strcpy(eventRoom, "RRR");
		return false;
	}
//strcpy(temp, room);
//delete[] eventRoom;
strcpy(eventRoom, room);
//eventRoom = temp;
return true;
}

// bool for the checking and the event attended and returning the bollen value


bool event :: set_Attended( int buffer)
{
	if (buffer<=0)
	{
	attended = -1;
	predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
	return false;
	}
	attended = buffer;
	predict_attendance( eventPurpose, eventType, goal, eventSize, attended);
    return true;
}

// bool for the checking and the target value and returning the bollen value

bool event :: set_Target_general(float goal)
{
	tar.g_fund = goal;
	return true;
}

bool event :: set_Target_charity(float goal)
{
	tar.c_fund = goal;
	return true;
}

bool event :: set_Target_talent(char goal)
{
	tar.talent_demo = goal;
	return true;
}

bool event :: set_Target_services(int goal)
{
	tar.com_serv =goal;
	return true;
	
}

bool event :: set_Target_networking(int goal)
{
	tar.social_net = goal;
	return true;
}

bool event :: set_Target_recruiting(int goal)
{
	tar.recruit = goal;
	return true;
}

// this is the function call by the chkData function specially for the while loop

bool chkdate_2(int month, int date)
{
    if (month==2 && (date>0 && date<=28))
    {
      return false;

    }
    else if ((month==9 || month==4 || month==6 || month==11) && (date>0 && date<=30))
    {
     return false;

    }
    else if ((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (date>0 && date<=31))
    {
     return false;

    }
    else return true;
}

// bool for the checking and the event time and returning the bollen value

bool chktime_min(float time)
{
    int first_half;
    float second_half;
    first_half=(int) time;
    second_half=(time - first_half);
    if ((first_half >= 0 && first_half<24) && (second_half>= 0 && second_half<.60))
    {
     return false;
    }
    else
    return true;
}

// the function for printing the data in the array

void event :: printArray()
{
	cout << eventName<<endl;
	cout <<setw(3)<<fixed<<eventNum<<setw(5)<<eventPurpose<<setw(7)<<eventType<<setw(7);
	cout<<fixed<<setprecision (2)<<eventTime<<setw(7)<<eventDay<<setw(5)<<eventMonth<<setw(10)<<eventSize<<setw(10)<<setprecision (2)<<eventCost<<setw(7)<<eventBuilding<<setw(25)<<eventRoom<<setw(7)<<eventLength<<setw(7)<<goal<<setw(7);
	if (goal == networking)
	{
	cout<<tar.social_net;
	}
	if (goal == recruiting)
	{
	cout<<tar.recruit;
	}
	if (goal == charitable)
	{
	cout<<tar.c_fund;
	}
	if (goal == general)
	{
	cout<<tar.g_fund;
	}
	if (goal == talent)
	{
	cout<<tar.talent_demo;
	}
	if (goal == service)
	{
	cout<<tar.com_serv;
	}
	cout<<setw(7)<<attended<<setw(10)<<predict<<endl<<endl;
	
}

//--------------------------------- the predicted attendance for the function-----------------------------------

void event :: predict_attendance( char pur, char typ, int gol, int siz, int atten)
{
	if (typ == 'C' || typ == 'S' || typ == 'O'){
		if(pur == 'F' || pur == 'M' || pur == 'C' || pur == 'S' ){
			if (gol == charitable || gol == general || gol == service){
				if (atten == -1){
					predict = (int)(.75 * (siz));
				}else{
					predict = int (1.2 * atten);
					}
			}
			
		else if (gol == recruiting || gol == talent || gol == networking){
			if (atten == -1){
				predict = (int) (.45 * (siz));
			}else{
				predict = int (1.05 * atten);
				}
			}
		}else if(pur == 'V' || pur == 'L' || pur == 'E' || pur == 'A' || pur == 'P' || pur == 'O' ){
			if (atten == -1){
					predict = (int) (.40 * (siz));
			}else{
				predict = int (1.03 * atten);
				}
			}
	}else if (typ == 'P' || typ == 'N'){
		if(pur == 'F' || pur == 'V'|| pur == 'S' ){
			if (gol == recruiting || gol == service || gol == networking){
				if (atten == -1){
					predict = (int) (.60 * (siz));
				}else{
					predict = (int) (1.1 * (atten));
					}
			}
			
		}else if (gol == charitable || gol == general || gol == talent){
			if (atten == -1){
				predict = (int) (.45 * (siz));
			}else{
				predict = (int) (1.05 * (atten));
				}
			
		}else if(pur == 'M' || pur == 'L' || pur == 'C' || pur == 'A' || pur == 'P' || pur == 'O' || pur == 'E' ){
			if (atten == -1){
					predict = (int) (.50 * (siz));
			}else{
				predict = (int) (1.08 * (atten));
				}
			}
	}else if (typ == 'D' || typ == 'L' || typ == 'B'){
		if(pur == 'M' || pur == 'C' || pur == 'S' || pur == 'V' || pur == 'O'){
			if (atten == -1) {
					predict = (int) (.85* (siz));
				}else{
					predict = (int) (1.4 * (atten));
					}
			}
			
		else if(pur == 'F' || pur == 'L'|| pur == 'E' || pur == 'A' || pur == 'P' ){
			if (gol == service || gol == networking ){
			if (atten== -1){
				predict = (int)(.65* (siz));
			}else{
				predict = (int)(1.18 * (atten));
				}
			}
			
		}else if(gol == recruiting || gol == talent || gol == charitable || gol == general ){
			if (atten == -1){
					predict = (int)(.50 * (siz));
				predict = (int)(1.08 * (atten));
				}
			}
	  }
	
		
	
}
//--------------------------------- display event purpose--------------------------------

void menuEventpurpose(void)
{
       cout<<"**Event Purpose**\n"<<endl;
       cout<<" F - fun and social event,\n M - fine arts event; music, dance, art, theatre, comedy, and other types of arts activities,\n C - cultural; offers support and education related to a specific culture or group of cultures,\n S - sports; opportunities to play or support teams,\n V - volunteer event that does service activities of any type,\n L - leadership; opportunities for leadership on campus or learning skills for leadership,\n E - educational; offers some discipline-related content for student,\n A - academic; offers some sort of academic focused purpose such as tutoring, mentoring, study group, etc.\n, P - professional; focused on providing support to student for future professions,\n O - other"<<endl<<endl;
}

//------------------------------ display menu function--------------------------------------

void menu ()
{
	cout<<endl<<"********* Main Menu ***********"<<endl;
	cout<<"A.	Sort the event by"<<endl;
	cout<<"			1.Code Number"<<endl;
	cout<<"			2.Name"<<endl;
	cout<<"B.	Search by"<<endl;
	cout<<"			3.Event date"<<endl;
	cout<<"			4.Group Purpose"<<endl<<endl;
	cout<<"			5.List all the event"<<endl;
	cout<<"			6.EXIT"<<endl;
}


//--------------------------------Display Event type List --------------------------------------------

void menuEventtype(void)
{
     cout<<"**Event Type List**"<<endl<<endl;
     cout<<"C Concert, S Spectator, P Participatory | Competitive,\nN Participatory | Non-Competitive, D Dinner, L Lunch, B Breakfast, O Other"<<endl<<endl;

}



