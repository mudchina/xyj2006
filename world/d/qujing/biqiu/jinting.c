// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "金亭馆");
  set ("long", @LONG

金亭馆为远道而来的客人而设，门有一对招牌红灯笼，屋里有
杨木茶桌和几把椅子，墙角有软草席纱罩木床。有几位客人正
在馆里休息聊天。

LONG);

  set("exits", ([
        "west"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/suohana"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  set("valid_startroom", 1);
  setup();
}

