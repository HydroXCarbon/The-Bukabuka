#include <iostream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include<cstdlib>
#include"NODE.h"
#include "LL.h"
#include"monster.h"

using namespace std;

int main(int argc, char *argv[]){
   srand(time(0));
   system("Color 09");
   int user_input;
   LL A;
   NODE Boss("Bukabuka",1000,0);
   NODE *t,*b= &Boss;
   NODE* temp=A.get_head();
   for(int i=1;i<argc;i+=3) {
        t=new NODE(argv[i],atoi(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
   }
   do{
      user_input = 0;
      system("CLS");
      Show_Boss_HP(Boss.show_hp());
      A.show_all();
      action(A.get_head(),A.get_size(),user_input,b);
      if(A.check_monster())
         break;
   }while(user_input != 4);
   cout<<"-------------------Game Over-------------------"<<endl<<endl;
   temp=A.get_head();
   for(int i=1; i<=A.get_size();i++){;
      if(temp->show_hp()==0)
         cout<<"Monster "<<temp->show_name()<<" was killed in the line of duty"<<endl;
      temp = temp->move_next();
   };
   cout << "Press any key to pay respect . . . " <<endl<< endl;
   _getch();
   cout<<"------------------------------------------------"<<endl;
   return 0;
}
