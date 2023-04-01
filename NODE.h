using namespace std;
class NODE{
private:
      int potion,hp;
      string name;
      NODE* next;
public:
      NODE(string="Entity", int=100,int=2);
      void heal();
      void atk(NODE*);
      void show_node();
      void insert(NODE*&);
      int show_hp();
      void check_stats1(NODE*);
      void check_stats2(NODE*);
      string show_name();
      NODE* move_next();
      ~NODE();
};
