//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "天蓬府门");
  set ("long", @LONG

天蓬帅府高大雄伟，府门旌旗迎风招扬，每幅旌旗上都画着大猪头。
门前有几个猪头猪脑的兵士在来回巡逻，西边是尧王街，往东进入便
是帅府内。

LONG);

  set("exits", ([
        "east" : __DIR__"shuaifu",
        "west" : __DIR__"yao1",
      ]));
  set("objects", ([
        __DIR__"npc/zhubing" :  2,
      ]));

  setup();
}


