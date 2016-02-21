//Cracked by Roath
inherit NPC;

string *names = ({
  "[31m»¨½ÅÎÃ×Ó[m",
  "´óÍ·ÎÃ×Ó",
  "×ÏÍ·ÎÃ×Ó",
  "ºìÍ·ÎÃ×Ó",
  "»¨±ßÎÃ×Ó",
  "»¨¶ÇÎÃ×Ó",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ "wen zi","wenzi" }) );
   set("race", "Ò°ÊŞ");
   set("age", 3);
   set("long", "Ò»Ö»ºÜĞ¡ÇÉµÄ»¨½ÅÎÃ×Ó¡£\n");

   set("str", 32);
   set("max_kee",200);
   set("kee",200);
   set("max_sen",200);
   set("sen",200);
   set("limbs", ({ "Í·²¿", "ÉíÌå", "ÍÈ", "³á°ò", "×ì°Í" }) );
   set("verbs", ({ "bite", "claw" }) );
   set("chat_chance",80);
   set("chat_msg",({
        "ÎÃ×ÓÎËÎËÎËµÄ·ÉÀ´·ÉÈ¥¡£\n",
        }));
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);
   setup();
}
