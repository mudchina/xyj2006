// created by snowcat

inherit ROOM;

void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

皇宫大殿里金光闪烁瑞霭如云紫气环绕，殿中是雕龙绘凤祥云朵
朵，殿心有一白玉台阶，正中是金银宝座，唐太宗怡然高坐。两
边文武官弁肃然伫立，神态庄严。

LONG);

  set("exits", ([
        "south"   : __DIR__"baiyujie",
        "north"   : __DIR__"houdian",
        "east"   : __DIR__"dongdian",
        "west"   : __DIR__"xidian",
      ]));
  set("objects", ([
        __DIR__"npc/dachen1" : 1,
        __DIR__"npc/dachen2" : 1,
        __DIR__"npc/dachen3" : 1,
        __DIR__"npc/dachen4" : 1,
        __DIR__"npc/dachen5" : 1,
        __DIR__"npc/emperor" : 1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "east" || 
      dir == "west" ||
      dir == "north")
  {
    message_vision ("$N将头往殿里一探，里面几个威武武弁将$N架出。\n",who);
    return notify_fail("");
  }
  if (dir == "south" && who->query_temp("mpwar_join")) 
   {
    write ("你真的不拿奖励吗。\n");
    return notify_fail("");
  }
  return 1;
}

