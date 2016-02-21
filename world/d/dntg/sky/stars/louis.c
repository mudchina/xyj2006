//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("龙五",({"star louis","louis","star"}));
  set("gender", "男性");
  set("title", "亢金星官");
  set("age", 57);
  set ("long", @LONG
他是个很随便的人，有好衣服穿，他就穿着;没有好衣服穿，他就穿破的。有好酒好莱，他
就猛吃;没有得吃，就算饿三天三夜，他也不在乎。
就算饿了三天三夜后，他还是会笑，很少有人看见过他板着脸的时候。　
现在他就在笑。他笑得很随便，有时候会皱起鼻子来笑，有时会眯起眼睛来笑，有时候
甚至会象小女孩一样，噘起嘴来笑。

他的笑容中，绝对看不出有一点儿恶意，更没有那种尖刻的讥诮。
所以无论他怎样笑，样子绝不难看。
LONG);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1897251);
  set("daoxing", 1897251);
  set("kee", 1231);
  set("max_kee", 1231);
  set("sen", 2307);
  set("max_sen", 2307);
  set("force", 5465);
  set("max_force", 2733);
  set("mana", 9459);
  set("max_mana", 4730);
  set("force_factor", 149);
  set("mana_factor", 237);
  set("str", 24);
  set("per", 21);


  set_skill("buddhism", 34);
  set_skill("cuixin-zhang", 79);
  set_skill("dao", 11);
  set_skill("dodge", 198);
  set_skill("force", 199);
  set_skill("ghost-steps", 151);
  set_skill("jindouyun", 246);
  set_skill("kusang-bang", 142);
  set_skill("literate", 139);
  set_skill("parry", 156);
  set_skill("puti-zhi", 17);
  set_skill("qianjun-bang", 267);
  set_skill("spells", 254);
  set_skill("stick", 188);
  set_skill("unarmed", 138);
  set_skill("wuxiangforce", 200);
  set_skill("yaofa", 253);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "cuixin-zhang");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/shoes")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="shoes";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"金色白朗宁"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"白色西装"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"黑色皮靴"NOR);
}

