inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
山路弯弯曲曲，一直延伸的远方。路旁长满了杂草。
不时有几声虫鸣从草丛间传出来。
LONG);

    set("exits", ([
          "east"      : __DIR__"shandao1",
        ]));

  set("outdoors", __DIR__);

    setup();
}

