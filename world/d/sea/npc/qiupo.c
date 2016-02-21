inherit NPC;

void create()
{
       set_name("öúÆÅ", ({"qiupo"}));

set("long","Ò»Î»ÀÏÆÅÆÅ£¬ÊÇÁúÅ®µÄÌùÉíÆÍÈË£®\n");
       set("gender", "Å®ÐÔ");
       set("age", 56);
	set("per", 20);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 50);
	set_skill("dodge", 80);
	set_skill("parry", 40);
        set("combat_exp", 26000);
  set("daoxing", 50000);

        setup();
        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

ÿ