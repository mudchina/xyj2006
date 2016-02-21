//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("¹ÛÒôÆÐÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
	set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ðÉí¡£Ã¼ÈçÐ¡ÔÂ£¬ÑÛËÆË«ÐÇ¡£À¼ÐÄÐÀ×ÏÖñ£¬
Þ¥ÐÔ°®µÃÌÙ¡£Ëý¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
	set("gender", "Å®ÐÔ");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "Æ¶É®");
	set("rank_info/respect", "ÆÐÈøÄïÄï");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 145);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	set_skill("literate", 150);
	set_skill("spells", 200);
	set_skill("buddhism", 200);
	set_skill("unarmed", 150);
	set_skill("jienan-zhi", 150);
	set_skill("dodge", 180);
	set_skill("lotusmove", 180);
	set_skill("parry", 180);
	set_skill("force", 180);
	set_skill("lotusforce", 180);
	set_skill("staff", 180);
	set_skill("lunhui-zhang", 180);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
	}) );

	setup();
	carry_object("/d/nanhai/obj/jiasha")->wear();
	carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  
  int i;

  if(!who) return;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/huoyun") == "done")
    return;
  if (! who->query_temp("obstacle/hong_killed"))
    return;
  if (who->query("obstacle/wuji") != "done")
    return;  

  	i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/huoyun","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"¿ÝËÉ½§»ðÔÆ¶´.ÊÕ·þºìº¢¶ù");
  message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÊ®ËÄ¹Ø£¡\n"NOR,users());
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
              chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}
