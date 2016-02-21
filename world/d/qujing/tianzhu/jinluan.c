// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "金銮殿");
  set ("long", @LONG

金銮殿里庄严静肃，十二根盘龙柱将大殿擎起。从天花板顶上
披下无数金银线珍珠帘，一盏盏大如莲座的翡翠灯放着奇异的
光彩。殿的中间有一白玉台阶，上有一高大的龙纹宝座。

LONG);

  set("exits", ([
        "south"   : __DIR__"zhaoyang",
        "north"   : __DIR__"yuhua",
      ]));
  set("objects", ([
        __DIR__"npc/king"   : 1,
        __DIR__"npc/junji"   : 1,
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


