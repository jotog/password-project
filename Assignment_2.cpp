#include <iostream>
#include <string>
using namespace std;

//lists the functions that are to be used and their variables
void GreetUser();
double CalculateHat(double height, double weight);
double CalculateJacket(double height, double weight, int age);
double CalculateWaist(double weight, int age);
void ReportResults(double HatSize, double JacketSize, double WaistSize);

//main function
int main()
{
   //starts with the greetuser() function to display it first.
   GreetUser();

   double HatSize, JacketSize, WaistSize, height, weight;
   int age;
   string prompt; //for the prompts
   char answer;   //for user answer to questions
   //the larger do loop is so that the whole program can be looped in order to restart it.
   do
   {
      do      //this 2nd do loop is to ask the user if they made any errors and loops only the user input segment
      {
         do   //loop for height
         {
         prompt = "Please enter your height in inches. \n(only use positive numeric values, no commas): ";
         cout << prompt;
         cin >> height;
         }  while (height < 0);

         do   //loop for weight
         {
         prompt = "\nNow enter your weight in pounds. \n(only use positive numeric values, no commas): ";
         cout << prompt;
         cin >> weight; //store in weight
         } while (weight <=10);

         do   //loop for age
         {
         prompt = "\nFinally, enter your age in years. (only use positive numeric valuse, no commas): ";
         cout << prompt;
         cin >> age; //store in age
         } while (age < 0);

         prompt = "\nDid you make any sort of mistakes?" //asks the user if they made a mistake
         "\nType Y for yes and N for no: ";
         cout << prompt;
         cin >> answer;
         }  while (answer == 'y' || answer == 'Y');   //any choices other than y or Y will continue the program with user input

      //program continues with these functions
   HatSize = CalculateHat(height, weight);
   JacketSize = CalculateJacket(height, weight, age);
   WaistSize = CalculateWaist (weight, age);
   ReportResults(HatSize, JacketSize, WaistSize);

   //asks the user if they want to run it for someone else.
   prompt = "\n\nDo you wish to calculate sizes for another person? "
      "\nType Y for yes and N for no: ";   
   cout << prompt;
   cin >> answer;
   } while (answer == 'y' || answer == 'Y');

   cout << "\n\nGood bye!\n\n";  //any choices other than y or Y will terminate the program.
   return 0;

}

// function to greet the user to the program
void GreetUser()
{
   string instructions;
   instructions = 
      "Welcome! This program will calculate your \n" 
      "hat, jacket, and waist size. \n" 
      "We can do this by just using your height, weight, and age.\n\n";
   cout << instructions;
}

//calculates Hat size and sends it back
double CalculateHat(double height, double weight)
{
   double HatSize;
   HatSize = (weight / height) * 2.9;  //formula for hat sizes

   return HatSize;
}
//caluclates the jacket size and sends it back
double CalculateJacket(double height, double weight, int age)
{
   double JacketSize;
   JacketSize = (height * weight ) / 288; //formula for jacket size
   if (age >= 30)   //the adjustment for jacket size
      JacketSize = JacketSize + ((age - 30)/10) * (0.125);

   return JacketSize;
}
//calculates the waist size and send it back
double CalculateWaist(double weight, int age)
{
   double WaistSize;
   WaistSize = ( weight / 5.7 ); //formula for waist size
   if (age >= 28)
      WaistSize = WaistSize + ((age - 28)/2) * (0.10);   //waist size adjustment

   return WaistSize;
}
//reports the results to the screen
void ReportResults(double HatSize, double JacketSize, double WaistSize)
{
   string goodbye;

   goodbye = "\n\nThank you for using the Foothill Size Calculator! "
      "\nCome back for all your hat, jacket, and waist sizing needs!\n\n";
   cout << goodbye;
   cout.setf(ios::fixed);  //sets precision to 2 decimal places
   cout.precision(2);
   cout << "Your Hat Size is: " << HatSize << endl;
   cout << "Your Jacket Size is: " << JacketSize << endl;
   cout << "Your Waist Size is: " << WaistSize << endl;

}


/*---------------------------------------- Paste of Run -------------------------------------------------------------------
Welcome! This program will calculate your
hat, jacket, and waist size.
We can do this by just using your height, weight, and age.

Please enter your height in inches.
(only use positive numeric values, no commas): 72

Now enter your weight in pounds.
(only use positive numeric values, no commas): 140

Finally, enter your age in years. (only use positive numeric valuse, no commas):
 20

Did you make any sort of mistakes?
Type Y for yes and N for no: n


Thank you for using the Foothill Size Calculator!
Come back for all your hat, jacket, and waist sizing needs!

Your Hat Size is: 5.64
Your Jacket Size is: 35.00
Your Waist Size is: 24.56


Do you wish to calculate sizes for another person?
Type Y for yes and N for no: n


Good bye!

Press any key to continue . . .
--------------------------------------------------------------------------------------------------------------------------*/
