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
// declaration of enum
enum typeofevent
{FREE=0,PAID=1};

// declaration of union
union typeofevent1
{
	int tickets_sold;
	int total_seats;
};

// the class declaration
class event 
{
	// public for the class
public:
	event();
	void printSingle();

	// set functions 
	bool set_speakerCode(int code);
	bool set_pday(int day);
	bool set_pmonth(int month);
	bool set_pyear(int year);
	bool set_pTime(float time);
	bool set_seriesCode(char sCode);
	bool set_ebirdPrice(float ePrice);
	bool set_regPrice(float rPrice);
	bool set_stateName(char state[]);
	bool set_expertiseCode(char eCode);
	bool set_bday(int day1);
	bool set_bmonth(int month1);
	bool set_byear(int year, int year1);
	bool set_firstName(char fName[]);
	bool set_lastName(char lName[]);
	bool set_eventPrice(float ePrice, float rPrice);
	bool set_tickets_sold(int num);
	bool set_total_seats(int num);
	bool set_titleName(char tName[]);

	// is functions 
	int speakerCode_is() const{return speakerCode;}
	int pday_is() const{return pday;}
	int pmonth_is() const{return pmonth;}
	int pyear_is() const{return pyear;}
	float pTime_is() const {return pTime;}
	char seriesCode_is() const {return seriesCode;}
	float ebirdPrice_is() const {return ebirdPrice;}
	float regPrice_is() const {return regPrice;}
	const char *stateName_is() const {return stateName;}
	char expertiseCode_is() const {return expertiseCode;}
	int bday_is() const{return bday;}
	int bmonth_is() const{return bmonth;}
	int byear_is() const{return byear;}
	const char *firstName_is() const {return firstName;}
	const char *lastName_is() const {return lastName;}
	int eventPrice_is() const {return eventPrice;}
	int total_seats_is() const {return eventSeats.total_seats;}
	int tickets_sold_is() const {return eventSeats.tickets_sold;}
	const char *titleName_is() const {return titleName;}


	// the private and the variable definitions
private:
	int speakerCode;
	int pday;
	int pmonth;
	int pyear;
	float pTime;
	char seriesCode;
	float ebirdPrice;
	float regPrice;
	char *stateName;
	char expertiseCode;
	int bday;
	int bmonth;
	int byear;
	char *firstName;
	char *lastName;
	char *titleName;
	union typeofevent1 eventSeats;
	enum typeofevent eventPrice;

};

