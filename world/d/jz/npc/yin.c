//Cracked by Roath

inherit NPC;
#include <ansi.h>
int ask_chen();
void create()
{
  set_name("殷温娇", ({"yin wenjiao", "yin", "wenjiao"}));
  set("long", "殷夫人乃是殷开山之女，玄奘之母。\n");
  set("title", "御赐贤夫人");
  set("gender", "女性");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 10000);
	set("daoxing",10000);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",300);
  set("max_mana",300);
  set("force_factor",5);
  set("inquiry", ([
        "陈光蕊":   (: ask_chen :),
      ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

int ask_chen()
{
        object ob = this_player();
//by dragon 判断是否dntg over for laojunlu is the last one of dntg
        if(  ob->query("obstacle/jz") == "done" )
	return notify_fail("他是我丈夫。");
        
	if( present("liu hong",environment() ))
        return notify_fail("这个.......");

        command("cry1");
        ob->set_temp("obstacle/jz_yin_asked",1);
        command("say 我好命苦啊，丈夫和儿子都死了。");
	return 1;
           
}

int accept_object(object who, object ob)
{
	who=this_player();
        if( who->query("obstacle/jz") == "done" )
                return 1;
        
        if( ! who->query_temp("obstacle/jz_yin_asked") )
                return 1;
        
        if ( ob->query("id") == "xue shu" || ob->query("id") == "han shan" )
        {
        command("ah");
        command("nocry");
        command("say 你是从哪拿来的？我儿现在怎么样了。\n");
        tell_room(environment(this_object()),HIR"忽然刘洪，李彪闯了进来。\n"NOR);
        who->set_temp("obstacle/jz_given",1);
        call_out("liuhong_appear",1,who);
        return 1;
        }
}

void liuhong_appear(object who)
{
        object liuhong = new(__DIR__"liuhong");
        object libiao = new(__DIR__"libiao");
	liuhong->set_temp("my_killer",who);
	libiao->set_temp("my_killer",who);
        liuhong->move(environment(this_object()));
        libiao->move(environment(this_object()));
        
        liuhong->kill_ob(who);
        libiao->kill_ob(who); 
}
                       
