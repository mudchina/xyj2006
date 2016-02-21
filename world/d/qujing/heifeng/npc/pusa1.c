//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// guanyin.c ¹ÛÒôÆĞÈø
// By Dream Dec. 19, 1996
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("¹ÛÒôÆĞÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
   set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ğÉí¡£Ã¼ÈçĞ¡ÔÂ£¬ÑÛËÆË«ĞÇ¡£À¼ĞÄĞÀ×ÏÖñ£¬
Ş¥ĞÔ°®µÃÌÙ¡£Ëı¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
   set("gender", "Å®ĞÔ");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "Æ¶É®");
   set("rank_info/respect", "ÆĞÈøÄïÄï");
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

   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("ÄÏº£ÆÕÍÓÉ½", 1, "ÆĞÈø");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/jingu1");
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
void announce_success (object who)
{
  int i;
  object me = this_object();

  if (who->query("combat_exp") < 10000)
    return;
  if( ! who->query_temp("fired") )
     return;
   if(! ob->query("obstacle/hf") )
    return; 
  if (! who->query_temp("obstacle/heixiong_killed"))
    return;
  if (who->query("obstacle/yj") != "done")
    return;  
    
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/hf","done");
  who->add("combat_exp",i+8000);
  command("chat "+who->query("name")+"ºÚ·çÉ½ÊÕ½µºÚĞÜ¹Ö£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ıÎ÷ĞĞ[1;37mµÚËÄ¹Ø[m£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
                   chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
	  command("wave");
	  who->save();
}
  call_out("die",1,this_object());
  return;
}
void die(object me)
{
        destruct(me);
}

