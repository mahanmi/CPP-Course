#include <iostream>
#include <string>

int main()
{
  int input;
  int dool;
  std::string ans;
  std::cout << "Who Are You?" << std::endl
            << "1. Mahan" << std::endl
            << "2. Mobin" << std::endl
            << "3. Navid" << std::endl
            << "4. Arman" << std::endl
            << "5. Mirj" << std::endl
            << "6. Vahedi" << std::endl
            << "Please enter a number: ";
  std::cin >> input;

  if (input == 1)
  {
    std::cout << "Hello Arbab!" << std::endl;
  }
  else if (input == 2)
  {
    std::cout << "Hello Mr Mozi!" << std::endl;
  }
  else if (input == 3)
  {
    std::cout << "Did You wash the dishessss?" << std::endl;
    std::cin >> ans;
    if (ans == "y" || ans == "yes")
    {
      std::cout << "Mobinnnnnnnnn's Bag in Your Ass" << std::endl;
    }
    else if (ans == "n" || ans == "no")
    {
      std::cout << "Go Wash The dishes Asshole!" << std::endl;
    }
  }
  else if (input == 4)
  {
    std::cout << "Hello Dool Kesh Meshiii!" << std::endl
              << "How long was your Dick? " << std::endl;
    std::cin >>
        dool;

    {
      while (dool > 3)
      {
        std::cout << "\033[1;31mDon't Lie!\033[0m" << std::endl;
        std::cout << "How long is your Dick? " << std::endl;
        std::cin >> dool;
      }
      if (dool <= 3)
      {
        std::cout << "Good boy!" << std::endl;
      }
    }
  }
  else if (input == 5)
  {
    std::cout << "Go Read 707 Nerd!" << std::endl;
  }
  else if (input == 6)
  {
    std::cout << "Hello Vahedi!" << std::endl;
  }
  else
  {
    std::cout << "Invalid input!" << std::endl;
  }

  return 0;
}
