//sgzl

inherit NPC;

string *names = ({
  "小红鱼",
  "小青鱼",
  "小蓝鱼",
  "小白鱼",
  "小花鱼",
});

string *ids = ({
  "xiao hong yu",
  "xiao qing yu",
  "xiao lan yu",
  "xiao bai yu",
  "xiao hua yu",
});

void create()
{
  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i], "xiao yu", "fish", "yu"}));
  set("long","一条"+names[i]+"，正在海中自由自在的游着。\n");

  set("race", "野兽");
  set("age", 2);

  set_skill("dodge", 60);
  set("combat_exp", 10);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);
  set("chat_msg", ({
                names[i]+"摆了摆尾巴。\n",
                (: random_move :)
        }) );

  setup();
}

