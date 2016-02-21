// hudian.c
// created by mes, updated 6-20-97 pickle
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("»¤µîÑý", ({"hudian yao", "yao", "hu dian", "hudian", "monster"}));
  set("long","Ò»¸ö°òÀ«ÑüÔ²µÄ»¤µîÑý£¬¿´ÉÏÈ¥µÀÐÐ²»Ç³¡£\n");
  set("gender", "ÄÐÐÔ");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 130000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() 
	  && living(me) ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  int myspells, mykar, diff;
  string npcname=this_object()->query("name");

  if( !me || environment(me) != environment() ) return;

  myspells=me->query_skill("spells");
  mykar=me->query_kar(); 
  diff=40-mykar;

  if(me->query("family/family_name") == "ÏÝ¿ÕÉ½ÎÞµ×¶´")
    return;
  if( member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1)
    {
      command("say Ê²Ã´¶«Î÷£¿¾¹¸ÒÔÚÎÞµ×¶´³öÈë£¡");
      kill_ob(me);
      return;
    }
  if( random(myspells+mykar) > diff) return;
  else
    {
      message_vision(CYN ""+npcname+"¶Ô$N´óºÈµÀ£ºß¾£¡Ê²Ã´¶«Î÷£¡£¿ÐÝÏë´ÓÀÏ×ÓÑÛÏÂÁï¹ýÈ¥£¡\n"NOR, me);
      message_vision(npcname+"´óº°Ò»Éù£ºÏÖ£¡$N¶ÙÊ±ÏÖ³öÔ­ÐÎ£¬Ô­À´ÊÇ"+me->query("name")+"£¡\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}









ÿ