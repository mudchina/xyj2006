// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ºÚÎŞ³£", ({ "hei wuchang","wuchang", "gargoyle" }));
        set("long","Ò»¸öºÚÒÂÆáºÚÃæÆ¤µÄÊ¹Õß£¬÷îºÚµÄÁ³ÉÏ¿´²»³öÈÎºÎÏ²Å­°§ÀÖ¡£\n");
        set("attitude", "peaceful");
	set("per", 10);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "ÒıÆÇË¾Ö÷");
        set("combat_exp", 150000);
  set("daoxing", 200000);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
	set("class", "youling");
	set("force", 1500);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 600);
	set("mana", 1000);
	set("mana_factor", 40);
	set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("spells", 70);
	set_skill("gouhunshu", 60);
	set_skill("jinghun-zhang", 70);
	set_skill("force", 70);
	set_skill("tonsillit", 60);
/*
	set_skill("stick", 100);
	set_skill("kusang-bang", 100);
	map_skill("stick", "kusang-bang");
	map_skill("parry", "kusang-bang");
*/
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
create_family("ÑÖÂŞµØ¸®", 3, "ÄãºÃ");
  set("inquiry",([
   "name":"ÔÚÏÂÒı»êÊ¹ºÚÎŞ³££¬·îÊ®µîÚ¤ÍõÖ®Ãü£¬Ç°ÍùÑô¼ä¹´»ê¡£\n",
   "here":"ÕâÀïÊÇÑÖÂŞµØ¸®¡£\n",
   "¹´»ê":"ÎÒ°´ÅúÎÄËùÊé¹´ÈË£¬ÈôÓĞÔ©Çü£¬¿ÉÓë·¢´Ë¹«ÎÄÖ®Ú¤ÍõÉêËß(complain)¡£\n",
   "Ô©Í÷":"ÎÒ°´ÅúÎÄËùÊé¹´ÈË£¬ÈôÓĞÔ©Çü£¬¿ÉÓë·¢´Ë¹«ÎÄÖ®Ú¤ÍõÉêËß(complain)¡£\n",
   "Ô©Çü":"ÎÒ°´ÅúÎÄËùÊé¹´ÈË£¬ÈôÓĞÔ©Çü£¬¿ÉÓë·¢´Ë¹«ÎÄÖ®Ú¤ÍõÉêËß(complain)¡£\n",
  ]));

        setup();
	carry_object("/d/obj/cloth/hei")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say ºÜºÃ£¬" + RANK_D->query_respect(me) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//		ob->set("title", "µØ¸®ÒıÆÇË¾Òõ±ø");
}

ÿ
