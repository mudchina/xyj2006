// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/zhulin.c

#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "紫竹林");
   set("long", @LONG

普陀后山的紫竹林。也是观音菩萨闲憩常到的所在。紫竹细疏，
清风微拂。漫步于此，世事之纷扰顿时烟消云散。
LONG
   );
   set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhulin"+sprintf("%d", random(25)),
  "west" : __DIR__"zhulin"+sprintf("%d", random(25)),
  "south" : __DIR__"zhulin"+sprintf("%d", random(25)),
  "east" : __DIR__"zhulin"+sprintf("%d", random(25)),
]));

   setup();
//   replace_program(ROOM);
}

void init()
{

        object me=this_player();

        if ( (me->query_temp("aware_of_jinguzhou")) && 
     (me -> query_kar() > 20) ) {
                tell_object(me, HIY"你心中一动，似乎有所觉悟。\n"NOR);
        }
        add_action("do_search", "search");
}

int do_search (string arg)
{
  object ob, me = this_player();

    if (!arg || arg != "jinguzhou")
  {
    message_vision ("$N蹲下去寻找什么。\n",me);
    return 1;
  }

  if (me -> query_kar() < 20)
  {
    message_vision ("$N蹲下去在竹丛里胡乱翻了起来。\n",me);
    return 1;
  }

   if( !(ob = find_object(__DIR__"obj/jingu1")) ) {
            ob = load_object(__DIR__"obj/jingu1");
       ob -> move(me);
       message_vision ("$N眼睛一亮：紧箍咒！\n",me);
       if (me->query_temp("aware_of_jinguzhou"))
     me -> delete_temp("aware_of_jinguzhou");
       return 1;   
   }

   message_vision ("$N蹲下去在竹丛里仔细地翻来翻去。\n",me);
   return 1;
}

