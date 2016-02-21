// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhting.c

inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "阎罗宝殿");
  set ("long", @LONG

这里便是名闻天下，令人提起心惊胆寒的阎罗地府。人死后都会
在这里受到应有的处置。正前一张大桌，后面坐着阎罗王，旁边
立着崔判官。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"new-walk5",
  "north": __DIR__"walk1",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
//  __DIR__"npc/panguan" : 1,
]));
  setup();
  call_other("/obj/board/shengsi_b", "???");
}

void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
    add_action("do_hear","hear");
}

void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==5&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==6&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",HIG+"【阎罗地府】阎罗王(Yanluo wang)：现在给弟子们说说我们的鬼族的家事！\n"+NOR,users());
tell_object(where,"阎罗王(Yanluo wang)：鬼常去一些有饭食气息的地方以解饥饿。\n");
tell_object(where,"阎罗王(Yanluo wang)：鬼在强光中如人在火中，鬼尽量避开人，以免被人伤害。\n");
tell_object(where,"阎罗王(Yanluo wang)：鬼的世界也有阶层之分。\n");
tell_object(where,"阎罗王(Yanluo wang)：我们鬼族应以和平为贵，不要伤害无辜。\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"阎罗王说道：大家休息吧。\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("你还是等会再来吧。\n");
   if((string)me->query("family/family_name")!="阎罗地府")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>1000)
      return notify_fail("阎罗王叹道：这个你我知道的还多啊。\n");
   tell_object(me,"你不禁点头赞许。\n");
   me->start_busy(5);
   me->add("faith",1);
   me->improve_skill("gouhunshu",random((int)(me->query("spi")+me->query("int"))/2),1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   tell_object(me,"你对勾魂术的领悟加深了！\n");
   return 1;
}
