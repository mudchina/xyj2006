#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "云楼殿");
  set ("long", @LONG

云楼殿乃是托塔天王之公务堂，托塔天王乃是天界元帅，云楼殿
实乃是天界之军事中枢。廊下将军天王两旁列，杀气腾腾，堂前
一对金烛燃，指点光明。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "up" : "台上白云绕绕，什么也看不清楚。\n",
]));

set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
    "up": __DIR__"yunloutai",
    "south": __DIR__"yongdao",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/julingshen" : 1,
]));

  setup();
}


int valid_leave(object me, string dir)
{       
/*        object a;
        if( wizardp(me)) return 1;

        if (dir == "up" && !me->query("mieyao") ) {
                if(objectp(a=present("juling shen", environment(me))) && living(a) )
                return notify_fail("巨灵神对你大喝一声：呜，与我闪开！\n");

        return ::valid_leave(me, dir);
        }
*/
        return 1;
}

