// rewritten by snowcat on 4/11/1997
// room: xiaomiao

#include <ansi.h>

#include <room.h>

inherit ROOM;

void init()
{
  add_action("do_push","push");
}

void create ()
{
  set ("short", "土地庙");
  set ("long", @LONG

土地庙里有两尊泥像，塑像剥落不堪，看来很少有人来这进香上供。西北
山坡挡住了火焰山的热浪，这儿便成了行路人歇脚的好去处，几个行人正
在这打尖歇脚。

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "泥像" : "泥像剥落不堪，看起来似乎能够推动(push)。\n",
]));

  set("exits", ([
          "northwest" : __DIR__"south2",
          "southwest" : __DIR__"south3",
       ]));

  setup();
}

int do_push(string arg)
{
  object me,tudi,where;
  int i,j;

  i = 5 + random(10);
  j = i + 3 + random(7);  

  me = this_player();
  where = environment(me);

  if(me->is_busy())
    return notify_fail("你不正忙着吗？\n");

  if(!arg)
    return notify_fail("什么？\n");

  if(arg != "nixiang" && arg != "泥像")
    return notify_fail("你要干什么？\n");

  if(me->query("combat_exp") < 20000)
      return notify_fail("你涨红了脸，死命地扳了泥像半天，一点动静也没有。\n");
  if(tudi = present("tudi",where))
  {
    if(!me->query_temp("push_nixiang") || me->query_temp("push_nixiang")==0)
      return notify_fail("土地就在眼前，推泥像干吗？\n");
    message_vision(HIY"$N只是自顾自地推那菩萨像，小庙里尘埃飞杨。\n" NOR,me);
    me->add_temp("push_nixiang", 1);
    if((me->query_temp("push_nixiang")) > j)
    {
      message_vision("土地对$N苦笑了一声，身形一动闪入泥像后，不见了。\n",me);
      destruct(tudi);
      me->set_temp("qi_zou_tu_di",1);
    }
    return 1;
  }
  else
  {
    if(me->query_temp("qi_zou_tu_di"))
      return notify_fail("你继续去推那泥像，泥像再没动过。\n");
    me->add_temp("push_nixiang", 1);
    if(me->query_temp("push_nixiang") < i)
    {
      message_vision("\n$N推了推泥像，泥像竟似晃了晃。\n"NOR,me);
      return 1;
    } 
    if(!me->query_temp("called_tudi"))
    {
      message_vision(HIR"泥像忽然猛烈地摇了摇，土地神颤巍巍地从后面走了出来。\n"NOR,me);
      tudi = new (__DIR__"npc/tudi");
      tudi->move(where);
      me->set_temp("called_tudi");
    }
    return 1;
  }
}


int valid_leave(object me, string dir)
{
  me->delete_temp("push_nixiang");
  call_out("peace", 300,me);
  return ::valid_leave(me, dir);
}

void peace(object me)
{
  if (me)
    me->delete_temp("qi_zou_tu_di");
}
