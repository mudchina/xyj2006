inherit NPC;

string *names = ({
  "老虎",
  "花豹",
  "雄狮",
  "豺狼",
  "大象",
});

string *ids = ({
  "lao hu",
  "hua bao",
  "xiong shi",
  "chai lang",
  "da xiang",
});


void create()
{
int ii;
ii=random(sizeof(names));

set_name(names[ii], ({ids[ii], "jing", "monster"}));
set("race", "野兽");
set("age", 33);

set("long", @LONG
一只吸取日月精华而成精的猛兽。
LONG);

set("attitude", "aggressive");
set("class", "yaomo");
set("combat_exp", (random(5)*10000+50000));
set("daoxing", (random(5)*1000+20000));
set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
set("verbs", ({ "bite"}));

set("kee", 800);
set("max_kee", 800);
set("sen", 1200);
set("max_sen", 800);
set("force", 1000);
set("max_force", 1000);
set("mana", 500);
set("max_mana", 500);
set("force_factor", 30);
set("mana_factor", 30);
set("str", 30);


set_skill("unarmed", 50);
set_skill("parry", 50);
set_skill("yingzhaogong", random(30)+20);
set_skill("spells", 100);
set_skill("dengxian-dafa", random(100)+30);
set_skill("force", 100);
set_skill("ningxie-force", random(100)+30);


map_skill("force", "ningxie-force");
map_skill("spells", "dengxian-dafa");
map_skill("unarmed", "yingzhaogong");
map_skill("unarmed", "yingzhaogong");

/*
set("chat_chance_combat", 40);
set("chat_msg_combat", ({
    (: cast_spell, "jieti" :),
  }) );
*/

setup();
}

