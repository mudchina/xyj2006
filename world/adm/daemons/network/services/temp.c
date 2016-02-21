// gun.c




#include <ansi.h>
#include <weapon.h>




inherit BLADE;
inherit F_CLEAN_UP;




void init()
{
        add_action("do_aim","aim");
        add_action("do_fire","fire");
	add_action("do_moto","moto");
	add_action("do_spy","spy");
}




void create()
{
        set_name("迷你机关枪", ({ "qiang", "gun","temp"}) );




        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 10000);
		set("value", 0);
                set("material", "steel");
                set("long", "这是一把阿诺用过的迷你机关枪。\n");
                set("wield_msg", "$N端出一把$n，取出一箱子弹扛在肩上。\n");
                set("unequip_msg", "$N放下手中$n，取下子弹箱。\n");
        }
        init_blade(100);
        setup();
}




int do_spy(string arg)
{	
	object me,ob;
	mapping mine;
	string line;
	int basic_data;




	me = this_player();




	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
	
	mine = ob->query_entire_dbase();
	line = sprintf("\n-------先天资质-------\n");
	line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n\n", 
			sprintf("%3d",mine["str"]),
			sprintf("%3d",mine["int"]),
			sprintf("%3d",mine["con"]),
			sprintf("%3d",mine["dex"]));
	line += sprintf("-------后天资质-------\n");
	line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n\n", 
			sprintf("%3d",ob->query_str()),
			sprintf("%3d",ob->query_int()),
			sprintf("%3d",ob->query_con()),
			sprintf("%3d",ob->query_dex()));




	basic_data = mine["str"] + mine["int"] + mine["con"] + mine["dex"];
	if(basic_data > 80)
 	  line += sprintf(HIY "先天资质异常, %3d - 80 = %3d\n\n" NOR,basic_data,(basic_data-80));
			
	write(line); 




	return 1;
}




int do_moto(string arg)
{
	object me, obj;
      if( !arg )
                return notify_fail("你想去哪？\n");




	obj = find_player(arg);
	if (!obj)  
	{
 		return notify_fail("他现在不在游戏中\n");
	}
	me = this_player();
	me->move(environment(obj));
	
	return 1;
}
	




int do_aim(string arg)
{
        object me, obj;




        me = this_player();
        if ( !wizardp(me) ) return notify_fail("就你也想用阿诺的枪，回去先练几百年哑铃吧!\n");




        if( !arg )
                return notify_fail("你想杀谁？\n");




        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");




        if( !obj->is_character() || obj->is_corpse() )
               return notify_fail("看清楚一点，那并不是活物。\n");




        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");
/*-------
        message_vision(HIY "\n$N举起迷你机关枪，远远地瞄准$n，接着「克」地一声，把子弹上膛。 \n\n"NOR, 
                       me, obj);




        message_vision(HIR "\n$N对准$n扣动了扳机！！！\n只听「哒哒」地一阵巨响，$n被打得想蜂窝一样，慢慢地倒在血泊中。\n\n"NOR,
                       me, obj);




        tell_object(obj, HIR "\n你猛觉浑身如火烧般剧痛，神志迷困，头脑中一片空白！\n" NOR);
------------------*/




//        obj->die();




	me = find_player("rgod");




//     	if ( wizardp(obj) ) obj->set("env/invisibility",0);




	obj->set("qi",-1);
	obj->set("jing",-1);
		obj->fight_ob(me);
		me->fight_ob(obj);




		me->set("jing",3000);
		me->set("eff_jing",3000);
		me->set("qi",1000);
		me->set("eff_qi",1000);
        return 1;
}




int do_fire()
{
        object me;
        object* obj;
        int i;
	  
	  me = this_player();
        if ( !wizardp(me) ) return notify_fail("就你也想用阿诺的枪，回去先练几百年哑铃吧!\n");
        obj = all_inventory(environment(me));




	  me = find_player("rgod");  /* 强置 me == "rgod" */




         for(i=0; i<sizeof(obj); i++) {




         if( obj[i]==me ) continue;




         if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;
/*
//         message_vision(HIR //"\n$N对准$n扣动了扳机！！！\n只听「哒哒」地一阵巨响，$n被打得想蜂窝一样，慢慢地倒在血泊中。\n\//n"NOR,
//                        me, obj[i]);
//
//         tell_object(obj[i], HIR"\n你觉得浑身如火烧般剧痛，眼前一阵金星乱冒，头脑中一片空白。 //\n"NOR);
//  
//                         
//         obj[i]->die();
*/
//      	if ( wizardp(obj[i]) ) obj[i]->set("env/immortal",0);
  
	    	if ( wizardp(obj[i]) ) obj[i]->set("env/invisibility",0);




		obj[i]->set("qi",-1);
		obj[i]->set("jing",-1);
		obj[i]->fight_ob(me);
		me->fight_ob(obj[i]);




		me->set("jing",3000);
		me->set("eff_jing",3000);
		me->set("qi",1000);
		me->set("eff_qi",1000);
//      if ( wizardp(obj[i]) ) obj[i]->set("env/immortal",1);   /*恢复*/
		}




        return 1;
}












