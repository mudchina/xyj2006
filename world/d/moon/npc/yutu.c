
#include <ansi.h>

inherit NPC;

void create() {
  set_name("玉兔",({"yu tu","tu","rabbit"}));
  set("long","一只活泼可爱的小白兔，红眼睛，三瓣嘴，两只耳朵长乎乎。\n");
  set("gender","女性");
  set("age",10);
  set("per",999);
  set("str",30+random(10));
  set("cor",40);
  set("cps",30);
  set("max_sen",1000);
  set("sen",1000);
  set("max_kee",2000);
  set("kee",2000);
  set("max_mana",500);

  set("combat_exp", 300);
  set("daoxing",300);
  set_skill("unarmed", 10);
  set_skill("baihua-zhang", 10);
  map_skill("unarmed", "baihua-zhang");
  set_skill("dodge", 20);
  
  set("limbs", ({
               "头部", "颈部", "胸口", "后心", "尾巴","耳朵",
               "左爪", "右爪", "腰间", "小腹", "前腿", "后腿",
               "前爪", "后爪" }) );

  setup();
  carry_object("/d/moon/obj/daoyaochu")->wield();
  set("chat_chance",3);
  set("chat_chance_combat", 4);
  set("chat_msg_combat", ({
        (CYN"玉兔越打越高兴，口中连呼：“好玩，好玩！再打，再打！”\n"NOR),
      }) );
}
