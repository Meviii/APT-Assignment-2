#include "LinkedList.h"
#include "Menu.h"
#include "Player.h"

#include <iostream>
#include <fstream>

#define EXIT_SUCCESS 0

int main(int argc, char *args[])
{

   // std::ofstream saveFile("fileName");
   // saveFile << "Test" << std::endl;
   if(argc == 3){
      std::cout << args[1] << " " << args[2] << std::endl;
      //Will pass args into test logic


   }
   else {
      Menu *menu = new Menu();
      menu->runMenu();
   }

   return EXIT_SUCCESS;
}