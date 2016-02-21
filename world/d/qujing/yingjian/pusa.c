//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
   set_name("½ÒÚÐ", ({ "jie di"}));
   set("title", "¹ÛÒôÊÌÕß");
   set("long", @LONG
¹ÛÒôÆÐÈøµÄÊÌÕß¡£
LONG);
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
   carry_object("/d/nanhai/obj/sengpao")->wear();
   carry_object("/d/nanhai/obj/budd_staff")->wield();

}

void announce_success (object who)
{
  int i;
  object horse=new("/d/qujing/yingjian/obj/horse");
  object here;
  object me = this_object();
  here=environment(who);

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yj") == "done")
    return;
  if (! who->query_temp("obstacle/long_killed"))
    return;
  if (who->query("obstacle/sc") != "done")
    return;  
    
  i = random(600);
  message_vision (HIY"Ò»Æ¬ÏéÔÆ¹ýºó£¬$N³öÏÖÔÚÄãÃæÇ°£¡\n",me);
  message_vision ("\nÖ»Ìý$NÅ­³âÒ»Éù°½ÈòÁúÍõÓñÁúÈýÌ«×Ó»¹²»°Ý¹ýÈ¡¾­ÈË£¡\n",me);
  message_vision ("\nºöÈ»°×ÁúÆËµ¹ÔÚµØ£¬±ä³ÉÁËÒ»Æ¥°×Âí¡£\n",who);
  horse->move(here);
  who->add("obstacle/number",1);
  who->set("obstacle/yj","done");
  who->add("combat_exp",i+8000);
  command("chat "+who->query("name")+"Ó¥³î½§½µ·þ°×ÁúÂí£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐ[1;37mµÚÈý¹Ø£¡[m");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
                   chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
	  command("wave");
	  who->save();
}