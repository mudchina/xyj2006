// Room: /d/jjf/jjf_bingqi.c

inherit ROOM;

void create ()
{
  set ("short", "兵器架");
  set ("long", @LONG

这里有一个兵器架(rack)，十八般兵刃样样齐全。架子旁边挂着数十
副闪闪发光的盔甲，腰带，和战靴等物。旁边一位将军正闭目养神，
看来可以跟他要一副衣甲和一件趁手的兵器。
LONG);

  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinping" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"front_yard2",
]));

  set("item_desc", ([
"rack": "
兵器架上插着：

长剑(sword)，单刀(blade)，铜锏(mace)，长枪(spear)，
铁锤(hammer)，板斧(axe)，钢叉(fork)，和铁棍(stick)。

旁边摆着：

匕首(dagger)，皮鞭(whip)，弓箭(bow)，和一些飞蝗石(throwing)。

一边衣架上挂着：

钢盔(head)，铁甲(body)，护心镜(waist)，和战靴(feet)。

",
]));
  setup();
}
