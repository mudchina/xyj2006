// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// inside2.c
//方寸

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

inherit ROOM;
void create ()
{
  set ("short", "讲经堂");
  set ("long", @LONG

这里是三星洞的讲经堂，平时道士们便在这里讲经说法。若是
有什么大事，也在这里集会商议。左右整整齐齐地放着四五十
个软垫，也坐了一二十个道士。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houlang1.c",
  "southdown" : __DIR__"inside1.c",
  "up" : __DIR__"wuchang.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao" : 1,
  __DIR__"npc/yunyang" : 1,
]));
  set("valid_startroom", 1);

  setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("master yunyang", environment(me)))) {
   if((string)me->query("family/family_name")=="方寸山三星洞") {
      if(me->query("sixiang_winner"))
         return ::valid_leave(me,dir);
   }
      return notify_fail("云阳真人说道：祖师清修，少见外人，只有本门通过四象阵的弟子才有资格参见祖师。\n您还是请回吧！\n");
   }
   }
        return ::valid_leave(me, dir);
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
message("channel:es",HIG+"【方寸山】菩提老祖[master puti]：现在开讲道家心法，各位弟子到讲经堂听讲。\n"+NOR,users());
tell_object(where,"你听到菩提老祖的声音：知其雄，守其雌，为天下溪。为天下溪，常德不离，复归于婴儿。\n");
tell_object(where,"你听到菩提老祖的声音：知其白，守其辱，为天下谷。为天下谷，常德乃足，复归于朴。\n");
tell_object(where,"你听到菩提老祖的声音：知其白，守其黑，为天下式。为天下式，常德不忒，复归于无极。\n");
tell_object(where,"你听到菩提老祖的声音：朴散则为器，圣人用之，则为官长，故大智不割。\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"菩提老祖说道：大家休息吧。\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("菩提老祖还没有开始传授道家仙法。\n");

 if((string)me->query("family/family_name")!="方寸山三星洞")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>400)
      return notify_fail("菩提老祖对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你不禁被菩提老祖的讲道深深吸引了。\n");
   me->start_busy(5);
   me->add("faith",1);
   me->improve_skill("dao",random((int)(me->query("spi")+me->query("int"))/2),1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   tell_object(me,"你觉得道家仙法进步了！\n");
   return 1;
}
