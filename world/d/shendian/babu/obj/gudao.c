//by repoo

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIR"沉鱼"+HIW"刀"NOR, ({ HIR"chenyu dao"NOR, "dao", "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "bone");
             set("long", "古时尧的随身武器。\n");
                set("wield_msg", "一道白光闪过，$N手中已多了把$n。\n");
        }
 set("no_sell", 1);
 set("no_drop", 1);
 set("no_put",1);
 set("no_give",1);

         init_blade(150);
        setup();
}
void init()
{
        check_owner();
}

int ji_ob(object victim)
{
        object fabao=this_object();
        object me=this_player();
        object where=environment(me);

        int my_spi;

        int vic_enchant, vic_dx, vic_mana;
        int damage;

        fabao->set("spi", 0);
         fabao->add("spi", 6000);
        if( me->is_busy() )
return notify_fail("你正忙着呢，无法祭出"+HIR"沉鱼"+HIW"刀。\n"NOR);
        if( !victim )
                return notify_fail("你想祭的人不在这里。\n");
        if( where->query("no_magic") )
     return notify_fail("这里不能祭"+HIR"沉鱼"+HIW"刀。\n"NOR);
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能祭出。\n");
        if( (int)me->query("mana") < 800 )
   return notify_fail("你的法力不能控制"+HIR"沉鱼"+HIW"刀。\n"NOR);

message_vision(YEL"\n$N大喝一声“去!”，只见$n"+YEL"「呼」地一下化做一条巨龙飞到半空。\n"NOR, me, fabao);

message_vision(YEL"霎那间天色一变！$n"+YEL"呼啸着向"+HIW"$N"+YEL"迎面斩下！\n"NOR, victim, fabao);
        if( !victim->is_fighting(me) ) 
        {
                if( living(victim) ) 
                {
                        if( userp(victim) ) 
                                victim->fight_ob(me);
                        else
                                victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }

        me->add("mana", -500);
        me->receive_damage("sen", 100);
        me->start_busy(1+random(3));

        my_spi = query("spi");
        fabao->set("spi", my_spi*3/2);
        //躲闪与成功
        vic_mana = (int)victim->query("mana");
        vic_dx = (int)victim->query("daoxing");
        vic_enchant = (int)victim->query("mana_factor");

        if( random(vic_dx/1000) > my_spi ) 
        {
message_vision(HIY"\n结果$N身形急闪，躲过了$n"+HIY"的攻势。\n"NOR, victim, fabao);
        }
        else
                if( random(vic_mana) > my_spi )
                {
message_vision(WHT"\n$N手一指大喝一声“来！”，只听$n"+WHT"发出一声轻哮！飞到了"+HIR"$N"+HIW"手中。\n"NOR, victim, fabao);
                        fabao->move(victim);
                }
                else
                {
                        damage = 0;
                        damage = 100 + my_spi/2 - random(vic_mana/10) - vic_enchant*2;
                        if( damage < 0 ) damage = 0;
                     if( damage > 3000 ) damage = 3000; 

                        if( damage > 0 )
                        {
message_vision(HIY"\n结果$N"+HIY"来不及闪开，白光闪过之后，$n"+HIY"已经在"+HIW"$N"+HIY"的身体上砍了数刀,\n"+HIY"        过了一会，鲜血才喷出来！\n\n"+"        $n"+HIW"通过这次实践,攻击力加强了.\n"NOR, victim, fabao,victim);
                                victim->receive_damage("kee", damage);
                                victim->receive_wound("kee", damage/2);
                                fabao->add("spi",100);
                                COMBAT_D->report_status(victim);
                        }
                }
        return 1;
}

int ji (string target)
{
        object fabao = this_object ();
        object me = this_player();
        string name=fabao->query("name");
        object victim;

        if (!target)
                return notify_fail("你想对谁祭"+name+"？\n");
        victim=present(target,environment(me));
        return fabao->ji_ob(victim);
}
