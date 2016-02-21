// rewritten by snowcat on 4/11/1997
// Room: south2

inherit ROOM;

void create ()
{
  set ("short", "小山南坡");
  set ("long", @LONG

山坡上乱石丛生，零零星星地长着些杂草，不时会有几只野兔从石堆
中跃出。东南不远处是一座小庙，似是歇脚的好去处。

LONG);

  set("objects", ([
        __DIR__"npc/qiaofu" : 1,
  ]));
  set("outdoors", "firemount");
  set("exits", ([
        "southeast" : __DIR__"xiaomiao",
        "northup"   : __DIR__"south1",
        "southdown" : __DIR__"south3",
      ]));
      
  setup();
}
