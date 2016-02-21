// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "洞厅");
  set ("long", @LONG

洞厅乃一较大的洞穴，里面洞壁上插着兽油火把，中间有石桌
石凳。洞的深处有一排排兵器架，洞的东南方向有一通道，通
向洞外。

LONG);

  set("exits", ([
        "southeast"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



