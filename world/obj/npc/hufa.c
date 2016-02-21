#include <ansi.h>
inherit NPC;
void create()
{
        object ob1, ob2;
        set_name("韦陀", ({ "wei tuo"}) );
        set("long", "这是一位来自灵山的守护神，专门担任护法之责。\n");
        set("attitude", "friendly");
        set("max_kee", 1000);
        set("max_sen", 800);
        set("max_mana", 700);
        set("mana", 700);
        set("str", 40);
        set("cor", 30);
        set("cps", 35);
        set("combat_exp", 150000);
        set_skill("staff", 110);
        set_skill("parry", 110);
        set_skill("dodge", 110);
        setup();
        ob1=carry_object("/d/obj/armor/jinjia");
        ob1->wear();
        ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
        ob2=carry_object("/d/obj/weapon/staff/budd_staff");
        ob2->wield();
        ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
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
                RED + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n" + name() + "化成一道红光，冲上天际消失不见了。\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}
void invocation(object who)
{
        int i;
        object *enemy;
        message("vision",
                RED "只听啪！的一声，一团红光爆开，现出身穿金甲手执禅杖的天神韦陀。\n "+ name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
                environment(), this_object() );
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
}
