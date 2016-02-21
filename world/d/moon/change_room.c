//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "长思馆");
  set ("long", @LONG

房中珠帘低垂，案上炉中点着一束沉香，轻烟袅绕。当地放著一张花梨大
理石大案，案上堆著各种名人法帖，并十数方宝砚，各色笔筒；那一边设
著斗大的一个汝窑花囊，插著满满的水晶球的白菊花。书案正中撂着几张
绢纸，字迹娟秀，似是嫦娥百般无赖之中所涂。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "纸上反反复复地写着一句话：天不老，情难绝，心似双丝网，中有千千结。
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/change.c" : 1,
  "/d/obj/flower/juhua.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huilang.c",
]));

  setup();
}
