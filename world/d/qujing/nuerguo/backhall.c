// created by snowcat.c 4/4/1997
// room: /d/nuerguo/backhall.c

inherit ROOM;

void create ()
{
  set ("short", "后宫");
  set ("long", @LONG

这便是西梁公主接见宾客的后宫了。一帘镶珠紫红大帐将后
宫的入口遮严，殿内庄严肃穆，正中玉白台阶上是彩龙金凤
双蝶宝座，上面高高地坐着西梁公主。

LONG);

  set("exits", ([
        "north" : __DIR__"greenyard",
        "south" : __DIR__"fronthall",
      ]));

  set("objects", ([
         __DIR__"npc/princess" : 1,
         __DIR__"npc/girl" : 1,
     ]));

  setup();
}

int valid_leave (object me, string dir)
{
  object princess;
  princess = present("xiliang princess",environment(me)); 
  if (princess && dir=="north") 
  {
    return notify_fail("小公主对你大喝一声大胆！\n");
  }
  // once get into here, reset all greenyard temps, to prevent abuse
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}

