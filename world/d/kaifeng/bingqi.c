//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "兵器场");
  set ("long", @LONG

御相府的兵器场面积不小，大部分兵器自外面收集而来。分类挑选之
后，特等精品派专人送到长安进贡给唐王，上等佳品送军务大臣处备
案仿造。兵器场的南边有一门通往相府中堂。

LONG);

  set("exits", ([
        "south" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
        __DIR__"npc/xgong" :  1,
      ]));

  setup();
}


