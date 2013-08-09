#include <iostream>

using namespace std;

int main()
{
   int subject_lbs, minutes, MET;                 //Defines integer variables.
   double subject_kg, total_calories;             //Defines double variables.

   //Sets decimal digit precision to 4 instead of 3.
   cout.setf(ios::fixed);       
   cout.precision(4);

   //Asks and grabs the value of the user's weight. Stores it in subject_lbs.
   cout << "Please enter your weight in pounds: ";
   cin >> subject_lbs;

   //Asks and grabs the number of METs for an activity. Stores it in MET.
   cout << "Enter the number of METs for your activity: ";
   cin >> MET;

   //Asks and grabs the user's amount of time for the activity. Stores it in minutes.
   cout << "Enter the amount of minutes spent doing the activity: ";
   cin >> minutes;

   //Equation to convert user's weight in lbs. to kg.
   subject_kg = subject_lbs * 2.2;        
   
   //Equation for Total Calories burned during activity.
   total_calories = 0.0175 * MET * subject_kg * minutes;

   // Outputs the user's estimated burned calories.
   cout << "Excellent! You burned: " << total_calories << " calories." << endl;

   //End greeting.
   cout << "Keep it up! :)" << endl;

   return 0;
}

/*------------Paste of Run------------

Please enter your weight in pounds: 135
Enter the number of METs for your activity: 10
Enter the amount of minutes spent doing the activity: 30
Excellent! You burned: 1559.2500 calories.
Keep it up! :)
Press any key to continue . . .

-------------------------------------*/