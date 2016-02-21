inherit NPC;

void create()
{
	set_name("ÎºÕ÷", ({ "wei zheng", "wei", "chengxiang" }));
	set("title", "µ±³¯Ô×Ïà");
	set("gender", "ÄÐÐÔ");
	set("age", 45);
	set("str", 20);
	set("dex", 20);
	set("long", "Ëû¾ÍÊÇµ±³¯Ø©ÏàÎºÕ÷£¬ÐÔ¸ñ¸ÕÕý²»°¢£¬ÒÔ¸ÒÓÚÖ±ÚÉÎÅÃû¡£\n");
	set("combat_exp", 60000);
  set("daoxing", 600000);

	set("attitude", "heroism");

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
	carry_object(__DIR__"obj/choupao")->wear();
        add_money("gold", 1);

}
ÿ