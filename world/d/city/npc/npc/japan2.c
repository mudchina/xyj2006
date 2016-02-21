inherit NPC;
 
void do_drink();
 
int exp, lvl;

void create()
{

        seteuid(getuid());
        set_name("小小倭贼", ({"little jap", "jap"}));
        set("long", "一个小倭贼，偷偷摸摸地想在长安城捞些什么。\n");
        set("gender",((random(2)==1)?"男性":"女性"));
        set("age",14);
        set("con",30);
        set("per",2+10*(query("gender")=="女性"));
        set("str",25);
        set("int",15);
        
        exp=random(200);
        lvl=exp/50;

        set("combat_exp",exp);

        set("eff_dx",-exp);
        set("nkgain",20);

//        set("attitude","aggressive");
        set("chat_msg", ({
//        (: do_drink :),
//	(: random_move :),
        }));

 //       set("chat_chance", 5);

        set_skill("dodge", 0);
        set_skill("force", lvl);
        set_skill("parry", 0);
        set_skill("unarmed", lvl);
	set("max_force", 100);
	set("force", 100);
        set("max_kee", 100);
        set("max_gin", 100);
        set("max_sen", 100);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/blade/mudao")->wield();
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

