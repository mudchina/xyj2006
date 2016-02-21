// rewritten by snowcat on 4/11/1997
// Room: shimen

inherit ROOM;

void create ()
{
  set ("short", "石洞门");
  set ("long", @LONG

洞门由两块大石板依山势修葺而成。旁有一堆乱石(stone)，似是
为封严洞门时准备的。

LONG);

  set("light_up", 1);
  set("outdoors", "firemount");
  set("exits", ([
        "west" : __DIR__"dongkou",
      ]));
  set("item_desc", ([
        "stone" : "一堆石头，不妨拿些石头来砸砸门。\n",
      ]));

  setup();
}

void init()
{
  add_action("do_get", "get");
  add_action("do_hit", "hit");
}

int do_get (string arg)
{
  object stone;
  object me = this_player();

  if (arg != "stone")
    return 0;

  stone = new (__DIR__"obj/stone");
  stone->move(me);
  message_vision("$N从石堆里拿出一块石头。\n",me);
  return 1;
}

int do_hit (string arg)
{
  object me = this_player();

  if (!present("stone",me))
    return 0;

  me->add_temp("obstacle/firemount_hit_door",1);
  if ((arg != "shimen" &&
       arg != "door") ||
      me->query_temp("obstacle/firemount_hit_door") > 10)
  {
    message_vision("$N拿起石头，一不小心砸在自己脚上。\n",me);
    return 1;
  }
  message_vision("$N拿起石头，用力地砸起石门。\n",me);
  call_out("cloud_or_fog_appear",random(5)+5,me);
  return 1;
}

void cloud_or_fog_disappear(object me)
{
  if(!me) return;
  message_vision ("$N慢慢地在红色云雾里消失了。\n",me);
  destruct(me);
}

void cloud_or_fog_appear(object me)
{
  object cloud;
  object fog;

  if(!me) return;

  if (! present("cloud fog",this_object()) &&
      random(2) == 0)
  {
    cloud = new (__DIR__"npc/cloud");
    cloud->move(environment(me));
    message_vision("一阵红云降临，$N在云里出现。\n",cloud);
    call_out("cloud_or_fog_disappear",20,cloud);
  }

  if (! present("fog cloud",this_object()) &&
      random(2) == 0)
  {
    fog = new (__DIR__"npc/fog");
    fog->move(environment(me));
    message_vision("一阵红雾降临，$N在雾里出现。\n",fog);
    call_out("cloud_or_fog_disappear",20,fog);
  }
}
