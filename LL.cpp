#include <iostream>
#include"NODE.h"
#include"LL.h"

using namespace std;

LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
     NODE* t=hol;
     NODE* temp;
     int i;
     for(i=0;i<size;i++){
          temp = t;
          t=t->move_next();
          delete temp;
     }
     size = 0;
}

void LL::show_all(){
     NODE* t=hol;
     for(int i=1;i<=size;i++){
          cout<<i<<". ";
          t->show_node();
          t=t->move_next();
     }
}

void LL::add_node(NODE *&A){
       hol->insert(A);
       hol=A;
       size++;
 }

NODE* LL::get_head(){
     return hol;
}

int LL::get_size(){
     return size;
}

int LL::check_monster(){
     NODE* t=hol;
     for(int i=1;i<=size;i++){
          if(t->show_hp() != 0)
               return 0;
          t=t->move_next();
     }
     return 1;
}