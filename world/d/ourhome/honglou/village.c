// Room: /u/hkgroup/village
inherit ROOM;

//#include "honglou.h"

void create ()
{
  set ("short", "稻香村");
  set ("long", @LONG

　　　　杏帘招客饮，在望有山庄。菱荇队邬水，桑榆燕子梁。
　　　　一畦春韭熟，十里稻花香。盛世无□馁，何须耕织忙。

　　一个酒幌(sign)用竹竿挑在树梢。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "
　　　　『杏帘在望』

",
]));
  set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"april",
  "south" : __DIR__"yard1",
  "north" : __DIR__"cave",
  "east" : __DIR__"fisher",
  "enter" : __DIR__"cottage",
]));
//  set("outdoors", "/u/hkgroup");

  setup();
}

/*
int valid_leave(object me, string dir)
{
	string membership = memberhood(me);

        if ( dir=="enter" &&
//		( membership == "(NotMember)" || membership == "(guest)") ) 
              ( membership == "(NotMember)"))
        {
        return notify_fail("只听『嘭』的一声，你的脑门儿被反弹回来的门撞个正着~~~~~~~~\n");
        }
        return ::valid_leave(me, dir);
}
*/
