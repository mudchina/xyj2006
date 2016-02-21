//Cracked by Roath

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "一叶小舟");
  set ("long", @LONG

一叶最多只能载两人的扁舟，船头站着一位脚踏七色祥云的绿衫少女，
手握一根碧绿的竹篙，正笑吟吟地看着你。你往船中仔细一看，不禁
吓了一跳，原来竟是一条无底船。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lotuspond.c",
]));
set("zuo_trigger", 0);

  setup();
}

void init() {

  object me=this_player();
  object *inv=deep_inventory(me);
  if (me->query("daoxing")<1000000 || random(me->query_kar())<10) call_out("drown",1,me);
  else if (me->query("family/family_name")!="月宫" && random(3)) call_out("drown",1,me);
  else for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i]) ) {call_out("drown",1,me);return;}

  return;
}

void drown(object me) {
  object *inv;

  if (!me) return;
  inv=deep_inventory(me);

  message_vision(HIC"$N没有注意到脚下是条无底之船，一脚踏了个空，扑通一声掉进了湖底。\n"NOR,me);
  me->move(__DIR__"hudi");
  for (int i=0;i<sizeof(inv);i++) 
    if (userp(inv[i])) {
/*
      inv[i]->remove_all_killer();
      inv[i]->remove_all_enemy();
      inv[i]->set_temp("death_msg","被月亮湖怪兽吃掉了。\n");
      inv[i]->die();
      inv[i]->delete_temp("death_msg");
*/
   inv[i]->unconcious();
   inv[i]->move(__DIR__"hudi");
    } else destruct(inv[i]);
  if (me->query("family/family_name")!="月宫" || me->query("family/generation")!=2) me->unconcious();
}
