// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "花涧");
  set ("long", @LONG

古树连天，瀑布自山岩上长挂下来，两边是涧水潺流，飘满落
花朵朵。岸上垂柳煦风绿色满园，路上铺着五彩小石卵，细细
碎碎如甘露洒落。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"huajian1",
        "north"    : __DIR__"qianhua",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

