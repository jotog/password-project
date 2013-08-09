#include <iostream>
using namespace std;

#define INITIAL_RENT 1700

int main()
{
   double mo_rate, yr_rate, orig_pay, pay, principal, amount_saved;
   int num_months, months_saved;
   const double xtra_amount = 250;

   principal = 465254;   //remaining principal at the moment
   yr_rate = .06;       //6%
   orig_pay = 2998;      //fixed monthly pay bank ordered you to pay

   //convert % to monthly values
   mo_rate = yr_rate / 12;

   pay = orig_pay + xtra_amount;
   num_months = 0;

   while (principal > 0)
   {
      //start with interest charge to principal:
      principal *= (1+mo_rate);

      //now make payment
      principal -= pay;
      num_months++;

      //every 12mo. print out balance
      if (num_months%12 == 0)
         cout << "Balance after " << num_months 
            << " months = $" << principal << "." << endl;
   }

   cout << "You paid off the loan in " << num_months << " months." << endl;

   months_saved = 300 - num_months;    //25yrs less the actual time
   amount_saved = 300 * orig_pay - num_months * pay;

   cout<< "You paid it off " << months_saved << " months early.\n";
   cout << "You saved $" << amount_saved << "." << endl;

   return 0;
}

