/* Name: Dylan Nangle
   Assignment: HW 1
   Section: 109
   Date: 2/2/26
   Description: Order processing program for two types of monitors
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // Constants for calculations
  const double SAMSUNG_PRICE = 190.00;
  const double SONIC_PRICE = 170.00;
  const double DISCOUNT = 0.05;
  const double OHIO_TAX = 0.07;

  // Variables
  char monitor_type;
  int quantity; 
  double price;
  double discount;
  double subtotal = 0.0;
  double tax = 0.0;
  double total = 0.0;
  string ohio_resident;
  string brand;

  // Input
  cout << "Enter a monitor type (s,v) followed by a quantity: ";
  cin >> monitor_type >> quantity;

  // Error handling for monitor type
  if (monitor_type != 's' && monitor_type != 'v')
  {
    cout << "Error: Invalid monitor type" << endl;
    return EXIT_FAILURE;
  }
  // Define brand
  if (monitor_type == 's')
  {
    brand = "Samsung";
  }
  else 
  {
    brand = "ViewSonic";
  }

  // Error handling for quantity
  if (quantity <= 0)
  {
    cout << "Error: Invalid number of monitors" << endl;
    return EXIT_FAILURE;
  }

  // Calculate initial price
  if(monitor_type =='s')
    price = SAMSUNG_PRICE;
  else if (monitor_type == 'v')
  {
    price = SONIC_PRICE;

  }

  // Ohio resident tax
  cout << "Do you live in Ohio (yes/no)?";
  cin >> ohio_resident;

  // Error handling Ohio response
  if (ohio_resident != "yes" && ohio_resident != "no")
  {
    cout << "Please respond yes or no" << endl;
    return EXIT_FAILURE;
  }
  // Total price calculation
  subtotal = price * quantity;

  if (quantity >= 3)
        discount = subtotal * DISCOUNT;

  subtotal -= discount;

  if (ohio_resident == "yes")
        tax = subtotal * OHIO_TAX;

  total = subtotal + tax;
  
  // Format output
  cout << fixed << setprecision(2);
  cout << "\nMonitors Invoice\n";
  cout << "----------------------------------\n";
  cout << "Monitor brand: " << brand << endl;
  cout << "Quantity: " << quantity << endl;
  cout << "Price: $" << price << endl;
  cout << "Ohio Resident: ";
  if (ohio_resident == "yes")
  {
    cout << "Yes" << endl;
  }
  else 
  {
    cout << "No" << endl;
  }
  cout << "Total price: $" << price * quantity << endl;
  cout << "----------------------------------\n";
  cout << "Discount: $" << discount << endl;
  cout << "Subtotal: $" << subtotal << endl;
  cout << "Taxes: $" << tax << endl;
  cout << "==================================\n";
  cout << "Total: $" << total << endl;
  cout << "==================================\n";
  
  return EXIT_SUCCESS;
}