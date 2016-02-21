// qiankun-quan.c, 4-12-98 bbs

/************************************************************/

// some files to inherit,include, and some functions to declare.
// notice from the declarations that the fabao can be used as a
// weapon alone... at least in this case. :)

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit HAMMER;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);

/************************************************************/

void create()
{

    // i personally prefer a name with a pretty comprehensive id list
    // that makes it easier on the playrs, particularly those with slow net.
    // another recommendation is that the first id for this item, or any
    // item/npc you ever write, should have a space in it. that way you will
    // avoid a lot of potential trouble.

    set_name(YEL "乾坤圈" NOR,({"qiankun quan", "quan", "qiankunquan", "qiankun", "fabao"}));
    set_weight(10000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","只");
	set("value",1);		//this is mainly to prevent selling

	// these are quite important in my opinion, since we don't want
	// a highhand to get a fabao, then give it to his new character.
	// this fact is particularly important since the fabao is usually
	// unique which means once one person has it, there will not be
	// another copy in the mud.

        //set("no_drop","这么好的宝物，扔了多可惜呀！\n");
        set("no_give","这么好的宝物，留着自己用吧！\n");
        set("no_sell", 1);

	// this is very important, since as i've stressed many times,
	// we don't want everyone in the mud running around with a 捆仙索

	set("is_monitored", 1);

	// this is another very important variable.
	// if this variable is 1 or anything >0 for that matter, then
	// it can be "ji" even when the player is busy. this would be
	// useful for those "rescue" type fabao, such as a piece of
	// paper which when you ji it will take you to another room.
	// it is thus a good insurance for escape during tough fights.

	set("no_busy", 0);

	// i am note THE most sure what the effects would be if we didn't
	// specify this file (of course this file has to exist first).
	// however i do suggest you write it, because it is not that much
	// trouble, and also it might save you much grief later on.
	// note: try to keep the name of the replacement file recognizable
	// and keep it in the same directory if possible

	set("replace_file", "/d/obj/fabao/qiankun-fake");

	// there are some standard things for an object which i've ignored
	// here, things such as wield_msg and unwield_msg. if you want your
	// object to be fancier, look in other files for those properties.

	set("long","一只纯钢打造的钢环，很结实。\n");
	set("wield_msg","$N拿出一只$n握在手中。\n");
	set("unequip_msg", "$N将手中的$n收入豹皮囊。\n");
    }
    init_hammer(25);
    setup();
}

/************************************************************/

// ********make sure your fabao has this function******** 
// this is the function that the "ji" command looks for

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    
    // some fabao require a target, such as this one.
    // (the target is passed in by the "ji" command, if
    // you are interested/suspicious in how it works, you
    // can read /cmds/std/ji.c

    if (!target)
	return notify_fail("你想用对谁用"+objname+"？\n");

    // if indeed a target is needed we need to test whether the
    // target is around.

    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("这里没有 "+target+"。\n");

    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting(victim))
	return notify_fail("只有战斗中才能祭"+objname+"。\n");  

    // every fabao will have a mana cost and a sen cost.

    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");

    // here, the real fun begins. i started this one with an introduction
    // message, showing the rope being "ji".
    // notice the variable "objname". since in the course of the ji command
    // i will have to use the rope's chinese name many times, declaring it
    // up front is much more convenient (in case you change the name) and
    // much cleaner.

    msg="$N掏出一只"+objname+"，向空抛起，口中念念有词，\n";
    msg+=objname+"向$n的头顶砸去。\n";

    // here i call a function to determine the success of this ji.
    // i think all fabao should do this, just so the code is cleaner.
    // normally i prefer the following convention, whenever applicable:
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    // if condition is -1, then ji fails AND is bounced back.
    // if condition is -2, then the fabao is taken by the victim.
    // if you can find any more suitable conditions please let me know.

    condition=determine_success(me, victim);

    // the following are just applying those conditions.
    // they will probably vary with each fabao.

    switch(condition)
    {
      case 1:
	msg+=HIR"$n被"+objname+"砸个正着，立不稳脚，跌了一跤。\n" NOR;
	damage=random(me->query("mana_factor")*5/2)+10;
	damage=damage*me->query("sen")/me->query("max_sen");
	msg+=COMBAT_D->damage_msg(damage,"伤害");
        victim->receive_damage("kee",damage);
        ratio=(int)victim->query("kee")*100/victim->query("max_kee");
        msg+="( $n"+COMBAT_D->status_msg(ratio)+")\n";

	// this little if statement let's the wiz know what's going on,
	// if the wiz is using the fabao. this makes for easier debugging.

	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
	break;
      case 0:
	msg+=HIB"$n伸手一指，大喝一声“落！”只见"+objname+"落回$N手中。\n"NOR;
	break;
      case -1:
	msg+=HIB"$n伸手一指，大喝一声“回！”只见"+objname+"砸在了$N的头上！\n"NOR;
	damage=random(victim->query("mana_factor")*5/2)+10;
	damage*=victim->query("sen")/victim->query("max_sen");
	msg+=COMBAT_D->damage_msg(damage,"砸伤");
        victim->receive_damage("kee",damage);
        ratio=(int)me->query("kee")*100/me->query("max_kee");
        msg+="( $N"+COMBAT_D->status_msg(ratio)+")\n";
	break;
      case -2:
	msg+=HIB"$n伸手一指，大喝一声“收！”只见"+objname+"落入$n手中。\n"NOR;
	this_object()->move(victim);
	break;
    }

    // shows the message. this is pretty straight forward.

    message_vision(msg,me,victim);

    // i have written a function to determine the cost of mana and sen.
    // again, it makes for cleaner code. i suggest you follow this convention
    // also though it is not THAT necessary.

    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}

/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;

    // sometimes you may want to just use what COMBATD.C
    // provides for skill power. if you want an example of
    // that you can look at a cast function in /daemon/class
    // in this case i chose to calculate my own powers,
    // though i don't know why. :P

    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;

    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    // nothing complicated here i think.

    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

/************************************************************/
