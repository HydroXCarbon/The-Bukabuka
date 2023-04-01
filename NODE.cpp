#include <iostream>
using namespace std;
#include"NODE.h"

NODE::NODE(string x,int a,int b){
      name = x;
      hp = a;
      potion = b;
      next=NULL;
      cout<<"Adding "<<name<<endl;
}
NODE::~NODE(){
      cout<<"Node "<<name<<" is being deleted"<<endl;
}
NODE* NODE::move_next(){
      return next;
}
void  NODE::show_node(){
      if(hp>60)
            cout<<"Monster name : "<<name<<" (hp is "<<hp<<" , "<<potion<<" potion left)"<<endl;
      else{
            cout<<"Monster name : "<<name<<" (hp is ";
            cout << "\033[31m" <<hp<< "\033[94m";
            cout<<" , "<<potion<<" potion left)"<<endl;
      }
}
void NODE::insert(NODE*& x){
      x->next=this;
}
void NODE::heal(){
      if(potion>0){
            int r_number = 1+ (rand() % 3);
            potion--;
            cout<<name;
            if(r_number == 1){
                  hp+=20;
                  cout<<" heal 20 hp ("<<name<<" hp is "<<hp<<" , "<<potion<<" potion left)"<<endl;
            }
            else if(r_number == 2){
                  hp+=30;
                  cout<<" heal 30 hp ("<<name<<" hp is "<<hp<<" , "<<potion<<" potion left)"<<endl;
            }
            else if(r_number == 3){
                  hp+=40;
                  cout<<" heal 40 hp ("<<name<<" hp is "<<hp<<" , "<<potion<<" potion left)"<<endl;
            }
      }
      else{
            cout<<name<<" Can't heal out of potion"<<endl;
      }
}

void NODE::check_stats1(NODE* monster){
      if(monster->show_hp() <=0 )
            monster->hp=0;
}

void NODE::check_stats2(NODE* monster){
      if(monster->show_hp() <=0 )
            cout << "\033[31m" <<monster->show_name()<<" is dead"<<endl<< "\033[94m";
}

void NODE::atk(NODE* monster){
      int r_number = 1+ (rand() % 6);
      if(r_number == 1){
            cout<<name<<" miss attack ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
      }
      else if(r_number == 2){
            monster->hp-=20;
            check_stats1(monster);
            cout<<name<<" throw rock and hit "<<monster->show_name()<<" for 20 hp ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
            check_stats2(monster);
      }
      else if (r_number == 3){
            monster->hp-=30;
            check_stats1(monster);
            cout<<name<<" punch "<<monster->show_name()<<" for 30 hp ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
            check_stats2(monster);
      }
      else if (r_number == 4){
            monster->hp-=40;
            check_stats1(monster);
            cout<<name<<" kick "<<monster->show_name()<<" for 40 hp ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
            check_stats2(monster);
      }
      else if (r_number == 5){
            monster->hp-=50;
            check_stats1(monster);
            cout<<name<<" stab "<<monster->show_name()<<" for 50 hp ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
            check_stats2(monster);
      }
      else{
            monster->hp-=60;
            check_stats1(monster);
            cout<<name<<" throw grenade and hit "<<monster->show_name()<<" for 60 hp ("<<monster->show_name()<<" hp is "<<monster->show_hp()<<")"<<endl;
            check_stats2(monster);
      }
}

int NODE::show_hp(){
      return hp;
}

string NODE::show_name(){
      return name;
}


