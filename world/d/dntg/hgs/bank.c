// Room: /d/4world/bank.c
inherit BANK;

void create ()
{
  set ("short", "张家钱庄");
  set ("long", @LONG

张家钱庄张万宝乃是城中首富，和许多王孙公子也很有交情。由
于其经营有方，门路又广，钱庄的生意也是不错。正中横摆一张
七尺柜台，台前有个小牌子(paizi)。后面站着位精明的老先生。
LONG);
        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：

account         查帐。
deposit         存款。
withdraw        取款。
convert         兑换钱币。
TEXT

]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"north2",
]));

  setup();
}
