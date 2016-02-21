inherit NPC;

void create()
{
       	set_name("ÁèÐé×Ó", ({"lingxu zi", "zi"}));
       	set("gender", "ÄÐÐÔ");
       	set("age", 30);
        set("long", "Ò»¸öÉí¸ß±Û³¤µÄµÀÊ¿£¬ÈÝÃ²»¹¿´µÄ¹ýÈ¥¡£
¿É×ÐÏ¸Ò»ÇÆ£¬¾±ÖÐ¾¹³¤×ÅÃÜÃÜÂéÂéµÄ³¤Ã«¡£\n");
       	set("attitude", "heroism");
	set("class", "yaomo");
	set("bellicosity", 800);
       	set("per", 18);
	set("looking", "ÏàÃ²Ð×¶ñ£¬ÂúÁ³ºáÈâ¡£");
	set("str", 25);
       	set("combat_exp", 120000);
  set("daoxing", 120000);

        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);
	set_skill("force", 75);
	set_skill("spells", 75);
	set_skill("moshenbu", 75);
	set_skill("cuixin-zhang", 75);
	map_skill("unarmed", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");
	map_skill("dodge", "moshenbu");
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 300);
        set("mana", 300);
	set("mana_factor", 20);
	set("eff_dx", -50000);
	set("nkgain", 300);
	set_temp("apply/armor", 25);
	setup();
	carry_object("/d/obj/cloth/changpao")->wear();
	carry_object("/d/qujing/jisaiguo/obj/panzi");
}


ÿ