//girl.c
#include <ansi.h>

inherit NPC;
string ask_for_shuizhu();
void check_player();
void create()
{
       set_name("李忆如", ({"li yiru","li"}));
       set("long", "李忆如是李逍遥大侠与圣女赵灵儿的女儿，为纪念死去的林月如
阿姨，赵灵儿为其起名叫忆如。\n");
       set("gender", "女性");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 40);
       set("int", 40);
       set("str", 40);
       set("cps", 40);
       set("spi", 40);
       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 200);
       set("max_mana", 5000);
       set("mana", 10000);
       set("mana_factor", 150);
       set("combat_exp", 5000000);
       set_skill("literate", 90);
       set_skill("unarmed", 200);
       set_skill("dodge", 220);
       set_skill("parry", 220);
 set_skill("sword", 220);
 set_skill("spells", 220);
 set_skill("moonshentong", 220);
 set_skill("baihua-zhang", 220);
 set_skill("moonforce", 220);
 set_skill("force", 220);
 set_skill("snowsword", 220);
 set_skill("moondance", 220);
 map_skill("spells", "moonshentong");
 map_skill("unarmed", "baihua-zhang");
 map_skill("force", "moonforce");
 map_skill("sword", "snowsword");
 map_skill("parry", "snowsword");
 map_skill("dodge", "moondance");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
                (: cast_spell, "mihun" :),
                (: perform_action, "sword.huifeng" :),
                (: perform_action, "sword.wuxue" :),
        }) );
        set("inquiry", ([
  "李逍遥" : "他是我父亲，不过现在出去了！",
  "赵灵儿" : "是我的娘亲，我刚出生她就去世了。",
  "水灵珠" : (: ask_for_shuizhu :),
  ]) );
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/baowu/shuizhu");
}
void init()
{
add_action("do_agree","yes");
        check_player();
}
string ask_for_shuizhu()
{
        object who = this_player();
if(!present("shuizhu",this_object()))
  return "对不起,水灵珠已经被人拿走了!\n";
if(who->query("search_for_mujian"))
  return "不是要你找来木剑给我吗?\n";  
        if(who->query("asked_for_shuizhu") || who->query("liyiru/kill_jiaolong"))
            return "不是要你先去教训教训水潭里的妖怪吗？\n";
        command("say 给你也行。不过....\n");
        command("xixi "+who->query("id"));
        command("say 你先帮我教训一下水潭里的妖怪，自从父亲出去后，\n
它就想出去害人了。\n");
        who->set("asked_for_shuizhu",1);
return "你同意(yes)吗？很危险的！";
}
int do_agree()
{
 object who = this_player();

        if(!who->query("asked_for_shuizhu"))
           return notify_fail("你要答应什么啊？\n");
        who->delete("asked_for_shuizhu");
        if(who->query("combat_exp")<1000000)
           return notify_fail("李忆如摇摇头道：你去恐怕是送死啊！\n");
        who->set("liyiru/kill_jiaolong",1);
        command("bow");
        command("say 有劳你了。\n");
        return 1;
}
int accept_object(object who,object ob)
{
 int i;
 object *inv;
 if(!who->query("search_for_mujian"))
    return notify_fail("这怎么敢当？\n");
 if(ob->query("id") != "wanju mujian")
    return notify_fail("这不是我想要的！\n");
        who->delete("search_for_mujian");
 inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++)
        {
         if (inv[i]->query("id")=="shuizhu" || inv[i]->query("id")=="shui lingzhu")
                {
                   inv[i]->move(who);
                   message_vision("$N从怀里掏出一颗白色的珠子，递到$n手里。\n",this_object(),who);
            message("channel:rumor",RED+"【谣言】某人："+who->query("name")+"拿到水灵珠了！\n"+NOR,users());
         }
        }
}
void check_player ()
{
  object who = this_player();
  object me = this_object();
  if (who && visible(who))
  {
   if ( environment(who)==environment(me))
   {
    if(who->query("search_for_mujian"))
       message_vision("$N对$n说：不是要你帮我找木剑吗？\n",me,who);
    if (who->query("liyiru/killed_jiaolong"))
                {
                message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect
(who)+
                    "！\n",me,who);
                message_vision ("$N对$n说道：不过我想再麻烦你帮我找一下父亲给
我的木剑！\n",me,who);
who->delete("liyiru/killed_jiaolong");
                who->set("search_for_mujian",1);
                }
        }
  }
}
