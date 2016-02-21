inherit NPC;
 
void do_drink();
 
int exp, lvl;

void create()
{

        seteuid(getuid());
        set_name("倭寇", ({"wo kou", "kou"}));
        set("long", "一个倭寇，偷偷摸摸地想在长安城捞些什么。\n");
        set("gender","男性");
        set("age",37);
        set("con",30);
        set("per",10);
        set("str",25);
        set("int",25);
        
        exp=100000+random(40)*10000;
        lvl=60+exp/10000;

        set("combat_exp",exp);

        set("eff_dx",-exp/3);
        set("nkgain",150);

//        set("attitude","aggressive");
        set("chat_msg", ({
        (: do_drink :),
//	(: random_move :)
        }));

        set("chat_chance", 5);

        set_skill("dodge", lvl);
        set_skill("force", lvl);
        set_skill("blade", lvl);
        set_skill("parry", lvl);
        set_skill("unarmed", lvl);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", exp/10000);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/blade/blade")->wield();
}
/* 
void init()
{
    object ob=this_player();
    object me=this_object();
    int dx=ob->query("combat_exp");

    if(userp(ob) && !wizardp(ob) && dx<exp && dx>exp/2
      && !environment(me)->query("no_fight"))
      me->kill_ob(ob);

}
*/
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
      if(random(2)==1)
        command("sigh");
      else
        command("say 舔了舔嘴唇，喃喃道：要是有酒就好了．．．");
    }
    return;
}

