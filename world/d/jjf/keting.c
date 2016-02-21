// Room: /d/jjf/keting.c

inherit ROOM;

void create ()
{
  set ("short", "正厅");
  set ("long", @LONG

厅门口挂着一块横匾，上书「铁面无私」四个大字，看来还是御笔
亲书。几个家将站立两旁。秦将军坐在当中的太师椅上，不怒自威。
看到你进来，他对你点头笑了笑。也许是因为没有人说话，厅上的
气氛很严肃。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone_road",
  "north" : __DIR__"front_yard2",
  "west" : __DIR__"side_keting",
  "east" : __DIR__"dining_room",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/jiajiang" : 2,
  __DIR__"npc/qinqiong" : 1,
]));
  set("valid_startroom", 1);

  setup();

  call_other("/obj/board/jjf_b", "???");
}
/*
int valid_leave(object me, string dir)
{
  if ((dir == "east") || (dir == "south") || (dir == "west") )
    {
      if (!(  ((string)me->query("family/master_name") == "罗成")
	  ||  ((string)me->query("family/master_name") == "秦琼"))
	  &&  objectp(present("qin qiong", environment(me)))
)
	return notify_fail("将军府内堂，企可随便出入？\n");
      return ::valid_leave(me, dir); 
    }
  return 1;
}
*/
