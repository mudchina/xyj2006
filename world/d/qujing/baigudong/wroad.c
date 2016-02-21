// Room: come to pingding  writted by smile 12/09/1998

inherit ROOM;

void create ()
{
  set ("short", "平顶山界");
  set ("long", @LONG

    很快就要进入平顶山界了，令人恐惧的白骨洞越来越远，
不禁让人想坐下来休息休息。可是眼看太阳就要西下，薄
暮中的平顶山也迷糊起来，路旁幽幽鸟鸣提醒人们，快走，
快走。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yelu8",
  "east" : __DIR__"sanchakou",
]));

  setup();
}






