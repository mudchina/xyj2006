#include <ansi.h>

inherit NPC;

#include <greeting.h>

void create()
{
        set_name("金甲卫士", ({ "wei shi", "shi", "guard" }) );
        set("gender", "男性");
        set("age", 35);
        set("long",
"这是位守护皇城的金甲武士，身披铜甲，手执金瓜。
他双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("combat_exp", 130000+random(40000));
        set("attitude", "heroism");

        set("str", 30);
        set("max_kee", 750);
        set("max_gin", 500);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 25);
        set_skill("hammer", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);

        setup();

        carry_object("/d/obj/weapon/hammer/jingua")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
        greeting1 (this_player());
}

int accept_fight(object me)
{
        message_vision("金甲卫士对$N大喝一声：你活得不耐烦了？皇宫前也敢胡闹！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

