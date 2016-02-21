// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "天井");
  set ("long", @LONG

小小院子里铺着石条，墙边种着无名花草，墙上爬着藤条结着
棘皮葫芦。院子一角架有一木架，架上拉着长绳晒着几件洗净
的衣服。

LONG);

  set("exits", ([
        "east"    : __DIR__"guafu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

