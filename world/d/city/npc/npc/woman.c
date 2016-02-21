inherit NPC;

void wield_knife();

void create()
{
        set_name("妇人", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 30);
        set("long", "一个寻常的村里妇人.");
        set("combat_exp", 4000);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("unarmed", 10);
        set_skill("blade",10);

        set("chat_chance",3);
        set("chat_msg", ({
                "妇人打开锅盖闻了一下.\n",
                "妇人喃喃说道: 怎么还不回来? \n",
                "妇人又抬头望向门外. \n",
        }));
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
                (: wield_knife :)
        }));
        setup();

        carry_object("/d/obj/cloth/linen")->wear();
}

void wield_knife()
{
    object knife;
    
    knife = present("cai dao", environment(this_object()));
    if(!knife) return;

    if(knife->query("weapon_prop") == 0) return;

    knife->move(this_object());
    say("妇人抓起一把菜刀喊到：你这挨千刀的！\n");
    command("wield knife");
}

