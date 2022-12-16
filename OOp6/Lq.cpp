/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Programmer: OSAMA MALIK                      Reg No~ 4319-FBAS-BSSE/F21                            Project: AirTime        /////
Teacher Name: Sir NADEEM                       osamamaliktoru@gmail.com                            Date: 10-18-2022        /////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cmath>
//#pragma warning (disabled:4996)
#include <iomanip>

using namespace std;

class AirTime
{
	unsigned int hrs, min, sec;
public:
	AirTime (unsigned int h=0, unsigned int m=0, unsigned int s=0):hrs(h), min(m), sec(s){}    //Constructor
	void setTime();            //Fetch time from User
	void SetTime();            //Fetch Time from System
	void displayTime();        //Display Time

	/*********Operator Overloading***********/
	AirTime operator-(const AirTime &TT1);
	AirTime operator-=(const AirTime &TT1);
	AirTime operator+(const AirTime &TT1);
	bool operator>(const AirTime &T);
	bool operator<(const AirTime &T);
	AirTime operator+=(const AirTime &T);
	AirTime operator++();                  //Prefix Incriment
	AirTime operator++(int);               //Prefix Incriment
	AirTime operator--();
	AirTime operator--(int);

	~AirTime (){cout<<"Destroyed"<<endl;}
};
//////////////////////  Menually Set Time  //////////////////////////
void AirTime::setTime()       //
{
	do{
	cout<<"Enter the Hours(24 hrs format): ";
	cin>>hrs;
	} while (!((hrs>=0) && (hrs<24)));
	do{
	cout<<"Enter the Minutes(1-59): ";
	cin>>min;
	} while (!((min>=0) && (min<60)));
	do{
	cout<<"Enter the Seconds(1-59): ";
	cin>>sec;
	} while (!((sec>=0) && (sec<60)));
}
///////////////////////  System Time  ///////////////////////////////
void AirTime::SetTime()              
{
	time_t now= time(0);
	tm* local_time= localtime(&now);

	hrs=local_time->tm_hour;
	min=local_time->tm_min;
	sec=local_time->tm_sec;
	//return now;
}
///////////////////////  Display Time  ///////////////////////////////
void AirTime::displayTime(){         
	cout<<"Time is: "
		<<setw(2)
		<<setfill('0')
		<<hrs <<":"
		<<setw(2)
		<<setfill('0')
		<<min<<":"
		<<setw(2)
		<<setfill('0')
		<<sec<<endl;
	
}
///////////////////////  Stay Time   ///////////////////////////////    
AirTime AirTime::operator-(const AirTime &TT1)                     
{
	AirTime Temp;	
	if(sec<TT1.sec)
	{
		sec=sec+60;
		--min;
	}
	Temp.sec= sec-TT1.sec;

	if(min<TT1.min)
	{
		min=min+60;
		--hrs;
    }
	Temp.min= min-TT1.min;
	
	if(hrs<TT1.hrs)
		hrs=hrs+12;
	Temp.hrs= hrs-TT1.hrs;	
	return Temp;
}
////////////////////////  Stay Time and overwrite T2 ///////////////
AirTime AirTime::operator-=(const AirTime &TT1)           
{
    if(sec<TT1.sec)
	{
		sec=sec+60;
		--min;
	}
	sec-=TT1.sec;
	
	if(min<TT1.min)
	{
		min=min+60;
		--hrs;
    }
	min-=TT1.min;

	if(hrs<TT1.hrs)
		hrs=hrs+12;
	hrs-=TT1.hrs;
	return *this;
}
///////////////////////// Add Time //////////////////////////////////
AirTime AirTime::operator+(const AirTime &TT1)           
{
	AirTime Temp;
	int a,b;
	a= sec+TT1.sec;
	Temp.sec= a%60;
	b=(a/60)+min+TT1.min;
	Temp.min= b%60;
	Temp.hrs= (b/60)+hrs+TT1.hrs;
	Temp.hrs=Temp.hrs%24;
	return Temp;
}
////////////////////// Add Time and Overwrite Arrival Time ///////////////
AirTime AirTime::operator+=(const AirTime &T)               
{
	int a,b;
	a=sec+T.sec;
	sec= a%60;	
	b=(a/60)+min+T.min;
	min=b%60;
	hrs=(b/60)+hrs+T.hrs;
	hrs=hrs%24;
	return *this;
}
///////////////////////// Greater Time //////////////////////////////////
bool AirTime::operator>(const AirTime &T)                  
{
	if(hrs>T.hrs)
		return true;
	else if((hrs==T.hrs) && (min>T.min))
		return true;
	else if((hrs==T.hrs) && (min==T.min) && (sec>T.sec))
		return true;
	else
		return false;
}
///////////////////////// Lower Time //////////////////////////////////
bool AirTime::operator<(const AirTime &T)                  
{
	if(hrs<T.hrs)
		return true;
	else if((hrs==T.hrs) && (min<T.min))
		return true;
	else if((hrs==T.hrs) && (min==T.min) && (sec<T.sec))
		return true;
	else
		return false;
}
/////////////////// Prefix Incriment Time ///////////////////////////////
AirTime AirTime::operator++()                               
{
	++hrs;
	++min;
	++sec;
	return *this;
}
/////////////////// Postfix Incriment Time //////////////////////////////
AirTime AirTime::operator++(int)                                  
{
	AirTime Temp;
	Temp=*this;
	++hrs;
	++min;
	++sec;
	return Temp;
}
/////////////////// Prefix Decriment Time //////////////////////////////
AirTime AirTime::operator--()                               
{
	--hrs;
	--min;
	--sec;
	return *this;
}
/////////////////// Postfix Decriment Time //////////////////////////////
AirTime AirTime::operator--(int)                            
{
	AirTime Temp;
	Temp=*this;
	--hrs;
	--min;
	--sec;
	return Temp;
}
int main()
{
	AirTime T1(1,1,1),T2(2,2,2),T3;              //T1 for arrival && T2 for departure time    //T3 for Stay time
	int option;
	do{
		cout << "\t\t\t\t\t**********************************\n"
			 << "\t\t\t\t\t*            Main Menu           *\n"
			 << "\t\t\t\t\t**********************************\n"
			 << "\t\t\t\t\t| 1.Set Time                     |\n"
			 << "\t\t\t\t\t| 2.Display Time                 |\n"
			 << "\t\t\t\t\t| 3.Stay Time                    |\n"
			 << "\t\t\t\t\t| 4.Stay Time and overwrite T2   |\n"
			 << "\t\t\t\t\t| 5.Add Time                     |\n"
			 << "\t\t\t\t\t| 6.Add time and overwrite T1    |\n"
			 << "\t\t\t\t\t| 7.Greater time                 |\n"
			 << "\t\t\t\t\t| 8.Lower time                   |\n"
			 << "\t\t\t\t\t| 9.Prefix incriment time  T1    |\n"
			 << "\t\t\t\t\t| 10.Postfix incriment time T1   |\n"
			 << "\t\t\t\t\t| 11.Prefix decriment time T1    |\n"
			 << "\t\t\t\t\t| 12.Postfix decriment time T1   |\n" 
			 << "\t\t\t\t\t| 13.Exit                        |\n"
			 << "\t\t\t\t\t|________________________________|\n";
		cin>>option;
		switch (option){
			case 1:                                                  //Set Time
				do{
				cout<<"\n1.Arrival Time\n"
					<<"2.Departure time\n";
				cin>>option;
				}
				while(!((option>0) && (option<3)));
				switch(option)
				{
			        case 1:                                          //Set Arrival time
						do
						{
						cout<<"Press 1 for Set Menually\n"
							<<"Press 2 for System Time\n";
						cin>>option;
						}
						while(!((option>0) && (option<3)));
						switch(option)
						{
					    case 1:          //Menually Set
				        T1.setTime();
				        break;
		     			case 2:          //System Time
			            T1.SetTime();
			            break;
						}
					break;
			        case 2:                                           //Set Deparute Time
				    	do{
						cout<<"Press 1 for Set Menually\n"
							<<"Press 2 for System Time\n";
						cin>>option;
						}
						while(!((option>0) && (option<3)));
				        switch(option)
						{
					    case 1:           //Menually Set
				        T2.setTime();
				        break;
		     			case 2:
			            T2.SetTime();     //System Time
			            break;
				       }
					break;
		        }
			    break;
			case 2:                                                    //Display Time
				do{
				cout<<"\n1.Arrival Time\n"
					<<"2.Departure time\n";
				cin>>option;
				}
				while(!((option>0) && (option<3)));
				switch(option)
				{
			        case 1:
				    T1.displayTime();
				    break;

			        case 2:
				    T2.displayTime();
				    break;
				}
			    break;
			case 3:                                                    //Stay Time
				T3= T2-T1;
				T3.displayTime();
				break;
			case 4:                                                    //Stay Time and overwrite T2
				T3=T2-=T1;
				T3.displayTime();
				break;
			case 5:                                                    //Add Time
				T3= T1+T2;
				T3.displayTime();
				break;
			case 6:                                                    //Add Time in T1(Arrival Time)
				T3=T1+=T2;
				T3.displayTime();
				break;
			case 7:                                                    //Greater Time
				if(T1>T2)
					T1.displayTime();
				else
					T2.displayTime();
				break;
			case 8:                                                    //Lower Time
				if(T1<T2)
					T1.displayTime();
				else
					T2.displayTime();
				break;
			case 9:                                                    //Incriment T1 (prefix)
				T3=++T1;
				T3.displayTime();
				break;
			case 10:                                                    //Incriment T1 (postefix)
				T3=T1++;
				T3.displayTime();
				break;
			case 11:                                                   //Decriment T1 (prefix)
				T3=--T1;
				T3.displayTime();
				break;
			case 12:                                                   //Decriment T1 (postfix)
				T3=T1--;
				T3.displayTime();
				break;
			case 13:                                                  
				exit(0);
				break;
			default:
				cout<<" invalid option...!!\n";
				}	//system("cls");	
} while (true);

}
