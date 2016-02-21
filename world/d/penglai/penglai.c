//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "蓬莱仙岛");
  set ("long", @LONG

蓬莱岛上风光秀丽，当真是好去处！远望海中，碧波如镜，高山之
上，巍峨势耸。山间少闻人语声，但听猿啼鹤鸣。几树乔松栖野鹤，
数株翠柳语山莺。曲径碧萝垂挂，石梯蓬葛攀笼。远山见白云出釉，
近现花色蓉蓉。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"undertree",
    "southup":  __DIR__"hongyandong",
]));
	set("outdoors", 1);
  setup();
}
int valid_leave(object me, string dir)
{       
	object room;

	if (dir=="northup"){
		if( room=load_object(__DIR__"yashang")) {
			if( (int)room->query("grow_grass") ) {
			return ::valid_leave(me, dir);
			}
			room->grass_grow();
			room->set("grow_grass",1);
		}
	return ::valid_leave(me, dir);
	}
	return 1;
}
