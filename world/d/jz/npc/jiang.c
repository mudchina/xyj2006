//Cracked by Roath
inherit NPC;
#include <ansi.h>
string ask_fish();
string ask_bingfa();

void create()
{
  set_name("姜太公", ({ "jiang taigong","jiang"}));
  set("long", "他就是那个钓鱼的姜太公。\n");
  set("gender", "男性");
  set("age", 57);
  set("str", 50);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 3000);
  set("max_force", 2000);
  set("force_factor", 60);
  set("max_mana", 2000);
  set("mana", 2000);
  set("mana_factor", 60);
  set("combat_exp", 1500000);
	set("daoxing",1500000)	
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 150);
  set_skill("spells", 150);
  set_skill("unarmed", 150);
  set_skill("staff", 150);
  set_skill("gouhunshu", 150);
  set_skill("tonsillit", 150);
  set_skill("ghost-steps", 150);
  set_skill("jienan-zhi", 150);
  set_skill("lunhui-zhang", 150);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance", 10);
  set("inquiry", ([
        "钓鱼" : (: ask_fish :),
        "fish" : (: ask_fish :),
        "兵法" : (: ask_bingfa :),
        ]));
  set("chat_msg", ({
                "姜太公说道：愿者上钩...愿者上钩。\n",
                        }));
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
   carry_object("/d/jz/obj/yugan");  
}
string ask_fish()
{
        object ob = this_player();
        object me = this_object();

           if( ob->query("combat_exp") < 1000000 ||
            ob->query("office_number") < 300 )
                return "没看到我在钓鱼吗？\n";

        command("hehe");
        ob->set_temp("just_wait",time());
        return "既然"+ RANK_D->query_respect(ob)
        +"对钓鱼感星期，可否陪老夫钓会鱼？\n";
}

string ask_bingfa()
{
        object ob = this_player();
        object book = new("/d/obj/book/bingfa");

        if( ! ob->query_temp("just_wait") )
                return "你在罗嗦什么？\n";

        if( time() - ob->query_temp("just_wait") < 60*60*8 )
                return "你说什么，我怎么不太懂？\n";

        book->set("owner",ob->query("id") );
        book->move(ob);
        return "果然有诚心，这本书你拿去研读研读吧。\n";
}
