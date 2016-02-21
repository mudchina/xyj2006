// Room: baigushan.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "白骨山");
  set ("long", @LONG

    这里就是白骨山了。但见雾气腾腾罩山头，腥风阵阵刮
树藤，路遗嶙峋白骨，脚踩空洞骷髅，让人头皮一阵发麻，
心跳加速。
    山头旌旗飘舞，远远看去，上面似乎绣了一个大大的白
字。阴郁的阳光下，散发出妖异的光芒。半山立着一个亭
子，隐隐约约有几个身影在晃动。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"broad",
  "southdown": __DIR__"sanchakou",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("xiaoyao") == "xiaoyao" &&
      dir == "southdown")
    return 0;
  return ::valid_leave (who, dir);
}

