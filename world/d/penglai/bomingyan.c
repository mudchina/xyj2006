//Cracked by Roath

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "薄命岩");
  set ("long", @LONG

一座山崖兀立高耸，佼佼不群。崖边一棵青松，
苍劲挺拔，直插白云之间。这里就是百花仙子隐
居的所在。崖下是百花谷，遍地是奇花异草，可
惜山势陡峭，轻身功夫不佳的如果贸然跃(jump)
下(down)，不免摔得骨断筋折。
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "northdown" : __DIR__"penglai",
  "enter": __DIR__"hongyandong",
]));
  set("outdoors", 1);
  setup();
}
void init() {
    add_action("do_jump","jump");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"baihuagu"+(string)(random(4)+1)+random(5)+".c";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("往哪儿跳？\n");

  msg="$N";
  if (ridee) msg=msg+"骑着"+ridee->query("name");
  msg+="纵身往谷底跃下。\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-50) damage=me->query("eff_kee")-50;
  if (damage<=0) damage=0;
  me->receive_wound("kee",damage);
  me->move(dest);
  if (ridee) ridee->move(dest);
  if (!damage) message_vision("$N从悬崖上跳了下来，轻轻巧巧地落在地上，毫发未损。\n",me);
  else {
  message_vision("$N从悬崖上跳了下来，跌了个大跟斗。\n",me);
  COMBAT_D->report_status(me); 
  }
  if (ridee) {
      message_vision("\n$N骑着的"+ridee->query("name")+"摔成了一团肉饼。",me);
      ridee->die();
  }
  me->start_busy(1+random(2));
  return 1;
}
