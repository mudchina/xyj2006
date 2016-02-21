// 青玉葫芦, created by mes
// updated 6-9-97 pickle
 
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
    set_name(HIC "青玉葫芦" NOR,({"qingyu hulu", "qingyu", "hulu", "qingyuhulu", "fabao"}));
    set_weight(5000);
    set_max_encumbrance(50000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","只");
	set("value",100);
	set("material","jade");
	set("long","一只暗青色的葫芦，不知是拿什么做的，触手生温。\n");
    }
    set("unique", 1);
    set("replace_file", "/d/obj/fabao/qingyu-fake.c");
    set("is_monitored",1);
    setup();
} 
int ji(string target)
{
    object victim,weapon,hulu,me=this_player(), ob=this_object();
    int damage,ap,dp, myspells, mydx, victimspells, victimdx;
    int ratio, mykar=me->query_kar(), victimkar;
    string msg, obname=(string)ob->query("name"), weaponname;

    hulu=present("qingyu hulu",me);
    if(!target) return notify_fail("你想用对谁用"+obname+"？\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim)) return notify_fail("死人的兵器还需要用法宝去拿？\n");
    if(!me->is_fighting()) return notify_fail("只有战斗中才能祭"+obname+"。\n");
    if( (int)me->query("mana") < 300 ) return notify_fail("这么一点点法力也想驱动法宝？\n");
    if( (int)me->query("sen") < 100 ) return notify_fail("你无法集中精神念咒语。\n");
    weapon = victim->query_temp("weapon"); 
    if(!weapon) return notify_fail("你的敌人并没有使用武器。\n");
    msg="$N抛起"+obname+"，口中念念有词，\n";
    msg+="只见一阴风刮起，青玉葫芦口射出一道青光。\n";
    me->start_busy(30/mykar);
    victimkar=victim->query_kar();
    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;
    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*mykar/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victimkar/1000;
    if (wizardp(me) && me->query("env/combat")=="verbose")
        tell_object(me, GRN "进攻："+ap+"，防守："+dp+"。\n" NOR);
    if(random(ap+dp)>dp)
    {
	msg+=BLU"$n被青光罩个正着，手中"+ weapon->name() +BLU"向葫芦里飞去！ \n"NOR;
	msg+="$n手中的"+weapon->query("name")+"被$N收去了！\n"NOR; 
	weapon->unequip();
	if (weapon->query_weight()>hulu->query_max_encumbrance())
	{
	    weaponname=weapon->name();
	    destruct(weapon);
	    msg+=BLU"只见"+weaponname+BLU"被"+obname+BLU"化成一缕轻烟，随风飘去。\n" NOR;
	}
	else weapon->move(hulu);
	me->add("mana", -250);
    }
    else {
	msg+="$n将身一侧，躲过了青光。\n";
	me->add("mana", -125);
    }
    message_vision(msg,me,victim);
    return 1;
}





