// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//standroom.c used by weiqi...others may hate this format:D
//icegate.c
#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();
void create ()
{
   set ("short", "东武场");
   set ("long", @LONG

放眼望去，这座冰宫通体雪明，当真是巍峨壮观。但是此刻宫门
紧闭，一位身披银甲的壮汉和一位面目阴森的老者正神情紧张地
守在门前。
LONG);

   //set("item_desc", ([" *** " : " *** \n", ]));
   //for look something.

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"wuchang-se",
     "north" : __DIR__"wuchang-ne",
     "west" : __DIR__"wuchang-c",
     //"north" : __DIR__"icegate",
//"west" : __DIR__"wuchang-nw",
//"east" : __DIR__"wuchang-ne",
     //"up" : __DIR__"***",
     //"down" : __DIR__"***",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     __DIR__"npc/tuying-zunzhe" : 1,
     __DIR__"npc/baixiang-zunzhe" : 1,
   ]));


   set("outdoors", "xueshan");

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
   if(phase==4&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==5&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:es",CYN+"◇"WHT"大雪山"CYN"◇"WHT"白象尊者[Baixiang zunzhe]"CYN":雪山弟子，现在开始讲授登仙大法. \n"+NOR,users());
   tell_object(where,"登仙大法可谓是明王创造出来的奇特的仙法.\n");
   set("jiangjing",1);
     set ("long", @LONG
        就见着小小的地方，有二十多个和你一个级别的
  小妖们在听白象尊者讲仙法.
LONG);
}
void finish_jing(object where)
{
   set("jiangjing",0);
}
int do_hear()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("白象尊者还没开始授法呢.\n");              
   if((string)me->query("family/family_name")!="大雪山")
      return notify_fail("外派弟子不得来听讲。\n");
    if(me->query("faith")>40000)
      return notify_fail("你觉得自己不用再听讲了。\n");
    tell_object(me,"你在旁闻听，若有所悟，不禁眉花眼笑。\n");
   me->start_busy(5);
   me->improve_skill("dengxian-dafa",random((int)(me->query("spi")+me->query("int"))/2),1);
  me->add("faith",1);
  me->add("combat_exp",12);
  me->add("potential",3);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}                                                                    

