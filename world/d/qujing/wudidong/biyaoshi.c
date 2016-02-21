// 避妖室 bbs 8-17-98

inherit ROOM;

void create()
{
	set("short", "避妖室");
	set("long", @LONG

这是一间小石室，收拾得很干净，虽然在地下，却似乎一点儿也不气闷。
一张小石桌上放着一盏点着的油灯(light)。
LONG);

	set("item_desc", ([
		"light" : "一盏昏暗的油灯，黄铜的灯座似乎与桌子连在一起，\n你试了试，灯座好象可以转(turn)动。\n",
	]));
	set("exists", ([
		"up" : __DIR__"dragon-room",
	]));
	set("ligh_up", 1);
	set("door_locked",0);

	setup();
}

void init()
{
	add_action("do_turn", "turn");
}

int do_turn()
{
	object me=this_player();

	message_vision("$N转了一下灯座，",me);
	if(query("door_locked")) {
		message_vision("灯座喀啦，喀啦地响了两声。\n",me);
		set("door_locked", 0);
		set("exits/up", __DIR__ "dragon-room");
	}
	else {
		message_vision("灯座喀嚓响了一声。\n",me);
		set("door_locked", 1);
		delete("exits/up");
	}
	return 1;
}

