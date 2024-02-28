#include <iostream>
using namespace std;
int main(){
  double sales = 95000;
  double stateTax = 0.04*sales;
  double countyTax = 0.02*sales;
  double total = sales + stateTax + countyTax;
  cout << "Sales: $" << sales << endl
  << "State Tax: $" << stateTax << endl
  << "County Tax: $" << countyTax << endl
  << "Total Tax: $" << stateTax + countyTax << endl
  << "Total Sales: $" << total << endl;
  
}