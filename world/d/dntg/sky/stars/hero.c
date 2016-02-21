//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("东方英雄",({"star hero","hero","star"}));
  set("gender", "男性");
  set("title", "参水星官");
  set("age", 46);
  set ("long", @LONG
纪念日:
-------------------------------------------------------------------------
年龄33 : 道行 303.33.3, 最后一战用时33m, 然后和 green 结婚  :)
年龄46 : 终于修成不堕轮回, 成了老不死  :D
年龄53 : 不打算继续陷在险恶的江湖中, 整天学学游手好闲(如果还来的话)  :P
-------------------------------------------------------------------------
LONG);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1564041);
  set("daoxing", 1564041);
  set("kee", 1221);
  set("max_kee", 1221);
  set("sen", 1770);
  set("max_sen", 1770);
  set("force", 5133);
  set("max_force", 2567);
  set("mana", 6101);
  set("max_mana", 3051);
  set("force_factor", 140);
  set("mana_factor", 153);
  set("str", 25);
  set("per", 15);


  set_skill("buddhism", 46);
  set_skill("dao", 180);
  set_skill("dodge", 152);
  set_skill("force", 202);
  set_skill("jindouyun", 225);
  set_skill("literate", 145);
  set_skill("parry", 170);
  set_skill("puti-zhi", 70);
  set_skill("qianjun-bang", 224);
  set_skill("spells", 202);
  set_skill("stick", 203);
  set_skill("tonsillit", 10);
  set_skill("unarmed", 140);
  set_skill("wuxiangforce", 180);


map_skill("force", "wuxiangforce");
map_skill("spells", "dao");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "puti-zhi");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"英雄棒"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"英雄战甲"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"战袍"NOR);
}

