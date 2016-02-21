#include <room.h>
inherit ROOM;

// by snowcat 1998.9.1 reminder:
//    东方七宿　南方七宿　西方七宿　北方七宿
//
//    房日(兔)　星日(马)　昂日(鸡)　虚日(鼠)
//    心月(狐)　张月(鹿)　毕月(乌)　危月(燕)
//    亢金(龙)　鬼金(羊)　娄金(狗)　牛金(牛)
//    角木(蛟)　井木(■)　奎木(狼)　斗木(獬)
//    尾火(虎)　轸水(蚓)　参水(猿)　壁水(狳)
//    箕水(豹)　翼火(蛇)　觜火(猴)　室火(猪)
//    氐土(貉)　柳土(獐)　胃土(雉)　女土(蝠)
    

void create ()
{
  set ("short", "二十八宿殿");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanmenting.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"stars/foxer" : 1,
  __DIR__"stars/acer" : 1,
  __DIR__"stars/smallfox" : 1,
  __DIR__"stars/cygnus" : 1,
  __DIR__"stars/ljty" : 1,
]));

  setup();
}
