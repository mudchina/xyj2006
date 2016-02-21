// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "林中木屋");
  set ("long", @LONG

长廊的尽头现出一个小木屋，木屋从外边看起来不大，周围也很
安静，听不到一丝声响。奇怪地是从木板的缝隙中透出几许红光。
正面一扇木门紧闭。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"houlang4",
  "enter": __DIR__"room",
]));

  setup();
}
/*
void init()
{
        add_action("do_knock", "knock");
}

int do_knock(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "door") ))
                return notify_fail("你要敲什么？\n");

	message_vision("$N轻轻的拉起门上的铜环，＂啪，啪＂地扣了两下。\n",me); 
	message_vision("门被轻轻拉开，走出位中年道人，上下打量了$N一番。\n",me);
	if((string)me->query("family/family_name")=="方寸山三星洞") {
			if(((int)me->query("combat_exp") < 100000)) {
			message_vision("中年道人对$N笑道：道兄也来拜见祖师吗？\n",me);
			message_vision("$N随着中年道人走了进去。\n",me);
	                tell_room( environment(me), "门又轻轻的关上了。\n",({me}));
        	        me->move("/d/lingtai/room");
                	tell_room( environment(me), me->name() + "走了进来。\n",({me}));
			return 1;
			}
		message_vision("$N随着中年道人走了进去。\n",me);
		tell_room( environment(me), "门又轻轻的关上了。\n",({me}));
                me->move("/d/lingtai/room");
		tell_room( environment(me), me->name() + "走了进来。\n",({me}));
                return 1;
		}
        message_vision("中年道人皱了皱眉头：切莫久留，扰我祖师清修！\n", me);
	message_vision("$N随着中年道人走了进去。\n",me);
        tell_room( environment(me), "门又轻轻的关上了。\n",({me}));
        me->move("/d/lingtai/room");
        tell_room( environment(me), me->name() + "走了进来。\n",({me}));


	return 1;

}


*/
