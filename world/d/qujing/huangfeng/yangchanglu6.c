// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yangchanglu6.c

inherit ROOM;

void create ()
{
  set ("short", "羊肠小道");
  set ("long", @LONG

小路崎岖难行，一路上但见古木参天，香花烂漫。南面有一座
高山，山头祥云环绕，瑞霭纷纷，山凹里有一座禅院，只听得
钟磬悠扬，又见那香烟缥缈。

LONG);

  set("exits", ([
        "south" : __DIR__"yangchanglu5",
        "northup" : __DIR__"shanmen",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
