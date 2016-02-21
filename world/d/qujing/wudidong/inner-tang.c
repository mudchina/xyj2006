// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/inner-tang.c

inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

大殿里无数小妖来回奔走，正在准备大开筵席。一个女子正中高坐，
云髻低垂，金钗半溜，正笑吟吟地指挥着众小妖，全不顾自己香汗淋
漓。你往人群中一混，一时倒也无人发觉。这个地方也是传授人肉
包子做法的地方。你只要来(hear)，就可以了。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tang-gate",
]));

  setup();
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
message("channel:es",CYN+"◇"WHT"陷空山无底洞"CYN"◇"WHT"玉鼠精[Yu shu]"CYN"：现在开始传授我们无底洞的宝典。\n"+NOR,users());
tell_object(where,"地涌夫人说道：这人肉包子的味道可实在是好啊。\n");
tell_object(where,"首先要心狠手辣，不能拖泥带水。\n");
tell_object(where,"人肉包子吃的就是新鲜，不能放置，砍下肉后，要立即做成包子。\n");

   tell_object(where,"要点是：人的心脏附近的肉最为鲜美。\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"地涌夫人说道：回去试试你的人肉包子做的如何。\n");
   set("jiangjing",0);
     set ("long", @LONG
    这里坐着些怪模怪样的妖怪，他们的眼睛红红的
，似乎想要吃人，他们在听地涌夫人说些什么。
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("地涌夫人还没开始传授宝典呢。\n");

 if((string)me->query("family/family_name")!="陷空山无底洞")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("做人肉包子这种小事，你已经是地涌夫人的师傅了。\n");

    tell_object(me,"你在旁边听着，听着。不禁想起了人肉包子的美味。\n");
   me->start_busy(5);
   me->improve_skill("huntian-qigong",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("yaofa",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}

