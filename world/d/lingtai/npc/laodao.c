// worker.c

inherit NPC;

void create()
{
        set_name("ÀÏµÀÊ¿", ({"laodao"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 73);
        set("long", "Ò»Î»ÀÏµÀÊ¿£¬Ã¼Ã«ºÍºú×Ó¶¼°×ÁË£®\n");
        set("combat_exp", 20000);
	set("daoxing", 50000);

        set("attitude", "peaceful");
        set_skill("unarmed", 30);
        set_skill("dodge", 60);
        set_skill("parry", 30);
        set_skill("literate", 40);
        set_skill("puti-zhi", 20);  
        set_skill("force", 60);   
        set_skill("wuxiangforce", 60);
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");

        set("per", 30);
        set("max_kee", 300);
        set("max_gin", 200);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 2);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
	carry_object("/d/obj/book/stickbook");
}

int accept_object(object me,object ob)
{	object who;
        who=this_player();

        if (ob->query("id")=="songguo"
	&& who->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
write("ÀÏµÀÊ¿¸ßÐËµÄºú×Ó¶¼ÇÌÆðÀ´ÁË£¬Ëµ£ºÕâ¿ÉÊÇºÃ¶«Î÷Ñ½£¡\n");
                command("give piece to " + who->query("id"));
                call_out("destroy", 1, ob);
		return 1;
		}
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

ÿ
