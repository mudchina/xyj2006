// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/zhuzitop.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_pick(string arg);
int  timer_pick(object ob);

void create ()
{
	set ("short", "定风柱上");
	set ("long", @LONG

爬上来才看清楚，那放光的原来是一颗核桃大小的明珠(ming zhu)。

LONG);

	set("item_desc", ([ /* sizeof() == 1 */
  		"ming zhu" : "一颗浑圆的珠子，巧妙的嵌在铁柱上，珠子发出淡淡的光晕，
看上去朦朦胧胧的，你不禁伸手过去，想把它取出来。
",
]));

	set("exits", 
	([ //sizeof() == 1
        "down" : __DIR__"yuan",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", __DIR__);

	setup();
}

void init()
{
   add_action("do_bite","bite");
   add_action("do_bite","yao");
   add_action("do_get","get");
}

int do_bite(string arg)
{
   object me=this_object();
   object who=this_player();
   object ob;
   string realzhu="/d/qujing/huangfeng/obj/dingfengzhu.c";

   if(!arg||(arg!="zhu"&&arg!="明珠"&&arg!="ming zhu"&&arg!="珠" && arg!="mingzhu"))
     return notify_fail("你要咬谁？\n");

   if(me->query("no_zhu")==0)
       {
       if(realzhu->in_mud())
             ob=new(realzhu->query("replace_file"));
       else ob=new(realzhu);
   
       ob->move(who);
    me->set("no_zhu",1);
    remove_call_out("timer_pick");
    call_out("timer_pick",900,me);
  message_vision(HIC"只见一道霞光闪过，你的眼前顿时一亮。\n"NOR,who);
  message_vision(HIC"$N张开嘴，轻轻咬起一颗闪亮的明珠！\n"NOR,who);
  who->set_temp("obstacle/huangfeng_zhu_getted",1);
     }
else   message_vision(HIY"$N用嘴去咬那明珠，突然眼前一花，凝神再看时，光茫消散，那里什么都没有！\n"NOR,who);
  return 1;
}

int timer_pick(object ob)
{
  ob->delete("no_zhu"); 
  return 0;
}

int do_get(string arg)
{
object who=this_player();
  message_vision(HIC"$N正牢牢抱着铁柱，唯恐一个不小心跌下去，看样子是腾不出手来拿东西了！\n"NOR,who);
return 1;
}
