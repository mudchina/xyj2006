// wri by bear

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
   if(phase==0&&(!query("jiangjing"))) jiang_jing(where);
if(phase==7&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",CYN+"◇"RED"阎罗地府"CYN"◇"WHT"阎罗王[Yanluo wang]"CYN"：阎罗小鬼速到阎罗宝殿听经。\n"+NOR,users());
tell_object(where,"阎罗王喊道;小鬼集合开始讲经。\n");
tell_object(where,"一时鬼气森森,四面阴风煞煞，好不吓人。\n");
    set("jiangjing",1);
}
void finish_jing(object where)
{
  tell_object(where,"阎罗王朗声道:弟子们辛苦了。\n");
   set("jiangjing",0);
   }
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
  if(!query("jiangjing"))
     return notify_fail("阎罗地府还没有开始讲经呢。\n");

 if((string)me->query("family/family_name")!="阎罗地府")
      return notify_fail("非阎罗地府小鬼不得在此听经。\n");
   if(me->query("faith")>40000)
      return notify_fail("你已经有一定功底,不用再听了。\n");
       tell_object(me,"你听着听着似乎若有所悟。\n");
  me->start_busy(5);
   me->improve_skill("tonsillit",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("gouhunshu",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
  return 1;
}





