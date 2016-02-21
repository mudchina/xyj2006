  inherit NPC;

void create()
{
        set_name("后羿", ({"hou yi"}));
  set("gender", "男性" );
    set("title","落日神箭");
        set("long", "他就是传说中射落九个太阳的大英雄。\n");
    set("age", 25);
  set("per", 25);
      set("combat_exp", 500000);
        set("daoxing", 50000);
      set("max_kee", 900);
    set("max_sen", 500);
  set("attitude", "friendly");
    set("per", 30);
  set_skill("force",180);
set_skill("archery",200);
  set_skill("dodge",180);
  set_skill("unarmed",180);
    set_skill("baihua-zhang",180);
  set_skill("parry",180);
map_skill("unarmed","baihua-zhang");
set("force",1500);
set("max_force",1500);
set("force_factor",50);
  setup();
    carry_object("/d/obj/cloth/surcoat")->wear();
      carry_object("/d/obj/weapon/archery/zhentian-arrow");
}
void init()
{
        object ob;
  ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
                  "后羿仰天长叹！\n",
                    "后羿擦了擦额头上的汗水。\n",
                  "后羿眼里流露出一丝哀怨。\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                  "name" : "我就是射日的后羿。\n",
         ]) );
add_action("do_cast","cast");
}
int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();
  message_vision("$N对着$n结结巴巴的想念咒语，却怎么也张不开嘴。\n",who,me);
    return 1;
}
