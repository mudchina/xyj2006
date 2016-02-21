// tian-ding2.c
// created 4-8-97 pickle
#include <ansi.h>
inherit NPC;
string *first_name = ({ "µË¹úÑÒ","ÐÁ¾ÆÈª","ÕÅÑ§ËÉ","ÌÕê¿¸Ú"});
// ÅÓ£¬Áõ£¬¹¶£¬±Ï£¬µË£¬ÐÁ£¬ÕÅ£¬ÌÕ

varargs void drool(string msg, string who);

void create()
{
  string name, id;

  name = first_name[random(sizeof(first_name))];

  set_name(name, ({ "tian ding", "tian", "ding" }) );
  set("gender", "ÄÐÐÔ" );
  set("long", "

¶ÔÓÚÄãµÄ´æÔÚ£¬"+name+"ËÆºõË¿ºÁÃ»ÓÐ×¢Òâ¡£
Ö±µ½Äã×ß½üÌìÃÅ£¬Ëû²Å½÷É÷ÆðÀ´£¬Ä¿¹â³¯ÄãÉ¨ÁËÒ»É¨¡£
");
  set("title", "´óÁ¦Ìì¶¡");
  set("attitude", "peaceful");
  set("age", 35+random(10));
  set("str", 27);
  set("int", 25);
  set("combat_exp",380000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 20);
  set("max_kee", 850);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",99);
  set_skill("dodge",99);
  set_skill("parry",99);
  set_skill("axe",99);
  set_skill("force",80);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/axe/bigaxe")->wield();
}
ÿ