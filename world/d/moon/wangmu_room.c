//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "卧云轩");
  set ("long", @LONG

此间乃是王母居处，收拾的与别处不同，竟分不出间隔来的。四面皆是雕
空玲珑木板，或「流云百蝠」，或「岁寒三友」，或山水人物，或翎毛花
卉，或集锦，或博古，或万万福寿，各种花样，皆名手雕镂，五彩销金嵌
宝的。一隔一隔，或有贮书处，或设鼎处，或安置笔砚处，或供花设瓶安
放盆景处，其格各式各样，或天圆地方，或葵花蕉叶，或连环半壁，真是
花团锦簇，剔透玲珑。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiwangmu.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huilang1.c",
]));

  setup();
}
