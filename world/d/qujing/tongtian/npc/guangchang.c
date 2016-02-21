//Cracked by Roath
// Room: /d/nanhai/guangchan
inherit ROOM;

void create ()
{
  set ("short", "洞前广场");
  set ("long", @LONG

这是南海普陀山上一快比较平整的土地，普陀山门人弟子们经
常在这里切磋武艺，宣讲佛法，交流心得。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/nanhai/npc/huian" : 1,
  "/d/nanhai/npc/zhangmen" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/nanhai/xiaoyuan",
  "west" : "/d/nanhai/zoulang",
  "east" : "/d/nanhai/road1.c",
  "enter" : "/d/nanhai/chaoyindong",
]));

  setup();
}
void init()
{
	add_action("do_back", "back");
}
int valid_leave(object me, string dir)
{
	if (dir == "enter" )
	{
	  if(me->query("obstacles/tongtian")=="guanyin")
	    return notify_fail("观音在讲经不能见你，你到后面(back)去等她吧．\n");
	}
return 1;
}

int do_back(string arg)
{
	object me = this_player();
	if (arg) return 0;
	if( me->query("obstacles/tongtian")!="won") return 0;
	if (me->is_busy()) return notify_fail("等你忙完了再说也不迟嘛！\n");
	me->move("/u/opal/qujing/tongtian/lianting");		
	return 1;
}
