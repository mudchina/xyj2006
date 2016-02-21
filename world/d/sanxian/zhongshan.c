//【三界散仙】mind 2001/2
// 中山夫子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("中山夫子", ({ "zhongshan fuzi", "fuzi", "zhongshan" }));
//        set("title","");
        set("long", 
"战国时代剑家一门的祖师，满头白发的老人，两眼炯炯有神。\n");

        set("gender", "男性");
        set("age", 365);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","sanxian");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 50000000);
        set("daoxing", 500000);

        set_skill("spells",200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("binfen-steps", 200);        
        set_skill("mysticism", 200);      
        set_skill("butian-force", 200);      
        set_skill("literate", 200);
set_skill("unarmed", 100);
        set_skill("spysword", 150);        
        map_skill("dodge", "binfen-steps");        
        map_skill("parry", "spysword");
        map_skill("sword", "spysword");
        map_skill("spells", "mysticism");
        map_skill("force", "butian-force");
        


        create_family("三界散仙", 2, "师傅");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","dunnoname" :),
                              
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
  set("inquiry", ([
        "leave": (: expell_me :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
int is_ghost() { return 1; }

void attempt_apprentice(object ob)
{
if((string)ob->query("family/family_name")=="三界散仙")
  {command("recruit " + ob->query("id"));
   ob->set("class", "sanxian");
   ob->set("title","三界散仙 相士");
  }
else





        if(ob->query("daoxing") > 100000 || ob->query("combat_exp") > 100000)
        {
        command("say 你入世太深,不宜学我剑家工夫．．．\n");
        return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("class", "sanxian");
        ob->set("title","剑家传人");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="三界散仙")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("按我剑家门规，却须受罚，你可愿意(agree)？");
    }
  return ("我不知道！");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N答道：弟子愿意。\n\n", this_player());
      command("say 那你便去吧。。。或者这是天意！");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/sanxian", 1);
      this_player()->delete_skill("mysticism");
      this_player()->delete_skill("spysword");
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
      message_vision("中山夫子在$N的头上怕了一下，$N顿时觉得若有所失。\n\n", this_player());
      this_player()->delete("family");
      this_player()->set("title", "普通百姓");
      this_player()->save();
      return 1;
    }
  return 0;
}




