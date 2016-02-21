
//古战场迷宫
//tomcat 
//inherit VRM_SERVER;
inherit "/adm/daemons/vrm_server";

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM );

	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/kulou");

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"shanlu");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"taoyuan");

	//入口房间短描述
	set_entry_short("荒野");

	//入口房间描述
	set_entry_desc(@LONG
这里是据说就是上古时期天神大战的遗址，相传远古时期
北方的大神和南方的的大神为了争夺主宰的权利，在这里爆发
了一场惨烈的大战。如今这里已经破败不堪，杂草丛生的荒野
之地了，不小心就可能迷失方向了.
LONG);

	//出口房间短描述
	set_exit_short("荒野");

	//出口房间描述
	set_exit_desc(@LONG
你眼前一亮，深深的吸了口气，心想总算是出来了。四周小鸟
的鸣叫声和风吹过树林的沙沙声交织成美丽的大自然的旋律。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("古战场");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
四周越来越暗了，你胆颤心惊的象前摸索着，到处是一些
迷路人的尸体和骷髅。不时传来一阵阵鬼哭浪嚎,好象有什么
东西在暗中窥视着，你不由的加快了脚步。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}

