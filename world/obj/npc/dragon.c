// Rainy


#include <ansi.h>

inherit NPC;
string *first_name = ({ "花皮", "背苍", "八爪金角", "金尾虬髯"});
string *name_words = ({ "龙"});

void create()
{
	string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"dragon"}));
        set("race", "野兽");
        set("age", 20);
        set("long", "一只模样高大，极有气势的龙。\n");
        set("str", 40);
        set("cor", 30);
	set("con", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee", 1200);
        set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);
	set("mana", 1000);
	set("max_mana", 1000);
	set("mana_factor", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("dragonfight", 50);
	set_skill("dragonstep", 50);
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "dragonstep");
	set("combat_exp", 100000);
	set("daoxing", 100000);
        set("limbs", ({ "头部", "身体", "前爪", "尾巴", "肚皮", "后爪"}) );
        set("verbs", ({ "bite", "claw"}) );
	set_weight(500000);

        setup();
}

void copy_status(object me,object ob)
{
	me->set_skill("unarmed", (int)ob->query_skill("unarmed", 1));
	me->set_skill("dodge", (int)ob->query_skill("dodge", 1));
	me->set_skill("parry", (int)ob->query_skill("parry", 1));
	me->set_skill("dragonfight", (int)ob->query_skill("dragonfight",
1) + 20);
	me->set_skill("dragonstep", (int)ob->query_skill("dragonstep", 1)
+ 20);

        me->set("combat_exp",ob->query("combat_exp"));
	me->set("daoxing",ob->query("daoxing"));
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIB + name() +"一个转身，飞向东方，身影渐渐淡去了。\n"
NOR,environment(),  this_object() );
        destruct(this_object());
}

void invocation(object who)
{       int i;
        object *enemy;

	object me=this_object();
        copy_status(me,who);
        message("vision", HIB"忽然狂风大做，半空现出一条"+ name() +
"来！\n\n"NOR,environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }

}

