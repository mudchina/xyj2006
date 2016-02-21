// Room: /d/death/road3.c

inherit ROOM;

void create()
{
        set("short", "黑暗之中");
        set("long", @LONG

也不知是到了那里，只觉得四周异常狭小．上下左右不过寸余．
连翻身都是不可能的．什么也看不到，什么也听不到．空气中
有一股腐烂的味道．
LONG
        );
set("exits", ([ /* sizeof() == 4 */
]));

        set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_magic", 1);
        setup();
}
void init()
{
	object who=this_player();
	if( (string)who->query("family/family_name")=="阎罗地府" ) {
		call_out("heal_up", 10, who);
	}

        add_action("do_open", "open");
}

int do_open(string arg)
{       
        object me;
        int sen,damage;
        me=this_player();

        if ( !arg || ((arg != "guancai")&&(arg != "棺材") ) )
                return notify_fail("你要打开什么？\n");
        else {
          sen=me->query("sen");
          damage=random(10)+10;
	  if(sen>damage) {
            message_vision("$N飞起一脚踢开棺材，爬了出去。\n\n",me);
            me->receive_damage("sen",damage);
	    me->set("gin", (int)me->query("max_gin"));
            me->move("/d/changan/fendui");
            message_vision("\n坟上的土动了动，$N顶着满头的杂草钻了出来。\n",me);
          } else {
            message_vision("$N飞起一脚朝棺盖踢去．．．\n\n",me);
	    me->receive_damage("sen",damage);
	  }
        }
        return 1;
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ) return 1;


        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

	message_vision("忽然一股青气笼住了$N。\n", who);
	write("你觉得自己的精神气血一下子都恢复了。\n");

	return 1;
}
