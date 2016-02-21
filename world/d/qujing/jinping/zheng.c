// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "正殿");
  set ("long", @LONG

正殿气势雄伟，佛象高高在台上。殿前有一排香案，下铺有一
些灰布蒲团。香案上有木鱼木锤经书等等。北面和东面的殿门
大开，外面是花园。

LONG);

  set("exits", ([
        "west"   : __DIR__"qian",
        "north"   : __DIR__"huayuan1",
        "east"   : __DIR__"huayuan3",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));

  setup();
}



