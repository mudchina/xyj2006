inherit NPC;
 
void do_drink();
 
int exp, lvl;

void create()
{

        seteuid(getuid());
        set_name("小倭贼", ({"wo kou", "kou"}));
        set("long", "一个小倭贼，偷偷摸摸地想在长安城捞些什么。\n");
        set("gender",((random(2)==1)?"男性":"女性"));
        set("age",17);
        set("con",30);
        set("per",10+10*(query("gender")=="女性"));
        set("str",25);
        set("int",15);
        
        exp=10000+random(40)*1000;
        lvl=20+exp/2000;

        set("combat_exp",exp);

        set("eff_dx",-exp/2);
        set("nkgain",80);

//        set("attitude","aggressive");
        set("chat_msg", ({
//        (: do_drink :),
//	(: random_move :),
        }));

 //       set("chat_chance", 10);

        set_skill("dodge", lvl);
        set_skill("force", lvl);
        set_skill("blade", lvl);
        set_skill("parry", lvl);
        set_skill("unarmed", lvl);
	set("max_force", 500);
	set("force", 500);
//	set("force_factor", exp/1000);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);

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

