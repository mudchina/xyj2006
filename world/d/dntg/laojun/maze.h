
inherit ROOM;

string* directions=({"east","south","west","north",});
int is_drunk(object);

void create() {

  mapping exits=allocate_mapping(4);

  set("short","云路");
  set("long",@LONG

踏着这条宽敞的天宫云路，脚下飘过朵朵白云，俯视人间农舍
中飘起的袅袅炊烟，令人倍感心旷神怡。

LONG );
  exits=(["southwest":"/d/dntg/sky/yunlue3"]);
  for (int i=0;i<4;i++)
    exits+=([directions[i]:__DIR__"laojunmaze"+(string)random(8)]);
  set("exits",exits);
  set("outside",1);
  
  setup();
}

void init() {
  string* place=allocate(4);
  string *dest=({"兜率宫","蟠桃园","齐天大圣府","瑶池"});
  mapping map=allocate_mapping(4);
  int r;

  if (!is_drunk(this_player())) return;  
  for (int i=0;i<4;i++)  {
     r=random(4);
     while (place[r]) 
        r=(r+1)%4;
     place[r]=directions[i];
     map+=([directions[i]:dest[r]]);
  }

  this_player()->set_temp("laojunmaze/dir",map);
  add_action("do_look","look");
}

int is_drunk(object me) {
// int limit = me->query("con")*6+(int)me->query("max_force")/50;
 int limit = me->query("per")*6+(int)me->query("max_force")/50;
  int duration=me->query_condition("drunk");
 if (duration > limit/10 ) return 1;
  return 0;
}


int do_look(string arg) {
  string msg="\n你醉眼惺松，早已不辨东西，看什么都是两个影儿。\n";
  object me=this_player();
  mapping dir=me->query_temp("laojunmaze/dir");

  if (!arg) return 0;
  if (!dir) return 0;
  if (!dir[arg]) return 0;

  msg=msg+"你迷迷糊糊中感觉到这里似乎是去"+dir[arg]+"的路。\n\n";
  write(msg);

  return 1;
}

int valid_leave(object me,string dir) {
  mapping map=me->query_temp("laojunmaze/dir");
  int steps=(int)me->query_temp("laojunmaze/steps");
  string ridemsg;
  string loc="/d/dntg/laojun/gate";  
  object ridee;
  me->add("kee",-60+me->query_kar());

  if (!steps) return 1;
  if (!map) return 1;
  if (!map[dir]) return 1;

  
  if (map[dir]=="齐天大圣府") steps--;
    else steps++;
  if (steps>10) steps=10;
  me->set_temp("laojunmaze/steps",steps);
  if (steps) return 1;

  if (ridee = me->ride()) {
     ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
     ridee->move(loc);
  }  
    else  
      ridemsg = "";
   tell_room(environment(me),me->name()+ridemsg+
          "一头栽进云端里不见了。\n",me); 
   me->move(loc);
   tell_room(environment(me),me->name()+ridemsg+"走了过来。\n", me);
   me->delete_temp("laojunmaze");

   return 2;
}
    
