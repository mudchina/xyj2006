inherit NPC;
void create()
{
       set_name("¿ïÎÄÕý", ({ "kuang wenzheng", "kuang", "teacher"}));
       set("title", "½ÌÊéÏÈÉú");
       set("long","´åÀïµÄÀÏ½ÌÊéÏÈÉú£¬º¢×ÓÃÇµÄÉ¨Ã¤È«¿¿ËûÁË£®\n");
       set("gender", "ÄÐÐÔ");
       set("age", 66);
	set("int", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("literate",60);
	set_skill("sword", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set("combat_exp", 10000);
  set("daoxing", 5000);

set("inquiry", ([
"name"  : "ÀÏ·òÐÕ¿ï£¬×ÖÎÄÕý£®¸óÏÂÊÇ£®£®£®",
"here"  : "Õâ¶ùÊÇÀÏ·ò°ìµÄÑ§ÌÃ£¬½Ìº¢×ÓÃÇÒ»Ð©ÖªÊ¶£®",

]) );
set("chat_chance", 5);
set("chat_msg", ({
"¿ïÎÄÕýËµµÀ£º¡ºÐ¡ÐÄÌìÏÂÈ¥µÃ£¬Ã§×²´ç²½ÄÑÐÐ¡»¡£ÄãÒªÀÎÀÎ¼ÇµÃ£®\n",
"¿ïÎÄÕýÒ¡Í·»ÎÄÔµÄÄîµÀ£º×ÓÔ»£ºÓÐÅó×ÔÔ¶·½À´£¬²»ÒàÀÖºõ£®£®ÎÞÐë±¸·¹£®\n",
"¿ïÎÄÕýÐ¦Ó¯Ó¯µØ¸úÄã´òÕÐºô£º³ÔÁË£¿£¡\n",
}) );

setup();
carry_object("/d/gao/obj/ruler")->wield();
carry_object("/d/gao/obj/changpao")->wear();
add_money("silver", 5);
}


ÿ