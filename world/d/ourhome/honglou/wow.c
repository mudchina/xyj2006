// Room: /u/hkgroup/wow

inherit ROOM;

//#include "honglou.h"

void create()
{
  set ("short", "空房间");
  set ("long", @LONG
这是一间什么都没有的房间。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
　　　　世人都晓神仙好，只有功名忘不了！
　　　　古今将相在何方？荒冢一堆草没了！
　　　　世人都晓神仙好，只有金银忘不了！
　　　　终朝只恨聚无多，及到多时眼闭了！
　　　　世人都晓神仙好，只有姣妻忘不了！
　　　　君生日日说恩情，君死又随人去了！
　　　　世人都晓神仙好，只有儿孙忘不了！
　　　　痴心父母古来多，孝顺儿孙谁见了？

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yard1",
]));
  set("no_clean_up", 1);
  setup();
}

void init()
{
        object me = this_player();

        message_vision("$N被一块看不见的石头(stone)绊了一下。\n", me);
}


