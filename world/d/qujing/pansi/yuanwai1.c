// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "院外");
  set ("long", @LONG

院外茅草丛生，阴风朔朔令人不禁有点胆寒。南面是一座高大
的墙，墙根下面有一暗洞直通黄花观院内。北面是绝路悬崖峭
壁，无路可行。

LONG);

  set("exits", ([
        "south"    : __DIR__"yuannei",
      ]));
  set("objects", ([
        __DIR__"npc/xie1"    : 1,
        __DIR__"npc/xie2"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

