// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/tiandi.c

inherit ROOM;

void create ()
{
  set ("short", "天地阁");
  set ("long", @LONG

天地阁祥云飞舞瑞霭环绕，阁内绘云万道金丝银线缭绕朦胧，阁
中是金光闪闪的宝座。四周文官武弁目光炯炯肃然伫立，两边自
有洁衣宫女手托金银果盘，内有百味异果香醪佳酿。

LONG);

  set("exits", ([
        "northdown"   : __DIR__"yujie6",
      ]));
  set("objects", ([
        __DIR__"npc/girl" : 2,
        __DIR__"npc/king" : 1,
       ]));

  setup();
}

