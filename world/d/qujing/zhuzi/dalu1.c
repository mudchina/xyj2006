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
    "northeast" : __DIR__"lin4",
    "west" : __DIR__"lin6",
    "south" : __DIR__"dalu2",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
