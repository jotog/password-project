#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
// method prototypes
void StateInstructions();
void GetInput();
double ComputeMonthlyPayment();
void ReportResults(double result);

// global variables shared by more than one method
double dblPrincipal, dblRate, dblYears;   

int main()
{ 
   double answer;

   StateInstructions();
   GetInput();
   answer = ComputeMonthlyPayment(); 
   ReportResults(answer);
}
    
// gives an overview to user
void StateInstructions()
{
   string instructions;
   instructions = 
      "The following program will calculate the \n"
      "monthly payment  required for a loan of D dollars \n"
      "over a period of Y years at an annual \n"
      "interest rate of R%.\n";
   cout << instructions;
}

// gets input
void GetInput()
{
   string prompt;

   // get principal
   prompt = "\nEnter amount of the loan. (only use numbers, \n"
      "please, no commas or characters like '$')\n"
      "Your loan amount: ";
   cout << prompt;
   cin >> dblPrincipal;
   
   // get interest
   prompt = "\nNow enter the interest rate (If the quoted rate is 6.5%, \n"
      "for example, enter 6.5 without the %.)\n"
      "Your annual interest rate: ";
   cout << prompt;
   cin >> dblRate;

   // get length of loan
   prompt = "\nEnter term of the loan in years: ";
   cout << prompt;
   cin >> dblYears;
}

// computes and returns answer
double ComputeMonthlyPayment()
{
   double dblTemp, dblPmt, dblMoRt, dblMonths;
   
   // convert to years months
   dblMonths = dblYears * 12;
   
   // convert rate to decimal and months
   dblMoRt = dblRate / (100 * 12);
   
   // use formula to get result
   dblTemp = pow(1 + dblMoRt, dblMonths);
   dblPmt = dblPrincipal * dblMoRt * dblTemp 
      / ( dblTemp - 1 );

   // now that we have computed the payment, return it
   return dblPmt;
}

// displays results and sign off
void ReportResults(double result)
{
   string signoff;
   signoff = 
      "\nThanks for using the Foothill Mortgage &lt;. \n"
      "We hope you'll come back and see us again, soon.\n\n";

   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "\nYour Monthly Payment: $" << result << endl;

   cout << signoff;
}