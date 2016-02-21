#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIY"ÌÆÌ«×Ú"NOR, ({ "tang taizong", "tang", "emperor" }));
	set("gender", "ÄÐÐÔ");
	set("age", 50);
	set("per", 30);
	set("str", 20);
	set("dex", 20);
	set("long", "ÌÆÌ«×ÚÀîÊÀÃñ£¬·á×ËÓ¢Î°£¬²½ÂÄ¶ËÏê¡£\n");
	set("combat_exp", 60000);
	set("attitude", "heroism");
	set("rank_info/respect", "ÍòËêÒ¯");
	set("rank_info/rude", "ÎÞµÀ»è¾ý");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("force", 500); 
	set("max_force", 500);
	set("enforce", 10);

	setup();
	carry_object(__DIR__"obj/longpao")->wear();
        add_money("gold", 1);

}
