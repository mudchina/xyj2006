#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
int do_amalgamation();
object offensive_target(object me);

void create()
{
        set_name(HIR "火灵珠" NOR, ({"huo lingzhu", "huozhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
set("no_steal",1);
                set("value",10000);
                set("no_drop", "如此宝贵的宝物再世难求啊。\n");
                set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","传说中的五行宝珠之一，佩之可避火烧，并可发出火系法术。\n为祈雨所必需之物。");
                set("replace_file", "/d/obj/flower/rose");
                set("bb",1);
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        //风火雷土水四珠合壁
        add_action("do_amalgamation", "wuzhuhebi");
        return 1;
}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if (arg == "all") arg ="huozhu";
if (arg != "huozhu" &&  arg != "huo lingzhu" )
    return notify_fail("你要佩带什么？\n");
  msg = "$N戴上一颗"+name+"，红光照亮了天际。\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("conditionhuozhu");
call_out("conditionhuozhu",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

  if (arg!= "all" && arg != "huozhu" && arg != "huo lingzhu")
    return notify_fail("你要摘掉什么？\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  zhu->set("unequip_msg",msg);
  remove_call_out("conditionhuozhu");
  return 0;
}

void conditionhuozhu(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
         if( ! present( target,environment(who)) ) return ;    

        msg = HIR"火灵珠猛然红光四射，半空中浮现出一个赤红的火神祝融，只见祝融双手一圈，\n
一个硕大的火球冲着$n飞去！\n"NOR;
//divid by 10;

                ap = 2000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被火球撞个正着！须发尽焦。\n" NOR;

                                target->receive_damage("sen", damage*4/5);
                                target->receive_wound("sen", damage/3);
                                target->receive_damage("kee", damage*4/5);
                                target->receive_wound("kee", damage/4);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n谁知$n毫无反应。\n" NOR;   
                }
                else
                        msg += "但是被$n躲开了。\n";

                message_vision(msg, who, target); 
        }
call_out("conditionhuozhu",7,who,ob);
}

int do_amalgamation()
{
        //五颗宝珠
        object wind,water,thunder,earth;
        object who = this_player();
        object shengzhu;

        if(who->is_fighting())
           return notify_fail("你正打仗呢！想死啊！\n");
        if(who->is_busy())
           return notify_fail("你正忙着呢!\n");
        if(!wind = present("fengzhu",who))
           return notify_fail("你还缺少"+HIG "风灵珠" NOR +"呢!怎么五珠合壁呢?\n");
        if(!thunder = present("leizhu",who))
           return notify_fail("你还缺少"+HIB "雷灵珠" NOR +"呢!怎么五珠合壁呢?\n");
        if(!earth = present("tuzhu",who))
           return notify_fail("你还缺少"+HIY "土灵珠" NOR +"呢!怎么五珠合壁呢?\n");
        if(!water = present("shuizhu",who))
           return notify_fail("你还缺少"+HIW "水灵珠" NOR +"呢!怎么五珠合壁呢?\n");
if ((water->query("equipped")!="worn") && (wind->query("equipped")!="worn") && (thunder->query("equipped")!="worn") && (earth->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
{        
        message_vision("$N把五颗宝珠放在一起。只见五颗宝珠冉冉升起，一时宝光大盛，直冲云霄！\n
俄顷，"+HIG "风灵珠" NOR+"飞至东方放出柔和绿光；"+HIR "火灵珠" NOR +"飞至南方发出灼目红光；"+HIB "雷灵珠" NOR +"飞至西方忽明忽暗，\n
闪出幽幽蓝光；"+HIW "水灵珠" NOR +"却通体莹白，飞至北方；"+HIY "土灵珠" NOR +"直冲天穹，泻下万里黄光。\n
又待片刻，五珠呼的一暗，$N手中却多了一颗硕大的透明宝珠，不时发出五彩毫光。\n",who);

        message("channel:rumor",RED+"【谣言】某人："+who->query("name")+"拿到圣灵珠了！\n"+NOR,users() );
        
         shengzhu = new("/d/obj/baowu/shengzhu");
        shengzhu->move(who);
        destruct(wind);
        destruct(water);
        destruct(earth);
        destruct(thunder);
        destruct(this_object());
        return 1;
}
return notify_fail("宝珠必须摘下才能合璧！\n");
}
