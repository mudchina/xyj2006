////xueshanhufa2.c --不死鸟
//created by vikee
//2000.10
#include <ansi.h>
inherit NPC;
#include <soldier_skill.h>
void create()
{
        
        set_name("不死鸟",({ "busi niao", "hufa" }) );
        set("long", "一只得道多年的不死鸟，传说是大鹏明王手下的得力干将。\n");
        set("attitude", "friendly");

        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 100);
        set("max_mana", 2000);
        set("mana", 2000);
        set("mana_factor", 100);
        
        set("combat_exp", 1500000);
        set("daoxing", 1500000);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        setup();        
        
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

int receive_damage(string arg,int damage,object me)
{       
        me->set("max_gin", 2000);
        me->set("max_kee", 2000);
        me->set("max_sen", 2000);
        me->set("max_force", 2000);
        me->set("force", 2000);
        me->set("force_factor", 100);
        me->set("max_mana", 2000);
        me->set("mana", 2000);
        me->set("mana_factor", 100);    
        return 1;       
        
}

void leave()
{
        message("vision",
                HIR + "充满伤感的火焰燃烧起来，不死鸟冲进火焰中飞走了......\n\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
                HIR "充满热情的火焰燃烧起来，不死鸟从火焰中飞了出来......\n\n" NOR,environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
  give_skill(who,"dengxian-dafa","sword");
}

