// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "朝门");
  set ("long", @LONG

宫殿雄伟琼阁入云，一座淡绿色朝天拱门南北向大开，门楼上
飘扬着太平旗。里面就是比丘国的王宫，祥云瑞瑞紫气腾腾，
歌舞乐声徐徐传来。

LONG);

  set("exits", ([
        "north"    : __DIR__"xiaozi",
        "southwest"    : __DIR__"guan",
        "west"    : __DIR__"da",
      ]));
  set("objects", ([
        __DIR__"npc/wenguan"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir != "north")
    return 0;
  return 1;
}
