
#include <ansi.h>

inherit "/d/dntg/lijing/troops.c";

int do_jifabao();
    
void create()
{
  set_name("哪吒", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "三坛海会之神");
  create_family("陷空山无底洞", 1, "弟子");
  set("class", "xian");
  set("long", "一位唇红齿白的美少年。\n");
  set("gender", "男性");
  set("age", 16);
  set("attitude", "friendly");
  set("rank_info/respect", "小太子");
  set("rank_info/rude", "乳臭未干的小儿");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 2000);
  set("max_sen", 3000);
  set("force", 2600);
  set("max_force", 4000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 120);
  set("combat_exp", 1500000);
  set("daoxing", 2000000);

  set_skill("spells", 200);
  set_skill("dao", 200);
  set_skill("unarmed", 200);
  set_skill("yinfeng-zhua", 200);
  set_skill("dodge", 200);
  set_skill("lingfu-steps", 200);
  set_skill("parry", 200);
  set_skill("force", 190);
  set_skill("huntian-qigong", 180);
  set_skill("spear", 200);
  set_skill("huoyun-qiang", 200);
  set_skill("blade", 170);
  set_skill("sword", 200);
  set_skill("qixiu-jian", 180);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
        "name": "我乃托塔天王三太子李哪吒是也。",
        "rumors": "玉帝敕封家严为降魔大元帅，在下为三坛海会之神，专管降妖除魔。",
        "风火轮": "送人了！",
        ]));
  setup();

  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object(__DIR__"obj/huojianqiang")->wield();

  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-fake");
  else
    carry_object("/d/obj/fabao/huntian-ling");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-fake");
  else
    carry_object("/d/obj/fabao/qiankun-quan");

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
     (: do_jifabao :),
  }) );

}

int do_jifabao() {
  object me=this_object();
  object target=query("master")->target();
  object fabao;

//  message_vision("ji fabao on..\n",me);
  if (target) {
  //  message_vision(target->name()+"\n",me);
    if (random(2)) fabao = present ("qiankun quan",me);
      else fabao=present("huntian ling",me);
    if (fabao) {
    //  message_vision(fabao->query("name")+"\n",me);
      fabao->ji_ob (target);
    }
  }
  return 1;
}
