//Cracked by Roath
 
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("Áé¼ªÆÐÈø", ({ "lingji pusa", "ling ji", "pusa" }));
   set("long","Ò»¸ö´ÈÏéµÄÁéÉ½ÆÐÈø¡£");
   set("gender", "ÄÐÐÔ");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "Æ¶É®");
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
   set("daoxing", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jinguzhou" :)
   }) );

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/jingu1");
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  int i;
  object me = this_object(); 
  
  if( ! who->query_temp("obstacle/hfg_killed"))
     return;
  if (who->query("obstacle/yz") != "done")
    return;  
  if( who->query("combat_exp") < 10000)
     return;
  if( who->query("obstacle/hfg") == "done")
    return;

  i = random(500);
  who->add("obstacle/number",1);
  who->set("obstacle/hfg","done");
         who->add("daoxing",i+2000);
me->command("chat "+who->query("name")+"»Æ·çÉ½»Æ·çÁëÊÕ½µ»Æ·ç¹Ö£¡");
  message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+who->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÁù¹Ø£¡\n"NOR,users());
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}
