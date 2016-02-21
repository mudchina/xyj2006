// jiading.c

inherit NPC;

void create()
{
       set_name("Ñ²É½Ñý", ({"yaomo"}));

set("long","Ò»¸öÏàÃ²Ð×ÏÕµÄµÁÔô, Äã×ÐÏ¸Ò»¿´, Ö»¼ûËû¹ÉºóËÆ
ÓÐÒ»ÌõÎ²°Í¡£°¡£¡ÄÑ¹ÖµÁÔôÈç´ËÐ×ºÝ£¬Ô­ÊÇÔçÒÑ²ò
ÀÇ³É¾«£¬²¢·Ç·²Ì¥°¡¡£\n");
       set("gender", "ÄÐÐÔ");
       set("age", 20+random(15));
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 300000);
  set("daoxing", 150000);

        set_skill("unarmed", 70);
	set("per", 5);
	set("bellicosity", 50000);
	set_skill("parry", 65);
	set("max_kee", 800);
        set("max_sen", 800);
	set_skill("dodge", 65);
	set_skill("blade", 60);
	

	setup();
        add_money("silver", 20);
	carry_object("/u/mes/obj/blade")->wield();
}
ÿ