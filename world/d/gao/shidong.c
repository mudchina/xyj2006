// rewritten by xueshan on 09/11/2000
// Room: shidong

inherit ROOM;

void create ()
{
  set ("short", "石洞");
  set ("long", @LONG

洞门由两块大石板依山势修葺而成。看起来做的严严实实。

LONG);

  set("light_up", 1);
  set("outdoors", "firemount");
  set("exits", ([
        "westdown" : __DIR__"shanlu2",
      ]));

  setup();
}

void init()
{
  add_action("do_za", "za");
}

int do_za (string arg)
{
  object me = this_player();
  object weapon = me->query_temp("weapon");

  if ((arg != "shimen" &&
       arg != "door"))
  {
    message_vision("$N想砸什么。\n",me);
    return 1;
  }
  
  if (! weapon)
  {
    message_vision ("$N赤膊上阵捏着拳头往石门上一砸！\n",me);
    message_vision ("乓地一声$N只觉得骨头都震碎了！\n",me);
    me->unconcious();
  }
  else
  {
    message_vision("$N鼓足劲，轮起$n向大门砸去。\n",me,weapon);
    if (! this_object()->query("exits/south"))
    {
      message_vision ("乓地一声门开了！\n",me);
      me->set_temp("obstacle/zhu_shidong",1);
    }
    else
    {
      	message_vision ("乓地一声砸在已经打开的门上！\n",me);
    }
    if (me->query("force") <= 1000)     
      me->unconcious();
    else
    {
      me->add("force",-200);
    }
    this_object()->set("exits/east", __DIR__"shandong");
    remove_call_out ("close");
    call_out ("close",60);
  }
    return 1;
}
