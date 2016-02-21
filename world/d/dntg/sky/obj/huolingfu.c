// make by take for cs system. edit 1-31-02 13:20
inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIR"火灵符"NOR, ({"huo lingfu","fu"}));
	set("unit", "张" );
	set_weight(10);
        set("long",@long
这是放火专用的火灵符，它可以放置在任何地方，指令(fire),如果中途想中断可用(halt) .
long );
	set("no_sell","掌柜的摇摇头说：这宝贝小店不敢收。\n");
	set("no_put",1);
	set("bomb",1);
	setup();

}

void init()
{
	add_action("do_fire","fire");
	add_action("do_halt","halt");
}

int do_fire()
{
	object room,ob,me,fire;
	string answer ;
	me = this_player();
	ob = this_object();
	room = environment(me);
	answer = MISC_D->find_place(room);
   	if(!answer || sizeof(answer)<2)
   	return notify_fail("这里不能放置火灵符，你还是换个地方吧！\n");
   	if ( (answer == "傲来国") || (answer == "阴曹地府") || (answer == "红楼一梦") || (answer == "创世皇宫") )
   	return notify_fail("这里不能放置火灵符，你还是换个地方吧！\n");
	if (room->query("no_fight") || room->query("no_magic"))
	return notify_fail("这里不能放置火灵符，你还是换个地方吧！\n");
	if (me->is_busy())
	return notify_fail("你还是等有空的时候再来放火吧。\n");
	if (me->query_temp("firewait"))
	return notify_fail("你不是正在放火吗？\n");
	message_vision (HIR"\n$N小心翼翼的将一道火灵符放在地上，随后默默念动咒语。。。。。。\n"NOR, me );
	me->set_temp("firewait",1);
	me->start_busy(9);
        call_out("wait_fire",10,me,ob,room,answer);
        return 1;
}

int do_halt()
{
	object me;
	me = this_player();
	if (!me->query_temp("firewait")) return 0;
	remove_call_out("wait_fire");
	me->start_busy(1);
	me->delete_temp("firewait");
    	message_vision (HIW"\n$N突然收起火灵符，恢复了战斗状态。\n"NOR, me );
    	return 1;
}

void wait_fire(object me,object ob,object room,string answer)
{
   	object fire ;
   	if (!me || !room) return;
          message( "chat", HIY"\n\n【太平盛世】千里眼(Qianli yan)："+answer+HIY"方向隐隐泛起一片火光中带着妖气，只怕有点问题。\n\n"NOR, users() );
        fire = new("/d/dntg/sky/obj/fire");
        fire -> set_temp("fire_id",me);
        fire->move(room);
     	me->delete_temp("firewait");
     	message_vision (HIR"\n火灵符被咒语催动，带着$N的内心深处的黑暗熊熊燃烧起来！\n"NOR, me );
        destruct (ob);
}
