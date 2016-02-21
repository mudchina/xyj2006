// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "阴阳塔");
  set ("long", @LONG

阴阳塔内成拱形，上方一片光明。隐约看到有阴阳二气轮回相转不
绝。周围墙上按八方画了八卦之象。空中偶有磷火飘飘，又好象隐
隐传来和尚道士做法事时的铃响。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk4",
]));
  set("hell", 1);

  setup();
}

void init()
{
        object who=this_player();
        if( (string)who->query("family/family_name")=="阎罗地府" ) {
                call_out("heal_up", 9, who);
        }
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
	string *msgs=({
    "「铛，铛」传来几声铃响。\n",
    "「啪」地一道火花闪过。\n",
    "“咚咚咚”一阵鼓声传来。\n",
    "「呼」地一阵冷风吹过。\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("忽然一股青气笼住了$N。\n", who);
        write("你觉得自己的精神气血一下子都恢复了。\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}


