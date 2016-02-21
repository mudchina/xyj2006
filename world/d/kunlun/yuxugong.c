inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
void create()
{
        set("short",HIW "玉虚宫");
        set("long", @LONG
    这里玉虚宫了，面前一位老神仙正在入定打坐。
看到你来了冲你点了点头。
LONG );
        set("exits", ([
                "south" : __DIR__"hundun8",
        ]));
          set("kunlun", 1);
  set("objects", ([ // sizeof() == 1 //
 __DIR__"npc/tianzun" : 1,
 __DIR__"npc/baihe" : 1,
]));
  set("valid_startroom", 1);
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
message("channel:es",HIG+"【昆仑山玉虚洞】广成子[guang chengzi]：师尊于玉虚宫开坛讲法，玉虚门下回山听讲。\n"+NOR,users());
tell_object(where,"你听到元始天尊的声音：知其雄，守其雌，为天下溪。为天下溪，常德不离，复归于婴儿。\n");
tell_object(where,"你听到元始天尊的声音：知其白，守其辱，为天下谷。为天下谷，常德乃足，复归于朴。\n");
tell_object(where,"你听到元始天尊的声音：知其白，守其黑，为天下式。为天下式，常德不忒，复归于无极。\n");
tell_object(where,"你听到元始天尊的声音：朴散则为器，圣人用之，则为官长，故大智不割。\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"元始天尊说道：今日暂且讲到这里吧。\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("元始天尊还没有开坛讲法。\n");

 if((string)me->query("family/family_name")!="昆仑山玉虚洞")
      return notify_fail("非玉虚门下不得听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("元始天尊对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你不禁被元始天尊的讲法深深吸引了。\n");
   me->start_busy(5);
//   me->add("faith",1);
   me->improve_skill("yuxu-spells",random((int)(me->query("spi")+me->query("int"))/2));
//   me->add("combat_exp",30);
//   me->add("potential",5);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   tell_object(me,"你觉得玉虚仙法进步了！\n");
   return 1;
}
