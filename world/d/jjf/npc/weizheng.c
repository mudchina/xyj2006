//created 5-20-97 pickle
 
inherit NPC;
inherit F_MASTER;
 
void create()
{
  set_name("Îºáç", ({"wei zheng", "wei", "zheng", "weizheng", "shifu", "master"}));
  set ("long", @LONG
ÎºáçÏÈÊËÆë¸®ÎªÌ«×ÓÀî½¨³ÉÂÅÉèÃî¼Æ¡£µ«Àî½¨³É²»ÌıÆä
È°¸æ£¬ÖÕÎªÌ«×ÚËùÉ±¡£Ì«×Ú°®ÎºáçÖ®²Å£¬½«ÆäÊÕÂŞ£¬²¢
·âÎªÖ£¹ú¹«¡£
LONG);
 
  set("title", "Ö£¹ú¹«");
  set("gender", "ÄĞĞÔ");
  set("age", 55);
  set("str", 15);
  set("per", 25);
  set("int", 40);
  set("combat_exp", 40000);
  set("daoxing", 800000);

  set_skill("literate", 200);
  set_skill("spells", 150);
  set_skill("baguazhou", 100);
  set_skill("force", 30);
  set_skill("lengquan-force", 30);
  set_skill("dodge", 30);
  set_skill("yanxing-steps", 30);
  set_skill("parry", 30);
  set_skill("unarmed", 30);
  set_skill("changquan", 30);
  set_skill("sword", 40);
  map_skill("spells", "baguazhou");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 1000);
  set("max_kee", 300);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", 10);
  set("mana", 700);
  set("max_mana", 700);
  set("mana_factor", 70);
 
  create_family("½«¾ü¸®", 2, "ÎÄÈË");
  setup();
 
  carry_object("/d/obj/weapon/spear/gangqiang");
  carry_object("/d/obj/weapon/mace/malemace")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  command("say ÀÏ·òÊÖÖØ£¬ÈôÊÇÉËÈË·´¶ø²»ÃÀÁË¡£\n");
  return 0;
}
ÿ