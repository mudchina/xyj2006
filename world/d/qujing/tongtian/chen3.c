// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "陈家庄");
  set ("long", @LONG

陈家庄里住着大大小小的人家，多姓陈故为陈家庄。庄子里不
时可听见热闹的声音，夹杂着鸡鸣狗叫。一些人家的烟囱里冒
出淡淡的烟，空气中散发着柴烟香。

LONG);

  set("exits", ([
        "north"   : __DIR__"chen1",
        "west"   : __DIR__"xiaolu2",
        "east"   : __DIR__"minju5",
        "south"   : __DIR__"jitan",
        "southeast"   : __DIR__"minju6",
      ]));
  set("outdoors", __DIR__);

  setup();
}



