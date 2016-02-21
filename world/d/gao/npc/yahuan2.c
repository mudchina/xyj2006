// yahuan1.c

inherit NPC;

void create()
{
       set_name("小丫环", ({"yahuan"}));
       set("long","一个小丫环，正伺候高老爷．\n");
       set("gender", "女性");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
	set("combat_exp", 100);
	setup();
        carry_object("/d/gao/obj/pink_cloth")->wear();
}

