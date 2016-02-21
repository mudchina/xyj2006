// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "大路");
  set ("long", @LONG

一条宽敞的大路，由碎石铺就，可行车马。南北向伸延出去，北面
伸向远处，南面通向朱紫国。路两边长着庄稼，偶见农舍。

LONG);

  set("exits", ([ 
    "north" : __DIR__"dalu1",
    "south" : __DIR__"zhuzi1",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
