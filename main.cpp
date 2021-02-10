/*Assignment Description**
The ABC Company generally divides its customers into three groups: preferred customers, general customers, and black-listed customers.

1. All customers will have attributes such as customer ID, name, and address. All customers will have operations such as register() and printCustomerInfo().  

     * The register() function will fill up a new customer's information.

     * The printCustomerInfo() displays an existing customer's information.


2. The preferred customers have an additional attribute: preferred-tiers. It has three levels tier1, tier2, and tier3.

3. The black-listed customers has an additional attribute: black-listed date*/

//Thomas Barrella BCS370 Homework Assignment 1

#include <iostream>
#include <string>
using namespace std;

//have to create the constraint for the tier level
enum prefTier {tier1, tier2, tier3};

//generalCustomer has to be listed before the others so that the other classes can inherit it
class generalCustomer {
  protected:
  //default constructors
  int customerId = 0;
  string name = "N/A";
  string address = "N/A";
  public:
  

  //function to register a new customer, id is customer ID, n is name, a is address
  //take the input and write it to private variables without using cin
  void Register(int id, string n, string a) {
      this -> customerId = id;
      this -> name = n;
      this -> address =a;
  }

  //function to print the info for each customer, make a new line for each item for neat output
  void printCustomerInfo() {
      cout << "ID: " << customerId;
      cout << "\nName: " << name;
      cout << "\nAddress: " << address << endl;
  }

};

//preferredCustomer will inherit General Customer
class preferredCustomer: public generalCustomer {
  protected:
    prefTier tier = tier1;
  public:
  //function to register a new customer, have to include the tier level as well
  void Register(int id, string n, string a, prefTier t) {
    this -> customerId = id;
    this -> name = n;
    this -> address = a;
    this -> tier = t;
  }

  //function to printCustomerInfo including tier level, pass function from generalCustomer
  void printCustomerInfo() {
    generalCustomer::printCustomerInfo();
    //create the case for different tiers to appear based upon which tier
    cout << "\nPreferred Customer! Customer is : ";
    if (tier1)
    {
      cout << "Tier 1" << endl;;
    }
    else if (tier2)
    {
      cout << "Tier 2" << endl;
    }
    else if (tier3)
    {
      cout << "Tier 3" << endl;
    }
  }

};


//this class must inherit generalCustomer as well
class blackListedCustomer: public generalCustomer {
  protected:
    string blackListedDate = "n/a";
  public:
  

    //register a customer including their blacklisted date, d = date
    void Register(int id, string n, string a, string d) {
      this -> customerId = id;
      this -> name = n;
      this -> address = a;
      this -> blackListedDate = d;
    }

    //function to print customer info and their blacklisted date, pass function from generalCustomer
    void printCustomerInfo() {
      generalCustomer::printCustomerInfo();
      cout << "\nBlack-Listed Customer! Black-Listed Date: " << blackListedDate << endl;
    }
};
//*****
//void preferredCustomer::Register(12345, Tom, My house, tier1);
//preferredCustomer::void Register(12345, Tom, My house, tier1);
//preferredCustomer::Register(12345, Tom, My house, tier1);
//*****

int main() {
  //test generalCustomer
  generalCustomer P;

  P.Register(12345,"Tim", "My House");
  P.printCustomerInfo();

  //test preferredCustomer
  preferredCustomer T;

  T.preferredCustomer::Register(12346, "Paul", "His House", tier2);
  T.preferredCustomer::printCustomerInfo();

  //test blackListedCustomer
  blackListedCustomer S;

  S.blackListedCustomer::Register(12347, "Linda", "Her House", "January 16, 2009");
  S.blackListedCustomer::printCustomerInfo();

  return 0;
}

//I aimed to utilize the SRP SOLID principle in this code because even though each class has 2 functions, preferredCustomer and blackListedCustomer each exist for one variation of generalCustomer. This helps to keep the code organized and simple to understand. Also byy inheriting the printCustomerInfo() function I am saving time and keeping the code concise. Each of the two other functions adds one specific thing to customer info further showing my intended use of SRP.