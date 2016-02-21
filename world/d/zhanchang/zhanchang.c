inherit "/adm/daemons/vrm_server";

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( WARPLACE );

	//迷宫的单边长
	set_maze_long(5);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"zhanchang2");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"zhanchang1");

	//入口房间短描述
	set_entry_short("战场");

	//入口房间描述
	set_entry_desc(@LONG
门派战斗的场地。
LONG
);

	//出口房间短描述
	set_exit_short("战场");

	//出口房间描述
	set_exit_desc(@LONG
门派战斗的场地。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("战场");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
门派战斗的场地。
LONG
);

		
}
