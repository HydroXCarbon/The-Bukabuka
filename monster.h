#include <iostream>
using namespace std;

int action(NODE* hol,int size,int &user_input,NODE* Boss){
      int count = 0,monster_1=0,monster_2=0;
      NODE* temp1=hol;
      NODE* temp2=hol;
      cout<<endl<<"-------------------Select action below-------------------"<<endl<<endl;
      cout<<"1. Attack each other"<<endl;
      cout<<"2. Heal monster"<<endl;
      cout<<"3. Every monster attack BOSS!!"<<endl;
      cout<<"4. Leave Game"<<endl<<endl;
      looper:
      while(true){
            cout << "Input action :";
            cin >> user_input;
            if(cin.fail()){
                  cin.clear();
                  cin.ignore();
            }
            else
                  break;
      }
      switch(user_input){
         case 1 : {
            start:
            temp1=hol,temp2=hol;
            do{
            cout<<"\nSelect 2 monster to attack each other (insert number) :";
            cin>>monster_1>>monster_2;
            }while((monster_1 <= 0) || (monster_1 > size) || (monster_2 <= 0) || (monster_2 > size) || (monster_1 == monster_2));
            for(int i=1 ; i<=size;i++){;
                  if(i < monster_1)
                        temp1 = temp1 -> move_next();
                  if(i < monster_2)
                        temp2 = temp2 -> move_next();
            };
            if(temp1->show_hp() == 0){
                   cout << "\033[31m" <<temp1->show_name()<<" is dead"<<endl<< "\033[94m";
                  goto start;
            }
            if(temp2->show_hp() == 0){
                   cout << "\033[31m" <<temp2->show_name()<<" is dead"<<endl<< "\033[94m";
                  goto start;
            }
            cout<<endl;
            temp1->atk(temp2);
            temp2->atk(temp1);
            system("pause");
            break;
            }
         case 2 : {
            do{
                  cout<<"\nSelect monster to heal (insert number) :";
                  cin>>count;
            }while(count>size || count<0);
            cout<<endl;
            for(int i=1 ; i<count;i++){
                  temp1 = temp1 -> move_next();
            };
            if(temp1->show_hp() != 0)
                  temp1->heal();
            else 
                  cout << "\033[31m" <<temp1->show_name()<<" is dead"<<endl<< "\033[94m";
            system("pause");
            break;
         }
         case 3 : {
            system("CLS");
            cout<<endl<<" Every monster attack boss at all cost !!"<<endl;
            system("pause");
            cout<<endl<<" Every one attack !!"<<endl;
            for(int i=1 ; i<=size ;i++){
                  if(temp1->show_hp() != 0)
                        temp1->atk(Boss);
                  temp1 = temp1 -> move_next();
            };
            if(Boss->show_hp() == 0){
                  user_input=4;
                  break;
            }
            else{
                  system("pause");
                  cout<<endl;
                  temp1 = hol;
                  cout<<" "<<Boss->show_name()<<" attack back !!"<<endl;
                  for(int i=1 ; i<=size ;i++){
                        if(temp1->show_hp() != 0)
                              Boss->atk(temp1);
                        temp1 = temp1 -> move_next();
                  };
                  system("pause");
                  break;
            }
         }
         case 4 : break;
         default : goto looper;
      }
}

void Show_Boss_HP(int Boss_hp){
      cout<<"-----------------------Monster List-----------------------"<<endl<<endl;
      cout<<"  BOSS hp ";
      for(int i=1;i< Boss_hp/25;i++){
            if(Boss_hp<=500)
                  cout << "\033[31m" <<(char)254u<< "\033[94m";
            else
                  cout << (char)254u;
      }
      for(int i=2;i<(1000/25)-(Boss_hp/25);i++){
            cout <<"-";
      }
      cout<<" "<<Boss_hp<<"/1000"<<endl<<endl;
}
