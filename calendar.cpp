#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
   int day; int month; int year;

   int leap[4]={0,5,3,1};

   int month_leap[12]={3,1,3,2,3,2,3,3,2,3,2,3};
   int month_normal[12]={3,0,3,2,3,2,3,3,2,3,2,3};

   cout<<"Enter the date for which day is to be calculated"<<endl;

   cin>>day;
   cin>>month;
   cin>>year;

   int oddDays=0;

   int h_years=year/100;

   oddDays=leap[h_years%4];

   cout<<oddDays<<endl;

   int leftOverYears=year-h_years*100;
   leftOverYears-=1;

   int leftOverYearsLeapYears=leftOverYears/4;
   int leftOverYearsNonLeapYears=leftOverYears-leftOverYearsLeapYears;

   oddDays=(oddDays +leftOverYearsLeapYears*2 + leftOverYearsNonLeapYears)%7;

   cout<<oddDays<<endl;

   if(year%4==0 || year%400==0) {
        for(int i=0;i<month-1;i++) {
            oddDays+=month_leap[i];
        }
   }
   else {
    for(int i=0;i<month-1;i++) {
            oddDays+=month_normal[i];
        }
   }
   oddDays%=7;

   cout<<oddDays<<endl;

   oddDays=(oddDays + day%7 )%7;

   cout<<oddDays<<endl;

   switch(oddDays) {
       case 0:
       cout<<"Sunday"<<endl;
       break;
       case 1:
       cout<<"Monday"<<endl;
       break;
       case 2:
       cout<<"Tuesday"<<endl;
       break;
       case 3:
       cout<<"Wednesday"<<endl;
       break;
       case 4:
       cout<<"Thursday"<<endl;
       break;
       case 5:
       cout<<"Friday"<<endl;
       break;
       case 6:
       cout<<"Saturday"<<endl;
   }

   return 0;
}
