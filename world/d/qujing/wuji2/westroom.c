// Room: /u/mimi/zhuziguo/westroom  snowcat moved to /d/qujing/wuji

inherit ROOM;


void create ()
{
  set ("short", "西厢房");
  set ("long", @LONG

此间乃寺中主持的禅房，但因近来夜间闹鬼，主持已搬去别处。屋
中陈设甚是典雅。两边书架上摆满了经书，朝南的案上有一鼎香炉
却好象好久没人上香了。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
  ]));
  set("sleep_room",1);

  setup();
}

void init()
{
  add_action ("do_find","四处找找");
  add_action ("do_find","zhaozhao");

}

int do_find()
  {
  object jade;
  object me=this_object();
  object who=this_player();
  if (me->query("leave_gui")!=1) return 0;
  if (who->query("obstacle/qujing")!="ren")return 0;
  if (who->is_busy()) 
 	return notify_fail("你现在正忙着呢。\n");
  who->start_busy(3);
  if (random(5)) return notify_fail("你四处翻找,但是没有找到什么东西!\n"); 

  message_vision ("$N眼前一亮,啊,好一个宝贝,竟然找到了。\n",who);
  jade = new(__DIR__"obj/jade.c");
  jade->move(who);
  set("leave_gui",0);
  return 1;
  }

int valid_leave (object who, string dir)
{
  if (dir == "east")
  {
 
    if (who->query("id")=="qujing ren")
    {
   if (who->query_temp("have_dream")!=0)
      {
      message_vision("$N轻声说道:此事只怕还有蹊跷,我想留下来看看。\n",who);        return 0;     	
      }
    }
  }
  return ::valid_leave(who, dir);
}


