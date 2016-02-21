// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山涧");
  set ("long", @LONG

山路绕过一个轰然作响的山涧，这里地势低平，东边岩石下涧
水急速地冲走，腾起一片白白的雾气。西北边有一个山凹，西
南有一下山的斜坡。

LONG);

  set("exits", ([
        "up"   : __DIR__"shanjian",
      ]));
  set("objects", ([
        __DIR__"npc/niujiao"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  object who = this_player();
  if ( who->is_busy() )
               return 1;
        
  message_vision ("$N浑身颤抖着，向下一跳……\n",who);
  who->move(__DIR__"jian2");
  return 1;
}

