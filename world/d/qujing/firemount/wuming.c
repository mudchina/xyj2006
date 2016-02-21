// rewritten by snowcat on 4/11/1997
// Room: wuming

inherit ROOM;

void create ()
{
  set ("short", "无名小山");
  set ("long", @LONG

山顶上什么也没有，山的南麓是一堆乱石，间或可以见到几只野兔。
再往南去便是翠云山了。北面被大火烤得一片通红。

LONG);

  set("objects", ([
       __DIR__"npc/bajiaoq" : 1,
     ]));

  set("exits", ([
        "southdown" : __DIR__"south1",
        "eastdown"  : __DIR__"wuming4",
    ]));
  set("outdoors", "firemount");

  setup();
}
