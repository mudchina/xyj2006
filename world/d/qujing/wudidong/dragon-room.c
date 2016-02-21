// created by mes, updated 6-17-97 pickle

inherit ROOM;
void create ()
{
  set ("short", "龙穴");
  set ("long", @LONG

挤过石缝一瞧，乖乖不得了。这里原来是条井龙的巢穴。虽然这里没
有水，但潮湿无比。四处爬着各种各样你从未见过的虫子，角落里一
堆骸骨(bones)发散着阵阵腐臭之气。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"well",
]));
  set("outdoors", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon" : 1,
]));

  setup();
}

void init()
{
	add_action("do_move", "move");
}

int valid_leave(object me, string dir)
{
  if(dir=="west" &&
     objectp(present("dragon", environment(me))))
    return notify_fail("恶龙挡住了你的去路！\n");
  return ::valid_leave(me, dir);
}

int clean_up()
{
  return 0;
}

int do_move()
{
	object me=this_player();
	object biyaoshi;

	if( !(biyaoshi =find_object(__DIR__"biyaoshi"))) 
		biyaoshi=load_object(__DIR__"biyaoshi");
	if( biyaoshi = find_object(__DIR__"biyaoshi")) {
		message_vision("$N移动了几根骸骨，居然发现了一个按钮。\n", me);
		if(biyaoshi->query("door_locked")) {
			message_vision("$N按了按按钮，却什么也没发生。\n", me);
		}
		else {
			message_vision("$N按了一下按钮，脚下突然出现一道裂缝，\n", me);
			message_vision("$N落入裂缝之后，裂缝就合上了。\n", me);
			me->move(__DIR__"biyaoshi");
		}
	}
	return 1;
}

