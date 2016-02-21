//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("Ð¡¼¦",({"star trigger","trigger","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "ÐÇÈÕÐÇ¹Ù");
  set("age", 44);

  set("attitude", "heroism");
  set("class", "fighter");
  set("combat_exp", 8034443);
  set("daoxing", 8034443);
  set("kee", 1219);
  set("max_kee", 1219);
  set("sen", 2530);
  set("max_sen", 2530);
  set("force", 6139);
  set("max_force", 3070);
  set("mana", 10413);
  set("max_mana", 5207);
  set("force_factor", 141);
  set("mana_factor", 261);
  set("str", 24);
  set("per", 24);


  set_skill("baguazhou", 40);
  set_skill("bawang-qiang", 432);
  set_skill("buddhism", 42);
  set_skill("changquan", 280);
  set_skill("cuixin-zhang", 180);
  set_skill("dao", 45);
  set_skill("dodge", 111);
  set_skill("force", 203);
  set_skill("gouhunshu", 9);
  set_skill("hammer", 2);
  set_skill("lengquan-force", 181);
  set_skill("literate", 142);
  set_skill("ningxie-force", 21);
  set_skill("parry", 180);
  set_skill("spear", 162);
  set_skill("spells", 274);
  set_skill("stealing", 12);
  set_skill("tonsillit", 4);
  set_skill("unarmed", 140);
  set_skill("yanxing-steps", 420);
  set_skill("yaofa", 273);
  set_skill("zhuihun-sword", 8);


map_skill("force", "lengquan-force");
map_skill("spells", "yaofa");
map_skill("dodge", "yanxing-steps");
map_skill("parry", "bawang-qiang");
map_skill("unarmed", "cuixin-zhang");
map_skill("spear", "bawang-qiang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/spear")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="spear";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","¾µÍÈ");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"¹þ¹þ¾µ"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"¾µ¼Ü"NOR);
}

