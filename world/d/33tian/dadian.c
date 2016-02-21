// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/33tian/west1
#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "兜率宫");
  set ("long", @LONG
这就是离恨天兜率宫了.此宫位于三十三天之上,一向是太上
老君的住所.宫中有一座大药炉,几个青衣童子正在药炉旁煽火,
到处都弥漫着一股芬芳的丹药气息,太上老君经常在此宣讲
道德真经,众仙(hear)受益非浅.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"doushuai-gate",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laojun": 1,
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
   if(phase==3&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==4&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:es",CYN+"◇"MAG"八景宫玄都洞"CYN"◇"HIW"太上老君[Taishang laojun]"+NOR+HIY"：现在于兜率宫开讲道德经。\n"+NOR,users());
tell_object(where,"你听到太上老君的声音：知其雄，守其雌，为天下溪。为天下溪，常德不离，复归于婴儿。\n");
tell_object(where,"你听到太上老君的声音：知其白，守其辱，为天下谷。为天下谷，常德乃足，复归于朴。\n");
tell_object(where,"你听到太上老君的声音：知其白，守其黑，为天下式。为天下式，常德不忒，复归于无极。\n");
tell_object(where,"你听到太上老君的声音：朴散则为器，圣人用之，则为官长，故大智不割。\n");
tell_object(where,"........................................\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"太上老君说道：大家休息吧。\n");
   set("jiangjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("太上老君还没有开始讲授道德经。\n");

 if((string)me->query("family/family_name")!="五庄观")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("太上老君对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你不禁被太上老君的讲道深深吸引了。\n");
   me->start_busy(5);
   me->improve_skill("taiyi",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("zhenyuan-force",random((int)(me->query("spi")+me->query("int"))/2));
//   me->add("faith",1);
//   me->add("combat_exp",30);
//   me->add("potential",5);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
