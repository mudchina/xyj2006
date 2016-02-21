// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/guanwai.c

inherit ROOM;

void create ()
{
  set ("short", "关外");
  set ("long", @LONG

到得此处已非大唐领地。向西望去只见群山连绵，一条土路
蜿蜒于群山峻岭之间。往东进了嘉峪关就是大唐国了。嘉峪
关巍峨雄伟，果有一夫当关，万夫莫开的气势。

LONG);
 
  set("exits", ([
        "east"      : "/d/westway/jiayu",
        "southwest"   : __DIR__"shanlu1",
      ]));

  set("outdoors", __DIR__);

  setup();
}


