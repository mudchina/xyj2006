// Room: /d/city/club3
inherit ROOM;

int do_look();
void reset_long();

string long=@LONG

这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱子上贴
满了各种广告：有换房的，有卖家具的，但其中最多的还是找打牌搭
档的广告。厅的东南西北各有个门，里面传出“拱啊！”“毙了！”
等的叫声。
LONG;

void create ()
{
  set ("short", "聚义厅");
  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
//"east": __DIR__"piggy_e",
//"south": __DIR__"piggy_s",
//"west": __DIR__"piggy_w",
//"north": __DIR__"piggy_n",
  "down" : __DIR__"clubup",
  "up" : __DIR__"clubpoem",
]));

  set("objects", ([ 
	    __DIR__"npc/pig_counter" : 1,
  ]));

  setup();
  call_other("/obj/board/zhuzi_b", "???");
  reset_long();
}

object find_pig_counter()
{
    object *list = filter_array(children(__DIR__"npc/pig_counter"), 
	    (:clonep:));
    object obj;
    
    if(sizeof(list)==0) {
	seteuid(getuid());
	obj=new(__DIR__"npc/pig_counter");
	obj->move(this_object());
	return obj;
    } else
	return list[0];
}

int do_look()
{
    reset_long();
    return 0;
}

void reset_long()
{
    object pig=find_pig_counter();
    set("long",long+"\n"+pig->pig_bang());
}
