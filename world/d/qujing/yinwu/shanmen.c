// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

山巅之处有一背风低坳，古树连天，岩壁上有一石门。只见那
石门紧闭，门上有一个横石板，石板上书有“隐雾山折岳连环
洞”几个大字。

LONG);

  set("exits", ([
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_break","break");
}

int do_break (string arg)
{
  object tudi;
  object who = this_player();

  if (! arg || (arg!= "door" && arg!= "men"))
    return notify_fail ("你要砸什么？\n");

  message_vision ("$N憋红了脸大喝一声向门砸去！\n",who);
  message_vision ("\n一阵乱石轰响，砸在$N的头上！\n",who);
  who->unconcious();    
  if (who->query("combat_exp") < 10000 ||
      random(4))
  {
    return 1;
  }
  if (present("tu di",this_object()))
    return 1;
  tudi = new (__DIR__"npc/tudi");
  tudi->move(this_object());
  tudi->command_function("hi");
  return 1;
}
