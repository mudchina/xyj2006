//Cracked by Roath
// Room: ylt.c
// AceP

inherit ROOM;

void create()
{
	set("short", "杏林");
	set("long", @LONG

不知从何时开始昆仑山的玉女峰上便有了这么一片杏林，杏林
中便有了这么一位老人。他总在花前月下出现，为天下的有情
人祝福，主婚。此刻他拄着木杖，坐在一块大石头上，正在认
真地翻阅着一本看起来很特别的簿子(book)。
LONG
	);

	set("no_fight", "1");
	set("no_magic", "1");
	set("no_sleep_room", "1");

	set("item_desc", ([
		"book" : "这簿子颜色很特别，封面书着《姻缘簿》，据说是记载天上地下\n所有姻缘的档案。你可用 read book 来查阅。\n"
		]));

	set("exits", ([
		"out" : __DIR__"yltw",
	]));

	set("objects", ([
		__DIR__"npc/yuelao": 1,
	]));

	setup();
}

void init()
{
        add_action("read_book","read");
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="book") return 0;
   write("\n               ===  姻缘录  ===\n\n");
   if(file_size("/log/yl.rc")>0)
     this_player()->start_more( read_file("/log/yl.rc"));
   write("\n");
   return 1;
}
