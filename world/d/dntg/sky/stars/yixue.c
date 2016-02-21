//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("楚楚",({"star yixue","yixue","star"}));
  set("gender", "女性");
  set("title", "心月星官");
  set("age", 43);
  set ("long", @LONG
风雪剑派掌门大师姐 「楚楚剑 -- 楚楚」
   风雨纷纷风中闯江湖风雨心相戚
剑   
系   荡魔剑--小令狐
风   天涯剑--浪迹天涯
雪   孤星剑--流星蝴蝶剑
情
   雪原莽莽雪下忆神州雪原映丹心
LONG);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1753250);
  set("daoxing", 1753250);
  set("kee", 1363);
  set("max_kee", 1363);
  set("sen", 2125);
  set("max_sen", 2125);
  set("force", 6519);
  set("max_force", 3260);
  set("mana", 8039);
  set("max_mana", 4020);
  set("force_factor", 150);
  set("mana_factor", 202);
  set("str", 21);
  set("per", 20);


  set_skill("baihua-zhang", 130);
  set_skill("blade", 1);
  set_skill("buddhism", 41);
  set_skill("dodge", 172);
  set_skill("force", 202);
  set_skill("huoyun-qiang", 95);
  set_skill("jueqingbian", 66);
  set_skill("literate", 142);
  set_skill("moondance", 245);
  set_skill("moonforce", 200);
  set_skill("moonshentong", 190);
  set_skill("ningxie-force", 21);
  set_skill("parry", 155);
  set_skill("snowsword", 258);
  set_skill("spear", 60);
  set_skill("spells", 254);
  set_skill("sword", 201);
  set_skill("unarmed", 133);
  set_skill("whip", 100);
  set_skill("xiaofeng-sword", 48);
  set_skill("yaofa", 21);
  set_skill("zhuihun-sword", 35);


map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIB"楚楚动人剑"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIC"冷月孤冢带"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIW"天禅雪舞衣"NOR);
}

