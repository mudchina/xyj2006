// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver1.c

inherit ROOM;

void create ()
{
  set ("short", "子母河东岸");
  set ("long", @LONG

澄澄清水，湛湛寒波。一条小河(river)横在前面。对面是西梁
女国。你看了一看四周没有桥也没有摆渡，河水在此处深而急，
直接趟过去有点危险。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "river" : "这大概是母子河吧，泛着清绿色的光泽。
据说喝了母子河水饮了会怀孕。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastriver2",
  "east" : __DIR__"start",
]));
  set("outdoors", __DIR__"");

  setup();
}
