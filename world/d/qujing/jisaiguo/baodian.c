#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG

宝殿正中的一尊大佛好象已很久没有上金了，身上的金衣大部分
脱落，看起来很滑稽。周围的菩萨罗汉竟都拿红布包了起来，上
面落着厚厚的灰尘，后面有道小门，象是通向个要紧的地方。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/kusu" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
//  "enter" : __DIR__"tower1",
  "southdown" : __DIR__"inner3",
]));

  setup();
}

void open_down()
{
        object tower;

        if( !(tower = find_object(__DIR__"tower1")) )
                tower = load_object(__DIR__"tower1");

        if( tower = find_object(__DIR__"tower1") ) 
        {
                set("exits/enter", __DIR__"tower1");
                message("vision", "苦宿禅师掏出把钥匙，将门上的铜锁打开。\n", this_object() );
		message("vision", "小门被人从外面打开了。\n", tower );
        set("long", @LONG
    
宝殿正中的一尊大佛好象已很久没有上金了，身上的金衣大部分
脱落，看起来很滑稽。周围的菩萨罗汉竟都拿红布包了起来，上
面落着厚厚的灰尘，后面有道小门，门开着，里面黑洞洞的。
LONG);
	}
	
        call_out("close_down", 300);
}

void close_down()
{
        object tower;

	message("vision", "小门啪的一声又关上了。\n", this_object() );
	if( tower= find_object(__DIR__"tower1")) {
	message("vision", "小门被人关上了。\n", tower);
	tower->delete("exits/out");
	}

        delete("exits/enter");
        set("long", @LONG
    
宝殿正中的一尊大佛好象已很久没有上金了，身上的金衣大部分
脱落，看起来很滑稽。周围的菩萨罗汉竟都拿红布包了起来，上
面落着厚厚的灰尘，后面有道小门，门上一把铜锁，象是通向个
要紧的地方。
LONG);
}

