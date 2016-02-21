// Room: /u/rainy/sea/jiashan1.c
inherit ROOM;

void create ()
{
  set ("short", "假山");
  set ("long", @LONG

假山上多有尖石玲珑，耸拔瘦削。远观如有山云突涌，夹杂草木嫩
绿满山。假山上却有一铜石，中有小孔(hole)。间闻园中笑音阵阵，
极是热闹。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "hole" : "洞中似乎是个机关，能放(insert)下什么东西。\n",
]));



  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yidao",
]));
//      
        set("water", 1);
//  
  setup();
}
void init()
{
	add_action("do_insert", "insert");
}
int do_insert(string arg)
{
        object mishi, ob, me;
	me=this_player();
	if( !arg )
		return notify_fail("你要放什么东西？\n");

        if( !arg || arg!="yao pai" || !(ob=present(arg, me)) || ob->query("name")!="水晶腰牌" )
		return notify_fail("似乎孔中放不下这个东西。\n");


        if( !(mishi = find_object(__DIR__"mishi1")) )
                mishi = load_object(__DIR__"mishi1");

        if( mishi = find_object(__DIR__"mishi1") ) 
        {
                set("exits/enter", __DIR__"mishi1");
                message_vision("$N将$n塞入小孔，只听喀喀几声，一座大石移开，露出向下一个通口。\n", me, ob);
                message("vision", "大石被人从外推开了。。\n", mishi );
		mishi->set("exits/out", __DIR__"jiashan1");
		destruct(ob);
        call_out("close_down", 10);
	}
	return 1;
}

void close_down()
{
        object mishi;

        message("vision", "大石轰地又回到原位。\n", this_object() );
        if( mishi= find_object(__DIR__"mishi1")) {
        message("vision", "大石轰地又回到原位。\n", mishi);
        mishi->delete("exits/out");
        }

        delete("exits/enter");

}

