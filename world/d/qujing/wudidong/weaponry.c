// Room: /d/qujing/wudidong/weaponry.c

inherit ROOM;

/************************************************************/

// some global variables.

mapping msg=([
	"changjian":	"\t三柄长剑(chang jian)\n",
	"duanjian":	"\t二柄短剑(duan jian)\n",
	"zhujian":	"\t二柄竹剑(zhu jian)\n",
	"dandao":	"\t三柄单刀(dan dao)\n",
	"mudao":	"\t二柄木刀(mu dao)\n",
]);
mapping amount=([
        "changjian":    3,
        "duanjian":     2,
        "zhujian":      2,
        "dandao":       3,
        "mudao":        2,
]);

int pull_count;
string update_wall();
string look_chair();

/************************************************************/
void create ()
{
  set ("short", "兵器库");
  set ("long", @LONG

你摸摸索索地走了过来，却发现洞内比你想象的要宽敞的多。四壁挂
着些刀剑等兵器，几个小妖正在舞锤弄斧，看上去还真有几手。洞深
处有一把宽大的石凳，据说是玉鼠赐给碧鼠的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"square2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bishu.c" : 1,
]));
  set("item_desc", ([
	"wall": (: update_wall :),
	"四壁": (: update_wall :), 
	"chair": (: look_chair :),
	"石凳" : (: look_chair :),
]));
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}
/************************************************************/

// this function is to add actions. :P

void init()
{
    add_action("do_take", "take");
    add_action("do_take", "na");
    add_action("do_pull", "pull");
    add_action("do_pull", "la");
    add_action("do_push", "push");
    add_action("do_push", "tui");
}

/************************************************************/

// this function is to allow people to take weapons from
// the wall. the weapons include 3 types of swords and 2 blades.

int do_take(string arg)
{
    object me=this_player(), ob;
    string weapon, destination, type;

    if (!arg) return notify_fail("你要拿什么？\n");
    if (me->is_busy()) return notify_fail("你上一个动作还没有完成！\n");

    if (sscanf(arg, "%s from %s", weapon, destination)!=2)
        return notify_fail("用 take <weapon> from <wall|四壁> 来拿想用的兵器。\n");

    if (destination != "wall" && destination != "四壁")
        return notify_fail("从哪里拿？\n");

    if (weapon == "chang jian" || weapon == "changjian" || weapon == "长剑"
     || weapon == "duan jian" || weapon == "duanjian" || weapon == "短剑"
     || weapon == "zhu jian" || weapon == "zhujian" || weapon == "竹剑")
    {
	if (present("sword", me))
	    return notify_fail("别这么自私，身上不是有一柄剑了吗？\n");
	if(present("sword", environment(me)))
	    return notify_fail("地上不是有吗？\n");
	type = "sword";
    }
    if (weapon == "dan dao" || weapon == "dandao" || weapon == "单刀"
     || weapon == "mu dao" || weapon == "mudao" || weapon == "木刀")
    {
	if (present("blade", me))
	    return notify_fail("别这么自私，身上不是有一柄刀了吗？\n");
	if(present("blade", environment(me)))
	    return notify_fail("地上不是有吗？\n");
	type = "blade";
    }
    if (weapon == "chang jian" || weapon == "changjian" || weapon == "长剑")
    {
	weapon = "changjian";
    }
    if (weapon == "duan jian" || weapon == "duanjian" || weapon == "短剑")
    {
	weapon ="duanjian";
    }
    if (weapon == "zhu jian" || weapon == "zhujian" || weapon == "竹剑")
    {
	weapon ="zhujian";
    }
    if (weapon == "dan dao" || weapon == "dandao" || weapon == "单刀")
    {
	weapon ="dandao";
    }
    if (weapon == "mu dao" || weapon == "mudao" || weapon == "木刀")
    {
	weapon ="mudao";
    }
    if(amount[weapon]==0)
	return notify_fail("墙上已经没有你要的兵器了。\n");
    ob=new("/d/obj/weapon/"+type+"/"+weapon);
    amount[weapon]-=1;
    if (amount[weapon] == 0)
	msg[weapon]="";
    else msg[weapon]="\t"+chinese_number(amount[weapon])+ob->query("unit")+
		ob->query("name")+
		"("+ob->query("id")+")\n";
    message_vision("$N从墙上取下一"+ob->query("unit")+ob->query("name")+"。\n", me);
    update_wall();
    ob->move(me);
    return 1;
}
/************************************************************/

// this function is used to update the message on the wall
// showing how many weapons of each type are available.

string update_wall()
{
    string wall;
wall =
"墙上挂着：

"+
(string)msg["changjian"]+
(string)msg["duanjian"]+
(string)msg["zhujian"]+
"\n"+
(string)msg["dandao"]+
(string)msg["mudao"]+
"\n";

return wall;
}

string look_chair()
{
    if (present("bi shu", this_object()))
	return "碧鼠精正歪歪扭扭地靠在石凳上，看起来象在打瞌睡。\n";

    return "一把宽大结实的石凳，凳子中央刻着个巨大的骷髅头。\n"
	   "这骷髅头竟似活的一般，一对黑洞洞的眼睛死死盯着你！\n";
}
/************************************************************/

// these actions allow the player to go into the room that has
// the kugu-blade books. need to pull 9 times on the skull, and
// push once, the hint given from bishu's nickname, 九死一生

int do_pull(string arg)
{
    object me=this_player();

    if (arg != "kulou" && arg != "skull" && arg != "骷髅")
        return notify_fail("你东张西望看了半天，没找到什么可拉的。\n");
    if (present("bi shu", this_object()))
	return notify_fail("没看见石凳上坐着人？\n");
    tell_object(me,"你将手指伸入骷髅的眼睛中，用力一掀。\n");
    tell_object(me, "骷髅突然张开了嘴，喷出一股青烟。\n");
    pull_count+=1;
    return 1;
}
    
int do_push(string arg)
{
    object me=this_player();

    if (arg != "kulou" && arg != "skull" && arg != "骷髅")
        return notify_fail("你东张西望看了半天，没找到什么可推的。\n");
    if (present("bi shu", this_object()))
	return notify_fail("没看见石凳上坐着人？\n");
    tell_object(me, "你将手指伸入骷髅的眼睛中，用力一压。\n");
    tell_object(me, "骷髅突然张开了嘴，喷出一股浓烟。\n");
    if(pull_count == 9)
    {
	message_vision("一股浓烟过后，$N不见了。\n", me);
	me->move(__DIR__"book-cave1");
	message("vision", "一阵冷风吹过，洞中突然多了一个人。\n", me);
	me->add_temp("wudidong/enter_book_cave1", 1);
        pull_count=0;
	return 1;
    }
    pull_count=0;
    message_vision("一阵浓烟中射出一道火焰，直指$N的左眼。\n", me);
    if(random(100)<(40-me->query_kar()))
    {
	message_vision("$N向旁边一闪，结果没闪开。\n", me);
	me->receive_wound("kee", 10);
    }
    else
    {
	message_vision("$N向旁边一闪，让了开去。\n", me);
    }
    return 1;
}
/************************************************************/
