// Room: /d/qujing/wudidong/guanjia.c

inherit ROOM;

void create ()
{
  set ("short", "偏洞");
  set ("long", @LONG

这偏洞虽非金窗玉槛，却也是颇为富丽堂皇，原来无底洞的总管就住
在这里。洞深处的梳妆台上红烛高点，台前坐着一个妖娆女子，正在
对镜整妆，衣衫上传来阵阵浓香扑鼻，却掩不住这洞中的一股骚臭之
气。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"square2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tianshu" : 1,
]));
  set("outdoors", 0);

  setup();
}
