// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/woman.c

inherit NPC;

void create()
{
       set_name("王奶奶", ({"wang nainai", "wang", "nainai"}));
       set("long","王村长的老婆，慈祥可亲的老人。正忙着料理家务。\n");
       set("gender", "女性");
       set("age", 50);
       set("per", 100);
	set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 7400);
       set_skill("unarmed", 10);
	set_skill("dodge", 50);
	set_skill("parry", 20);
	setup();
       add_money("gold", 1);
       carry_object("/d/gao/obj/ao")->wear();

}
