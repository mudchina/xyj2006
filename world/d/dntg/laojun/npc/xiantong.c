//Cracked by Roath
#include <ansi.h>

inherit NPC;

string *names = ({
  "ÏÉÍ¯",
  "ÏÉ½«",
  "ÏÉ¹Ù",
  "ÏÉÀô",
});

string *ids =   ({
   "xian tong",
   "xian jiang",
   "xian guan",
   "xian li",
});

void create()
{

  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "ÄÐÐÔ" );
  set("age", 33);
  set("long", "¶µÂÊ¹¬Ì«ÉÏÀÏ¾ýµÄÏÂÊô£¬¸ºÔðÁ¶µ¤ÉÕ»ð£¬ÅÜÇ°ÅÜºó¡£\n");
  set("class", "xian");
  set("combat_exp", 25000);
  set("daoxing", 50000);

  set("attitude", "peaceful");
  set_skill("unarmed", 50);
  set_skill("wuxing-quan", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 70);
  set_skill("taiyi", 70);
  set_skill("baguazhen", 60);
  set_skill("force", 60);   
  set_skill("zhenyuan-force", 80);
  map_skill("force", "zhenyuan-force");
  map_skill("dodge", "baguazhen");
  map_skill("unarmed", "wuxing-quan");
  map_skill("spells", "taiyi");

  set("max_kee", 500);
  set("max_sen", 500);
  set("mana", 700);
  set("max_mana", 700);
  set("mana_factor", 20);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 5);

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
        (: cast_spell, "zhenhuo" :),
        }) );

  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}


