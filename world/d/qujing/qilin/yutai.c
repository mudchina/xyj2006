// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "玉台");
  set ("long", @LONG

山环路的开阔地带处，立有一块凸出于山外的大石，洁白净光无草
无藓样子奇特。大石平滑可并排坐下二人，石头的下侧刻有两个大
字：“玉石”。

LONG);

  set("exits", ([ 
    "left" : __DIR__"shan11",
    "right" : __DIR__"shan12",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N奋力向上爬去。\n",who);
  message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
  who->unconcious();
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N鼓足勇气往下跳去。\n",who);
  message_vision ("$N砰地重重摔在台下。\n",who);
  who->unconcious();
  return 1;
}
