// rewritten by snowcat on 4/12/1997
//qiaofu.c

inherit NPC;

void create()
{
  set_name("樵夫", ({"qiaofu"}));
  set("gender", "男性" );
  set("age", 35);
  set("long", "翠云山中的樵夫，一边伐木，一边哼着山歌。\n");
  set("combat_exp", 25000);
  set("attitude", "peaceful");
  set_skill("dodge", 40);
  set_skill("axe", 50);
  set_skill("literate", 30);
  set("per", 25);
  set("max_kee", 200);
  set("max_gin", 100);
  set("max_sen", 100);
  set("chat_chance",10);
  set("chat_msg",({
        "只听樵夫唱道：云际依依认旧林，断崖荒草路难寻。\n",
        "樵夫唱道：西山望见朝来雨，南涧归时渡处深。\n",
        (:random_move:)
    }));

  setup();
  carry_object("/d/ourhome/obj/linen")->wear();
  carry_object("/d/ourhome/obj/lumber_axe")->wield();
}


