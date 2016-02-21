// rewritten by snowcat on 4/11/1997
// Room: wuming

inherit ROOM;

void create ()
{
  set ("short", "小山南坡");
  set ("long", @LONG

山坡上乱石丛生，零零星星地长着些杂草，不时会有几只野兔从石
堆中跃出。

LONG);

  set("objects", ([
       __DIR__"npc/bajiaoq" : 1,
      ]));

  set("exits", ([
        "southdown" : __DIR__"south2",
        "northup"   : __DIR__"wuming",
      ]));
  set("outdoors", "firemount");

  setup();
}
