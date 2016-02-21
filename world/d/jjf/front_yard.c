// 将军府演武场
//2001 by lestat

inherit ROOM;
#include <ansi.h>
void yan_wu(object where);
void finish_yan(object where);
void check_time(object where);
int do_yanwu();

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG
空阔的场地上铺满了细细的黄土，正好适合演武(yanwu)。四面有几
个秦府家将正在练武。树荫里，一位管家打扮的人正在背着手观看，
还不时走上前去指点一二。场地边上挂着几个大沙袋(sandbags)，不
知有什么用处。西面有间破败的小屋，门窗都封死了，与将军府里其
它的房舍格格不入。
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "window" : "门窗都被封死了，墙上好象有些锤砸的痕迹．\n",
  "door" : "
门窗都被封死了，墙上好象有些锤砸的痕迹．\n",
  "sandbags" : "
几个沉重的沙袋，可以试着打打(da)看。\n",
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gate",
  "south" : __DIR__"front_yard2",
  "east" : __DIR__"majuan",
  "southwest" : __DIR__"guest_bedroom",
]));

  set("objects", ([
                   __DIR__"npc/qinfu": 1,
        __DIR__"npc/xiaotong": 2,
                   ]));

  setup();
}

void init()
{   object where=this_object();
    remove_call_out("check_time");
   check_time(where);
   add_action("do_yanwu","yanwu");
  add_action("do_hammer", "hammer");
  add_action("do_da", "da");
}

void check_time(object where)
{

   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==3&&(!query("yanwu"))) yan_wu(where);
if(phase==4&&query("yanwu")) finish_yan(where);
   call_out("check_time",60,where);
}
void yan_wu(object where)
{
message("channel:es",CYN+"◇"RED"大唐将军府"CYN"◇"WHT"程咬金[Cheng yaojin]"CYN"：大唐将军府众将演武场点兵。\n"+NOR,users());
tell_object(where,"秦富喊道;众将士集合开始演武。\n");
tell_object(where,"战鼓声声,一片将士的呐喊声震耳欲聋。\n");
   set("yanwu",1);
}
void finish_yan(object where)
{
   tell_object(where,"秦富大声喊道:众将士辛苦了。\n");
   set("yanwu",0);
//     set ("long", @LONG
//    空阔的场地上整整齐齐站满了方阵,战鼓声声,旌旗招展。
//LONG);
}
int do_yanwu()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("yanwu"))
      return notify_fail("将军府还没有开始点兵,你一个人演的什么武。\n");

 if((string)me->query("family/family_name")!="将军府")
      return notify_fail("非将军府将士不得演武。\n");
   if(me->query("faith")>40000)
      return notify_fail("你已经功勋卓越,不用演武了。\n");

    tell_object(me,"你随着声声战鼓与众将士一起演武。\n");
   me->start_busy(5);
   me->improve_skill("lengquan-force",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("baguazhou",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}

int do_da(string arg)
{
  object me=this_player();
  int unarmedskll=(int)(me->query_skill("unarmed", 1)/2);
  int maxlevel, exp=(int)me->query("combat_exp");
 
  if( !arg || !((arg == "sandbags") || (arg == "沙袋")))
    return notify_fail("你要打什么？\n");
  if( me->query("kee") < (int)(me->query("max_kee")/5))
    return notify_fail("再打下去你会累死的！\n");
  if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
    return notify_fail("用兵器会把沙袋打坏的！\n");
  if (!((string)me->query("family/family_name")=="将军府"))
    {
      message_vision("$N一拳向沙袋打去，可是沙袋一动不动。\n", me);
    }
  else
    {
      message_vision("$N用尽力气向沙袋打去，打得沙袋直晃。\n", me);
      if (exp*10 <= (unarmedskll*unarmedskll*unarmedskll))
   {
     me->receive_damage("kee", (int)me->query("max_kee")/10);
     return notify_fail("你的道行不够高，不能从打沙袋中学到新知。\n");
   }
      if (unarmedskll*2<((int)me->query("con")+(int)me->query("str"))*3)
   {
     me->improve_skill("unarmed", random((int)(me->query("con")+me->query("str"))*20));
     tell_object(me, "你领悟出一些基本拳脚方面的窍门。\n");
   }
      else
   {
     tell_object(me, "你在沙袋上费了半天劲，可是什么也没有学到。\n");
   }
    }
  me->receive_damage("kee", (int)me->query("max_kee")/10);
  return 1;
}

int do_hammer(string arg)
{       
  object me;
  me=this_player();
  if ( !present("hammer", me) || (arg != "door"))
    return notify_fail("你挥起拳头往墙上砸去，呃．．．．好象挺疼！\n");
  else
    message_vision("$N挥舞大锤，往墙上砸去．\n", me);
  if((int)me->query_temp("mark/将军") < 1)
    {
    me->set_temp("mark/将军", 1);
  }
  me->add_temp("mark/将军", 1);
  me->receive_damage("kee", 40);
  if((int)me->query_temp("mark/将军") > 5)
    {
    message_vision("$N把墙砸开了一个洞，连忙钻了进去．\n", me);
    me->set_temp("mark/将军", 1);
    me->set_temp("mark/将军禁地", 1);
    me->move("/d/jjf/mishi");
    return 1;
  }
  return 1;
}
