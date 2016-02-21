
inherit BANK;

void create ()
{
  set ("short", "杨记钱庄");
  set ("long", @LONG

杨记钱庄门外挑着一大字招牌：“杨记钱庄”。屋子里面是一个高高
的紫木柜台，杨老板正一本正经地坐在柜台上结帐。钱庄的西面墙头
挂有一匾(bian)。东面是大门，通向舜王大街。

LONG);

  set("item_desc", ([
    "bian": @TEXT

客户可以在本钱庄：

account         查帐。
deposit         存款。
withdraw        取款。
convert         兑换钱币。

TEXT
  ]) );

  set("exits", ([
    "east" : __DIR__"shun4",
  ]));

  set("objects",  ([
    __DIR__"npc/yang" : 1,
  ]));

  set("no_clean_up", 0);
  setup();
}


