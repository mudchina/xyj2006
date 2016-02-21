// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
   set ("short", "乘云阁");
   set ("long", @LONG

乘云阁居观中的最高处，阁上画栋雕梁，丹楹刻柱，显是下了很
大的功夫、周围朱栏曲槛，凭栏四望，远处景致俱在眼前。山下
村房楼舍，山上奇石怪松历历在目。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "down": __DIR__"yanzhen",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/qingfeng" : 1,
     "/u/fly/doublesword/npc/zhenyuan" : 1,
   ]));


   set("outdoors", "wuzhuang");

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
   if(phase==5&&(!query("jiangjing"))) jiang_jing(where);
if(phase==6&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",HIG+"【五庄观】镇元大仙[zhenyuan daxian]：现在开始说道，弟子们注意了。\n"+NOR,users());
tell_object(where,"天长地久。天地所以能长且久者，以其不自生，故能长生。\n");
tell_object(where,"金玉满堂，莫之能守；\n");
tell_object(where,"故贵以身为天下，若可寄天下；爱以身为天下，若可托天下。\n");
tell_object(where,"绝圣弃智，民利百倍；绝仁弃义，民复孝慈；绝巧弃利，盗贼无有。\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"镇元大仙说道：大家休息吧。\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("镇元大仙还没有说道。\n");

 if((string)me->query("family/family_name")!="五庄观")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>5000)
      return notify_fail("镇元大仙对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你不禁被镇元大仙的讲道深深吸引了。\n");
   me->start_busy(5);
   me->add("faith",1);
   me->improve_skill("taiyi",random((int)(me->query("spi")+me->query("int"))/2),1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   tell_object(me,"你觉得太乙仙法进步了！\n");
   return 1;
}
